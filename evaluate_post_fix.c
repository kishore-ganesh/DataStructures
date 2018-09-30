#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node NODE;

struct Node
{
    int data;
    NODE *next;
};

NODE *push(NODE *stack, int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    NODE *current = stack;
    if (stack == NULL)
    {
        stack = newnode;
    }

    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
    }

    return stack;
}

int pop(NODE *start)
{
    NODE *prev = start;
    while (start->next->next != NULL)
    {
        prev = start;
        start = start->next;
    }

    int t = start->next->data;
    free(prev->next);
    prev->next = NULL;
    return t;
}

evaluate_postfix(char *expression)
{
    int len = strlen(expression);
    NODE *stack = NULL;
    for (int i = 0; i < len; i++)
    {
        switch (expression[i])
        {
        case '+':
        {

            int a = pop(stack);
            int b = pop(stack);
            push(stack, a + b);
            break;
        }
        case '-':
        {

            int a = pop(stack);
            int b = pop(stack);
            push(stack, b - a);
            break;
        }
        case '*':
        {

            int a = pop(stack);
            int b = pop(stack);
            push(stack, b * a);
            break;
        }
        case '/':
        {

            int a = pop(stack);
            int b = pop(stack);
            push(stack, b / a);
            break;
        }
        default:
        {

            push(stack, expression[i] - '0');
        }
        }

        return pop(stack);
    }
}

int main()
{
}
