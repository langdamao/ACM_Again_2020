//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "1 + 1"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：s = " 2-1 + 2 "
//输出：3
// 
//
// 示例 3： 
//
// 
//输入：s = "(1+(4+5+2)-3)+(6+8)"
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成 
// s 表示一个有效的表达式 
// '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效) 
// '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的) 
// 输入中不存在两个连续的操作符 
// 每个数字和运行的计算将适合于一个有符号的 32位 整数 
// 
// Related Topics 栈 递归 数学 字符串 👍 752 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
struct node{
    int ty=0;
    char ch=' ';
    int x=0;
    node(char _ch):ch(_ch),ty(0) {}
    node(int _x):x(_x),ty(1){}
};
class Solution {
public:
    bool isNumber(char ch){
        if (ch>='0' and ch<='9') return true;
        return false;
    }
    int getNumber(int & tail, string &s){
        int head = tail;
        while(head>=0 && isNumber(s[head])) head--;
        int ret= 0;
        for (int i = head+1;i<=tail;i++) ret=ret*10+((int)s[i]-'0');
        tail = head+1;
        return ret;
    }
    int cal(stack<node>& st){
        int ret=0;
        char op = '+'; //0 +, 1-
        while(!st.empty()){
            node tmp = st.top();
            st.pop();
            if (tmp.ch==')') break;
            if (tmp.ty==0) {
                op = tmp.ch;
            }
            else {
                if (op=='+') ret+=tmp.x;
                else ret-=tmp.x;
            }
        }
        return ret;
    }
    int calculate(string s) {
        int len = s.length();
        stack<node> st;
        for (int i = len-1;i>=0;i--){
            if (s[i]==' ') continue;
            if (isNumber(s[i])) {
                int x = getNumber(i,s);
                st.push(node(x));
            }
            else {
                if (s[i]=='('){
                    st.push(cal(st));
                }else {
                    st.push(node(s[i]));
                }
            }
        }
        return cal(st);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
