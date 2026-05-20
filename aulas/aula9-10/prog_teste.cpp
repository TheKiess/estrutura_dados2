#include <iostream>
#include "graph.cpp"
using namespace std;
int main()
{
  graph::digraph objGrafico;

  objGrafico.insert_nodo("A");
  objGrafico.insert_nodo("B");
  objGrafico.insert_nodo("C");
  objGrafico.insert_nodo("D");
  objGrafico.insert_nodo("E");
  objGrafico.insert_nodo("F");
  objGrafico.insert_nodo("G");
  objGrafico.insert_nodo("H");

  cout << objGrafico.size() << " nodos" << endl;

  if(objGrafico.find("L"))
    cout << "Encontrou!\n";
  else
    cout << "Não encontrado\n";

  objGrafico.insert_link("A", "B");
  objGrafico.insert_link("A", "D");
  objGrafico.insert_link("C", "D");
  objGrafico.insert_link("C", "A");
  objGrafico.insert_link("E", "C");
  objGrafico.insert_link("F", "F");

  objGrafico.draw();

  cout << objGrafico.indegree("C")  << endl
       << objGrafico.outdegree("C") << endl
       << objGrafico.degree("C")    << endl;

  return 0;
}