#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
const int N = 10000 + 5;
const int M = 10000000 + 5;
long long w[N], v[N];
long long dp[M];
int main() {
  while (scanf("%d%d", &m, &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld", &w[i], &v[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int j = w[i]; j <= m; j++) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    }
    printf("%lld\n", dp[m]);
  }
  return 0;
}
