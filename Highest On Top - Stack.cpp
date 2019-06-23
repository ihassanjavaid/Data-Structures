#include <iostream>
using namespace std;

struct Node{
    int integer;
    Node * nextLocation;
};

class Stack {
    //Node *head; (declare here if you want anything to be private

public: // Everything in the public public is accessible outside and everything (method, attribute above it is private by default
    Node *head;

    //Constructor
    Stack () {
        head = NULL;
    }

    void push(int num) {

        // Add on head
        Node* newNode = new Node;
        newNode -> integer = num;

        if ( head == NULL ){

            newNode->nextLocation = NULL;
            head = newNode;
        }

        else {

            newNode -> nextLocation = head;
            newNode = head;
        }
    }

    int pop() {

        int poppedNum;

        if ( head != NULL ){
            Node * temp = head;
            head = head -> nextLocation;
            poppedNum = temp -> integer;
            delete(temp);
        }
        return poppedNum;
    }

    int readTop(){
        // reads the top character without affecting the stack
        return  head-> integer;

    }

    bool stackisEmpty(){
        // checks if stack is empty through checking if a node exists or not

        if ( head == NULL )
            return true;
        return false;

    }

    void displayStack() {

        Node *traverse = head;
        int count = 1;

        while (traverse != NULL) {
            cout << count << ". " << traverse->integer << endl;
            traverse = traverse->nextLocation;
            count++;
        }
    }

};



int main() {

    Stack stack;
    cout << "Working!";

}
