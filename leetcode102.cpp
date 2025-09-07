#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Direct function (no class)
vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    vector<int> level;

    for (int i = 0; i < n; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
      level.push_back(node->val);
    }
    ans.push_back(level);
  }
  return ans;
}

int main()
{
  // Build a small tree:
  //       1
  //      / \
    //     2   3
  //        / \
    //       4   5
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  vector<vector<int>> result = levelOrder(root);

  // Print output
  for (auto &level : result)
  {
    for (int val : level)
      cout << val << " ";
    cout << endl;
  }
}
