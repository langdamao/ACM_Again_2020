//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 如果数组中不存在目标值，返回 [-1, -1]。 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4] 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1] 
// Related Topics 数组 二分查找


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findbigFirst(vector<int>& nums,int x){
      int head=0;
      int tail = nums.size()-1;
      while(head<=tail){
        int mid =(head+tail)/2;
        if (nums[mid]>=x){
          tail = mid-1;
        }
        else {
          head=mid+1;
        }
      }
      if (head<nums.size() && nums[head]==x)
      return head;
      else return -1;
    }
    int findlowLast(vector<int>& nums,int x){
      int head=0;
      int tail = nums.size()-1;
      while(head<=tail){
        int mid = (head+tail)/2;
        if (nums[mid]<=x){
          head = mid+1;
        }
        else {
          tail = mid-1;
        }
      }
      if (tail>=0 && nums[tail]==x)
      return tail;
      else return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ret;
      ret.push_back(findbigFirst(nums,target));
      ret.push_back(findlowLast(nums,target));
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
