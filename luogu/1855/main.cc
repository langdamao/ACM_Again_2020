#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100 + 5;
const int M = 200 + 5;
const int T = 200 + 5;
int dp[M][T];
int w[N], c[N];
int n, m, t;
int main() {
  while (scanf("%d%d%d", &n, &m, &t) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &w[i], &c[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = m; j >= w[i]; j--) {
        for (int k = t; k >= c[i]; k--) {
          dp[j][k] = max(dp[j][k], dp[j - w[i]][k - c[i]] + 1);
        }
      }
    }
    printf("%d\n", dp[m][t]);
  }
  return 0;
}