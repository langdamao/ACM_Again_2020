//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
// Related Topics 回溯 👍 989 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(int step, int n,int k,vector<int>& now){
        if (now.size()==k) {
            ret.push_back(now);
            return ;
        }
        if (step>=n) return;
        if (now.size()<k) {
            now.push_back(step+1);
            dfs(step+1,n,k,now);
            now.pop_back();
        }
        if (k-now.size()<n-step){
            dfs(step+1,n,k,now);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> now;
        dfs(0,n,k,now);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
