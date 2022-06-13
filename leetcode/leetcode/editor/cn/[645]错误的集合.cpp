//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有
//一个数字重复 。 
//
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。 
//
// 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2,4]
//输出：[2,3]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,1]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁴ 
// 1 <= nums[i] <= 10⁴ 
// 
// Related Topics 位运算 数组 哈希表 排序 👍 267 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i=0;i<n;i++){
            x^=nums[i];
            x^=(i+1);
        }
        int lb = x&(-x);
        int ans[2]={0,0};
        for (int i=0;i<n;i++){
            ans[((i+1)&lb)==0]^=(i+1);
            ans[(nums[i]&lb)==0]^=nums[i];
        }
        for (int i=0;i<n;i++){
            if (nums[i]==ans[1]) {
                swap(ans[0],ans[1]);
                break;
            }
        }
        return vector<int>(ans,ans+2);
//        int fu = -1;
//      for (int i=0;i<n;i++) {
//          if (nums[i]!=i+1){
//              int k = nums[i];
//              nums[i]=0;
//              while(nums[k-1] != 0) {
//                  if (nums[k-1] == k) {fu = k;break;}
//                  int next = nums[k- 1];
//                  nums[k - 1] = k;
//                  k = next;
//              }
//              nums[k-1] = k;
//          }
//      }
//      for (int i=0;i<n;i++){
//          if (nums[i]!=i+1) return {fu,i+1};
//      }
//      return {0,0};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
