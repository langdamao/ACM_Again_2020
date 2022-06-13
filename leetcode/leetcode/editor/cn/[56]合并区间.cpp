//给出一个区间的集合，请合并所有重叠的区间。 
//
// 示例 1: 
//
// 输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
// Related Topics 排序 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(), [](const vector<int>& x,const vector<int>& y){
           if (x[0]!=y[0]) return x[0]<y[0];
           return x[1]<y[1];
       });
        vector<vector<int>> ret;
       int n = intervals.size();
       if (n==0) return ret;
       vector<int> now = {INT_MAX,-1};
       for (auto & x:intervals){
           if (x[0]<=now[1] || now[1]==-1) {
               now[0]=min(x[0],now[0]);
               now[1]=max(x[1],now[1]);
           }
           else {
               ret.push_back(now);
               now = x;
           }
       }
       ret.push_back(now);
       return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
