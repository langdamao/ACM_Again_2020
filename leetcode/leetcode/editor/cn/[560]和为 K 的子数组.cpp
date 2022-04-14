//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1], k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3], k = 3
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -1000 <= nums[i] <= 1000 
// -10⁷ <= k <= 10⁷ 
// 
// Related Topics 数组 哈希表 前缀和 👍 1426 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> has;
        int sum=0,ans=0;
        has[0]=1;
        for (auto x:nums){
            sum+=x;
            if (has.find(sum-k)!=has.end()){
                ans +=has[sum-k];
            }
            has[sum]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
