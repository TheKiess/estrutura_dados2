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

    cout << "Pre.: ";
    DFS_pre(root, idPrimeiro);
    cout << endl;

    cout << "In..: ";
    idPrimeiro = true;
    DFS_in(root, idPrimeiro);
    cout << endl;

    cout << "Post: ";
    idPrimeiro = true;
    DFS_post(root, idPrimeiro);
    cout << endl;

    cout << endl;
  }
}