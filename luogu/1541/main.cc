#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
int a[350];
int b[4];
int dp[41][41][41][41];
int cal(int i, int j, int k, int h) { return i + j * 2 + k * 3 + h * 4; }
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    int tmp;
    for (int i = 0; i < 4; i++)
      b[i] = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", &tmp);
      b[tmp - 1]++;
    }
    dp[0][0][0][0] = a[0];
    for (int i = 0; i <= b[0]; i++) {
      for (int j = 0; j <= b[1]; j++) {
        for (int k = 0; k <= b[2]; k++) {
          for (int h = 0; h <= b[3]; h++) {
            int tmp = 0;
            if (i > 0)
              tmp = max(tmp, dp[i - 1][j][k][h]);
            if (j > 0)
              tmp = max(tmp, dp[i][j - 1][k][h]);
            if (k > 0)
              tmp = max(tmp, dp[i][j][k - 1][h]);
            if (h > 0)
              tmp = max(tmp, dp[i][j][k][h - 1]);
            dp[i][j][k][h] = tmp + a[cal(i, j, k, h)];
          }
        }
      }
    }
    printf("%d\n", dp[b[0]][b[1]][b[2]][b[3]]);
  }
  return 0;
}
