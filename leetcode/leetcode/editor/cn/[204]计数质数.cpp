//给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 10
//输出：4
//解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
//
// 示例 2： 
//
// 
//输入：n = 0
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：n = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 5 * 10⁶ 
// 
// Related Topics 数组 数学 枚举 数论 👍 890 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
        vector<int> ans(n+1,0);
        vector<int> prime;
        for (int i=2;i<n;i++){
            if (ans[i]==0){
                prime.push_back(i);
                ans[i]=i;
            }
            for (int j=0;j<prime.size() && prime[j]<=i && prime[j]*i<n; j++){
                ans[prime[j]*i] = prime[j];
            }
        }
        return prime.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
