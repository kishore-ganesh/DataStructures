swap_first_last(NODE* start)
{
    NODE* current=start;
    while(current->next!=NULL)
    {
        current=current->next;
    }

    int temp=start->data;
    start->data=current->data;
    current->data=temp;
}

swap_contiguous(NODE * start)
{
    while(start->next!=null)
    {
        int t=start->data;
        start->data=start->next->data;
        start->next->data=t;
        start=start->next->next;
        if(start==null)
        {
            break;
        }

    }
}

check_palindrome(NODE* start)
{

    NODE* current=start;
    int cc=0;
    while(current!=NULL)
    {
        cc++;
        current=current->next;
    }

    
    current=start;
    for(int i=0; i<cc/2; i++)
    {
        current=current->next;
    }

    current=reverse_list(current);
    int flag=0;
    while(current!=null)
    {
        if(current->data!=start->data)
        {
            flag=1;
            break;
        }

        start=start->next;
        current=current->next;
    }

    if(flag)
    {
        printf("NOT A PALINDROME");
    }

    else
    {
        printf("IS A PALINDROME");
    }


}

reverse_list(NODE* start)
{
    NODE* prev=NULL;
    while(start!=NULL)
    {
        NODE* t=start->next;
        start->next=prev;
        prev=start;
        start=t;
    }

    return prev;
}