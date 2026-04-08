#include <iostream>
#include "tree.cpp"

using namespace tree;// -> usar '::' para não misturar as bibliotecas.
using namespace std;

int main()
{
  node *root = nullptr;
  string dsValor;
  while (cin >> dsValor && dsValor != "exit")
  {
    if (BST_find(root, dsValor))
      cout << "Já foi inserido" << std::endl;
    else
      BST_insert(root, dsValor);
  }

  //show2(root, "!", 0);
  //show(root);

  cout << "Pre: "; DFS_pre(root);  cout << endl;
  cout << "In : "; DFS_in(root);   cout << endl;
  cout << "Pos: "; DFS_post(root); cout << endl;
  cout << "BSF: "; BST(root);      cout<< endl;

  return 0;
}