#include<bits/stdc++.h>
using namespace std;
int cc=0;


void print_all_permutations(vector<int> A, int resultIndex, int vectIndex)
{

    
    cc++;
    // cout<<"A"<<resultIndex<<" "<<vectIndex<<"A\n";
    if((resultIndex>(A.size()-1)||vectIndex>(A.size()-1))&&resultIndex!=-1&&vectIndex!=-1)
    {
    
        return;
    }
    if(vectIndex>-1)
    {
     
     swap(A[resultIndex], A[vectIndex]);
    }

    if(resultIndex==A.size()-1)
    {
        for(int i=0; i<A.size(); i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n";
        
    }
    
    for(int i=resultIndex+1; i<A.size(); i++)
    {
        
        print_all_permutations(A, resultIndex+1, i);
    }



}

//1. Fix one, now length of string is S-1
//Keep doing same till end of string. Each time you select, swapit with the value at that index so that all non chosen values are clearly visible
//

int main()
{
    vector<int> A;
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        A.push_back(i+1);
    }
    print_all_permutations(A, -1, -1);
    cout<<"COUNT: "<<cc<<endl;
}