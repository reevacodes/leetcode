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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
      inMap[inorder[i]] = i;
    }
    return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
  }

private:
  TreeNode *build(vector<int> &postorder, int postStart, int postEnd,
                  vector<int> &inorder, int inStart, int inEnd,
                  unordered_map<int, int> &inMap)
  {
    if (postStart > postEnd || inStart > inEnd)
      return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode *root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart; // number of nodes in left subtree

    // Build left and right recursively
    root->left = build(postorder, postStart, postStart + numsLeft - 1,
                       inorder, inStart, inRoot - 1, inMap);

    root->right = build(postorder, postStart + numsLeft, postEnd - 1,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
  }
};

// Helper function to print preorder traversal for checking
void printPreorder(TreeNode *root)
{
  if (!root)
    return;
  cout << root->val << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

int main()
{
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  Solution sol;
  TreeNode *root = sol.buildTree(inorder, postorder);

  cout << "Preorder of constructed tree: ";
  printPreorder(root);
  cout << endl;

  return 0;
}
