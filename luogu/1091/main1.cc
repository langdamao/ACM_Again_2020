#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int a[100], dp[2][100], n;

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        dp[j][i] = 1;
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j])
          dp[0][i] = max(dp[0][i], dp[0][j] + 1);
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (a[i] > a[j])
          dp[1][i] = max(dp[1][i], dp[1][j] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(dp[0][i] + dp[1][i] - 1, ans);
    }

    printf("%d\n", n - ans);
  }
  return 0;
}
