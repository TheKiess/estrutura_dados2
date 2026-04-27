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

int main()
{
  int n; cin >> n;
  node *root = nullptr;
  
  for (int i = 0; i < n; i++)
  {
    string value; cin >> value;
    BST_insert(root, value);
  }

  queue<node*> fila;
  fila.push(root);

  int nrProfundidade = 0;

  while (!fila.empty())
  {
    int nrTam    = fila.size();
    int nrMinimo = 99999;

    for (int i = 0; i < nrTam; i++)
    {
      node *aux = fila.front();
      fila.pop();

      nrMinimo = min(nrMinimo, stoi(aux->value));
      
      if (aux->left != nullptr)
        fila.push(aux->left);
      
      if (aux->right != nullptr)
        fila.push(aux->right);
    }

    cout << nrProfundidade << " " << nrMinimo << endl;
    nrProfundidade++;
  }

  return 0;
}