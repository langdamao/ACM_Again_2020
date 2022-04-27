//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 整数除法仅保留整数部分。 
//
// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2³¹, 2³¹ - 1] 的范围内。 
//
// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "3+2*2"
//输出：7
// 
//
// 示例 2： 
//
// 
//输入：s = " 3/2 "
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：s = " 3+5 / 2 "
//输出：5
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 10⁵ 
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开 
// s 表示一个 有效表达式 
// 表达式中的所有整数都是非负整数，且在范围 [0, 2³¹ - 1] 内 
// 题目数据保证答案是一个 32-bit 整数 
// 
// Related Topics 栈 数学 字符串 👍 554 👎 0


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
    bool isMul(char ch){
        if (ch=='*' || ch=='/') return true;
        return false;
    }
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
        stack<node> addSt;
        char op ='+';
        char mulOp = ' ';
        int ret=0;
        int tmpret = 1;
        while(!st.empty()){
            node tmp = st.top();
            st.pop();
            if (tmp.ch==')') break;
//            cout<<op<<' '<<mulOp<<' '<<ret<<' '<<tmpret<<' '<<tmp.x<<endl;
            if (tmp.ty==0 ) {
                if (!isMul(op)&&!isMul(tmp.ch)){
                    ret = op=='+'? ret+tmpret:ret-tmpret;
                    tmpret = 0;
                }
                if (isMul(tmp.ch)) mulOp = tmp.ch;
                else op = tmp.ch;
            }
            else {
                if (isMul(mulOp)){
                    int num = mulOp=='*' ? tmpret*tmp.x:tmpret/tmp.x;
                    tmpret = num;
                    mulOp = ' ';
                }else {
                    tmpret = tmp.x;
                }
            }
//            cout<<"end: "<<op<<' '<<mulOp<<' '<<ret<<' '<<tmpret<<' '<<tmp.x<<endl;
        }
//        cout<<op<<' '<<mulOp<<' '<<ret<<' '<<tmpret<<endl;
        ret = op=='+'? ret+tmpret:ret-tmpret;
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
