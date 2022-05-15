//给定两个单词 word1 和 word2 ，返回使得 word1 和 word2 相同所需的最小步数。 
//
// 每步 可以删除任意一个字符串中的一个字符。 
//
// 
//
// 示例 1： 
//
// 
//输入: word1 = "sea", word2 = "eat"
//输出: 2
//解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
// 
//
// 示例 2: 
//
// 
//输入：word1 = "leetcode", word2 = "etco"
//输出：4
// 
//
// 
//
// 提示： 
// 
//
// 
// 1 <= word1.length, word2.length <= 500 
// word1 和 word2 只包含小写英文字母 
// 
// Related Topics 字符串 动态规划 👍 417 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        vector< vector<int> > dp(2,vector<int>(l2+1,0));
        for (int i=0;i<l1;i++){
            for (int j=0;j<l2;j++){
                int t = i&1;
                dp[t][j+1] = max(dp[t^1][j+1],dp[t][j]);
                if (word1[i]==word2[j]){
                    dp[t][j+1] = max(dp[t][j+1],dp[t^1][j]+1);
                }
            }
        }
        return l1+l2-dp[(l1&1)^1][l2]*2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
