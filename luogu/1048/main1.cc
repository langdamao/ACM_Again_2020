#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int t, m;
int weight[100], value[100];
int dp[2][1001];
int main() {
  while (scanf("%d%d", &t, &m) != EOF) {
    for (int i = 0; i < m; i++)
      scanf("%d%d", &weight[i], &value[i]);
    for (int i = 0; i <= t; i++)
      dp[0][t] = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j <= t; j++) {
        int t = i & 1;
        dp[t][j] = dp[t ^ 1][j];
        if (j >= weight[i - 1])
          dp[t][j] = max(dp[t][j], dp[t ^ 1][j - weight[i - 1]] + value[i - 1]);
      }
    }
    printf("%d\n", dp[m & 1][t]);
  }
  return 0;
}
