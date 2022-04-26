//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。 
//
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 进阶： 
//
// 你能在线性时间复杂度内解决此题吗？ 
//
// 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    struct node {
//      int wei;int x;
//    };
//    struct que{
//       vector<node> v;
//       int tail = 0;
//       int head= 0;
//       void clear(){
//         tail=0;
//         head = 0;
//       }
//       void insert(node tmp){
////         cout<<tail<<endl;
//         if (v.size() >tail){
//           v[tail] = tmp;
//         }
//         else v.push_back(tmp);
//         tail++;
//       }
//       void push_back(int wei,int x){
//         node tmp ;tmp.wei=wei;tmp.x=x;
//         while(tail>head && v[tail-1].x<=tmp.x){
//           tail--;
//         }
//         insert(tmp);
//       }
//       node top(int x){
//         while(head<tail && v[head].wei<x){
////           cout<<head<<' '<<v[head].wei<<' '<<v[head].x<<endl;
//           head++;
//         }
//         return v[head];
//       }
//
//    }q;
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//      q.clear();
//      for (int i=0;i<k-1;i++){
//        q.push_back(i,nums[i]);
//      }
//      vector<int> ret;
//      int n= nums.size();
//      for (int i=k-1;i<n;i++){
////        cout<<i<<' '<<nums[i]<<endl;
//        q.push_back(i,nums[i]);
//        ret.push_back(q.top(i-k+1).x);
//      }
//      return ret;
//    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> st;
       vector<int> ret(nums.size()-k+1);
       for (int i=0; i<nums.size(); i++){
           while(!st.empty() && nums[st.back()] <= nums[i]) st.pop_back();
           while(!st.empty() && i-st.front() >= k) st.pop_front();
           st.push_back(i);
           if(i >= k-1){
               ret[i-k+1] = nums[st.front()];
           }
       }
       return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
