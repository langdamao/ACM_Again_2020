#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int sh, sm, eh, em, n;
const int M = 1005;
const int N = 1e4 + 5;
int dp[M];
int t[N], p[N], c[N];
int main() {
  while (scanf("%d:%d %d:%d %d", &sh, &sm, &eh, &em, &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &t[i], &c[i], &p[i]);
    }
    int m = (eh - sh) * 60 + (em - sm);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      if (p[i] == 0 || t[i] * p[i] >= m) {
        for (int j = t[i]; j <= m; j++) {
          dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        }
      } else if (p[i] == 1) {
        for (int j = m; j >= t[i]; j--) {
          dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        }
      } else {
        int k = 1;
        while (p[i] > 0 && p[i] >= k) {
          for (int j = m; j >= t[i] * k; j--) {
            dp[j] = max(dp[j], dp[j - t[i] * k] + c[i] * k);
          }
          p[i] -= k;
          k <<= 1;
          if (k > p[i])
            k = p[i];
        }
      }
    }
    printf("%d\n", dp[m]);
  }
}