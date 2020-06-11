#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node {
  node() {
    x = 0;
    wei = 0;
  };
  node(int _x, int _wei) : x(_x), wei(_wei){};
  int x, wei;
} p[200005];
int n, m;
int a[200005], b[200005];
int found[200005];

int main() {
  long long ans;
  long long mod = 998244353L;
  while (scanf("%d%d", &n, &m) != EOF) {

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int j = 0; j < m; j++) {
      scanf("%d", &b[j]);
    }
    int tail = 0;
    for (int i = 0; i < n; i++) {
      while (tail != 0) {
        node t = p[tail - 1];
        if (t.x >= a[i])
          tail--;
        else
          break;
      }
      p[tail++] = node(a[i], i);
    }
    p[tail].x = -1;
    int now = 0;
    bool got = 0;
    for (int i = 0; i < m; i++) {
      while (now < tail && p[now].x < b[i])
        now++;
      if (p[now].x != b[i]) {
        got = 1;
        break;
      }
      found[i] = now;
    }
    if (found[0] != 0)
      got = 1;
    if (got)
      ans = 0;
    else {
      ans = 1L;
      for (int i = 1; i < m; i++) {
        ans *= p[found[i]].wei - p[found[i] - 1].wei;
        ans %= mod;
      }
    }
    printf("%lld\n", ans);
  }
}
