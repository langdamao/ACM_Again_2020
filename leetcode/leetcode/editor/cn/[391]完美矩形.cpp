//给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是
// (xi, yi) ，右上顶点是 (ai, bi) 。 
//
// 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。 
// 
//
// 示例 1： 
//
// 
//输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
//输出：true
//解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
// 
//
// 示例 2： 
//
// 
//输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
//输出：false
//解释：两个矩形之间有间隔，无法覆盖成一个矩形。 
//
// 示例 3： 
//
// 
//输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
//输出：false
//解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。 
//
// 
//
// 提示： 
//
// 
// 1 <= rectangles.length <= 2 * 10⁴ 
// rectangles[i].length == 4 
// -10⁵ <= xi, yi, ai, bi <= 10⁵ 
// 
// Related Topics 数组 扫描线 👍 220 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool calmianji(vector<vector<int>>& rectangles){
        int minx = INT_MAX, miny = INT_MAX;
        int maxx = INT_MIN, maxy = INT_MIN;
        long long sum=0L;
        for (auto& x:rectangles){
            minx = min(minx,x[0]);
            miny = min(miny,x[1]);
            maxx = max(maxx,x[2]);
            maxy = max(maxy,x[3]);
            sum+=((long long)(x[2]-x[0]))*(x[3]-x[1]);
        }
//        cout<<sum<<' '<<((long long) maxx-minx)* (maxy-miny)<<endl;
        return sum == ((long long) maxx-minx)* (maxy-miny);
    }
    long long hashcode(int x,int y){
        return (x+1e5L)*1e6+(y+1e5);
    }
    bool adddian(int x,int y,int type, map<long long, int> & hash){
        long long tmp = hashcode(x,y);
        if ((hash[tmp] & (1<<type)) != 0 ) return false;
        hash[tmp] |= (1<<type);
        return true;
    }
    bool caldingdian(vector<vector<int>>& rectangles){
        map<long long, int> hash;
        for (auto & x:rectangles){
//            cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<x[3]<<endl;
            bool bad=true;
            bad = bad && adddian(x[0],x[1],0,hash);
            bad = bad && adddian(x[0],x[3],1,hash);
            bad = bad && adddian(x[2],x[3],2,hash);
            bad = bad && adddian(x[2],x[1],3,hash);

            if (!bad) {
//                cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<x[3]<<endl;
                return false;
            }
        }
        int ret=0;
        for (auto& x: hash){
            if (x.second ==1 || x.second==2 ||x.second ==4 || x.second==8 ||x.second ==7 || x.second==11||x.second ==13 || x.second==14) ret++;
//            cout<<x.first<<' '<<x.second<<endl;
        }
        return ret==4;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        return calmianji(rectangles) && caldingdian(rectangles);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
