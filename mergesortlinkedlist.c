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

NODE *merge(NODE *first, NODE *second, int N)
{
    NODE *result = NULL;
    NODE *prev;
    int cf, cs, cc;
    cf = cs = cc = 0;
    //  printf("%d %d", first->data, second->data);
    while (cf < N / 2 && cs < N - N / 2)
    {

        NODE *t1 = (first == NULL) ? NULL : first->next;
        NODE *t2 = (second == NULL) ? NULL : second->next;
        if (first->data < second->data)
        {
            if (result == NULL)
            {

                result = first;
            }

            else
            {

                prev->next = first;
            }

            prev = first;
            cf++;
            first = t1;
        }

        else
        {
            if (result == NULL)
            {
                result = second;
            }

            else
            {
                prev->next = second;
            }

            prev = second;
            cs++;
            second = t2;
        }

        cc++;
    }

    while (cs < N - N / 2)
    {
        NODE *t = second->next;
        prev->next = second;
        prev = second;
        second = t;
        cs++;
    }

    while (cf < N / 2)
    {
        NODE *t = first->next;
        prev->next = first;
        prev = first;
        first = t;
        cf++;
    }

    // printf("%p", result);
    return result;
}

NODE *mergesort(NODE *start, int N)
{
    if (N == 1)
    {
        return start;
    }

    NODE *first = start, *second = start;
    for (int i = 0; i < (N / 2); i++)
    {
        second = second->next;
    }

    first = mergesort(first, N / 2);
    second = mergesort(second, N - N / 2);
    return merge(first, second, N);
}

int findSize(NODE *start)
{
    int cc = 0;
    while (start != null)
    {
        cc++;
        start = start->next;
    }

    return cc;
}

int main()
{
    NODE *start = create();
    traversal(start);
    int N = findSize(start);
    //printf("%d", N);
    start = mergesort(start, N);

    traversal(start);
}
