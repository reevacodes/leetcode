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

// Function to perform zigzag level order traversal
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> result;
  if (root == NULL)
    return result;

  queue<TreeNode *> queueNodes;
  queueNodes.push(root);
  bool leftToRight = true;

  while (!queueNodes.empty())
  {
    int size = queueNodes.size();
    vector<int> row(size);

    for (int i = 0; i < size; i++)
    {
      TreeNode *node = queueNodes.front();
      queueNodes.pop();

      int index = leftToRight ? i : (size - 1 - i);
      row[index] = node->val;

      if (node->left)
        queueNodes.push(node->left);
      if (node->right)
        queueNodes.push(node->right);
    }

    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}

int main()
{
  // Example Tree:
  //        1
  //       / \
    //      2   3
  //     / \   \
    //    4   5   6
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  vector<vector<int>> result = zigzagLevelOrder(root);

  cout << "Zigzag Level Order Traversal:" << endl;
  for (auto &level : result)
  {
    for (int val : level)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
