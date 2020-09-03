//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(int step,vector<int>& tmp,vector<vector<int>>& ret,vector<int>& nums,int n){
      if (step>=n) {
        ret.push_back(tmp);
        return;
      }
      dfs(step+1,tmp,ret,nums,n);
      tmp.push_back(nums[step]);
      dfs(step+1,tmp,ret,nums,n);
      tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>ret;
      int n = nums.size();
      vector<int>tmp;
      dfs(0,tmp,ret,nums,n);
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
