//给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 
//upper）之内的 区间和的个数 。 
//
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。 
//
// 
//示例 1：
//
// 
//输入：nums = [-2,5,-1], lower = -2, upper = 2
//输出：3
//解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0], lower = 0, upper = 0
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// -10⁵ <= lower <= upper <= 10⁵ 
// 题目数据保证答案是一个 32 位 的整数 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 431 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    static const int N = 1e5*3 +5;
    int d[N];
    inline int lowbit(int x){
        return x&(-x);
    }
    void update(int x){
        while(x<N){
            d[x]+=1;
            x+=lowbit(x);
        }
    }
    int sumCal(int x){
        int ret = 0;
        while(x>0){
            ret+=d[x];
            x-=lowbit(x);
        }
        return ret;
    }
    void MergeSort(vector<long long>& nums, int l,int r, int& ret, int lower, int upper){
        if (l>=r-1) return ;
        int mid = (l+r)/2;
        MergeSort(nums, l, mid, ret, lower, upper);
        MergeSort(nums, mid, r, ret, lower, upper);
        merge(nums, l, r, mid , ret, lower, upper);
    }
    void merge (vector<long long>& nums, int l, int r, int mid, int& ret, int lower, int upper){
        vector<long long> tmp(nums.begin()+l, nums.begin()+r);
        int j = l;
        int k = l;
        for (int i = mid; i<r;i++){
            while(j<mid && nums[j]+upper<nums[i]) j++;
            while(k<mid && nums[k]+lower<=nums[i]) k++;
            ret+=k-j;
        }
        int pl = 0;
        int pr = mid-l;
        for (int i = l; i<r; i++){
            if (pl >=mid-l){
                nums[i] = tmp[pr++];
            }
            else if (pr >= r-l){
                nums[i] = tmp[pl++];

            }else if (tmp[pl]<=tmp[pr]){
                nums[i] = tmp[pl++];
            }
            else {
                nums[i] = tmp[pr++];
            }
        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n==0) return 0;
        int ret = 0;
//        map<long long, int> ma;
//        long long sum = 0L;
//        for (auto& x:nums){
//            sum+=x;
//            ma[sum]=0;
//            ma[sum-lower]=0;
//            ma[sum-upper]=0;
//        }
//        ma[0]=0;
//        int now=0;
//        for (auto& x: ma){
//            x.second = ++now;
//        }
////      树状数组
//        memset(d,0,sizeof(d));
//        update(ma[0]);
//        sum = 0L;
//        for (auto&x :nums){
//            sum+=x;
//            ret += sumCal(ma[sum-lower])-sumCal(ma[sum-upper]-1);
//            update(ma[sum]);
//        }
//       归并排序
        vector<long long> sums(n+1);
        sums[0]=0L;
        for (int i=0;i<n;i++){
            sums[i+1] = sums[i]+nums[i];
        }
        MergeSort(sums, 0, n+1, ret, lower, upper);
        return ret;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
