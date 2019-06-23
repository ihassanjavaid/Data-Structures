#include <iostream>
using namespace std;

struct Node {
    int number;
    Node * previousLocation;
    Node * nextLocation;
};

void addNode(Node *, int);
Node* verifyAscOrder(Node *);
Node* setEnd(Node *);
void printList(Node *, char);
void deleteNode(Node *, int);

int main() {

    Node * head;
    Node * end;

    Node * newNode = new Node;
    head = newNode;

    cout << "Please enter how long the list you want to make initially or \"0\" to exit: ";
    int listLength;
    cin >> listLength;

    if ( listLength == 0 ) {
        return 0;
    }

    else {

        cout << "Enter number # 1: ";
        cin >> newNode -> number;

        for (int i = 0; i < (listLength - 1); i++) {

            int newNum;
            cout << "Enter number # " << (i+2) << ": ";
            cin >> newNum;

            addNode(head, newNum);
        }

        head = verifyAscOrder(head); // to ensure that first element also gets sorted
        end = setEnd(head);

    }

    while ( true ){

        cout << "=================\n\n";

        cout << "1. Print List Forward.\n";
        cout << "2. Print List Backwards.\n";
        cout << "3. Add a number into list.\n";
        cout << "4. Delete a number.\n";
        cout << "0. Exit.\n";
        cout << "Enter choice:  ";
        int choice;
        cin >> choice;

        switch (choice){

            case 1:{
                printList(head, 'f');
                break;
            }

            case 2:{
                printList(end, 'b');
                break;
            }

            case 3:{

                cout << "Enter how many numbers you want to add: ";
                int numOfNewNums, num;
                cin >> numOfNewNums;

                for (int i = 0; i < numOfNewNums; i++) {
                    cout << "Enter number: ";
                    cin >> num;
                    addNode(head, num);
                }

                head = verifyAscOrder(head);
                end = setEnd(head);
                break;
            }

            case 4:{

                cout << "Enter number: ";
                int num;
                cin >> num;
                deleteNode(head, num);
                break;
            }

            case 0:{
                cout << "Program Terminated\n";
                return 0;
            }

            default:{
                cout << "Wrong choice please enter again!";
                break;
            }

        }

    }

    return 0;
}

void addNode(Node * head, int number_in){

    Node * pointer = head;

    if ( new Node == NULL )
        cout << "Space full!";

    else {

        while ( pointer -> nextLocation != NULL ) {

            if (pointer -> nextLocation -> number > number_in)
                break;

            pointer = pointer -> nextLocation;
        }


        Node *newNode = new Node;

        newNode -> number = number_in;
        newNode -> nextLocation = pointer -> nextLocation;

        if ( newNode -> nextLocation != NULL )
            newNode->nextLocation->previousLocation = newNode;

        pointer->nextLocation = newNode;
        newNode->previousLocation = pointer;
    }

}

Node* verifyAscOrder(Node * head){

    if ( head -> number > head -> nextLocation -> number ){

        addNode(head -> nextLocation, head -> number);
        Node * temporary = head;
        head = head -> nextLocation;
        head -> nextLocation -> previousLocation = nullptr;
        delete(temporary);

    }
    return head;
}

void printList(Node * headorEnd, char type){

    cout << endl << endl;
    int i = 1;

    cout << "No. " << "\tData" << "\t Address\n";

    if ( type == 'f' ) {
        for (Node *pointer = headorEnd ; pointer != NULL; pointer = pointer->nextLocation, i++) {
            cout << i << "\t\t" << pointer->number << "\t\t " << pointer << endl;
        }
    }
    else {
        Node * pointer;
        for ( pointer = headorEnd ; pointer -> previousLocation != NULL; pointer = pointer->previousLocation , i++) {
            cout << i << "\t\t" << pointer->number << "\t\t " << pointer << endl;
        }
        cout << i << "\t\t" << pointer->number << "\t\t " << pointer << endl;
    }

}

Node* setEnd(Node * head){

    Node * pointer = head;

    while ( pointer -> nextLocation != NULL )
        pointer = pointer -> nextLocation;

    return pointer;
}

void deleteNode(Node * head, int number_in){

    Node * pointer = head;
    Node * temp;
    bool flag = false;

    while ( pointer -> nextLocation != NULL ){

        if ( pointer -> nextLocation -> number == number_in ){
            flag = true;

            temp = pointer -> nextLocation -> nextLocation;
            delete(pointer -> nextLocation);
            pointer -> nextLocation = temp;
            temp -> previousLocation = pointer;

            cout << "Number found and deleted!\n";
            break;
        }

        pointer = pointer -> nextLocation;
    }

    if ( !flag )
        cout << "Number not found!\n";
}
