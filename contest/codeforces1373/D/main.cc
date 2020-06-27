#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 200005;

long long a[N], b[N];
int n;
long long findMax(int end) {
  long long res = 0;
  long long now = 0;
  for (int i = 0; i < end; i++) {
    now += b[i];
    now = max(now, 0LL);
    res = max(now, res);
  }
  return res;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);
    int tmpi = 0;
    int now = 0;
    while (tmpi + 1 < n) {
      b[now] = a[tmpi + 1] - a[tmpi];
      now++;
      tmpi += 2;
    }
    long long ans = findMax(now);
    now = 0;
    tmpi = 1;
    while (tmpi + 1 < n) {
      b[now] = a[tmpi] - a[tmpi + 1];
      now++;
      tmpi += 2;
    }
    ans = max(findMax(now), ans);
    for (int i = 0; i < n; i = i + 2) {
      ans += a[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
