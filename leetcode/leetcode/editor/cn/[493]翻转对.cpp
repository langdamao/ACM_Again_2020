//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//
// 你需要返回给定数组中的重要翻转对的数量。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,3,1]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: [2,4,3,5,1]
//输出: 3
// 
//
// 注意: 
//
// 
// 给定数组的长度不会超过50000。 
// 输入数组中的所有数字都在32位整数的表示范围内。 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 353 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    static const int N = 1e5 +5;
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
    int sum(int x){
        int ret = 0;
        while(x>0){
            ret+=d[x];
            x-=lowbit(x);
        }
        return ret;
    }
    void MergeSort(vector<int>& nums, int l,int r, int& ret){
        if (l>=r-1) return ;
        int mid = (l+r)/2;
        MergeSort(nums, l, mid, ret);
        MergeSort(nums, mid, r, ret);
        merge(nums, l, r, mid , ret);
    }
    void merge (vector<int>& nums, int l, int r, int mid, int& ret){
        vector<int> tmp(nums.begin()+l, nums.begin()+r);
        int pl = 0;
        int pr = mid-l;
        int ppr = mid-l;
        for (int i = l; i<r; i++){
            if (pl >=mid-l){
                nums[i] = tmp[pr++];
            }
            else if (pr >= r-l){
                nums[i] = tmp[pl];
                while(ppr<r-l && (long long)tmp[ppr]*2< tmp[pl]) ppr++;
                ret += ppr+l-mid;
                pl++;

            }else if (tmp[pl]<=tmp[pr]){
                nums[i] = tmp[pl];
                while(ppr<r-l && (long long)tmp[ppr]*2< tmp[pl]) ppr++;
                ret += ppr+l-mid;
                pl++;
            }
            else {
                nums[i] = tmp[pr++];
            }
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int ret = 0;
        map<long long, int> ma;
        for (auto& x: nums){
            ma[x]=0;
            ma[(long long)x*2]=0;
        }
        int now=0;
        for (auto& x: ma){
            x.second = ++now;
        }
//      树状数组
        memset(d,0,sizeof(d));
        for (int i=n-1; i>=0; i--){
            ret += sum(ma[nums[i]]-1);
            update(ma[(long long)nums[i]*2]);
        }
//       归并排序
//        MergeSort(nums, 0, n, ret);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
