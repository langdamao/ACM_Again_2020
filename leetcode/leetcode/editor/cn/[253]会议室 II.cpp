//给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 
//所需会议室的最小数量 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[0,30],[5,10],[15,20]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[7,10],[2,4]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// 0 <= starti < endi <= 10⁶ 
// 
// Related Topics 贪心 数组 双指针 排序 堆（优先队列） 👍 435 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct cmp{
        bool operator() (const vector<int>& x,const vector<int>& y) const{
            if (x[1] != y[1]) return x[1] < y[1];
            return x[0] < y[0];
        };
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x,const vector<int>& y){
            if (x[0]!=y[0]) return x[0]<y[0];
            return x[1]>y[1];
        });
        multiset<vector<int>,cmp> q;
        int ret =0;
        for (auto& x: intervals){
            q.insert(x);
            while(!q.empty() && (*q.begin())[1]<=x[0]) q.erase(q.begin());
            ret = max(ret, (int)q.size());
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
