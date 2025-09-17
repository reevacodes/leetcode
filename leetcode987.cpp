#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class (same logic as LeetCode)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left)  todo.push({node->left, {x - 1, y + 1}});
            if (node->right) todo.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

// Helper function to print result
void printResult(const vector<vector<int>>& result) {
    for (auto col : result) {
        for (auto val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> res = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal:" << endl;
    printResult(res);

    return 0;
}
