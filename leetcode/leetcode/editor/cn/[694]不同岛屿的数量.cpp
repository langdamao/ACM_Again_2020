//给定一个非空 01 二维数组表示的网格，一个岛屿由四连通（上、下、左、右四个方向）的 1 组成，你可以认为网格的四周被海水包围。 
//
// 请你计算这个网格中共有多少个形状不同的岛屿。两个岛屿被认为是相同的，当且仅当一个岛屿可以通过平移变换（不可以旋转、翻转）和另一个岛屿重合。 
//
// 
//
// 示例 1： 
//
// 11000
//11000
//00011
//00011
// 
//
// 给定上图，返回结果 1 。 
//
// 示例 2： 
//
// 11011
//10000
//00001
//11011 
//
// 给定上图，返回结果 3 。 
// 
//注意： 
//
// 11
//1
// 
//
// 和 
//
//  1
//11
// 
//
// 是不同的岛屿，因为我们不考虑旋转、翻转操作。 
//
// 
//
// 提示：二维数组每维的大小都不会超过 50 。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 哈希表 哈希函数 👍 126 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n,m;
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    string got;
    int minx,maxx,miny,maxy;
    unordered_map<string,bool> has;
    vector<vector<bool>> visit;
    vector<vector<bool>> now;
    bool ok(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void update(int x,int y){
        maxx = max(maxx,x);
        minx = min(minx,x);
        maxy = max(maxy,y);
        miny = min(miny,y);
        now[x][y]=true;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
        visit[x][y]=true;
        update(x,y);
        for (int i=0;i<4;i++){
            int tmpx = x+dir[i][0];
            int tmpy = y+dir[i][1];
            if (ok(tmpx,tmpy) && !visit[tmpx][tmpy] && grid[tmpx][tmpy]==1){
                dfs(tmpx,tmpy, grid);
            }
        }
    }
    string calCode(){
        string ret="";
        for (int i=minx;i<=maxx;i++){
            long long tmp =0L;
            for (int j=miny; j<=maxy;j++){
                tmp = (tmp<<1) + (now[i][j]?1:0);
            }
            ret.append(",").append(to_string(tmp));
        }
        return ret;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        if (n==0) return 0;
        m = grid[0].size();
        visit = vector<vector<bool>>(n,vector<bool>(m,false));
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!visit[i][j] && grid[i][j]==1){
                    now = vector<vector<bool>>(n,vector<bool>(m,false));
                    minx=i;maxx=i;miny=j;maxy=j;
                    dfs(i,j,grid);
                    got = calCode();
                    if (has[got]==false) ans++;
                    has[got]=true;
                }
            }
        }
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)
