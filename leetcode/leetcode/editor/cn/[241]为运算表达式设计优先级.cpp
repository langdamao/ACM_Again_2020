//给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：expression = "2-1-1"
//输出：[0,2]
//解释：
//((2-1)-1) = 0 
//(2-(1-1)) = 2
// 
//
// 示例 2： 
//
// 
//输入：expression = "2*3-4*5"
//输出：[-34,-14,-10,-10,10]
//解释：
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10
// 
//
// 
//
// 提示： 
//
// 
// 1 <= expression.length <= 20 
// expression 由数字和算符 '+'、'-' 和 '*' 组成。 
// 输入表达式中的所有整数值在范围 [0, 99] 
// 
// Related Topics 递归 记忆化搜索 数学 字符串 动态规划 👍 569 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> ret;
    vector<int> nums;
    vector<char> ops;
    int op(int x,int y,char op){
        if (op=='+') return x+y;
        if (op=='-') return x-y;
        if (op=='*') return x*y;
        return 0;
    }
    vector<int> dfs(int l,int r){
        if (l>=r) return {nums[l]};
        if (l==r-1) return {op(nums[l],nums[l+1],ops[l])};
        vector<int> ret;
        for (int i=l;i<r;i++){
            vector<int> left = dfs(l,i);
            vector<int> right = dfs(i+1,r);
            for (auto & x:left){
                for (auto & y: right){
                    ret.push_back(op(x,y, ops[i]));
                }
            }
        }
        return ret;
    }
    bool isNum(char ch){
        if (ch>='0' && ch<='9') return true;
        return false;
    }
    vector<int> diffWaysToCompute(string expression) {
        int i=0;
        while(i<expression.length()){
            if (!isNum(expression[i])){
                ops.push_back(expression[i]);
                i++;
            }
            else {
                int x=0;
                while(i<expression.length() && isNum(expression[i])){
                    x =x*10+expression[i]-'0';
                    i++;
                }
                nums.push_back(x);
            }
        }
        //return dfs(0,ops.size());
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size()));
        for (int i=0;i<nums.size();i++) dp[i][i]={nums[i]};
        for(int l=1;l<nums.size();l++){ //长度
            for (int i=0;i+l<nums.size();i++){
                int j= i+l;
                for (int s = 0;s<j;s++){
                    for (auto & x:dp[i][s]){
                        for (auto & y:dp[s+1][j]){
                            dp[i][j].push_back(op(x,y,ops[s]));
                        }
                    }
                }
            }
        }
        return dp[0][ops.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
