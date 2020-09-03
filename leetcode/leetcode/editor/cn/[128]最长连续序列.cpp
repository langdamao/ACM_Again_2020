//给定一个未排序的整数数组，找出最长连续序列的长度。 
//
// 要求算法的时间复杂度为 O(n)。 
//
// 示例: 
//
// 输入: [100, 4, 200, 1, 3, 2]
//输出: 4
//解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。 
// Related Topics 并查集 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    std::unordered_map<int,int> a;
    int find(int x){
       if (a.count(x)) {
         int k = find(a[x]);
         a[x] = k;
         return k;
       }
       else return x;
    }
    int longestConsecutive(vector<int>& nums) {
       for (auto i :nums){
           a[i]=i+1;
       }
       int ans=0;
       for (auto i:nums){
          int tmp = find(i);
          ans = max(ans,tmp-i);
       }
       return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
