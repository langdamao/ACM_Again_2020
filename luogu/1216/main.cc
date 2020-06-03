#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000][1000];
int dp[1000][1000];
int n, ans;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[i - 1][j - 1];
        if (j != i)
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] += a[i][j];
      }
    }
    ans = dp[n - 1][0];
    for (int j = 0; j < n; j++) {
      ans = max(ans, dp[n - 1][j]);
    }
    printf("%d\n", ans);
  }
}
