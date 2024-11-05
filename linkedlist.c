#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode (int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> data = value;
    newnode -> next = NULL;

    return newnode;
}

void main()
{
    struct node *head = createNode(10);
    head -> next = createNode(20);
    head ->next -> next = createNode(30);

    //display
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL");
}