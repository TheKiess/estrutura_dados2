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

void DFS_pre(node *root, bool &idPrimeiro)
{
  if(!root)
    return;

  if(!idPrimeiro)
    cout << " ";

  cout << root->value;
  idPrimeiro = false;

  DFS_pre(root->left,  idPrimeiro);
  DFS_pre(root->right, idPrimeiro);
}

void DFS_in(node *root, bool &idPrimeiro)
{
  if(!root) return;

  DFS_in(root->left, idPrimeiro);

  if(!idPrimeiro)
    cout << " ";

  cout << root->value;
  idPrimeiro = false;

  DFS_in(root->right, idPrimeiro);
}

void DFS_post(node *root, bool &idPrimeiro)
{
  if(!root)
    return;

  DFS_post(root->left,  idPrimeiro);
  DFS_post(root->right, idPrimeiro);

  if(!idPrimeiro)
    cout << " ";

  cout << root->value;
  idPrimeiro = false;
}

node *BST_find(node *root, string &dsValor)
{
  if (!root || root->value == dsValor)
    return root;

  if (stoi(dsValor) < stoi(root->value))
    return BST_find(root->left, dsValor);

  return BST_find(root->right, dsValor);
}

void BST_remove(node *&root, string &dsValor)
{
  if (!root)
    return;

  if (stoi(dsValor) < stoi(root->value))
    BST_remove(root->left, dsValor);
  else if (stoi(dsValor) > stoi(root->value))
    BST_remove(root->right, dsValor);
  else
  {
    if (!root->left)
      root = root->right;
    else if (!root->right)
      root = root->left;
    else
    {
      node *aux = root->left;

      while (aux->right)
        aux = aux->right;

      root->value = aux->value;
      BST_remove(root->left, aux->value);
    }
  }
}

int main()
{
  node *root = nullptr;
  string dsComando;

  while (cin >> dsComando)
  {
    string dsValor;

    if (dsComando == "I")
    {
      cin >> dsValor;
      BST_insert(root, dsValor);
    }
    else if (dsComando == "INFIXA")
    {
      bool idPrimeiro = true;
      DFS_in(root, idPrimeiro);
      cout << endl;
    }
    else if (dsComando == "PREFIXA")
    {
      bool idPrimeiro = true;
      DFS_pre(root, idPrimeiro);
      cout << endl;
    }
    else if (dsComando == "POSFIXA")
    {
      bool idPrimeiro = true;
      DFS_post(root, idPrimeiro);
      cout << endl;
    }
    else if (dsComando == "P")
    {
      cin >> dsValor;
      node *resultado = BST_find(root, dsValor);
      
      if (resultado != nullptr)
        cout << dsValor << " existe" << endl;
      else
        cout << dsValor << " nao existe" << endl;
    }
    else if (dsComando == "R")
    {
      cin >> dsValor;
      BST_remove(root, dsValor);
    }
  }

  return 0;
}