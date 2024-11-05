#include <stdio.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue()
{
    int x;
    printf("Element to be inserted: ");
    scanf("%d", &x);

    if(((rear+1)%SIZE) == front)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else{
        rear = (rear+1)%SIZE;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else if(front == rear)
    {
        front = -1; rear = -1;
    }
    else{
        front = (front+1)%SIZE;
    }
}

void peek()
{
    printf("Element at peek is %d\n", queue[front]);
}

void display()
{
    int i = front;
    while(i != rear)
    {
        printf("%d", queue[i]);
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
        printf("Enter 1 for enqueue, 2 for dequeue, 3 for peek, 4 for display and 0 for exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: peek();
            break; 
            case 4: display();
            break;
            case 0: exit = 0; //true
            break;
            default: printf("Enter a valid choice");
        }
    }
}