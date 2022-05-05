//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 557 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void Mergesort(vector<int>& nums, int l, int r){
        if (l>=r-1) return ;
        int mid = (l+r)/2;
        Mergesort(nums, l, mid);
        Mergesort(nums, mid, r);
        merge(nums, l, r, mid);
    }
    void merge(vector<int>& nums, int l,int r, int mid){
        vector<int> tmp(nums.begin()+l, nums.begin()+r);
        int pl = 0;
        int pr = mid-l;
        for (int i = l;i<r;i++){
            if (pl>=mid-l){
                nums[i] = tmp[pr++];
            }
            else if (pr>=r-l){
                nums[i] = tmp[pl++];
            }else if (tmp[pl]<=tmp[pr]){
                nums[i] = tmp[pl++];
            }
            else {
                nums[i] = tmp[pr++];
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
       Mergesort(nums, 0, nums.size());
       return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
