//在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示。一次 移动 定义为选择 0 与一个相邻的数字（
//上下左右）进行交换. 
//
// 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。 
//
// 给出一个谜板的初始状态 board ，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：board = [[1,2,3],[4,0,5]]
//输出：1
//解释：交换 0 和 5 ，1 步完成
// 
//
// 示例 2: 
//
// 
//
// 
//输入：board = [[1,2,3],[5,4,0]]
//输出：-1
//解释：没有办法完成谜板
// 
//
// 示例 3: 
//
// 
//
// 
//输入：board = [[4,1,2],[5,0,3]]
//输出：5
//解释：
//最少完成谜板的最少移动次数是 5 ，
//一种移动路径:
//尚未移动: [[4,1,2],[5,0,3]]
//移动 1 次: [[4,1,2],[0,5,3]]
//移动 2 次: [[0,1,2],[4,5,3]]
//移动 3 次: [[1,0,2],[4,5,3]]
//移动 4 次: [[1,2,0],[4,5,3]]
//移动 5 次: [[1,2,3],[4,5,0]]
// 
//
// 
//
// 提示： 
//
// 
// board.length == 2 
// board[i].length == 3 
// 0 <= board[i][j] <= 5 
// board[i][j] 中每个值都 不同 
// 
// Related Topics 广度优先搜索 数组 矩阵 👍 259 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct Node{
        vector<int> board;
        int step;
        int ling;
        Node(){};
        Node(vector<int>_b, int _l,int _s):board(_b),ling(_l),step(_s){};
        void findLing(){
            for (int i=0;i<board.size();i++){
                if (board[i]==0) {
                    ling = i;
                    return ;
                }
            }
        }
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<int>, int> has;
        vector<vector<int>> huan{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        vector<int> final = {{1,2,3,4,5,0}};
        queue<Node> q;
        vector<int> boardV(board[0].begin(),board[0].end());
        boardV.insert(boardV.end(),board[1].begin(),board[1].end());
        has[boardV]=1;
        q.push(Node(boardV,-1,1));
        q.front().findLing();
        while(!q.empty()){
            Node node = q.front();
            q.pop();
            if (has[final]!=0) return has[final]-1;
            for (int i=0;i<huan[node.ling].size();i++){
                int tmp = huan[node.ling][i];
                vector<int> tmpV(node.board.begin(),node.board.end());
                swap(tmpV[node.ling],tmpV[tmp]);
                if (!has[tmpV]) q.push(Node(tmpV,tmp,node.step+1));
                has[tmpV] = node.step+1;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
