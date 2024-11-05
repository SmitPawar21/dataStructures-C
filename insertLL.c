#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head;

struct node *createNode(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> data = value;
    newnode -> next = NULL;

    return newnode;
}

void insert_node(int pos, int value)
{
    int count = 0; // 0 for inserting after the pos and 1 for inserting before the pos
    struct node *temp, *newnode;
    temp = head;
    while(count != pos)
    {
        temp = temp -> next;
        count++;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> next = temp -> next;
    temp -> next = newnode;
    newnode -> data = value;
}

void main()
{
    int pos, value;
    //creating a linked list
    head = createNode(10);
    head -> next = createNode(20);
    head -> next -> next = createNode(30);
    head -> next -> next -> next = createNode(40);

    struct node *temp1;
    temp1 = head;
    while(temp1 != NULL)
    {
        printf("%d -> ", temp1 -> data);
        temp1 = temp1 -> next;
    }
    printf("NULL\n");

    printf("Enter the position after that to be inserted: "); scanf("%d", &pos);
    printf("Enter the data: "); scanf("%d", &value);

    insert_node(pos,value);

    struct node *temp2;
    temp2 = head;
    while(temp2 != NULL)
    {
        printf("%d -> ", temp2 -> data);
        temp2 = temp2 -> next;
    }
    printf("NULL\n");
}