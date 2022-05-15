//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。 
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 
//
// 你可以假设 nums1 和 nums2 不会同时为空。 
//
// 
//
// 示例 1: 
//
// nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
// 
//
// 示例 2: 
//
// nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
// 
// Related Topics 数组 二分查找 分治算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double getZhongwei(vector<int>& arr){
        int n = arr.size();
        return (arr[n/2]+arr[(n-1)/2])/2.0;
    }
    int get(vector<int>& arr, int i){
        if (i<0) return INT_MIN;
        if (i>=arr.size()) return INT_MAX;
        return arr[i];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()==0) return getZhongwei(nums2);
        if (nums2.size()==0) return getZhongwei(nums1);
        int k = (nums1.size()+nums2.size()+1)/2;
        if (nums1.size()<nums2.size()) nums1.swap(nums2);
        int head = 0; int tail = nums1.size();
        while(head<=tail){
            int mid = (head+tail)/2;
//            cout<<head<<' '<<tail<<' '<<mid<<' '<<k-mid<<endl;
//            cout<<get(nums1,mid-1)<<' '<<get(nums2,k-mid)<<endl;
            if (get(nums1,mid-1) < get(nums2,k-mid)){
                head = mid+1;
            }
            else {
                tail = mid-1;
            }
//            cout<<head<<' '<<tail<<' '<<mid<<' '<<k-mid<<endl;
        }
        int i  = tail-1; int j = k-(i+1)-1;
        cout<<i<<' '<<j<<' '<<tail<<' '<<nums1[0]<<endl;
        if ((nums1.size()+nums2.size())&1==1) return max(get(nums1,i),get(nums2,j));
        else return (max(get(nums1,i),get(nums2,j))+ min(get(nums1,i+1),get(nums2,j+1)))/2.0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
