#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// preorder DFS with stack
void PreOrderDFSWithStack(TreeNode *root) {
  if (root == nullptr) {
    // show error.
    return;
  }
  std::stack<TreeNode *> _stack;
  _stack.push(root);
  while (!_stack.empty()) {
    TreeNode *curr = _stack.top();
    _stack.pop();
    std::cout << curr->val << std::endl;
    if (curr->right != nullptr)
      _stack.push(curr->right);
    if (curr->left != nullptr)
      _stack.push(curr->left);
  }
}

void InOrderDFSWithStack(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  std::stack<TreeNode *> st;
  TreeNode *curr = root;
  while (curr != nullptr || !st.empty()) {
    while (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    std::cout << curr->val << std::endl;
    curr = curr->right;
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
  // PreOrderDFSWithStack(root);
  InOrderDFSWithStack(root);
  return 0;
}
