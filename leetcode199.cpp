// Right View of the Tree

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
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> ds;
    recursion(root, 0, ds);
    return ds;
  }

  void recursion(TreeNode *node, int level, vector<int> &ds)
  {
    if (node == nullptr)
      return;

    // If visiting this level for the first time → add this node
    if (level == ds.size())
      ds.push_back(node->val);

    // First go right, then left
    recursion(node->right, level + 1, ds);
    recursion(node->left, level + 1, ds);
  }
};

// Helper to build a sample tree
TreeNode *buildSampleTree()
{
  // Example tree:
  //       1
  //     /   \
    //    2     3
  //     \     \
    //      5     4
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  return root;
}

int main()
{
  Solution sol;
  TreeNode *root = buildSampleTree();

  vector<int> ans = sol.rightSideView(root);

  cout << "Right side view: ";
  for (int val : ans)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
