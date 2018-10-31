
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack STACK;

struct Stack{
    int data;
    STACK* next;

};


void push(STACK **s, int data)
{
    STACK* t=(STACK*)malloc(sizeof(STACK));
    t->data=data;
    t->next=*s;
    *s=t;
}

int pop(STACK **s)
{
    int temp=(*s)->data;
    STACK* t=*s;

    *s=(*s)->next;
    free(t);
    return temp;

}


int get_priority(char a)
{
    switch(a)
    {
        case '*': return 2; break;
        case '/': return 2; break;
        case '+': return 1; break;
        case '-': return 1; break; 
        case '(': return 0; break;
    }
}


int apply_op(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break; 
        case '/': return a/b; break;
    }
}

int evaluate_infix(char* exp)
{
    STACK* s1=NULL;
    STACK* s2=NULL;

    for(int i=0; i<strlen(exp); i++)
    {
        if(exp[i]>='0'&&exp[i]<='9')
        {
            push(&s1, exp[i]-'0');
        }

        else{
            if(exp[i]==')')
            {
                while(s2->data!='(')
                {
                     int a=pop(&s1);
                     int b=pop(&s1);
                    push(&s1,apply_op(a, b, s2->data));
                    pop(&s2);
                }

                pop(&s2);
                //keep popping till encountered
            }

            else if(exp[i]=='('){

                push(&s2, exp[i]);

                //modify for char
            }

            else{

                  while(s2!=NULL&&get_priority(s2->data)>=get_priority(exp[i])){

                int a=pop(&s1);
                int b=pop(&s1);
                push(&s1, apply_op(a, b, pop(&s2)));

            }

            push(&s2, exp[i]);


            }

          
        }


        
    }


    while(s2!=NULL)
    {
                int a=pop(&s1);
                int b=pop(&s1);
                push(&s1, apply_op(a, b, pop(&s2)));
    }

    return pop(&s1);

    //evaluate
}




int main(){

    char a[256];
    scanf("%s", a);
    printf("%d", evaluate_infix(a));
}