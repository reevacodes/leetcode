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
  int widthOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;
    long long ans = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      int size = q.size();
      long long levelMin = q.front().second;
      long long first = 0, last = 0;

      for (int i = 0; i < size; i++)
      {
        long long cur_id = q.front().second - levelMin; // normalize index
        TreeNode *node = q.front().first;
        q.pop();

        if (i == 0)
          first = cur_id;
        if (i == size - 1)
          last = cur_id;

        if (node->left)
          q.push({node->left, 2 * cur_id + 1});
        if (node->right)
          q.push({node->right, 2 * cur_id + 2});
      }
      ans = max(ans, last - first + 1);
    }
    return (int)ans;
  }
};

// Helper function to build a sample tree
TreeNode *buildTree()
{
  /*
          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
  */
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->right->right = new TreeNode(9);
  root->left->left->left = new TreeNode(6);
  root->right->right->right = new TreeNode(7);
  return root;
}

int main()
{

  // Build example tree
  TreeNode *root = buildTree();

  // Solve
  Solution sol;
  int width = sol.widthOfBinaryTree(root);

  cout << "Maximum width of the binary tree: " << width << "\n";

  return 0;
}
