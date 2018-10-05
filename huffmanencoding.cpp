#include<bits/stdc++.h>
using namespace std;
struct Tree{
    int frequency;
    char character;
    Tree* left=NULL;
    Tree* right=NULL;
};

class TreeComparator{
    public:
    bool operator() (Tree* a, Tree* b){
        return a->frequency>b->frequency;
    }
};

void printVector(vector<int> A)
{
    for(int i=0; i<A.size(); i++)
    {
        cout<<A[i];
    }
}

Tree* buildHuffmanTree(vector<pair<char, int> > freqtable)
{
    
    priority_queue<Tree*, vector<Tree*>,TreeComparator> huffqueue; 
    for(int i=0; i<freqtable.size(); i++)
    {
        Tree* node=new Tree();
        node->frequency=freqtable[i].second;
        node->character=freqtable[i].first;
        huffqueue.push(node);
    }

    while(huffqueue.size()>1)
    {
        Tree* a, *b;
        a=huffqueue.top();
        huffqueue.pop();
        b=huffqueue.top();
        huffqueue.pop();
        Tree* c=new Tree();
        c->frequency=a->frequency+b->frequency;
        c->left=a;
        c->right=b;
        huffqueue.push(c);
    }

    return huffqueue.top();
}

void traverseHuffmanTree(Tree* root, vector<int> code, int toAppend)
{
    
    if(toAppend!=-1)
    {
        code.push_back(toAppend);
    }
    if(root->right==NULL&&root->left==NULL){
        cout<<root->character<<" ";
        printVector(code);
        cout<<endl;
    }
    if(root->right!=NULL)
    {
        traverseHuffmanTree(root->right,code, 1);
    }

    if(root->left!=NULL)
    {
        traverseHuffmanTree(root->left, code, 0);
    }


}


int main(){

    vector<pair<char, int> > freqtable;
    for(int i=0; i<6; i++)
    {
        char character;
        int frequency;
        cin>>character>>frequency;
        freqtable.push_back(make_pair(character, frequency));

    }

    Tree* root=buildHuffmanTree(freqtable);
    vector<int> code;
    traverseHuffmanTree(root, code, -1);

}