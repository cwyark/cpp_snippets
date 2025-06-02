#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void DFS(TreeNode* node) {
  if (node == nullptr) {
    return; 
  }
  DFS(node->left);
  std::cout << node->val << std::endl;
  DFS(node->right);
}

int main() {
    // Construct a simple binary tree:
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    DFS(root);
    return 0;
}
