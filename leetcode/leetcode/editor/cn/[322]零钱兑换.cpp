//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 
//
// 示例 1: 
//
// 输入: coins = [1, 2, 5], amount = 11
//输出: 3 
//解释: 11 = 5 + 5 + 1 
//
// 示例 2: 
//
// 输入: coins = [2], amount = 3
//输出: -1 
//
// 
//
// 说明: 
//你可以认为每种硬币的数量是无限的。 
// Related Topics 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      const int INT_MAX = amount*2+5;
      vector<int> dp(amount+1, INT_MAX);
      dp[0]=0;
        for (int i=0;i<n;i++){
          for (int j=coins[i];j<=amount;j++){
              dp[j] = min(dp[j], dp[j - coins[i]] + 1);
          }
        }
        return dp[amount]>=INT_MAX? -1:dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
