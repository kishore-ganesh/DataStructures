#include<stdio.h>
#include<stdlib.h>
typedef struct Node NODE;
#define null 0 
struct Node {

    int data;
    struct Node* next;
};

NODE* create()
{
    NODE* start=null;
    NODE* prev;

    char ch='Y';
    while(ch=='Y')
    {

        NODE* newnode=(NODE*)malloc(sizeof(NODE));
        scanf("%d", &newnode->data);
        newnode->next=null;

        if(start==null)
        {
            start=newnode;
        }
        else
        
        {
            prev->next=newnode;
        }

        prev=newnode;
        printf("Continue?");
        scanf(" %c", &ch);

    }

    return start;
}

void traversal(NODE* start)
{
    while(start!=null)
    {
        printf("%d ", start->data);
        start=start->next;
    }

    printf("\n");
}


int getMiddle(NODE* start)
{
    NODE* middle=start;
    int cc=0;
    while(start!=NULL)
    {
        cc++;
        if(cc%2==0)
        {
           middle=middle->next;
        }

        start=start->next;
    }

    return middle->data;
}



int main()
{
    NODE* start=create();
    traversal(start);
    // swap_first_last(start);
    // traversal(start);
    //swap_contiguous(start);
    traversal(start);
    printf("%d", getMiddle(start));
    //  check_palindrome(start);
}