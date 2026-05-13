#include <iostream>
#include "graph.cpp"

using std::cout, std::cin, std::endl;

int main ()
{
    graph::digraph g = getDigraph();
}

graph::digraph getDigraph()
{
    graph::digraph g;
    g.insert_node("A");
    g.insert_node("B");
    g.insert_node("C");
    g.insert_node("D");
    g.insert_node("E");
}