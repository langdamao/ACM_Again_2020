//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Mar
//cos 贡献此图。 
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    inline long long abs(int x){
      if (x>0) return (long long )x;
      return (long long)-x;
    }
    struct node{
      node(int _h,int _x):h(_h),x(_x){};
      int h,x;
    };
    struct que{
      int tail;
      vector<node> a;
      void clear(int size){
        tail = 0;
        a.reserve(size);
      }
      bool empty(){
        return tail==0;
      }
      node get_tail() {
        if (tail>0)
        return a[tail-1];
        else return node(0,0);
      }
      void del_tail(){
        tail--;
      }
      void insert_back(node x){
        a[tail++]=x;
      }
    }q;
    int trap(vector<int>& height) {
        int n = height.size();
        q.clear(n);
        long long ans =0;
        for (int i=0;i<n;i++){
            int last_top = q.get_tail().h;
            while(!q.empty()){
     //         cout<<i<<' '<<q.get_tail().h<<' '<<q.get_tail().x<<' '<<ans<<endl;
              ans += abs(min(q.get_tail().h,height[i]) -last_top)*(i-q.get_tail().x-1);
              if (q.get_tail().h<=height[i]){
                last_top = q.get_tail().h;
                q.del_tail();
              }
              else break;
            }
            q.insert_back(node(height[i],i));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
