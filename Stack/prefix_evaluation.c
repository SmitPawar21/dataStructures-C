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

// operation same postfix eval jaisa hi hai, just apne ko reverse order me char array ko traverse karna. That's it!
void prefixEvaluation(char prefix[])
{
    int i;
    int a, b;
    char temp;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        temp = prefix[i];

        if (isalnum(temp))
        {
            push(temp - '0');  
        }
        else
        {
            a = pop();
            b = pop();
            
            switch (temp)
            {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
            }
        }
    }

    printf("Answer: %d\n", pop());
}

int main()
{
    char prefix[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixEvaluation(prefix);

    return 0;
}
