//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
// 
// 
// Related Topics 数组 回溯 👍 1353 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<bool>> has;
    int _n;
    bool ok(int x,int y){
        return !has[x][0] && !has[y][1] && !has[x+y][2] && !has[x-y+_n][3];
    }
    void mark(int x,int y){
        markWithType(x,y, true);
    }
    void unmark(int x,int y){
        markWithType(x,y, false);
    }
    void markWithType(int x,int y, bool type){
        has[x][0]=type;
        has[y][1]=type;
        has[x+y][2]=type;
        has[x-y+_n][3]=type;
    }
    void add2Ans(vector<pair<int,int>> now){
        vector<string> tmp(_n,string(_n,'.'));
        for (auto& x: now){
            tmp[x.first][x.second] = 'Q';
        }
        ret.push_back(tmp);
    }
    void dfs(int step, vector<pair<int,int>> now){
        if (step == _n) add2Ans(now);
        for (int i=0;i<_n;i++){
            if (ok(step,i)){
                mark(step,i);
                now.push_back(make_pair(step,i));
                dfs(step+1,now);
                now.pop_back();
                unmark(step,i);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        has = vector<vector<bool>>(n+n+1,vector<bool>(4,false));
        vector<pair<int,int>> now;
        dfs(0,now);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
