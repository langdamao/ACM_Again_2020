#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int dp[2005][2005][3];
int dp1[2005][2005][3];
int n;
int a[2005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  memset(dp, 0, sizeof(dp));
  memset(dp1, 0, sizeof(dp1));
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      dp[i][i][0] = dp[i][i][1] = 1;
    else
      dp[i][i][1] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      dp1[i][i][0] = dp1[i][i][1] = 1;
    else
      dp1[i][i][1] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] == 1) {
        dp[i][j][0] = dp[i][j - 1][0] + 1;
        dp[i][j][1] = dp[i][j - 1][1];
      } else {
        dp[i][j][0] = dp[i][j - 1][0];
        dp[i][j][1] = max(dp[i][j - 1][1] + 1, dp[i][j - 1][0] + 1);
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] == 1) {
        dp1[j][i][0] = dp1[j + 1][i][0] + 1;
        dp1[j][i][1] = dp1[j + 1][i][1];
      } else {
        dp1[j][i][0] = dp1[j + 1][i][0];
        dp1[j][i][1] = max(dp1[j + 1][i][1] + 1, dp1[j + 1][i][0] + 1);
      }
    }
  }
  int ans = 0;
  int a0, a1, b0, b1, c0, c1;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      a0 = dp[0][i - 1][0];
      a1 = dp[0][i - 1][1];
    } else {
      a0 = a1 = 0;
    }
    for (int j = i; j < n; j++) {
      b0 = dp1[i][j][0];
      b1 = dp1[i][j][1];
      if (j + 1 < n) {
        c0 = dp[j + 1][n - 1][0];
        c1 = dp[j + 1][n - 1][1];
      } else {
        c0 = c1 = 0;
      }
      ans = max(ans, a0 + b0 + c0);
      ans = max(ans, a0 + b0 + c1);
      ans = max(ans, a0 + b1 + c1);
      ans = max(ans, a1 + b1 + c1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
