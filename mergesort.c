#include<stdio.h>
#include<stdlib.h>


int* merge(int A[], int B[], int al, int bl)
{
    int* C=malloc((al+bl)*sizeof(int));
    int i1=0, i2=0;

    for(int i=0; i<al+bl; i++)
    {
        if(i1>=al)
        {
            C[i]=B[i2];
            i2++;
        }

        else if(i2>=bl)
        {
            C[i]=A[i1];
            i1++;
        }


        else{

            if(A[i1]<B[i2])
        {
            C[i]=A[i1];
            //  printf("%d\n", i1);
            i1++;
        }

        else
        {
            C[i]=B[i2];
            
            i2++;
        }
        }
        
    }


    return C;
}



int display(int *A, int al)
{
    printf("\n");
   
    for(int i=0; i<al; i++)
    {
        printf("%d ", A[i]);
    }

     printf("\n");
}
int* mergesort(int *A, int N)
{
    // display(A, N);
    if(N==1)
    {
        return A;
    }

   
    int *C=merge(mergesort(A, N/2), mergesort(A+N/2, N-N/2), N/2,N-N/2);
  //    display(C, N);
    return C;
 

   
}



int min(int a, int b)
{
    return(a<b?a:b);
}
int main()
{
   int A[]={1, 2, 7};
   int B[]={3, 5, 6, 8};
   //int* C=merge(A, B, 3, 4);
   int N;
   scanf("%d", &N);
   int toSort[N];

   for(int i=0; i<N; i++)
   {
       scanf("%d", toSort+i);
   }

   display(mergesort(toSort, N), N);
   int* sorted;

   int C[]={4, 5};
   int D[]={1, 2, 3};
   //display(merge(C, D, 2, 3), 5);
//    sorted=mergesort(toSort, 5);
//    for(int i=0; i<5; i++)
//    {
//        printf("%d ", sorted[i]);
//    }

   printf("\n");
//    for(int i=0; i<7; i++)
//    {
//       printf("%d ", C[i]);
//    } 
}