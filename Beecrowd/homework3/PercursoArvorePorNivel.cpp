#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct node
{
  string value;
  node *left;
  node *right;
};

node *create_node(const string &str_value)
{
  node *p  = new node;
  p->value = str_value;
  p->left  = nullptr;
  p->right = nullptr;

  return p;
}

void BST_insert(node *&root, string &dsValor)
{
  if (!root)
    root = create_node(dsValor);
  else
  {
    if (stoi(dsValor) < stoi(root->value))
      BST_insert(root->left, dsValor);
    else if (stoi(dsValor) > stoi(root->value))
      BST_insert(root->right, dsValor);
  }
}

void BFS_nivel(node *root, bool &idPrimeiro)
{
  if (!root)
    return;

  queue<node*> fila;
  fila.push(root);

  while (!fila.empty())
  {
    node *aux = fila.front();
    fila.pop();

    if(!idPrimeiro)
      cout << " ";

    cout << aux->value;
    idPrimeiro = false;

    if (aux->left != nullptr)
      fila.push(aux->left);

    if (aux->right != nullptr)
      fila.push(aux->right);
  }
}

int main()
{
  int qtRep = 0; cin >> qtRep;

  for (int i = 0; i < qtRep; i++)
  {
    node *root      = nullptr;
    int qtValues    = 0; cin >> qtValues;
    bool idPrimeiro = true;

    for (int j = 0; j < qtValues; j++)
    {
      string value; cin >> value;
      BST_insert(root, value);
    }

    cout << "Case " << i + 1 << ":" << endl;

    BFS_nivel(root, idPrimeiro);
    cout << endl << endl;
  }
}