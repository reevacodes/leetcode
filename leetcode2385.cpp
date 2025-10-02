// AMOUNT OF TIME TAKEN FOR BT TO GET AFFECTED / BURNT

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
private:
  // DFS: build parent map and find target node
  void mapParents(TreeNode *node, unordered_map<TreeNode *, TreeNode *> &parent,
                  TreeNode *&targetNode, int target)
  {
    if (!node)
      return;

    if (node->val == target)
      targetNode = node;

    if (node->left)
    {
      parent[node->left] = node;
      mapParents(node->left, parent, targetNode, target);
    }

    if (node->right)
    {
      parent[node->right] = node;
      mapParents(node->right, parent, targetNode, target);
    }
  }

public:
  int amountOfTime(TreeNode *root, int start)
  {
    unordered_map<TreeNode *, TreeNode *> parent;
    TreeNode *targetNode = nullptr;

    // Step 1: build parent map and find start node
    mapParents(root, parent, targetNode, start);

    // Step 2: BFS from target node
    unordered_set<TreeNode *> visited;
    queue<TreeNode *> q;
    q.push(targetNode);
    visited.insert(targetNode);

    int time = 0;
    while (!q.empty())
    {
      int size = q.size();
      bool burned = false;

      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        // Left child
        if (node->left && !visited.count(node->left))
        {
          visited.insert(node->left);
          q.push(node->left);
          burned = true;
        }

        // Right child
        if (node->right && !visited.count(node->right))
        {
          visited.insert(node->right);
          q.push(node->right);
          burned = true;
        }

        // Parent
        if (parent[node] && !visited.count(parent[node]))
        {
          visited.insert(parent[node]);
          q.push(parent[node]);
          burned = true;
        }
      }

      if (burned)
        time++;
    }
    return time;
  }
};

// Helper to create a test tree
TreeNode *buildTree()
{
  // Example tree:
  //        1
  //       / \
    //      2   3
  //     /
  //    4
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  return root;
}

int main()
{
  Solution sol;
  TreeNode *root = buildTree();
  int start = 2; // fire starts at node value 2
  cout << "Time to burn tree: " << sol.amountOfTime(root, start) << endl;
  return 0;
}
