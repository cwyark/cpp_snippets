#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
// Build BST from array.
TreeNode *buildBSTfromArray(const vector<int> &array, int left, int right) {
  if (left > right) {
    return nullptr;
  }
  int middle = left + (right - left) / 2;
  int value = array[middle];
  TreeNode *root = new TreeNode(value);
  root->left = buildBSTfromArray(array, left, middle - 1);
  root->right = buildBSTfromArray(array, middle + 1, right);
  return root;
}

void traversalRecusion(TreeNode *root) {
  if (root != nullptr) {
    traversalRecusion(root->left);
    cout << root->val << " ";
    traversalRecusion(root->right);
  }
}

void PreorderTraversalIteration(TreeNode *root) {
  stack<TreeNode *> stack;
  stack.push(root);
  while (stack.size() > 0) {
    TreeNode *root = stack.top();
    stack.pop();
    cout << root->val << " ";
    if (root->left) {
      stack.push(root->left);
    }
    if (root->right) {
      stack.push(root->right);
    }
  }
}

void InorderTravversalIteration(TreeNode *root) { stack<TreeNode *> stack; }

int main() {
  vector<int> array{0, 1, 2, 3, 4, 5, 6, 7};
  TreeNode *root = buildBSTfromArray(array, 0, array.size() - 1);
  cout << "Recusion Traversal" << endl;
  traversalRecusion(root);
  cout << endl;
  cout << "Iteration pre-order traversal" << endl;
  PreorderTraversalIteration(root);
  exit(EXIT_SUCCESS);
}
