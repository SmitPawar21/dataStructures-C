#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

int pop()
{
    return stack[top--];
}

void push(int ch)
{
    top++;
    stack[top] = ch;
}

void postfixEvaluation(char postfix[])
{
    int i;
    int a,b;
    char temp;
    for(i = 0; postfix[i] != '\0'; i++)
    {
        temp = postfix[i];
        if(isalnum(temp))
        {
            push(temp - '0');
        }
        else{
            a = pop();
            b = pop();
            switch(temp)
            {
                case '+': push(b+a);
                break;
                case '-': push(b-a);
                break;
                case '*': push(b*a);
                break;
                case '/': push(b/a);
                break;
            }
        }
    }
    printf("answer: %d", pop());
}

void main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixEvaluation(postfix);
}