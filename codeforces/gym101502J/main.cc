#include <cstdio>
#include <iostream>
using namespace std;
int n, a[1005], dp[1005][1005];
int cal(int h, int tail, int flag) {
  int l = dp[h + 1][tail] + a[h] * flag;
  int r = dp[h][tail - 1] + a[tail] * flag;
  if (flag < 0)
    return min(l, r);
  else
    return max(l, r);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    int flag = 1;
    if ((n & 1) == 0)
      flag = -1;
    for (int i = 0; i < n; i++)
      dp[i][i] = a[i] * flag;
    for (int l = 2; l <= n; l++) {
      flag = -1 * flag;
      for (int h = 0; h + l - 1 < n; h++) {
        int tail = h + l - 1;
        dp[h][tail] = cal(h, tail, flag);
      }
    }
    printf("%d\n", dp[0][n - 1]);
  }
  return 0;
}
