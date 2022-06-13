//给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向 （水平或者竖
//直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。 
//
// 如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1 中同一个岛屿完全包含，那
//么我们称 grid2 中的这个岛屿为 子岛屿 。 
//
// 请你返回 grid2 中 子岛屿 的 数目 。 
//
// 
//
// 示例 1： 
//
// 输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], 
//grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
//输出：3
//解释：如上图所示，左边为 grid1 ，右边为 grid2 。
//grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
// 
//
// 示例 2： 
//
// 输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], 
//grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
//输出：2 
//解释：如上图所示，左边为 grid1 ，右边为 grid2 。
//grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
// 
//
// 
//
// 提示： 
//
// 
// m == grid1.length == grid2.length 
// n == grid1[i].length == grid2[i].length 
// 1 <= m, n <= 500 
// grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 56 👎 0


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
    void dfs(int x,int y,vector<vector<int>>& grid, vector<vector<int>>& grid1){
        visit[x][y]=true;
        if (grid1[x][y]!=1) got=true;
        for (int i=0;i<4;i++){
            int tmpx = x+dir[i][0];
            int tmpy = y+dir[i][1];
            if (ok(tmpx,tmpy) && !visit[tmpx][tmpy] && grid[tmpx][tmpy]==1){
                dfs(tmpx,tmpy, grid,grid1);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        if (n == 0) return 0;
        m = grid2[0].size();
        visit = vector < vector < bool >> (n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && grid2[i][j] == 1) {
                    got=false;
                    dfs(i, j, grid2, grid1);
                    if (!got) ans ++;
                }
            }
        }
        return ans;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
