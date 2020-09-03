//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例： 
//
// 输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
// 
// Related Topics 字符串 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(string str,int index,int l,int r,int n,vector<string>& vec){
      if (l==r && l==n) {
        vec.push_back(str);
        return ;
      }
      if (l<n){
        dfs(str+'(',index+1,l+1,r,n,vec);
      }
      if (r<l){
        dfs(str+')',index+1,l,r+1,n,vec);
      }
    }
    vector<string> generateParenthesis(int n) {
      vector<string> ret;
      dfs("",0,0,0,n,ret);
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
