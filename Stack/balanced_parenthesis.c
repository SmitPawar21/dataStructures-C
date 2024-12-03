#include <stdio.h>
#define MAX 100

// WHAT WE HAVE TO DO?

// To check whether parenthesis are balanced. 
// Which means we have to check whether correct brackets are opened and closed accordingly. 
// For Example: 
// [{()}] this is balanced. 
// [(] this is NOT balanced.

// HOW WE ARE GOING TO DO?

// if we come across any OPENING bracket, push it in stack.
// if we come across a CLOSING bracket, then check whether the top element at stack is the pair of this closing bracket.
// top element = (  and  closing bracket we came across = ) => then no problem
// nut top = ( and closing bracket we came across = ] => PROBLEM! immediately come out of loop and print NOT BALANCED

char stack[MAX];
int top = -1;

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop()
{
    return stack[top--];
}

// This will return 1 if its opening bracket
int isOpening(char ch) {
    if(ch == '(' || ch =='[' || ch =='{') {
        return 1;
    }

    return 0;
}

// This will return 1 if its closing bracket
int isClosing(char ch) {
    if(ch == ')' || ch == ']' || ch == '}') {
        return 1;
    }

    return 0;
}

// This will return 0 if the opening and closing pair is wrong
int checkValid(char a, char b) {
    if(a == '(' && b == ')'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    else if(a == '{' && b == '}'){
        return 1;
    }

    return 0;
    
}

void main() {
    char str[MAX];
    char ch;
    int i = 0;

    printf("Enter parenthesis expression: ");
    scanf("%s", str);

    while(str[i] != '\0') {
        ch = str[i];

        if( isOpening(ch) == 1 ) {
            push(ch);
        }

        else if( isClosing(ch) == 1 ) {

            int answer = checkValid(pop(), ch);
            // Keep in mind to put pop() first then ch because pop would be opening always as it is coming from stack.

            if(answer == 0){
                printf("NOT BALANCED\n");
                break;
            }
        }

        i++;
        if(str[i] == '\0' && top == -1) {
            printf("BALANCED\n");
        }
    }
}