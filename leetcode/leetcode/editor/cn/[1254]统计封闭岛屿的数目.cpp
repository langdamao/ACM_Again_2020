//二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。 
//
// 请返回 封闭岛屿 的数目。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,
//0,1],[1,1,1,1,1,1,1,0]]
//输出：2
//解释：
//灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。 
//
// 示例 2： 
//
// 
//
// 
//输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：grid = [[1,1,1,1,1,1,1],
//             [1,0,0,0,0,0,1],
//             [1,0,1,1,1,0,1],
//             [1,0,1,0,1,0,1],
//             [1,0,1,1,1,0,1],
//             [1,0,0,0,0,0,1],
//             [1,1,1,1,1,1,1]]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length, grid[0].length <= 100 
// 0 <= grid[i][j] <=1 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 139 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n,m;
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    bool got;
    vector<vector<bool>> visit;
    bool ok(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
        visit[x][y]=true;
        for (int i=0;i<4;i++){
            int tmpx = x+dir[i][0];
            int tmpy = y+dir[i][1];
            if (!ok(tmpx,tmpy)) got = true;
            if (ok(tmpx,tmpy) && !visit[tmpx][tmpy] && grid[tmpx][tmpy]==0){
                dfs(tmpx,tmpy, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n==0) return 0;
        m = grid[0].size();
        visit = vector<vector<bool>>(n,vector<bool>(m,false));
        int ans;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!visit[i][j] && grid[i][j]==0){
                    got = false;
                    dfs(i,j,grid);
                    if (!got) ans++;
                }
            }
        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
