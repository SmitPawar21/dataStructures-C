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
    if(top == -1)
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

void reverse(char exp[])
{
    int start = 0;
    int end = 0;
    while (exp[end] != '\0')
    {
        end++;
    }
    end--; // Set to the last character of the string
    char temp;
    while (start < end)
    {
        temp = exp[start];
        exp[start] = exp[end];
        exp[end] = temp;
        start++;
        end--;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    char temp, x;
    int p = 0, q = 0;
    while (infix[p] != '\0')
    {
        temp = infix[p];
        if (isalnum(temp))
        {
            postfix[q++] = temp;
        }
        else if (temp == '(')
        {
            push(temp);
        }
        else if (temp == ')')
        {
            while ((x = pop()) != '(')
            {
                postfix[q++] = x;
            }
        }
        else
        {
            while (prcd(stack[top]) >= prcd(temp))
            {
                postfix[q++] = stack[top--];
            }
            push(temp);
        }
        p++;
    }
    while (top != -1)
    {
        postfix[q++] = stack[top--];
    }
    postfix[q] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    char postfix[max];
    infixToPostfix(infix, postfix);

    reverse(postfix);

    int i = 0;
    while (postfix[i] != '\0')
    {
        prefix[i] = postfix[i];
        i++;
    }
    prefix[i] = '\0';  
}

void main()
{
    char infix[max], prefix[max];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    printf("\n");

    printf("Infix expression: ");
    int i = 0;
    while (infix[i] != '\0')
    {
        printf("%c", infix[i]);
        i++;
    }

    infixToPrefix(infix, prefix);

    printf("\n");

    printf("Prefix expression: ");
    int j = 0;
    while (prefix[j] != '\0')
    {
        printf("%c", prefix[j]);
        j++;
    }
}
