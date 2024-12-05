#include <stdio.h>
#include <ctype.h>
#define max 100

int stack[max], top=-1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    if(top==-1)
    {
        return -1;
    }
    return stack[top--];
}

int prcd(char ch)
{
    if(ch == '(')
    {
        return 0;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    char temp, x;
    int p = 0, q = 0;
    while(infix[p] != '\0')
    {
        temp = infix[p];
        if(isalnum(temp))
        {
            postfix[q++] = temp;
        }
        else if(temp == '(')
        {
            push(temp);
        }
        else if(temp == ')')
        {
            while((x=pop()) != '(')
            {
                postfix[q++] = x;
            }
        }
        else
        {
            while(prcd(stack[top]) >= prcd(temp))
            {
                postfix[q++] = stack[top--];
            }
            push(temp);
        }
        p++;
    }
    while(top != -1)
    {
        postfix[q++] = stack[top--];
    }
    postfix[q] = '\0';
}

void main()
{
    char infix[max], postfix[max];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    printf("\n");

    printf("infix expression : ");
    int i=0;
    while(infix[i] != '\0')
    {
        printf("%c", infix[i]);
        i++;
    }

    infixToPostfix(infix, postfix);

    printf("\n");

    printf("postfix expression : ");
    int j=0;
    while(postfix[j] != '\0')
    {
        printf("%c", postfix[j]);
        j++;
    }
}