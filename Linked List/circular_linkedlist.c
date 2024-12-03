#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

//This create function creates five nodes with default values from 1 to 5
void createCLL() {
    int i;
    struct node *newnode, *temp;

    for(i=1; i<=5; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = i;
        newnode -> next = NULL;
        if(head == NULL) {
            head = newnode;
            temp = head;
        }
        else{
            while(temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }

    newnode -> next = head;
}

void insert_before() {
    int exist_value, new_value;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;

    printf("Enter the value before which You want to insert a node: ");
    scanf("%d", &exist_value);

    printf("Enter the data which You want to store in new node: ");
    scanf("%d", &new_value);

    newnode -> data = new_value;

    while((temp -> next -> data != exist_value) && (temp -> next != head)) {
        temp = temp -> next;
    }

    if((temp -> next == head) && (temp -> data != exist_value)) {
        printf("The value you entered is not present in this list.\n");
    }

    else{
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void insert_after() {
    int exist_value, new_value;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;

    printf("Enter the value after which You want to insert a node: ");
    scanf("%d", &exist_value);

    printf("Enter the data which You want to store in new node: ");
    scanf("%d", &new_value);

    newnode -> data = new_value;

    while((temp -> data != exist_value) && (temp -> next != head) ) {
        temp = temp -> next;
    }

    if((temp -> next == head) && (temp -> data != exist_value)) {
        printf("The value you entered is not present in this list.\n");
    }

    else{
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void delete_node() {
    int exist_value;
    struct node *temp;
    temp = head;

    printf("Enter the value you want to Delete: ");
    scanf("%d", &exist_value);

    while((temp -> next -> data != exist_value) && (temp -> next != head)) {
        temp = temp -> next;
    }

    if((temp -> next == head) && (temp -> data != exist_value )) {
        printf("The value you entered is not present in this list.\n");
    }

    else{
        temp -> next = temp -> next -> next;
    }
}

void display() {
    struct node *temp;
    temp = head;
    printf("_____________________________________________\n");
    while(temp -> next != head) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("%d\n", temp -> data);
    printf("_____________________________________________\n");
}

void main(){
    int choice;
    int exit = 0; //exit is false

    while(exit == 0) {
        printf("*****************************************\n");
        printf("Enter 1 for create circular linked list consisting of 5 nodes.\n");
        printf("Enter 2 for insert before a value\n");
        printf("Enter 3 for insert after a value\n");
        printf("Enter 4 for delete a value\n");
        printf("Enter 5 for display circular linked list\n");
        printf("Enter 0 for exit\n");
        printf("*****************************************\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: createCLL();
                    break;
            case 2: insert_before();
                    break;
            case 3: insert_after();
                    break;
            case 4: delete_node();
                    break;
            case 5: display();
                    break;
            case 0: exit = 1;
                    printf("*****************************************\n");
                    break;
            default: printf("Kindly Enter Valid Choice.\n"); 
        }
    }
}