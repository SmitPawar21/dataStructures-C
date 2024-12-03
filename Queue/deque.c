#include <stdio.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void insert_front()
{
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    if(((rear+1)%SIZE) == front)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = SIZE - 1;
    }
    else{
        front--;
    }
    queue[front] = x;
}

void insert_rear()
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if(((rear+1)%SIZE) == front)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
    }
    else if(rear == SIZE - 1)
    {
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = x;
}

void delete_front()
{
    if(front == -1 & rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if(front == SIZE - 1)
    {
        front = 0;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

void delete_rear()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = SIZE - 1;
    }
    else{
        rear--;
    }
}

void display()
{
    int i = front;
    while(i != rear)
    {
        printf("%d, ", queue[i]);
        i = (i+1)%SIZE;
    }
    printf("%d\n", queue[rear]);
}

void main()
{
    int exit = 1; //false
    int choice;

    while(exit == 1)
    {
        printf("Enter 1 for insert at front, 2 for insert at rear,\n3 for delete at front, 4 for delete at rear, 5 for display and 0 for exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert_front();
            break;
            case 2: insert_rear();
            break;
            case 3: delete_front();
            break;
            case 4: delete_rear();
            break;
            case 5: display();
            break;
            case 0: exit = 0;
            break;
            default: printf("Enter a valid choice");
        }
    }
}