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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
      inMap[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
  }

private:
  TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd,
                  unordered_map<int, int> &inMap)
  {
    if (preStart > preEnd || inStart > inEnd)
      return nullptr;

    int rootVal = preorder[preStart];
    TreeNode *root = new TreeNode(rootVal);

    int inRoot = inMap[rootVal];
    int numsLeft = inRoot - inStart; // number of nodes in left subtree

    root->left = build(preorder, preStart + 1, preStart + numsLeft,
                       inorder, inStart, inRoot - 1, inMap);

    root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                        inorder, inRoot + 1, inEnd, inMap);

    return root;
  }
};

// Helper function to print inorder traversal for checking
void printInorder(TreeNode *root)
{
  if (!root)
    return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Solution sol;
  TreeNode *root = sol.buildTree(preorder, inorder);

  cout << "Inorder of constructed tree: ";
  printInorder(root);
  cout << endl;

  return 0;
}
