#include <iostream>
#include <vector>



struct Edge
{
    float weight;
    struct Node* next;

    Edge (float weight, Node* n)
    {
        weight = weight;
        next = n;
    }
};
struct Node
{
    int value;
    std::vector<Edge> edges;
    bool visited = false;
    Node(int v)
    {
        this->value = v;
    }
    void connect(float w, Node* next)
    {
        Edge e(w, next);
        edges.push_back(e);
    }

};

void dfs (Node* node)
{
    std::cout<< node->value <<std::endl;
    node->visited = true;
    for ( int i = 0; i < node->edges.size(); i++)
    {
        if (!node->edges[i].next->visited)
        {
            dfs(node->edges[i].next);
        }
    }

}
int main(){
    std::vector<Node> graph;

    Node n0(0); /** ROOT */
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);

    n0.connect(0, &n1);
    n0.connect(0, &n2);

    n1.connect(0, &n3);
    n1.connect(0, &n4);

    n2.connect(0, &n5);
    n2.connect(0, &n6);

    graph.push_back(n0);
    graph.push_back(n1);
    graph.push_back(n2);
    graph.push_back(n3);
    graph.push_back(n4);
    graph.push_back(n5);
    graph.push_back(n6);

    n3.connect(0, &n1);
    n4.connect(0, &n1);

    n5.connect(0, &n2);
    n6.connect(0, &n3);
    dfs(&n0);

    return 0;
}

