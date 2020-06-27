#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1005;
int n;
int dp[N], a[N];
int main() {
  while (scanf("%d", &n) != EOF && n > 0) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    int ans = a[0];
    for (int i = 0; i < n; i++)
      dp[i] = a[i];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j] < a[i])
          dp[i] = max(dp[i], dp[j] + a[i]);
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
}
