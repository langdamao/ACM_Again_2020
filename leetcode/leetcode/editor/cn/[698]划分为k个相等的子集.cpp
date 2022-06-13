//给定一个整数数组 nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。 
//
// 
//
// 示例 1： 
//
// 
//输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。 
//
// 示例 2: 
//
// 
//输入: nums = [1,2,3,4], k = 3
//输出: false 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= len(nums) <= 16 
// 0 < nums[i] < 10000 
// 每个元素的频率在 [1,4] 范围内 
// 
// Related Topics 位运算 记忆化搜索 数组 动态规划 回溯 状态压缩 👍 563 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool dfs(int now,vector<int>& sums, int num,int each,int n,vector<int>& nums){
        if (now==n) return true;
        for (int i=0;i<sums.size()+1 && i<num;i++){
            int x = i==sums.size()? 0:sums[i];
            if (nums[now]+x<=each){
                if (i==sums.size()) sums.push_back(0);
                sums[i]=nums[now]+x;
                if (dfs(now+1,sums,num,each,n,nums)) return true;
                sums[i]=x;
                if (x==0) sums.pop_back();
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for (auto& x:nums){
            sum+=x;
        }
        if (sum%k) return false;
        vector<int> sums;
        return dfs(0,sums,k,sum/k,nums.size(),nums);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
