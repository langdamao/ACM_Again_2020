//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。 
//
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 示例 1: 
//
// 输入: [2,4,1], k = 2
//输出: 2
//解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
// 
//
// 示例 2: 
//
// 输入: [3,2,6,5,0,3], k = 2
//输出: 7
//解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 
//。
// 
// Related Topics 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const int int_min = -(1L<<30);
    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      if (n==0) return 0;
      if (k==0) return 0;
      if (k>n/2) {
        int ret=0;
        int now =prices[0];
        for (int i=1;i<n;i++){
          if (prices[i]>now){
            ret+=prices[i]-now;
          }
          now = prices[i];
        }
        return ret;
      }
      int dp[k+1][2];
      for (int i=0;i<=k;i++) {
        dp[i][0]=0;
        dp[i][1] = int_min;
      }
      for (int i=1;i<=n ;i++){
        dp[0][1] = max(dp[0][1],-prices[i-1]);
        for (int j=k;j>=1;j--){
            dp[j][1] = max(dp[j][1],dp[j][0]-prices[i-1]);
            dp[j][0] = max(dp[j][0],dp[j-1][1]+prices[i-1]);
//            cout<<i<<' '<<j<<' '<<dp[j][0]<<' '<<dp[j][1]<<endl;
        }
      }
      return dp[k][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
