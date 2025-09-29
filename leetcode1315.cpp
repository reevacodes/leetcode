#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 0;

        int sum = 0;
        if(root->val % 2 == 0) {
            if(root->left && root->left->left) sum += root->left->left->val;
            if(root->left && root->left->right) sum += root->left->right->val;
            if(root->right && root->right->left) sum += root->right->left->val;
            if(root->right && root->right->right) sum += root->right->right->val;
        }

        sum += sumEvenGrandparent(root->left);
        sum += sumEvenGrandparent(root->right);

        return sum;
    }
};

// Helper to build a sample tree
TreeNode* buildSampleTree() {
    /*
            6
           / \
          7   8
         / \   \
        2   7   1
       /   /
      9   1
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(1);

    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);

    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    cout << "Sum of nodes with even-valued grandparent = " 
         << sol.sumEvenGrandparent(root) << endl;

    return 0;
}
