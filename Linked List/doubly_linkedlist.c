//  FUNCTIONS 

//  Create a default 5 nodes Doubly LL
//  Forward Traversal
//  Backward Traversal
//  Insert at Beginning
//  Insert at Ending
//  Display 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

// This function will create five nodes of default values from 1 to 5
void createDLL() {
    int i;
    struct node *newnode, *temp;

    for(i=1; i<=5; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        temp = head;
        newnode -> data = i;
        newnode -> next = NULL;
        newnode -> prev = NULL;

        if(head == NULL) {
            head = newnode;
        }

        else{
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newnode;
            newnode -> prev = temp;
        }
    }
    tail = newnode;
}

void forward_traversal() {
    struct node *temp;
    temp = head;

    printf("__________________________________\n");
    if(head == NULL) {
        printf("Linked List is Empty\n");
    }
    else{
        while(temp -> next != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("%d -> NULL\n", temp -> data);
    }
    printf("__________________________________\n");
}

void backward_traversal() {
    struct node *temp;
    temp = tail;

    printf("__________________________________\n");
    if(head == NULL) {
        printf("Linked List is Empty\n");
    }
    else{
        while(temp -> prev != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> prev;
        }
        printf("%d -> NULL\n", temp -> data);
    }
    printf("__________________________________\n");
}

void insert_at_beginning() {
    int new_value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &new_value);

    newnode -> data = new_value;
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    newnode -> prev = NULL;
}

void insert_at_ending() {
    int new_value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &new_value);

    newnode -> data = new_value;
    newnode -> prev = tail;
    tail -> next = newnode;
    tail = newnode;
    newnode -> next = NULL;
}

void main() {
    int exit = 0; // exit is false
    int choice;

    while(exit == 0) {
        printf("****************************************\n");
        printf("Enter 1 for Create Doubly Linked List of 5 nodes.\n");
        printf("Enter 2 for Forward Traversal\n");
        printf("Enter 3 for Backward Traversal\n");
        printf("Enter 4 for Inserting node at Beginning\n");
        printf("Enter 5 for Inserting node at Ending\n");
        printf("Enter 0 to Exit Application\n");
        printf("****************************************\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: createDLL();
                    break;
            case 2: forward_traversal();
                    break;
            case 3: backward_traversal();
                    break;
            case 4: insert_at_beginning();
                    break;
            case 5: insert_at_ending();
                    break;
            case 0: exit = 1;
                    break;
            default: printf("Kindly enter a Valid choice.");
        }
    }
    printf("****************************************\n");
}

