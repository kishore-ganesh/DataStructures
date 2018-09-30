//use pair and priority queue, an array of node pointers

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct Node
{

    // pair<int, int> EdgePair;
    //  pair<int, Node*> EdgePair;
    int data;
    int visited = 0;
    int currentdistance = std::numeric_limits<int>::max();
    Node(int d)
    {
        data = d;
    }
    list<pair<int, Node *>> EdgePairList;
    int prev = 0;
};

class Graph
{
  public:
    vector<Node> NodeArray;
    list<int> Path;

    void addNode(int d)
    {
        NodeArray.push_back(Node(d));
    }
    void addEdge(Node &a, Node &b, int distance)
    {
        a.EdgePairList.push_back(make_pair(distance, &b));
    }

    int shortestPath(Node &a, Node b)
    {
        vector<Node *> SortedNodeArray;
        if (a.data == b.data)
        {
            std::cout << "SHORTEST PATH"
                      << " CURRENT DIST= " << a.currentdistance;
            return 1;
        }

        a.visited = 1;
        int ndat = a.data;

        list<pair<int, Node *>> templist = a.EdgePairList;
        while (templist.size() != 0)
        {

            auto b = templist.front();
            if (b.second->visited != 1)
            {
                SortedNodeArray.push_back(b.second);
            }

            calculateDistance(a, b);

            templist.pop_front();
        }

        if (SortedNodeArray.size() == 0)
        {
            std::cout << "NO POSSIBLE PATH TO NODE";
            return -1;
        }
        sort(SortedNodeArray.begin(), SortedNodeArray.end(), [](Node *c, Node *d) { return c->currentdistance < d->currentdistance; });

        Node *temp = SortedNodeArray.front();
        temp->prev = ndat;
        shortestPath(*temp, b);
    }

    void setPath(int a)
    {
        Path.push_front(NodeArray[a].data);
        if (NodeArray[a].prev != 0)
        {
            setPath(NodeArray[a].prev);
        }

        else
        {
            Path.push_front(0);
        }
    }

    void calculateDistance(Node a, pair<int, Node *> EdgePair)
    {
        int currentdistance;
        if (a.currentdistance == std::numeric_limits<int>::max())
        {
            currentdistance = 0;
        }
        else
        {
            currentdistance = a.currentdistance;
        }

        int disttonode = EdgePair.first;
        Node *connectedto = EdgePair.second;
        int destnodecurrentdistance = connectedto->currentdistance;

        if (currentdistance + disttonode < destnodecurrentdistance)
        {
            connectedto->currentdistance = currentdistance + disttonode;
            //        Path.push_back(connectedto->data);
        }
    }
};

int main()
{
    Graph agraph;
    for (int i = 0; i < 5; i++)
    {
        agraph.addNode(i);
    }
    try
    {
        agraph.addEdge(agraph.NodeArray[0], agraph.NodeArray[1], 10);
        agraph.addEdge(agraph.NodeArray[0], agraph.NodeArray[2], 5);
        agraph.addEdge(agraph.NodeArray[0], agraph.NodeArray[4], 31);
        agraph.addEdge(agraph.NodeArray[2], agraph.NodeArray[4], 7);
        agraph.addEdge(agraph.NodeArray[1], agraph.NodeArray[3], 15);
        agraph.addEdge(agraph.NodeArray[3], agraph.NodeArray[4], 7);
        agraph.addEdge(agraph.NodeArray[2], agraph.NodeArray[4], 12);

        agraph.shortestPath(agraph.NodeArray[0], agraph.NodeArray[4]);
        agraph.setPath(4);
        cout << endl;
        for (list<int>::iterator i = agraph.Path.begin(); i != agraph.Path.end(); i++)
        {
            std::cout << " " << *i;
        }
    }
    catch (exception e)
    {
    }

    //when to end, what to do if already visited
    //add exceptioon array out of bounds
}
