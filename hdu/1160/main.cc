#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1005;
struct node {
  int w, s, wei;
} a[N];
int dp[N], last[N];

inline bool cmp(const node &x, const node &y) {
  if (x.w != y.w)
    return x.w > y.w;
  if (x.s != y.s)
    return x.s < y.s;
  return x.wei < y.wei;
}
int main() {
  int n = 0;
  while (scanf("%d%d", &a[n].w, &a[n].s) != EOF) {
    a[n].wei = n + 1;
    n++;
  }
  sort(a, a + n, cmp);
  int ans = 1;
  int ansLast = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    last[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j].s < a[i].s && a[j].w > a[i].w && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        last[i] = j;
      }
    }
    if (dp[i] > ans) {
      ans = dp[i];
      ansLast = i;
    }
  }
  printf("%d\n", ans);
  while (ansLast != -1) {
    printf("%d\n", a[ansLast].wei);
    ansLast = last[ansLast];
  }
  return 0;
}
