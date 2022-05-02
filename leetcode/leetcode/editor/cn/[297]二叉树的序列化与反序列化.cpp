//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 示例: 
//
// 你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]" 
//
// 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这
//个问题。 
//
// 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。 
// Related Topics 树 设计


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
class Codec {
public:

    // Encodes a tree to a single string.
    string work (TreeNode* root){
        if (!root) return ",";
        return to_string(root->val).append(",").append(work(root->left)).append(work(root->right));
    }
    string serialize(TreeNode* root) {
//        cout<<work(root)<<endl;
       return work(root);
    }

    // Decodes your encoded data to tree.
    int getInt(string data, int& index){
        int head = index;
        while(data[index]!=','){
            index++;
        }
        int ret = atoi(data.substr(head,index-head).c_str());
        index ++;
        return ret;
    }
    bool isNumber(string data, int index){
        if (data[index]!=',') return true;
        return false;
    }
    TreeNode* workBack(string data, int& index){
        if (data[index]==',') {index++;return nullptr;}
        TreeNode * node = new TreeNode(getInt(data,index));
        node -> left = workBack(data, index);
        node -> right = workBack(data,index);
        return node;
    }
    TreeNode* deserialize(string data) {
        if (data.length() == 1 && data[0]==',') return nullptr;
        int index =0;
        int n = data.length();
        return workBack(data,index);
        TreeNode * root = new TreeNode(getInt(data,index));
        stack<TreeNode*> st;
        TreeNode * now = root;
        while(index<n){
            if (isNumber(data, index)){
                TreeNode * tmp = new TreeNode(getInt(data,index));
                if (now) {
                    now->left = tmp;
                    st.push(now);
                }
                else{
                    now = st.top();
                    st.pop();
                    now -> right = tmp;
                }
                now = tmp;
            }
            else {
                index+=1;
                if (now){
                    st.push(now);
                }
                else {
                    st.pop();
                }
                now = nullptr;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)
