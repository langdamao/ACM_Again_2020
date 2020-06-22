#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n, m;
const int N = 100 + 5;
int v[N], w[N], c[N];
const int M = 40000 + 5;
int dp[M];
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &v[i], &w[i], &c[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      int k = 1;
      while (c[i] > 0) {
        if (c[i] >= k) {
          c[i] -= k;
        } else {
          k = c[i];
          c[i] = 0;
        }
        int neww = w[i] * k;
        int newv = v[i] * k;
        for (int j = m; j >= neww; j--) {
          dp[j] = max(dp[j], dp[j - neww] + newv);
        }
        k <<= 1;
      }
    }
    printf("%d\n", dp[m]);
  }
  return 0;
}
