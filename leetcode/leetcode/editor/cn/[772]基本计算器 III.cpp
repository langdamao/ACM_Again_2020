//实现一个基本的计算器来计算简单的表达式字符串。 
//
// 表达式字符串只包含非负整数，算符 +、-、*、/ ，左括号 ( 和右括号 ) 。整数除法需要 向下截断 。 
//
// 你可以假定给定的表达式总是有效的。所有的中间结果的范围为 [-2³¹, 2³¹ - 1] 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "1+1"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：s = "6-4/2"
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：s = "2*(5+5*2)/3+(6/2+8)"
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：s = "(2+6*3+5-(3*14/7+2)*5)+3"
//输出：-12
// 
//
// 示例 5： 
//
// 
//输入：s = "0"
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s <= 10⁴ 
// s 由整数、'+'、'-'、'*'、'/'、'(' 和 ')' 组成 
// s 是一个 有效的 表达式 
// 
//
// 
//
// 进阶：你可以在不使用内置库函数的情况下解决此问题吗？ 
// Related Topics 栈 递归 数学 字符串 👍 114 👎 0


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
