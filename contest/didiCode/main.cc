#include <cstdio>
#include <cstring>
using namespace std;
struct Node {
  Node *left;
  Node *right;
  int val;
};
Node *find(Node *root, int key) {
  if (root == null) {
    return null;
  }
  if (root->val == key) {
    return root;
  }
  if (root->val > key) {
    return find(root->left, key);
  } else {
    return find(root->right, key);
  }
}
void delNode(Node *node) {
  while (node->left != null) {
    node->val = node->left->val;
    node = node->left;
  }
  if (node->right != null) {
  }
  delete node;
}
int main() {
  Node *root; // input
  int key;    // input
  Node *node = find(root, key);
  if (node == null) {
    // Not found 非法
  } else {
    delNode(node);
  }
  return 0;
}
