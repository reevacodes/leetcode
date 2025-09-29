#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class with LCA function
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == NULL || root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
      return right;
    else if (right == NULL)
      return left;
    else
      return root;
  }
};

// Helper function to build a simple tree for demo
TreeNode *buildTree()
{
  /*
          3
         / \
        5   1
       / \  / \
      6  2 0  8
        / \
       7   4
  */
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  return root;
}

int main()
{

  // Build tree
  TreeNode *root = buildTree();

  // Example queries
  Solution sol;

  TreeNode *p = root->left;              // Node 5
  TreeNode *q = root->left->right->left; // Node 7

  TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

  cout << "LCA of " << p->val << " and " << q->val << " is: "
       << (lca ? lca->val : -1) << "\n";

  return 0;
}
