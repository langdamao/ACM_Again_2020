//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[
//b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）： 
//
// 
// 0 <= a, b, c, d < n 
// a、b、c 和 d 互不相同 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// 你可以按 任意顺序 返回答案 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,2,2,2,2], target = 8
//输出：[[2,2,2,2]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
// Related Topics 数组 双指针 排序 👍 1248 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    int n;
    int next(int x,int k,int delta, vector<int>& nums){
        while (x>=0 && x<n &&nums[x]==k) x+=delta;
        return x;
    }
    void find(int begin,int end, int k, int xx,int yy, vector<int>& nums){
        int i=begin;
        int j = end-1;
        while(i<j && i<end && j>=begin){
            int x = nums[i]+nums[j];
            if (x==k) {
                ret.push_back({xx,yy,nums[i],nums[j]});
                i = next(i,nums[i],1,nums);
                j = next(j,nums[j],-1,nums);
            }
            else if (x<k) i = next(i,nums[i],1,nums);
            else j = next(j,nums[j],-1,nums);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0;i<n;i=next(i,nums[i],1,nums)){
            for (int j=i+1;j<n;j=next(j,nums[j],1,nums)){
                find(j+1,n,target-nums[i]-nums[j], nums[i], nums[j], nums);
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
