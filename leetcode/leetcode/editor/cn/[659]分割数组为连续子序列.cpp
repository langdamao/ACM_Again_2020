//给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个长度至少为 3 的子序列，其中每个子序列都由连续整数组成。 
//
// 如果可以完成上述分割，则返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入: [1,2,3,3,4,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3
//3, 4, 5
// 
//
// 示例 2： 
//
// 
//输入: [1,2,3,3,4,4,5,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3, 4, 5
//3, 4, 5
// 
//
// 示例 3： 
//
// 
//输入: [1,2,3,4,4,5]
//输出: False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10000 
// 
// Related Topics 贪心 数组 哈希表 堆（优先队列） 👍 372 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        queue<int> q;
        int same = 0;
        int n =nums.size();
        nums.push_back(nums[n-1]+2);
        int i=0;
        while(i<=n){
            if (i!=0 && nums[i]!=nums[i-1]+1) {
                same=0;
                while(!q.empty()){
                    if (nums[i-1]-q.front()<2) return false;
                    q.pop();
                }
            }
            int num=1;
            while(i<n && nums[i+1]==nums[i]) { num++;i++;}
            for (int j=same;j<num;j++) q.push(nums[i]);
            for (int j=num;j<same;j++) {
                if (q.empty()) return false;
                int x = q.front();
                q.pop();
                if (nums[i]-x<3) return false;
            }
            same = num;
            i++;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
