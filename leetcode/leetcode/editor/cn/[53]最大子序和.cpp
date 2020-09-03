//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct ansT{
      ansT(){};
      ansT(int x):mid(x),l(x),r(x),sum(x){};
      int mid,l,r,sum;

    };
    ansT merge(ansT ans1,ansT ans2,int l,int r,int mid){
      ansT ret;
      ret.l = max(ans1.l,ans1.sum+ans2.l);
      ret.r = max(ans2.r,ans2.sum+ans1.r);
      ret.sum = ans1.sum+ans2.sum;
      ret.mid = max(ans1.mid,ans2.mid);
      ret.mid = max(ret.mid,ans1.r+ans2.l);
      return ret;
    }
    ansT find(int l,int r,vector<int>& nums){
      if (l==r) return ansT(nums[l]);
      int mid = (l+r)/2;
      ansT ans1 = find(l,mid,nums);
      ansT ans2 = find(mid+1,r,nums);
      return merge(ans1,ans2,l,r,mid);
    }
    int maxSubArray(vector<int>& nums) {
//      if (nums.empty()) return 0;
//      int now=0;
//      int ans=nums[0];
//      for (int x:nums){
//        now=max(0,now);
//        now+=x;
//        ans = max(ans,now);
//      }
//      return ans;
        return find(0,nums.size()-1,nums).mid;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
