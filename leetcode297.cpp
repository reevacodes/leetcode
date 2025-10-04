#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (!root)
      return "";
    string s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *curNode = q.front();
      q.pop();
      if (curNode == NULL)
      {
        s.append("#,");
      }
      else
      {
        s.append(to_string(curNode->val) + ',');
        q.push(curNode->left);
        q.push(curNode->right);
      }
    }
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data.empty())
      return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ','); // root value
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      // left child
      if (!getline(s, str, ','))
        break;
      if (str == "#")
      {
        node->left = NULL;
      }
      else
      {
        TreeNode *leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }

      // right child
      if (!getline(s, str, ','))
        break;
      if (str == "#")
      {
        node->right = NULL;
      }
      else
      {
        TreeNode *rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
    }
    return root;
  }
};

// Helper function: Inorder traversal (for testing)
void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main()
{
  // Build a simple tree:
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

  Codec ser, deser;
  string data = ser.serialize(root);
  cout << "Serialized Tree: " << data << endl;

  TreeNode *ans = deser.deserialize(data);
  cout << "Inorder of Deserialized Tree: ";
  inorder(ans);
  cout << endl;

  return 0;
}
