//  Is Binary Tree Symmetrical

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
    return root == nullptr || isSymmetricHelp(root->left, root->right);
  }

  bool isSymmetricHelp(TreeNode *left, TreeNode *right)
  {
    if (left == nullptr || right == nullptr)
      return left == right; // both must be null
    if (left->val != right->val)
      return false;
    return isSymmetricHelp(left->left, right->right) &&
           isSymmetricHelp(left->right, right->left);
  }
};

// Helper to build a sample symmetric tree
TreeNode *buildSymmetricTree()
{
  // Example symmetric tree:
  //        1
  //      /   \
    //     2     2
  //    / \   / \
    //   3   4 4   3
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  return root;
}

// Helper to build an asymmetric tree
TreeNode *buildAsymmetricTree()
{
  // Example asymmetric tree:
  //        1
  //      /   \
    //     2     2
  //      \      \
    //       3      3
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(3);
  return root;
}

int main()
{
  Solution sol;

  TreeNode *symTree = buildSymmetricTree();
  TreeNode *asymTree = buildAsymmetricTree();

  cout << "Is symmetric tree symmetric? "
       << (sol.isSymmetric(symTree) ? "Yes" : "No") << endl;

  cout << "Is asymmetric tree symmetric? "
       << (sol.isSymmetric(asymTree) ? "Yes" : "No") << endl;

  return 0;
}
