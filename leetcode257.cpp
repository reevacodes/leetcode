// Binary tree paths

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findPath(TreeNode *root, vector<string> &ans, string s)
{
  if (!root)
    return;

  s += to_string(root->val);
  if (root->left)
    findPath(root->left, ans, s + "->");
  if (root->right)
    findPath(root->right, ans, s + "->");
  if (!root->left && !root->right)
    ans.push_back(s);
}

vector<string> binaryTreePaths(TreeNode *root)
{
  vector<string> ans;
  if (!root)
    return ans;
  findPath(root, ans, "");
  return ans;
}

int main()
{
  // Example tree: [1,2,3,null,5]
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  vector<string> result = binaryTreePaths(root);

  for (auto &path : result)
  {
    cout << path << endl;
  }

  return 0;
}
