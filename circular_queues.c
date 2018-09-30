#include <stdio.h>
#include <stdlib.h>
typedef struct CircularQueue QUEUE;
#define size 5
struct CircularQueue
{
    int data[size];
    int front;
    int back;
};

void enqueue(QUEUE *s, int data)
{
    if ((s->back == size - 1 && s->front == 0) || (s->back == s->front - 1))
    {
        printf("OVERFLOW");
        return;
        //overflow
    }

    else
    {
        if (s->back == -1)
        {
            s->front = 0;
        }
        if (s->back == size - 1)
        {
            s->back = 0;
        }

        else
        {
            s->back++;
        }

        s->data[s->back] = data;
    }
}

int dequeue(QUEUE *s)
{
    if (s->front == -1)
    {
        printf("UNDERFLOW");
        return -1; //underflow
    }

    else
    {
        int t = s->data[s->front];
        if (s->front == s->back)
        {
            s->back = -1;
            s->front = -1;
        }
        else if (s->front == size - 1)
        {
            s->front = 0;
        }

        else
        {
            s->front++;
        }
        return t;
    }
}

int main()
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    queue->front = -1;
    queue->back = -1;
    int ch;
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int data;
            scanf("%d", &data);
            enqueue(queue, data);
            break;
        }
        case 2:
        {
            int t = dequeue(queue);
            printf("%d\n", t);
            break;
        }
        case 3:
            return 1;
        }
    }
}