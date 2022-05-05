//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 1651 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int find(vector<int>& nums, int l,int r, int k){
        if (l>=r) return nums[l];
        swap(nums[l],nums[rand()%(r-l+1)+l]);
        int flag = nums[l];
        int i = l+1, j = r;
        while(i<=j){
            while(i<r && nums[i]<=flag) i++;
            while(j>l && nums[j]>flag) j--;
            if (i>=j) break;
            swap(nums[i],nums[j]);
        }
        swap(nums[j],nums[l]);
        if (r-j+1 == k) return nums[j];
        else if (r-j+1>k) return find(nums,j+1,r,k);
        else return find(nums,l,j-1,k-(r-j+1));

    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return find(nums,0,nums.size()-1,k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
