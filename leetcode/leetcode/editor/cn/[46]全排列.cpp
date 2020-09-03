//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(int step,vector<bool>& has,vector<int>& tmp,vector<int>& nums,vector<vector<int>>& ret,int n){
          if (step >= n) {
            ret.push_back(tmp);
            return ;
          }
          for (int i=0;i<n;i++){
            if (!has[i]){
              tmp[step] = nums[i];
              has[i]=true;
              dfs(step+1,has,tmp,nums,ret,n);
              has[i]=false;
            }
          }
          return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
      int n = nums.size();
//      vector<bool> has ;has.reserve(n);
//      vector<int> tmp ;tmp.reserve(n);
//      for (int i=0;i<n;i++) {
//        has.push_back(false);
//        tmp.push_back(0);
//      }
      vector<vector<int>> ret;
      long long ans = n;
      long long now =0;
      while (now<ans){
        ret.push_back(nums);
        next_permutation(nums.begin(),nums.end());
        now++;
        if (now<n) ans*=(n-now);
      }
//      dfs(0,has,tmp,nums,ret,n);
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
