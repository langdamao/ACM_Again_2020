//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    int n;
    int next(int x,int k,int delta, vector<int>& nums){
        while (x>=0 && x<n &&nums[x]==k) x+=delta;
        return x;
    }
    void find(int begin,int end, int k, vector<int>& nums){
        int i=begin;
        int j = end-1;
        while(i<j && i<end && j>=begin){
            int x = nums[i]+nums[j];
            if (x==k) {
                ret.push_back({-k,nums[i],nums[j]});
                i = next(i,nums[i],1,nums);
                j = next(j,nums[j],-1,nums);
            }
            else if (x<k) i = next(i,nums[i],1,nums);
            else j = next(j,nums[j],-1,nums);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
          n = nums.size();
          sort(nums.begin(),nums.end());
          for (int i=0;i<n;i++){
              find(i+1,n,-nums[i], nums);
              while(i+1<n&&nums[i+1]==nums[i]) i++;
          }
          return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
