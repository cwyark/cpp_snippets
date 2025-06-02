#include <iostream>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void BFS(TreeNode *root) {
  std::queue<TreeNode *> _queue;
  _queue.push(root);
  while (!_queue.empty()) {
    TreeNode *node = _queue.front();
    _queue.pop();
    std::cout << node->val << std::endl;
    if (node->left) {
      _queue.push(node->left);
    }
    if (node->right) {
      _queue.push(node->right);
    }
  }
}

int main() {
  // Construct a simple binary tree:
  //        4
  //      /   \
  //     2     6
  //    / \   / \
  //   1   3 5   7

  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);

  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(7);
  BFS(root);
  return 0;
}
