//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。 
//
// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。 
//
// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//输出：3
//解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//输出：0
//解释：所有 1 都在边界上或可以到达边界。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 500 
// grid[i][j] 的值为 0 或 1 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 172 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n,m;
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    int got;
    vector<vector<bool>> visit;
    bool ok(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
        visit[x][y]=true;
        if (got>=0) got++;
        for (int i=0;i<4;i++){
            int tmpx = x+dir[i][0];
            int tmpy = y+dir[i][1];
            if (!ok(tmpx,tmpy)) got=-1;
            if (ok(tmpx,tmpy) && !visit[tmpx][tmpy] && grid[tmpx][tmpy]==1){
                dfs(tmpx,tmpy, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        visit = vector < vector < bool >> (n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && grid[i][j] == 1) {
                    got = 0;
                    dfs(i, j, grid);
                    if (got >= 0) ans += got;
                }
            }
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
