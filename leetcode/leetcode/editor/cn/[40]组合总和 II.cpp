//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
// Related Topics 数组 回溯 👍 974 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    vector<bool> has;
    void dfs(int step, int sum, vector<int>& now, vector<int>& candidates,int target){
        if (sum==target){
            ret.push_back(now);
            return;
        }
        if (step>=candidates.size()) return ;
        if (sum>target) return;
        dfs(step+1,sum,now,candidates,target);
        if (step==0 || candidates[step]!=candidates[step-1] || has[step-1]) {
            has[step]=true;
            now.push_back(candidates[step]);
            dfs(step + 1, sum + candidates[step], now, candidates, target);
            now.pop_back();
            has[step]=false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> now;
        has = vector<bool>(candidates.size(), false);
        dfs(0,0, now, candidates, target);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
