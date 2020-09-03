//给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。 
//
// 
//
// 示例 1： 
//
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出：true
// 
//
// 示例 2： 
//
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//输出：false 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int l1 = s1.length();
      int l2 = s2.length();
      vector<bool> dp[2]={vector<bool>(l2+1,false),vector<bool>(l2+1,false)};
      dp[0][0]=true;
      for (int i=0;i<=l1;i++){
        for (int j=0;j<=l2;j++){
          if (i==0 && j==0) continue;
          int t = i&1;
          bool tmp = false;
          if (i!=0) tmp = tmp || (dp[t^1][j]&&s1[i-1]==s3[i+j-1]);
          if (j!=0) tmp = tmp || (dp[t][j-1]&&s2[j-1]==s3[i+j-1]);
          dp[t][j] = tmp;
        }
      }
      return dp[l1&1][l2] && l1+l2==s3.length();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
