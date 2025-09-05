// BINARY TREES - PREORDER

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

void preorderTraversal(struct Node *root, vector<int> &nodes)
{
  if (root == NULL)
    return;
  nodes.push_back(root->data);
  preorderTraversal(root->left, nodes);
  preorderTraversal(root->right, nodes);
}

int main()
{
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  vector<int> nodes;
  preorderTraversal(root, nodes);
  for (int n : nodes)
  {
    cout << n << " ";
  }
  return 0;
}