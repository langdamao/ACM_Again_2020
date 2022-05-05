//给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// 
// 
// Related Topics 树 二叉搜索树 动态规划 回溯 二叉树 👍 1201 👎 0


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
    vector<TreeNode*> generateTree(int l,int r){
        if (l>r) return {nullptr};
        vector<TreeNode*> ret;
        for (int i=l;i<=r;i++){
            vector<TreeNode*> left = generateTree(l,i-1);
            vector<TreeNode*> right = generateTree(i+1,r);
            for (auto& lt: left){
                for (auto& rt: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    ret.emplace_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
        return generateTree(1,n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
