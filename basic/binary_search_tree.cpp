#include <iostream>
#include <vector>

// Binary Search Tree => all left descendents <= n < all right descendents.
// For a balanced tree, insert is O(logN)  and find is O(logN)

// The left subtree of nodes contains only nodes with keys less than the node's
// key. The right subtree of nodes contains only nodes with keys greater than
// the node's key. Both the left and right subtrees must also be binary search
// tree.

// Question: Construct a binary search tree from a sorted array.

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *buildBST(vector<int> nums, int left, int right) {
  if (left > right)
    return static_cast<TreeNode *>(nullptr);
  int middle = left + (right - left) / 2;
  int val = nums[val];
  TreeNode *root = new TreeNode(val);
  root->left = buildBST(nums, left, middle - 1);
  root->right = buildBST(nums, middle + 1, right);
  return root;
}

void traversal(TreeNode *node) {
  if (node != nullptr) {
    cout << node->val << endl;
    traversal(node->left);
    traversal(node->right);
  }
}

int main() {
  vector<int> array{1, 2, 3, 4, 5, 6, 7};
  TreeNode *root = buildBST(array, 0, array.size() - 1);
  traversal(root);
  exit(EXIT_SUCCESS);
}
