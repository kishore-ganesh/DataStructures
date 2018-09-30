#include <bits/stdc++.h>

using namespace std;

class Node
{
  public:
    map<char, Node *> children;
    int value;
};
class Trie
{
    Node *root;

  public:
    Trie()
    {
        root = new Node();
    }
    int find(string key)
    {
        Node *t = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (t->children.find(key[i]) != t->children.end())
            {
                t = t->children[key[i]];
            }

            else
            {
                return -1;
            }
        }

        return t->value;
    }
    void insert_value(string a, int value)
    {

        Node *t = root;
        int index = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (t->children.find(a[i]) != t->children.end())
            {
                t = t->children[a[i]];
            }

            else
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            for (int i = index; i < a.size(); i++)
            {
                t->children[a[i]] = new Node();
                t = t->children[a[i]];
            }
        }

        t->value = value;
    }
};

int main()
{
    Trie *trie = new Trie();
    for (int i = 0; i < 5; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        trie->insert_value(a, b);
    }

    string key;
    cin >> key;
    cout << trie->find(key);
}