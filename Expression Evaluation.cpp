#include <iostream>
#include <string>
using namespace std;

struct Node {
    // The structure has two members
    // char is used while making postfix expression from infix expression
    // int is used for computation of postfix expression

    char character;
    int integer;
    Node* nextLocation;
};

void push(char);
void push(int);
char pop();
int popInteger();
char readTop();
bool stackisEmpty();
void checkCharacter(char);
bool isIncomingHigher(char, char);
void matchBracket(char);
void emptyTheStack();
void breakPostfix(string);
void doTheOperation(char);
bool verifyBracketsEquivalence(string);
string makePrefix(string);

Node * head = NULL;
string *postfixStr;

int main() {

    string expression; // the main input
    postfixStr = new string; // allocated dynamically here, so increment can be done

    cout << "=== Expression Evaluation ===\n\n";

    cout << "Enter an expression in infix notation: ";
    cin >> expression;

    // Verify if the expression is correctly entered
    if ( !verifyBracketsEquivalence(expression) ){
        cout << "\nWrong Expression Entered | Imbalanced Brackets !\n";
        return 0;
    }
    else {
        cout << "\nBrackets are balanced!\n";
    }

    // This loop sends every character and check whether it should be added to postfix expression or pushed to stack
    for ( int i = 0 ; i < expression.length() ; i++ ){
            checkCharacter(expression[i]);
    }

    // Check after ending the string if there's something left in the stack and then empty it
    emptyTheStack();

    // Postfix Expression
    cout << "\nPostfix Notation: " << *postfixStr << endl;

    cout << "\nPrefix Notation: " << makePrefix(*postfixStr) << endl;

    // Main function for computation of postfix expression
    breakPostfix(*postfixStr);

    // After all the computations of the postfix expression, the final answer is pushed into the stack according to the algorithm
    // which is retrieved here
    int answer = popInteger();


    // just a check for if the algorithm worked fine - can be removed
    if ( stackisEmpty() ) {
        cout << "\nFinal answer: " << answer << endl;
    }

    else {
        cout << "Error in computations!";
    }

    return 0;
}

bool verifyBracketsEquivalence(string strForCheck) {

    // This function takes the main unaltered infix expression and verifies if it's right or not
    // by checking the equivalence of brackets

    /*
     * Working:
     * If opening bracket is encountered, push it into the stack
     * else, check if on top place that matching bracket is present, if not, return false.
     */

    for (int i = 0; i < strForCheck.length() ; i++) {

        if (strForCheck[i] == '(' || strForCheck[i] == '[' || strForCheck[i] == '{') {
            push(strForCheck[i]);
        }

        else if ( strForCheck[i] == ')' ){
            if ( readTop() != '(' || stackisEmpty() ){
                return false;
            }
            else{
                pop();
            }
        }

        else if ( strForCheck[i] == ']' ){
            if ( readTop() != '[' || stackisEmpty() ){
                return false;
            }
            else{
                pop();
            }
        }

        else if ( strForCheck[i] == '}' ){
            if ( readTop() != '{' || stackisEmpty() ){
                return false;
            }
            else{
                pop();
            }
        }

    }

    if ( !stackisEmpty() ){
        return false;
    }
    return true;
}

void push(char character){

    // This push function takes char input and stores it into the character of node
    // used in making postfix expression

    if ( head == NULL ){
        // Make first node and set it as head
        Node* newNode = new Node;
        newNode->character = character;
        newNode->nextLocation = NULL;
        head = newNode;
    }

    else {
        // Add node at head
        Node *newNode = new Node;
        newNode->character = character;
        newNode->nextLocation = head;
        head = newNode;
    }

}

void push(int incomingNumber){

    // This push function takes int input and stores it into the integer of node
    // used in computation of postfix expression

    if ( head == NULL ){
        // Make first node and set it as head
        Node* newNode = new Node;
        newNode->integer = incomingNumber;
        newNode->nextLocation = NULL;
        head = newNode;
    }

    else {
        // Add node at head
        Node *newNode = new Node;
        newNode->integer = incomingNumber;
        newNode->nextLocation = head;
        head = newNode;
    }

}

char pop(){

    // Delete node at head and returns a character
    // used while making postfix string from infix string

    Node * temp = head;
    head = head -> nextLocation;
    char character = temp -> character;
    delete(temp);
    return character;
}

int popInteger(){

    // Delete node at head and returns integer
    // used for the computation of postfix expression

    Node * temp = head;
    head = head -> nextLocation;
    int integer = temp -> integer;
    delete(temp);
    return integer;

}

bool stackisEmpty(){
    // checks if stack is empty through checking if a node exists or not

    if ( head == NULL )
        return true;
    return false;

}

void checkCharacter(char ch){

    // Every character of the main input string ( infix string ) is processed in this function

    if ( ch >= '0' && ch <= '9' ){ // for numeric characters, directly add into the postfix string
        *postfixStr += ch;
    }

    else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/'){

        // for operators other than brackets
        // is stack is empty directly push.

        *postfixStr += ' ';

        if ( stackisEmpty() ) {
            push(ch);
        }

        else{

            // else if stack not empty
            // keep popping until the precedence of the incoming operator is higher than the one in the stack

            if ( isIncomingHigher(ch, head->character) ) {
                push(ch);
            }

            else{

                while ( !isIncomingHigher(ch, head->character) ){
                    *postfixStr += readTop();
                    *postfixStr += ' ';
                    pop();
                }
                push(ch);

            }

        }
    }

    else if ( ch == '(' || ch == '[' || ch == '{' || ch == ')' || ch == ']' || ch == '}' ) { // for all types of brackets

        if ( ch == '(' || ch == '[' || ch == '{' ){
            // if brackets are opening directly push them into stack
            push(ch);
        }

        else {
            // match corresponding brackets
            matchBracket(ch);
        }
    }

}

bool isIncomingHigher(char incomingCh, char stackCh){

    // this function just returns true or false by checking the precedence of the operators
    // it takes the incoming operator and the top operator in the stack as it's input.

    if ( incomingCh == '*' )
        return true;

    if ( incomingCh == '/' ){

        if (stackCh == '*'){
            return false;
        }
        return true;
    }

    if ( incomingCh == '+' ){

        if ( stackCh == '*' || stackCh == '/') {
            return false;
        }
        return true;
    }

    if ( incomingCh == '-'){

        if ( stackCh == '*' || stackCh == '/' || stackCh == '+') {
            return false;
        }
        return true;
    }

}

void matchBracket(char bracket){
    // This function takes closing bracket as it's input and looks the stack for it's corresponding opening bracket
    // Until it founds its corresponding opening bracket, it 'pops' from the stack and adds into postfix string what it pops.

    *postfixStr += ' ';

    if ( bracket == ')' ) {

        while ( head -> character != '(' ) {
            *postfixStr += readTop();
            *postfixStr += ' ';
            pop();
        }
        pop();

    }

    else if ( bracket == ']' ) {

        while ( head -> character != '[' ) {
            *postfixStr += readTop();
            *postfixStr += ' ';
            pop();
        }
        pop();

    }

    else if ( bracket == '}' ) {

        while ( head -> character != '{' ) {
            *postfixStr += readTop();
            *postfixStr += ' ';
            pop();
        }
        pop();

    }

}

void emptyTheStack(){
    // adds into postfix string and pops until the stack is empty
    *postfixStr += ' ';

    while ( head != NULL) {
        *postfixStr += readTop();
        *postfixStr += ' ';
        pop();
    }

}

char readTop(){
    // reads the top character without affecting the stack

    if ( stackisEmpty() )
        return ' ';
    return  head->character;

}

void breakPostfix(string postFix){
    // Every character of the postfix string will come in this methods and would be procedeed further from here
    // does nothing if encounters a space

    string intStr;

    for ( int i = 0 ; i < postFix.length() ; i++ ){

        if ( postFix[i] != ' ' ){

            if ( postFix[i] >= '0' && postFix[i] <= '9' ){

                // treat the digits as a single integer until seperated by a space
                while ( postFix[i] != ' '){
                    intStr += postFix[i];
                    i++;
                }
                // add the digits into a string until space is encountered
                // After having space, make an integer out of the string and empty the string afterwards

                //when a full integer of 'n' digits are obtained and stored into intStr push it into the stack after converting it into int
                // stoi() method is used to convert a string into an integer
                push( stoi(intStr) );
                intStr = "";
                continue;
            }

            else if ( postFix[i] == '+' || postFix[i] == '-' || postFix[i] == '*' || postFix[i] == '/' ){
                doTheOperation(postFix[i]);
            }

        }

    }

}

void doTheOperation(char operation){
    // checks what the operator is
    // performs the operation on top 2 numbers of the stack
    // pushes back the answer into the stack

    /*
     * The logic why temp 2 is popped first and temp1 after it is that,
     * in case of minus and divide, the operand on top of stack should go on right side of operator
     * and the next one on the left
     */

    int temp2 = popInteger();
    int temp1 = popInteger();

    if ( operation == '+' ){
        push( temp1 + temp2 );
    }

    else if ( operation == '-' ){
        push( temp1 - temp2 );
    }

    else if ( operation == '*' ){
        push( temp1 * temp2 );
    }

    else if ( operation == '/'){
        push( temp1 / temp2 );
    }

}

string makePrefix(string postFixToConv){

    string prefix = "";

    for ( int i = (postFixToConv.length()-1) ; i >= 0 ; i--){
        prefix += postFixToConv[i];
    }
    return prefix;
}


