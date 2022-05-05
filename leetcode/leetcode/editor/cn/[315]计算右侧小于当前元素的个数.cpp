//给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 
//nums[i] 的元素的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 示例 2： 
//
// 
//输入：nums = [-1]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：nums = [-1,-1]
//输出：[0,0]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 799 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static const int N = 1e4 * 2 +5;
    static const int MINX =1e4 +1;
    int d[N];
    inline int lowbit(int x){
        return x&(-x);
    }
    void update(int x){
        x += MINX;
        while(x<N){
            d[x]+=1;
            x+=lowbit(x);
        }
    }
    int sum(int x){
        x+=MINX;
        int ret = 0;
        while(x>0){
            ret+=d[x];
            x-=lowbit(x);
        }
        return ret;
    }
    struct Node{
        int val=0,id=0;
        Node(){}
        Node(int _val, int _id):val(_val),id(_id){}
    };
    void MergeSort(vector<Node>& nums, int l,int r, vector<int>& ret){
        if (l>=r-1) return ;
        int mid = (l+r)/2;
        MergeSort(nums, l, mid, ret);
        MergeSort(nums, mid, r, ret);
        merge(nums, l, r, mid , ret);
    }
    void merge (vector<Node>& nums, int l, int r, int mid, vector<int>& ret){
        vector<Node> tmp(nums.begin()+l, nums.begin()+r);
        int pl = 0;
        int pr = mid-l;
        for (int i = l; i<r; i++){
            if (pl >=mid-l){
                nums[i] = tmp[pr++];
            }
            else if (pr >= r-l){
                nums[i] = tmp[pl];
                ret[tmp[pl++].id] += pr+l-mid;

            }else if (tmp[pl].val<=tmp[pr].val){
                nums[i] = tmp[pl];
                ret[tmp[pl++].id] += pr+l-mid;
            }
            else {
                nums[i] = tmp[pr++];
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return nums;
        vector<int> ret(n,0);
//      树状数组
//        memset(d,0,sizeof(d));
//        for (int i=n-1; i>=0; i--){
//            ret[i] = sum(nums[i]-1);
//            update(nums[i]);
//        }
        vector<Node> arr(n);
        for (int i =0;i<n;i++){
            arr[i] = Node(nums[i],i);
        }
        MergeSort(arr, 0, n,ret);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
