#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* nextLocation;
};

void menu();
void insert();
void display();
void deleteQ();

Node* head = NULL;
Node* tail = NULL;

int main() {

    int choice;

    while (true){

        menu();

        cin >> choice;

        switch (choice){

            case 1:{
                insert();
                break;
            }
            case 2:{
                deleteQ();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 0:{
                return 0;
            }
        }
    }
}

void menu(){
    cout << "1. Insert\n"
                "2. Delete\n"
                "3. Display\n"
                "0. Exit\n"
                "Enter your choice: ";
}

void insert(){

    int item;
    cout << "Enter item to be inserted: ";
    cin >> item;

    Node* newNode = new Node;
    newNode -> data = item;

    if ( head == NULL ){
        newNode->nextLocation = NULL;
        head = newNode;
        tail = newNode;
    }

    else {
        tail -> nextLocation = newNode;
        tail = newNode;
    }

    tail -> nextLocation = NULL;

    cout << "Inserted!\n";
}

void display() {

    if ( head == NULL ) {
        cout << "Queue is empty!\n";
        return;
    }

    else {
        cout << "Queue elements: \n";

        Node * traverse = head;
        for ( traverse ; traverse -> nextLocation != NULL ; traverse = traverse -> nextLocation ) {
            cout << traverse->data << ", ";
        }
        cout << traverse->data << ".";
        cout << endl;

    }
}

void deleteQ(){

    if ( head == NULL ){
        cout << "Queue is Empty!\n";
        return;
    }

    Node* temp = head;
    head = head -> nextLocation;
    cout << temp -> data << " is deleted!\n";
    delete temp;

}