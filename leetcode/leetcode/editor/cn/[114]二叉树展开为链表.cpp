//给定一个二叉树，原地将它展开为一个单链表。 
//
// 
//
// 例如，给定二叉树 
//
//     1
//   / \
//  2   5
// / \   \
//3   4   6 
//
// 将其展开为： 
//
// 1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6 
// Related Topics 树 深度优先搜索


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if (!root) return root;
        if (!root->left && !root->right) return root;
        TreeNode* left = dfs(root->left);
        TreeNode* right = root->right;
        if (left) {
            root->right = root->left;
            root->left = nullptr;
            left->right = right;
        }
        right = dfs(right);
        if (right) return right;
        else if (left) return left;
        else return root;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
