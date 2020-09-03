//请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 
//
// 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2
//, 1, 1, 0, 0]。 
//
// 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。 
// Related Topics 栈 哈希表


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct node {
      node(int _i,int _x):i(_i),x(_x){};
      int x,i;
    };
    struct queue {
      int tail =0;
      vector<node> vec;
      void clear(){
        tail=0;
        vec.clear();
      }
      int size(){
        return tail;
      }
      void push_to(node x,int i){
        if (i<vec.size()) vec[i] = x;
        else vec.push_back(x);
      }
      void push_back(node x){
        while(tail>0 && vec[tail-1].x<=x.x){
          tail--;
        }
        push_to(x,tail);
        tail++;
      }
      node get(int x){
        if (x>=0) return vec[x];
        else return vec[tail+x];
      }
    };
    vector<int> dailyTemperatures(vector<int>& T) {
      vector<int> ret;
      int n = T.size();
      ret.reserve(n);
      for (int i=0;i<n;i++) ret.push_back(0);
      queue q;
      q.clear();
      for (int i=n-1;i>=0;i--){
         q.push_back(node(i,T[i]));
         if (q.size()>=2) {
           ret[i] = q.get(-2).i-i;
         }
      }
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
