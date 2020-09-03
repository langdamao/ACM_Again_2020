//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> q[2];
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (root==NULL) return ret;
       int now=0;
       q[now].clear();
       q[now].reserve(100);
       q[now].push_back(root);
       vector<int> tmp;
       tmp.push_back(root->val);
       ret.push_back(tmp);
       while(!q[now].empty()){
         q[now^1].clear();
         tmp.clear();
         for (TreeNode* node : q[now]){
           if (node->left!=NULL) q[now^1].push_back(node->left);
           if (node->right!=NULL) q[now^1].push_back(node->right);
         }
         now = now^1;
         tmp.reserve(q[now].size());
         for (TreeNode* node: q[now]){
           tmp.push_back(node->val);
         }
         if (!tmp.empty()) {
           ret.push_back(tmp);
         }
       }
       return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
