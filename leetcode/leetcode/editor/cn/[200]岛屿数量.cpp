//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1740 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n,m;
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    vector<vector<bool>> visit;
    bool ok(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int x,int y,vector<vector<char>>& grid){
        visit[x][y]=true;
        for (int i=0;i<4;i++){
            int tmpx = x+dir[i][0];
            int tmpy = y+dir[i][1];
            if (ok(tmpx,tmpy) && !visit[tmpx][tmpy] && grid[tmpx][tmpy]=='1'){
                dfs(tmpx,tmpy, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n==0) return 0;
        m = grid[0].size();
        visit = vector<vector<bool>>(n,vector<bool>(m,false));
        int ans;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!visit[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
