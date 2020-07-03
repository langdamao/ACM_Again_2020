#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 500005;
int n, m;
int a[N];
struct node {
  node(){};
  node(int _l, int _r, int _x) : l(_l), r(_r), x(_x){};
  int l, r;
  long long x;
};
struct segmenttree {
  node no[N * 4];
  void build(int i, int l, int r) {
    if (l == r) {
      no[i] = node(l, r, a[l]);
      return;
    }
    int mid = (l + r) / 2;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    no[i] = node(l, r, 0);
  }
  int query(int i, int l, int r, int x) {
    // cout<<i<<' '<<l<<' '<<r<<' '<<x<<endl;
    if (l == r && l == x)
      return no[i].x;
    int mid = (l + r) / 2;
    if (x <= mid)
      return no[i].x + query(i << 1, l, mid, x);
    else
      return no[i].x + query(i << 1 | 1, mid + 1, r, x);
  }
  void update(int i, int l, int r, int x, int y, int k) {
    // cout<<i<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<k<<endl;
    if (x <= l && r <= y) {
      no[i].x += k;
      return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
      update(i << 1, l, mid, x, y, k);
    if (y >= mid + 1)
      update(i << 1 | 1, mid + 1, r, x, y, k);
    // cout<<i<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<k<<endl;
  }
} tree;
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int ty, x, y, k;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    tree.build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
      scanf("%d", &ty);
      if (ty == 1) {
        scanf("%d%d%d", &x, &y, &k);
        tree.update(1, 0, n - 1, x - 1, y - 1, k);
      } else {
        scanf("%d", &x);
        printf("%d\n", tree.query(1, 0, n - 1, x - 1));
      }
    }
  }
  return 0;
}
