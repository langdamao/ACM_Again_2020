//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？ 
//
// 示例: 
//
// 输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3 
// Related Topics 树 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static const int N = 1e5+5;
    int f[N];
    int numTrees(int n) {
        //卡特兰数
        long long ret = 1L;
        for (int i=1;i<=n;i++){
            ret = (long long)2L*(2*i-1)*ret/(i+1);
        }
        return ret;
        if (f[n]!=0) return f[n];
        if (n==0) return 1;
        if (n==1) return 1;
        ret = 0;
        for (int i=0;i<n;i++){
            ret+= numTrees(i)* numTrees(n-i-1);
        }
        return f[n]=ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
