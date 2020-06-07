#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n, m;
int dp[2][30001];
int v[26], p[26];
int t;
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &v[i], &p[i]);
    }
    for (int i = 0; i <= n; i++)
      dp[0][i] = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        t = i & 1;
        dp[t][j] = dp[t ^ 1][j];
        if (j >= v[i])
          dp[t][j] = max(dp[t][j], dp[t ^ 1][j - v[i]] + v[i] * p[i]);
      }
    }
    printf("%d\n", dp[m & 1][n]);
  }
  return 0;
}
