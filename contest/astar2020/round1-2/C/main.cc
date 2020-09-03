#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2 * 1e4 + 5;
const int M = 2 * 1e5 + 5;
bool isill[N];
int v[N];
struct node {
  int t, p, k;
  node(){};
  node(int _t, int _p, int _k) : t(_t), p(_p), k(_k){};
  bool equ(node y) { return (t == y.t) && (p == y.p); }
} a[M];

int n, num;
inline bool cmp(const node &x, const node &y) {
  if (x.t != y.t)
    return x.t < y.t;
  if (x.p != y.p)
    return x.p < y.p;
  return x.k < y.k;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    num = 0;
    int len, t, p;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &len);
      for (int j = 0; j < len; j++) {
        scanf("%d%d", &t, &p);
        a[num++] = node(t, p, i);
      }
    }
    a[num++] = node(105, 105, n + 3);
    sort(a, a + num, cmp);
    memset(isill, false, sizeof(isill));
    isill[1] = true;
    int now = 0;
    for (int i = 0; i < num - 1; i++) {
      v[now++] = a[i].k;
      if (!a[i].equ(a[i + 1])) {
        bool ill = false;
        for (int j = 0; j < now; j++) {
          if (isill[v[j]]) {
            ill = true;
            break;
          }
        }
        if (ill) {
          for (int j = 0; j < now; j++) {
            isill[v[j]] = true;
          }
        }
        now = 0;
      }
    }
    bool got = false;
    for (int i = 1; i <= n; i++) {
      if (isill[i]) {
        if (got)
          printf(" ");
        printf("%d", i);
        got = true;
      }
    }
    printf("\n");
  }

  return 0;
}
