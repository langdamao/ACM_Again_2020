//给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵
//树的后序遍历，重构并返回二叉树。 
//
// 如果存在多个答案，您可以返回其中 任何 一个。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [1], postorder = [1]
//输出: [1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= preorder.length <= 30 
// 1 <= preorder[i] <= preorder.length 
// preorder 中所有值都 不同 
// postorder.length == preorder.length 
// 1 <= postorder[i] <= postorder.length 
// postorder 中所有值都 不同 
// 保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 244 👎 0


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
    TreeNode * dfs(vector<int>& preorder, vector<int>& postorder, int l1, int r1, int l2,  int r2){
        if (l1>=r1) return nullptr;
        if (l1 == r1-1) {
            return new TreeNode(preorder[l1]);
        }
        TreeNode * node = new TreeNode(preorder[l1]);
        int index = -1;
        for (int i = l2;i<r2;i++){
            if (preorder[l1+1] == postorder[i]){
                index = i;
                break;
            }
        }
        node -> left = dfs(preorder, postorder, l1+1, l1+1+index-l2+1, l2, index+1);
        node -> right = dfs(preorder, postorder, l1+1+index-l2+1, r1, index+1, r2-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        if (n==0) return nullptr;
        //return dfs(preorder, postorder, 0, n, 0, n);
        int index = 0;
        TreeNode * root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i=1;i<n;i++){
            TreeNode * now = st.top();
            if (now -> val != postorder[index]){
                TreeNode * tmp = new TreeNode( preorder[i]);
                now -> left = tmp;
                st.push(tmp);
            }
            else {
                while( index<n && !st.empty() && postorder[index]==st.top()->val){
                    st.pop();
                    index++;
                }
                now = st.top();
                TreeNode * tmp = new TreeNode(preorder[i]);
                now -> right = tmp;
                st.push(tmp);
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
