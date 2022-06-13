//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 数组 回溯 👍 1073 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    vector<bool> has;
    void dfs(int step,vector<int>& now,vector<int>&nums){
        if (step == nums.size()) {
            ret.push_back(now);
            return ;
        }
        for (int i=0;i<nums.size();i++){
            if (!has[i] && (i==0 || nums[i]!=nums[i-1] || has[i-1])){
                has[i]=true;
                now.push_back(nums[i]);
                dfs(step+1,now,nums);
                now.pop_back();
                has[i]=false;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        has = vector<bool> (nums.size(),false);
        vector<int> now;
        dfs(0,now,nums);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
