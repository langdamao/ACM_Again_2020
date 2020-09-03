//给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。 
//
// 
//
// 示例 1: 
//输入: 
//
// "bbbab"
// 
//
// 输出: 
//
// 4
// 
//
// 一个可能的最长回文子序列为 "bbbb"。 
//
// 示例 2: 
//输入: 
//
// "cbbd"
// 
//
// 输出: 
//
// 2
// 
//
// 一个可能的最长回文子序列为 "bb"。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 只包含小写英文字母 
// 
// Related Topics 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int len = s.length();
      if (len<=1) return len;
      int dp[2][len];
      memset(dp,0,sizeof(dp));
      for (int i=len-2;i>=0;i--){
            int t = i&1;
            dp[t][i]=1;
            for (int j=i+1;j<len;j++){
                  dp[t][j]=max(dp[t^1][j],dp[t][j-1]);
                  if (s[i]==s[j])
                        dp[t][j]=max(dp[t][j],dp[t^1][j-1]+2);
            }
      }
      return dp[0][len-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
