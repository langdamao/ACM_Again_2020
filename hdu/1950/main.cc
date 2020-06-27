#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 5;
int a[N], dp[N];
int n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
      dp[i] = INF;
    int len = 1;
    for (int i = 0; i < n; i++) {
      int k = lower_bound(dp + 1, dp + len + 1, a[i]) - dp;
      dp[k] = a[i];
      len = max(len, k);
    }
    printf("%d\n", len);
  }
  return 0;
}
