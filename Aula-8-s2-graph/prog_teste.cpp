#include <iostream>
#include "graph.cpp"

using std::cout, std::cin, std::endl;

graph::digraph getDigraph()
{
    graph::digraph g;
    g.insert_node("A");
    g.insert_node("B");
    g.insert_node("C");
    g.insert_node("D");
    g.insert_node("E");

    return g;

}

int main(){
    graph::digraph g = getDigraph();

    cout << g.size() << " nodos" << endl;

    if (g.find("L")) cout << "Encontrou!\n";
    else cout << "Não encontrado\n";

    g.insert_link("A","B");
    g.insert_link("A","D");
    g.insert_link("C","D");
    g.insert_link("C","A");
    g.insert_link("E","C");
    g.insert_link("F","F");


    cout << g.indegree("C") << endl;
    cout << g.outdegree("C") << endl;
    cout << g.degree("C") << endl;

    g.draw("teste");
    return 0;
}