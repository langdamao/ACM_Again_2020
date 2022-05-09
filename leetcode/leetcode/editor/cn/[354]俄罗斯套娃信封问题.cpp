//给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。 
//
// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。 
//
// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。 
//
// 注意：不允许旋转信封。 
// 
//
// 示例 1： 
//
// 
//输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
//输出：3
//解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。 
//
// 示例 2： 
//
// 
//输入：envelopes = [[1,1],[1,1],[1,1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= envelopes.length <= 10⁵ 
// envelopes[i].length == 2 
// 1 <= wi, hi <= 10⁵ 
// 
// Related Topics 数组 二分查找 动态规划 排序 👍 717 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(const vector<int>& x,const vector<int>&y){
        if (x[0]!=y[0]) return x[0]<y[0];
        return x[1]>y[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n==0) return 0;
       sort(envelopes.begin(),envelopes.end(),cmp);
       vector<int> low ;
       for (int i=0;i<n;i++){
           int k = lower_bound(low.begin(), low.end(), envelopes[i][1])-low.begin();
           if (k<low.size()) low[k] = envelopes[i][1];
           else low.push_back(envelopes[i][1]);
       }
       return low.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
