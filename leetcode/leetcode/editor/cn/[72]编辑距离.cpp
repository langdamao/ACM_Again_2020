//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
      int l1= word1.length();
      int l2= word2.length();
      vector<vector<int> > dp(2,vector<int>(l2+1,0));
      for (int j=0;j<=l2;j++) dp[0][j]=j;
      for (int i=1;i<=l1;i++){
         dp[i&1][0]=i;
        for (int j=1;j<=l2;j++){
            int t = i&1;
          dp[t][j] = min(dp[t][j-1]+1,dp[t^1][j]+1);
          if (word1[i-1]==word2[j-1]){
            dp[t][j] = min(dp[t^1][j-1],dp[t][j]);
          }else {
            dp[t][j]= min(dp[t][j],dp[t^1][j-1]+1);
          }
        }
      }
      return dp[l1&1][l2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
