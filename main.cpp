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

int main(){
    std::vector<Node> graph;

    Node n0(0);


    Node n1(1);


    Node n2(2);


    n0.connect(1.5, &n1);
    n0.connect(3.1, &n2);
    Node new_node(123);
    n0.connect(5.6, &new_node);

    graph.push_back(n0);
    graph.push_back(n1);
    graph.push_back(n2);
    graph.push_back(new_node);


}

