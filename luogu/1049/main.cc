#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int v, n;
int a[40];
int dp[20005];
int main() {
  while (scanf("%d%d", &v, &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = v; j >= a[i]; j--) {
        dp[j] = max(dp[j], dp[j - a[i]]);
      }
    }
    for (int i = v; i >= 0; i--)
      if (dp[i] != 0) {
        printf("%d\n", v - i);
        break;
      }
  }
}
