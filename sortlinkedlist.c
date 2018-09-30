#include <stdio.h>
#include <stdlib.h>
typedef struct Node NODE;
#define null 0

struct Node
{

    int data;
    struct Node *next;
};

NODE *create()
{
    NODE *start = null;
    NODE *prev;

    char ch = 'Y';
    while (ch == 'Y')
    {

        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        scanf("%d", &newnode->data);
        newnode->next = null;

        if (start == null)
        {
            start = newnode;
        }
        else

        {
            prev->next = newnode;
        }

        prev = newnode;
        printf("Continue?");
        scanf(" %c", &ch);
    }

    return start;
}

void traversal(NODE *start)
{
    while (start != null)
    {
        printf("%d ", start->data);
        start = start->next;
    }

    printf("\n");
}

int findSize(NODE *start)
{
    int cc = 0;
    while (start != NULL)
    {
        cc++;
        start = start->next;
    }

    return cc;
}
NODE *sort(NODE *start)
{
    NODE *current = start;
    NODE *prev;
    int cc = 0;
    cc = findSize(start);
    for (int i = 0; i < cc; i++)
    {
        current = start;
        while (current->next != NULL)

        {
            NODE *temp = current->next;
            if (current->data > current->next->data)
            {
                NODE *t = current->next;
                current->next = current->next->next;
                t->next = current;
                current = t;
                if (t->next != start)
                {
                    prev->next = current;
                }

                else
                {
                    start = current;
                }
            }

            prev = current;
            current = temp;
        }
    }

    return start;
}

int main()
{
    NODE *start = create();
    traversal(start);
    start = sort(start);
    traversal(start);
}
