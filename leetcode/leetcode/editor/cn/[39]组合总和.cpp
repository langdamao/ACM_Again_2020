//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(int step, int sum, vector<int>& now, vector<int>& candidates,int target){
        if (sum==target){
            ret.push_back(now);
            return;
        }
        if (step>=candidates.size()) return ;
        if (sum>target) return ;
        int num=0;
        while(sum<=target){
            dfs(step+1,sum,now,candidates,target);
            sum+=candidates[step];
            now.push_back(candidates[step]);
            num++;
        }
        for (int i=0;i<num;i++) now.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> now;
        dfs(0,0, now, candidates, target);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
