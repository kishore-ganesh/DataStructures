#include<stdio.h>   
#include<stdlib.h>  

int insert(int* A, int index, int element)
{
    A[index]=element;
  //  printf("%d %d \n", index, element);
    if(index==0)
    {
        A[0]=element;
        
    }
    else if(element<A[(index-1)/2]){

        A[index]=A[(index-1)/2];
        insert(A, (index-1)/2, element);

    }

    if(index==0)
    {   
        return 1;   
    }

    return index%2==0?2*(index-1)+1:index+1;
    
}

void minHeapify(int *A, int i, int N)
{
  //  printf("%d\n", i);
    
    int smallest=i;
    if(2*i+1<N){
        if(A[smallest]>A[2*i+1]){
        
        smallest=2*i+1;
    }
    }
    

    if(2*i+2<N)
    {
        if(A[smallest]>A[2*i+2])
    {
        
        smallest=2*i+2;
    }
    }

    

    int t=A[i];
    A[i]=A[smallest];
    A[smallest]=A[i];
    if(smallest!=i)
    {
        minHeapify(A, smallest, N);
    }
}

int delete(int* A, int index, int N)
{
    index=(index-1)/2;
    A[0]=A[index];
    minHeapify(A, index, N);
    return index-1;
}

void array_insert(int* A, int N)
{
    for(int i=N/2; i>=0; i--)
    {
        minHeapify(A, i, N);
    }
}
int main(){

    int A[3]={2, 1, 3};
    int pqueue[3];
    int index=0;
    for(int i=0; i<3; i++)
    {
        index=insert(pqueue, index, A[i]);
    }
   
    // for(int i=0; i<3; i++)
    // {
    //     printf("%d ", pqueue[i]);
    // }
    //printf("%d\n", pqueue[0]);
    index=delete(pqueue, index, 3);
    printf("%d\n", pqueue[0]);
    array_insert(A, 3);
    printf("%d\n", A[0]);

}