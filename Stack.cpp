#include <iostream>
#include <string>
using namespace std;

struct Node {
    char character;
    Node* nextLocation;
};

void push(char);
void pop();
char readTop();
void printStack();
void stringReverse();
void decToBinary();

Node * head;

int main() {

    int choice;

    Node * newNode = new Node;

    cout << "=== STACK ===\n\n";

    cout << "Enter first value: ";
    cin >> newNode -> character;

    while ( true ){

        cout << "==========\n";
        cout << "1. Push a character.\n"
                    "2. Pop a character.\n"
                    "3. Read the top.\n"
                    "4. Print stack.\n"
                    "5. Reverse a string.\n"
                    "6. Decimal to Binary conevrsion.\n"
                    "0. Exit.\n"
                    "Your choice: ";
        cin >> choice;

        switch ( choice ){

            case 1: {
                char character;
                cout << "Enter a character: ";
                cin >> character;
                push(character);
                break;
            }

            case 2:{
                cout << readTop() << " is popped.\n";
                pop();
                break;
            }

            case 3:{
                cout << "The top is: " << readTop();
                break;
            }

            case 4:{
                printStack();
                break;
            }

            case 5:{
                stringReverse();
                break;
            }

            case 6:{
                decToBinary();
                break;
            }

            case 0:{
                return 0;
            }

            default:{
                cout << "Wrong choice! Please enter again!\n";
            }

        }

    }
    return 0;
}

void push(char character){

    // add node at head
    Node * newNode = new Node;
    newNode -> character = character;
    newNode-> nextLocation = head;
    head = newNode;

}

void pop(){

    // delete node at head
    Node * temp = head;
    head = head -> nextLocation;
    delete(temp);

}

char readTop(){
    return head -> character;
}

void printStack(){

    if ( head != NULL ) {

        Node *pointer;
        for (pointer = head; pointer->nextLocation != NULL; pointer = pointer->nextLocation) {
            cout << "||\t" << pointer->character << "\t||\n";
        }
        cout << "||\t" << pointer->character << "\t||\n";
        cout << "=====\n\n";
    }

    else {
        cout << "Stack is empty!\n";
    }

}

void stringReverse(){

    string str;
    cout << "\nPlease enter the string to be reversed: ";
    cin >> str;

    for ( int i = 0 ; i < str.length() ; i++ )
        push(str[i]);

    cout << "The reversed string is: ";

    for ( int i = 0 ; i < str.length() ; i++ ) {
        cout << readTop();
        pop();
    }
    cout << endl;
}

void decToBinary(){

    int remainder;
    int numOfBinaryDigits = 0;
    int decNum;

    cout << "Enter a decimal number to be converted into binary: ";
    cin >> decNum;

    while ( decNum > 1 ){
        remainder = decNum % 2;
        decNum = decNum / 2;
        push(to_string(remainder)[0]);
        numOfBinaryDigits++;
    }

    cout << "The binary number is: ";

    while ( numOfBinaryDigits != 0 ){
        cout << readTop();
        pop();
        numOfBinaryDigits--;
    }
    cout << endl;
}


