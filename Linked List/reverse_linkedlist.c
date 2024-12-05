#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    return stack[top--];
}

// This creates linked list with 5 default-valued nodes
void createLL() {
    struct node *newnode, *temp;
    int i;

    for(i=1; i<=5; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = i;
        newnode -> next = NULL;

        if(head == NULL) {
            head = newnode;
        }
        else {
            temp = head;
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }
}

void reverse() {
    struct node *temp;
    temp = head;

    while(temp != NULL) {
        push(temp -> data);
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL) {
        temp -> data = pop();
        temp = temp -> next;
    }
}

void display() {
    struct node *temp;
    temp = head;

    while(temp -> next != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("%d\n", temp -> data);
}

void main() {

    createLL();
    printf("Linked List: ");
    display();

    printf("\n");

    reverse();
    printf("Reversed Linked List: ");
    display();

} 