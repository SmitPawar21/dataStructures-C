#include<stdio.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    return stack[top--];
}

void main()
{
    char str[SIZE], answer[SIZE];
    int j=0, i=0, k=0;
    int isPalin = 0; //true

    printf("Enter a string: ");
    scanf("%s", str);

    while(str[j] != '\0')
    {
        push(str[j]);
        j++;
    }

    while(top != -1)
    {
        answer[i] = pop();
        i++;
    }

    while(str[k] != '\0')
    {
        if(str[k] != answer[k])
        {
            isPalin = 1; //false
            break;
        }
        k++;
    }

    (isPalin == 0)?printf("Palindrome"):printf("not a palindrome");
}