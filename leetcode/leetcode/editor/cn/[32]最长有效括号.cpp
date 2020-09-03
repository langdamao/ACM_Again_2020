//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。 
//
// 示例 1: 
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
//
//
// 示例 2: 
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void flip(string& s){
      int n = s.length();
      for (int i=0;i<n-1-i;i++){
        swap(s[i],s[n-1-i]);
      }
      for (auto& ch:s){
        ch='('+')'-ch;
      }
    }
    int getAns(string s,int flag){
      if (flag==-1) {
        flip(s);
      }
      int n = s.length();
      int num=0;
      int ans=0;
      int len=0;
      for (auto ch :s){
        num += (ch=='('?1:-1);
        len++;
        if (num==0){
          ans =max(ans,len);
        }
        else if (num<0){
          num=0;
          len=0;
        }
      }
      return ans;
    }
    int longestValidParentheses(string s) {
        return max(getAns(s,1),getAns(s,-1));
    }
};
//leetcode submit region end(Prohibit modification and deletion)
