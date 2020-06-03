#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int a[100], tmp[100], dp[100], n;

int caldp(int head, int tail, int step) {
  int cnt = 0;
  for (int i = head; i != tail; i = i + step) {
    tmp[cnt++] = a[i];
  }
  int ans = 1;
  dp[0] = 1;
  for (int i = 1; i < cnt; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (tmp[i] > tmp[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  return dp[cnt - 1];
}
int cal(int i) {
  int r = caldp(n - 1, i - 1, -1);
  int l = caldp(0, i + 1, 1);
  return n - (l + r - 1);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      ans = min(ans, cal(i));
    }
    printf("%d\n", ans);
  }
  return 0;
}
