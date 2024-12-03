#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

//  jabhi bhi new element aayega toh use top bana do...
void push()
{
    int n;    
    struct node *newnode, *temp;

    printf("Enter a value to be pushed: ");
    scanf("%d", &n);

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> data = n;
    newnode -> next = NULL;

    if(top == NULL)
    { 
        top = newnode;
    }

    else{ 
        newnode -> next = top;
        top = newnode;
    }

}

// Top ke next ko Top bana do
int pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }

    else{
        temp = top;
        top = temp -> next;

        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = top;

    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void main()
{
    int exit = 0;   // Exit is False
    int choice;

    while(exit == 0) {
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Display\n");
        printf("0: Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 0: exit = 1;   // Exit is True
            break;
            default: printf("Kindly enter a Valid choice\n");
        }
    }
}