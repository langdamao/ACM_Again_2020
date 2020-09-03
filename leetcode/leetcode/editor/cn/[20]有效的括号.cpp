//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isleft(char c){
      if (c=='(' || c=='[' || c=='{') return true;
      return false;
    }
    bool ispair(char c1,char c2){
      if (c1=='(' && c2==')') return true;
      if (c1=='[' && c2==']') return true;
      if (c1=='{' && c2=='}') return true;
      return false;
    }
    bool isValid(string s) {
      stack<char> st;
      int n = s.length();
      for (int i=0;i<n;i++){
        if (isleft(s[i])) st.push(s[i]);
        else {
          if (st.empty() || !ispair(st.top(),s[i])) return false;
          st.pop();
        }
      }
      return st.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
