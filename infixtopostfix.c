#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Stack STACK;
#define NULL 0
struct Stack
{

    char data;
    STACK *next;
    //int size;
};

STACK *push(STACK *s, char data)
{
    STACK *t = (STACK *)malloc(sizeof(STACK));
    t->next = s;
    t->data = data;

    s = t;
    return s;
}

char pop(STACK **s)
{

    STACK *temp = *s;
    char t = (*s)->data;
    *s = (*s)->next;
    free(temp);

    return t;
}

int getPriority(char ch)
{

    if (ch == '(')
    {
        return 0;
    }

    else
    {
        switch (ch)
        {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        }
    }
}

char *infix_to_postfix(char *exp, STACK *s)
{
    char *result = (char *)malloc(sizeof(strlen(exp) * sizeof(char)));
    int index = 0;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] <= '9' && exp[i] >= '1')
        {
            result[index++] = exp[i];
        }

        else if (exp[i] == ')')
        {
            while (s != NULL && (s)->data != '(')
            {
                result[index++] = pop(&s);
            }

            pop(&s);
        }

        else
        {
            if (exp[i] == '(')
            {
                s = push(s, exp[i]);
            }

            else if (s == NULL || getPriority(exp[i]) > getPriority((s)->data))
            {
                s = push(s, exp[i]);
            }

            else
            {
                while (s != NULL && getPriority(exp[i]) < getPriority((s)->data))
                {
                    result[index++] = pop(&s);
                }

                s = push(s, exp[i]);
            }
        }
    }
}

int main()
{
    char s[100];
    scanf("%s", &s[0]);
    STACK *ss = NULL;
    printf("%s", infix_to_postfix(s, ss));
}
