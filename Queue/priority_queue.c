#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue() {
    int value, p;
    struct node *newnode, *temp, *prev;

    printf("Enter Value: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &p);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> priority = p;
    newnode -> next = NULL;

    if(front == NULL) {
        front = newnode;
        rear = newnode;
    }

    else {
        temp = front;
        while(temp != NULL && (p > temp -> priority)) {
            prev = temp;
            temp = temp -> next;
        }
        
        // if priority is less than front itself (insertion at begin)
        if(temp == front) {
            newnode -> next = front;
            front = newnode;
        }

        // if priority is max
        else if(temp == NULL) {
            rear -> next = newnode;
            rear = newnode;
        }

        else {
            prev -> next = newnode;
            newnode -> next = temp;
        }
    }
}

void dequeue() {
    struct node *temp = front;
    
    if(front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    }
    else if(front == rear) {
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else {
        front = front -> next;
        free(temp);
    }
}

void display() {
    struct node *temp;

    if(front == NULL) {
        printf("Queue is Empty\n");
    }
    
    else {
        temp = front;
        while(temp -> next != NULL) {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
}

void main() {
    int exit = 0; // Exit is False
    int choice;

    while(exit == 0) {
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Display\n");
        printf("0: Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 0: exit = 1; // Exit is true
            break;
            default: printf("Kindly enter a Valid Choice\n");
        }
    }
}