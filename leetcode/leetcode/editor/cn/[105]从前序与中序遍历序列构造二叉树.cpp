//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组


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
 //dfs
//    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int p, int l, int r){
//        if (l>=r) return nullptr;
//        if (l==r-1) return new TreeNode(preorder[p]);
//        int index =l;
//        for (int i=l;i<r;i++){
//            if (inorder[i]==preorder[p]) {
//                index = i;
//                break;
//            }
//        }
//        TreeNode* root = new TreeNode(preorder[p]);
//        root->left = dfs(preorder,inorder,p+1,l,index);
//        root->right = dfs(preorder,inorder,p+index-l+1,index+1,r);
//        return root;
//    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        return dfs(preorder, inorder, 0, 0 , inorder.size());
          int pre_index = 0;
          int in_index = 0;
          int len = preorder.size();
          if (len == 0) return nullptr;
          TreeNode* now = new TreeNode(preorder[0]);
          TreeNode* rootf = now;
          stack<TreeNode* > st;
          st.push(now);
          for (int i = 1;i<len;i++){
              if (now->val != inorder[in_index]){
                  TreeNode * tmp = new TreeNode(preorder[i]);
                  now -> left = tmp;
                  now = tmp;
                  st.push(tmp);
              }
              else {
                  while(in_index < len && !st.empty() && inorder[in_index] == st.top()->val){
                      now = st.top();
                      st.pop();
                      in_index++;
                  }
                  TreeNode * tmp = new TreeNode(preorder[i]);
                  now -> right = tmp;
                  st.push(tmp);
                  now = tmp;

              }
          }
          return rootf;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
