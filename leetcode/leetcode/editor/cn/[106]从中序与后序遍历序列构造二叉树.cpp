//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
//
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 👍 730 👎 0


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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int l, int r, int p){
        if (l>=r) return nullptr;
        if (l==r-1) {
            return new TreeNode(inorder[l]);
        }
        int index = -1;
        for (int i=l;i<r;i++){
            if (inorder[i] == postorder[p]){
                index = i;
                break;
            }
        }
        TreeNode * node = new TreeNode(postorder[p]);
        node -> left = dfs(inorder, postorder, l, index, p-(r-index));
        node -> right = dfs(inorder, postorder, index+1,r, p-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if (len == 0) return nullptr;
        TreeNode* root = new TreeNode(postorder[len-1]);
        stack<TreeNode*> st;
        st.push(root);
        int index = len-1;
        for (int i = len-2;i>=0;i--){
            TreeNode* now = st.top();
            if (now->val != inorder[index]){
                TreeNode* tmp = new TreeNode(postorder[i]);
                now -> right = tmp;
                st.push(tmp);
            }
            else {
                while( index<len && !st.empty() && st.top()->val == inorder[index]){
                    now = st.top();
                    st.pop();
                    index--;
                }
                TreeNode* tmp = new TreeNode(postorder[i]);
                now -> left = tmp;
                st.push(tmp);
            }
        }
        return root;
         //return dfs(inorder, postorder, 0, len, len-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
