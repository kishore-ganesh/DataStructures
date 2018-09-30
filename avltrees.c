#include <stdio.h>
#include <stdlib.h>
typedef struct Tree TREE;
struct Tree
{
    int data;
    TREE *left;
    TREE *right;
    TREE *parent;
    int left_count;
    int right_count;
    int balance_factor;
};

int max(int a, int b)
{
    return a > b ? a : b;
}

void set_children_null(TREE *s)
{
    s->left = NULL;
    s->right = NULL;
}

void set_children_count(TREE *s, int n)
{
    s->left_count = n;
    s->right_count = n;
}

void rotate_left(TREE* s)
{
    s->left_count++;
    s->left=s->parent;
    set_children_count(s->parent, 0);
    set_children_null(s->parent);
    if(s->parent->parent!=NULL)
    {
        if(s->parent->parent->left==s->parent)
        {
            s->parent->parent->left=s;
        }

        else
        {
            s->parent->parent->right=s;
        }
    }
    s->parent=s->parent->parent;
    s->parent->parent=s;
       
}

void rotate_right(TREE* s)
{
    s->right_count++;
    s->right=s->parent;
    set_children_count(s->parent, 0);
    set_children_null(s->parent);
    if(s->parent->parent!=NULL)
    {
        if(s->parent->parent->left==s->parent)
        {
            s->parent->parent->left=s;
        }

        else
        {
            s->parent->parent->right=s;
        }
    }
    s->parent=s->parent->parent;
    s->parent->parent=s;
}
TREE *insert(TREE *root, int value)
{
    TREE *n = (TREE *)malloc(sizeof(TREE));
    n->left = NULL;
    n->right = NULL;
    n->left_count = 0;
    n->right_count = 0;
    n->balance_factor = 0;
    n->data = value;
    n->parent = NULL;
    if (root == NULL)
    {
        return n;
    }
    if (value > root->data)
    {
        if (root->right == NULL)
        {
            root->right = n;
            root->right_count++;
            n->parent=root;
        }

        else
        {
            insert(root->right, value);
        }
    }

    else
    {
        if (root->left == NULL)
        {
            root->left = n;
            root->left_count++;
            n->parent=root;
            
        }

        else
        {
            insert(root->left, value);
        }
    }

    if (root->right != NULL)
    {
        root->right_count = max(root->right->right_count, root->right->left_count) + 1;
    }
    if (root->left != NULL)
    {

        root->left_count = max(root->left->left_count, root->left->right_count) + 1;
    }
    root->balance_factor = root->left_count - root->right_count;
    TREE *parent = root->parent;
    TREE *newroot = NULL;
    if (root->balance_factor < -1)
    {
        if (root->right->balance_factor == -1)
        {

            newroot = root->right;
            rotate_left(newroot);
            // newroot->parent = parent;
            // newroot->left = root;
            // newroot->left_count = 1;
            // root->parent = newroot;
            // set_children_count(root, 0);
            // set_children_null(root);
        }

        else if (root->right->balance_factor == 1)
        {
            newroot = root->right->left;
            rotate_right(newroot);
            rotate_left(newroot);
            // newroot->right = root->right;
            // newroot->left = root;
            // newroot->right_count = 1;
            // newroot->left_count = 1;
            // root->parent = newroot;
            // root->right->parent = newroot;
            // newroot->parent = parent;
            // set_children_count(root->right, 0);
            // set_children_count(root, 0);
            // set_children_null(root->right);
            // set_children_null(root);
        }
    }

    else if (root->balance_factor > 1)
    {
        if (root->left->balance_factor == 1)
        {
            newroot = root->left;
            rotate_right(newroot);
            // newroot->right = root;
            // newroot->left_count = 1;
            // root->left->parent = parent;
            // root->parent = newroot;
            // set_children_count(root, 0);
            // set_children_null(root);
        }

        else if (root->left->balance_factor == -1)
        {

            
             newroot->right = root;
             rotate_left(newroot);
             rotate_right(newroot);
            // newroot->left = root->left;
            // root->left->parent = newroot;
            // root->parent = newroot;
            // newroot->parent = parent;
            // set_children_count(newroot, 1);
            // set_children_count(root, 0);
            // set_children_count(root->left, 0);
            // set_children_null(root);
            // set_children_null(root->left);
        }
    }

    // if (parent != NULL&&newroot!=NULL)
    // {
    //     if (parent->left == root)
    //     {
    //         parent->left = newroot;
    //     }

    //     else
    //     {
    //         parent->right = newroot;
    //     }
    // }

    return newroot == NULL ? root : newroot;
}

int search(TREE *s, int val)
{
    if (s->data == val)
    {
        return 1;
    }

    if (val > s->data && s->right != NULL)
    {
        return search(s->right, val);
    }

    else if (val < s->data && s->left != NULL)
    {
        return search(s->left, val);
    }

    return -1;
}

int main()
{
    TREE *root = NULL;
    int arr[5] = {21, 42, 16, 12, 9};
    int arr2[5]={5, 4, 3, 2, 1};
    int arr3[5]={1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        root = insert(root, arr[i]);
    }


    int sval;
    scanf("%d", &sval);
    int a = search(root, sval);
    printf("%d", a);
}