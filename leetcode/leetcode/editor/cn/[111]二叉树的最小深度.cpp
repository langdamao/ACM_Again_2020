//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明：叶子节点是指没有子节点的节点。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数的范围在 [0, 10⁵] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 765 👎 0


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
    struct Node {
        TreeNode* node;
        int step;
        Node(){};
        Node(TreeNode* _node, int _step): node(_node),step(_step){};
        bool isLeave(){
            if (!node->left && !node->right) return true;
            return false;
        }
    };
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<Node> q;
        q.push(Node(root,1));
        while(!q.empty()){
            Node tmp  = q.front();
            q.pop();
            if (tmp.isLeave()) return tmp.step;
            if (tmp.node->left) q.push(Node(tmp.node->left,tmp.step+1));
            if (tmp.node->right) q.push(Node(tmp.node->right,tmp.step+1));
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
