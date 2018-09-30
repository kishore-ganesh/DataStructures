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

NODE *reversal(NODE *start)

{
    NODE *prev = null;
    while (start != null)
    {
        NODE *t = start->next;
        start->next = prev;
        prev = start;
        start = t;
    }

    return prev;
}

NODE *merge(NODE *start1, NODE *start2)
{
    while (start1 != null && start2 != null)
    {

        NODE *t1 = start1->next;
        NODE *t2 = start2->next;
        start1->next = start2;
        if (t1 != null)
        {
            start2->next = t1;
        }

        start1 = t1;
        start2 = t2;
    }
}

delete_alternate(NODE *start)
{
    NODE *prev = start;
    start = start->next;
    int cc = 0;

    while (start != null)
    {
        NODE *t = start->next;
        if (cc % 2 == 0)
        {

            prev->next = start->next;
            free(start);
        }

        prev = start;
        start = t;
        cc++;
    }
}

int main()

{

    NODE *start = create();
    traversal(start);
    start = reversal(start);
    traversal(start);
    NODE *start2 = create();
    merge(start, start2);
    traversal(start);
    delete_alternate(start);
    traversal(start);
}