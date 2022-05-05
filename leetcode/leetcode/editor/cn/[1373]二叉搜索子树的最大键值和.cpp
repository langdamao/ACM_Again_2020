//给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。 
//
// 二叉搜索树的定义如下： 
//
// 
// 任意节点的左子树中的键值都 小于 此节点的键值。 
// 任意节点的右子树中的键值都 大于 此节点的键值。 
// 任意节点的左子树和右子树都是二叉搜索树。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
//输出：20
//解释：键值为 3 的子树是和最大的二叉搜索树。
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [4,3,null,1,2]
//输出：2
//解释：键值为 2 的单节点子树是和最大的二叉搜索树。
// 
//
// 示例 3： 
//
// 
//输入：root = [-4,-2,-5]
//输出：0
//解释：所有节点键值都为负数，和最大的二叉搜索树为空。
// 
//
// 示例 4： 
//
// 
//输入：root = [2,1,3]
//输出：6
// 
//
// 示例 5： 
//
// 
//输入：root = [5,4,8,3,null,6,3]
//输出：7
// 
//
// 
//
// 提示： 
//
// 
// 每棵树有 1 到 40000 个节点。 
// 每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。 
// 
// Related Topics 树 深度优先搜索 二叉搜索树 动态规划 二叉树 👍 96 👎 0


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
    int maxRet = 0;
    struct node{
        bool isBST = false;
        int sum =0;
        int min = 1e5*4+5;
        int max = -1e5*4-5;
        node(){}
        node(bool _isBST, int _sum):isBST(_isBST), sum(_sum){}
        void print(){
            cout<<isBST<<' '<<sum<<' '<<min<<' '<<max<<endl;
        }
    };
     node dfs(TreeNode* root){
        if (!root) return node(true,0);
        node ret;
        node left = dfs(root->left), right = dfs(root->right);
        ret.isBST = left.isBST && right.isBST && left.max<root->val && right.min>root->val;
        ret.sum = left.sum+right.sum+root->val;
        ret.max = max(max(left.max, right.max),root->val);
        ret.min = min(min(left.min, right.min),root->val);
//        cout<<root->val<<endl;
//        ret.print();
        if (ret.isBST){
            maxRet = max(maxRet, ret.sum);
        }
        return ret;
    }
    int maxSumBST(TreeNode* root) {
       dfs(root);
       return maxRet;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
