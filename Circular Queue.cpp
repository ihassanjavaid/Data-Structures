#include <iostream>
using namespace std;

int queue[5];
int maxSize = 5;

int front = -1;
int rear = -1;

void insert();
void deleteQ();
void display();
void menu();
bool isEmpty();
bool isFull();

int main() {

    int choice;

    while (true){

        cout << "\n=== Circular Queue ===\n";
        menu();

        cin >> choice;

        switch (choice) {

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
            default: {
                cout << "Invalid Entry!\n";

            }
        }
    }
}

void insert(){

    int item;

    if ( isFull() ){
        cout << "Queue Overflow!\n";
        return;
    }

    cout << "Enter item to be added: ";
    cin >> item;

    if ( front == -1 )
        front = rear = 0;

    else if ( rear == maxSize -1 && front != 0 )
        rear = 0;

    else
        rear++;

    queue[rear] = item;
    cout << "Item inserted at position " << rear;
}

void display() {

    if ( isEmpty() ) {
        cout << "Queue is empty!\n";
        return;
    }

    if ( rear >= front ){

        for ( int i = front ; i <= rear ; i++)
            cout << queue[i] << ", ";
    }

    else{

        for ( int i = front; i < maxSize ; i++)
            cout << queue[i] << ", ";

        for (int i = 0; i <= rear; i++)
            cout << queue[i] << ", ";
    }

}

void deleteQ(){

    if ( isEmpty() ){
        cout << "Queue Empty!\n";
        return;
    }
    cout << queue[front] << " deleted!\n";

    if ( front == rear ){
        front = -1;
        rear = -1;
    }

    if ( front == maxSize-1 )
        front = 0;
    else
        front++;

}

void menu(){
    cout << "1. Insert\n"
            "2. Delete\n"
            "3. Display\n"
            "0. Quit\n"
            "Enter your choice: ";
}

bool isEmpty(){
    return front == -1;
}

bool isFull(){
    if ( rear == maxSize -1 && front == 0 )
        return true;
    return front == rear + 1;
}