//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// '.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3: 
//
// 输入:
//s = "ab"
//p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4: 
//
// 输入:
//s = "aab"
//p = "c*a*b"
//输出: true
//解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5: 
//
// 输入:
//s = "mississippi"
//p = "mis*is*p*."
//输出: false 
// Related Topics 字符串 动态规划 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        vector<vector<bool>> dp(2,vector<bool>(lp+1,false));
        dp[0][0]=true;
        for (int j=2;j<=lp;j++){
            if (p[j-1]=='*') dp[0][j] = dp[0][j-2];
        }
        for (int i=1;i<=ls;i++){
            int t = i&1;
            dp[t][0] = false;
            for (int j=1;j<=lp;j++){
                char chP= p[j-1];
                if (chP=='*'){
                    dp[t][j] = ((dp[1^t][j] || dp[1^t][j-1]) && j!=1 && (s[i-1]==p[j-2] || p[j-2]=='.')) || (j!=1 && dp[t][j-2]);
                }
                else if (chP=='.'){
                   dp[t][j] = dp[1^t][j-1];
                }
                else {
                    dp[t][j] = dp[1^t][j-1] && chP==s[i-1];
                }
//                cout<<i<<' '<<j<<' '<<dp[t][j]<<endl;
            }
        }
        return dp[ls&1][lp];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
