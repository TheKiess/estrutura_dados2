#include <iostream>
#include "tree.cpp"

using namespace tree;
using namespace std;

int main()
{
  node *root                     = create_node("8");
  root->left                     = create_node("3");
  root->left->left               = create_node("1"); 
  root->left->left->right        = create_node("6");
  root->left->left->right->left  = create_node("4");
  root->left->left->right->right = create_node("7");
  root->right                    = create_node("10");
  root->right->right             = create_node("14");
  root->right->right->left       = create_node("13");

  cout << "Pre: "; DFS_pre(root);  cout << endl;
  cout << "In : "; DFS_in(root);   cout << endl;
  cout << "Pos: "; DFS_post(root); cout << endl;
  cout << "BSF: "; BST(root);      cout << endl;

  return 0;
}