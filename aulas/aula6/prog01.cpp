#include <iostream>
#include "tree.cpp"

using namespace tree;
using namespace std;

int main()
{
  node *root               = create_node("A");
  root->left               = create_node("B");
  root->left->left         = create_node("D"); 
  root->left->left->left   = create_node("G");
  root->right              = create_node("C");
  root->right->left        = create_node("E");
  root->right->right       = create_node("F");
  root->right->left->left  = create_node("H");
  root->right->left->right = create_node("I");

  //cout << height(root) << endl;

  show(root);
}