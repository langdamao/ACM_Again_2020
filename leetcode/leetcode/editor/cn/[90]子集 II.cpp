//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// 
// 
// Related Topics 位运算 数组 回溯 👍 834 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(int step, vector<pair<int,int>>& numsV, vector<int>& now){
//        cout<<"step: "<<step<<' '<<endl;
//        for (auto& x: now) cout<<x<<' ';cout<<endl;
        if (step>=numsV.size()) {
            ret.push_back(now);
            return ;
        }
        int n = numsV[step].second;
        int x = numsV[step].first;
        for (int i=0;i<=n;i++){
            dfs(step+1, numsV, now);
            now.push_back(x);
        }
        for (int i=0;i<=n;i++) now.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> numsMap;
        for (auto& x: nums) numsMap[x]++;
        vector<pair<int,int>> numsV(numsMap.begin(),numsMap.end());
        vector<int> now;
        dfs(0,numsV,now);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
