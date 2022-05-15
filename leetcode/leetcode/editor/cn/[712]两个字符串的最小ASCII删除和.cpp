//给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。 
//
// 
//
// 示例 1: 
//
// 
//输入: s1 = "sea", s2 = "eat"
//输出: 231
//解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
//在 "eat" 中删除 "t" 并将 116 加入总和。
//结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
// 
//
// 示例 2: 
//
// 
//输入: s1 = "delete", s2 = "leet"
//输出: 403
//解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
//将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
//结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
//如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
// 
//
// 
//
// 提示: 
//
// 
// 0 <= s1.length, s2.length <= 1000 
// s1 和 s2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 269 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        vector<vector<int>> dp(2,vector<int>(l2+1,0));
        int sum =0;
        for (int i=1;i<=l2;i++){
            sum+=s2[i-1];
            dp[0][i] = sum;
        }
        for (int i=1;i<=l1;i++){
            int t = i&1;
            dp[t][0] = dp[t^1][0]+s1[i-1];
            for (int j=1;j<=l2;j++){
                dp[t][j] = min(dp[t][j-1]+s2[j-1],dp[t^1][j]+s1[i-1]);
                if (s1[i-1]==s2[j-1]){
                    dp[t][j]  = min(dp[t][j], dp[t^1][j-1]);
                }
            }
        }
        return dp[l1&1][l2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
