#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stk[100], infix[100], post[100], *c;
int top = -1;

void push(char e)
{
    stk[++top] = e;
}

char pop()
{
    return stk[top--];
}

int stk_precedence(char e)
{
    switch (e)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return (4);
    case '^':
        return (5);
    case '(':
    case '#':
        return (0);
    }
}

int input_precedence(char e)
{
    switch (e)
    {
    case '+':
    case '-':
        return (1);
    case '*':
    case '/':
    case '%':
        return (3);
    case '^':
        return (6);
    case '(':
    case '#':
        return (0);
    }
}

void main()
{

    printf("Enter the infix expression\n");
    gets(infix);

    int i = 0;
    c = infix;
    while (*c != '\0')
    {
        if (isalnum(*c))
        {
            post[i++] = *c;
        }
        else if (*c == '(')
        {
            push(*c);
        }
        else if (*c == ')')
        {
            while (stk[top] != '(')
                post[i++] = pop();

            pop();
        }
        else
        {
            while (stk_precedence(stk[top]) >= input_precedence(*c))
                post[i++] = pop();

            push(*c);
        }
        c++;
    }

    while (top != -1)
        post[i++] = pop();

    post[i] != '\0';

    printf("Postfix expression is:\n%s", post);
}
