#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 2005;
int T, n;
long long a[N], b[N];
long long dp[N][N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &b[j]);
    }
    memset(dp, -1, sizeof(dp));
    int now = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      now += b[i];
      dp[i][0] = now;
    }
    int ans = 0;
    long long tmp;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        tmp = -1;
        if (j != i && dp[i - 1][j] != -1) {
          tmp = max(tmp, dp[i - 1][j] + b[i]);
        }
        if (dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] + b[i] >= a[i]) {
          tmp = max(tmp, dp[i - 1][j - 1] + b[i] - a[i]);
        }
        dp[i][j] = tmp;
        if (tmp != -1)
          ans = max(ans, j);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
