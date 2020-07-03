#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 500005;
int n, m;
long long a[N];
int p;
struct node {
  node(){};
  node(int _l, int _r, int _x) : l(_l), r(_r), x(_x % p), flag1(1), flag2(0){};
  int l, r;
  long long x;
  long long flag1 = 1, flag2 = 0;
  void merge(node a, node b) {
    // cout<<"a:: "<<a.l<<' '<<a.r<< ' '<<a.x<<endl;
    // cout<<"b:: "<<b.l<<' '<<b.r<< ' '<<b.x<<endl;
    l = min(a.l, b.l);
    r = max(a.r, b.r);
    x = (a.x + b.x) % p;
  }
  void update(int ty, int k) {
    // if (l==5&& r==5) {
    // cout<<"single updateing "<<l<<' '<<r<<' '<<flag1<<' '<<flag2<<'
    // '<<x<<endl; cout<<ty<<' '<<k<<endl;
    //}
    if (ty == 1) {
      flag1 = flag1 * (k % p) % p;
      flag2 = flag2 * (k % p) % p;
      x *= k % p;
      x %= p;
    }
    if (ty == 2) {
      flag2 = (flag2 + k % p) % p;
      x += k % p * (r - l + 1);
      x %= p;
    }
    // if (l==5&& r==5) {
    // cout<<"single updateing "<<l<<' '<<r<<' '<<flag1<<' '<<flag2<<'
    // '<<x<<endl;
    //}
  }
  void updateFlag(node f) {
    // cout<<"updateing "<<l<<' '<<r<<' '<<flag1<<' '<<flag2<<' '<<x<<endl;
    // cout<<f.l<<' '<<f.r<<' '<<f.flag1<<' '<<f.flag2<<endl;
    x *= f.flag1;
    x %= p;
    x += f.flag2 % p * (r - l + 1);
    x %= p;
    flag1 *= f.flag1;
    flag1 %= p;
    flag2 = flag2 * (f.flag1 % p) % p;
    flag2 += f.flag2;
    flag2 %= p;
    // cout<<"updateing "<<l<<' '<<r<<' '<<flag1<<' '<<flag2<<' '<<x<<endl;
  }
  void clearFlag() {
    flag1 = 1;
    flag2 = 0;
  }
  bool has_flag() { return flag1 != 1 || flag2 != 0; }
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
    no[i].merge(no[i << 1], no[i << 1 | 1]);
  }
  void update(int i, int l, int r, int x, int y, int ty, long long k) {
    if (x <= l && r <= y) {
      no[i].update(ty, k);
      return;
    }
    push_down(i);
    int mid = (l + r) / 2;
    if (x <= mid)
      update(i << 1, l, mid, x, y, ty, k);
    if (y >= mid + 1)
      update(i << 1 | 1, mid + 1, r, x, y, ty, k);
    no[i].merge(no[i << 1], no[i << 1 | 1]);
  }
  long long query(int i, int l, int r, int x, int y) {
    // cout<<i<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
    if (x <= l && r <= y) {
      // cout<<i<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<no[i].x<<endl;
      return no[i].x;
    }
    push_down(i);
    int mid = (l + r) / 2;
    long long ret = 0;
    if (x <= mid)
      ret += query(i << 1, l, mid, x, y);
    if (y >= mid + 1)
      ret += query(i << 1 | 1, mid + 1, r, x, y);
    // cout<<i<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<ret<<endl;
    return ret % p;
  }
  void push_down(int i) {
    if (no[i].has_flag()) {
      int lc = i << 1;
      int rc = i << 1 | 1;
      no[lc].updateFlag(no[i]);
      no[rc].updateFlag(no[i]);
      no[i].clearFlag();
    }
  }
} tree;
int main() {
  while (scanf("%d%d%d", &n, &m, &p) != EOF) {
    int ty, x, y;
    int k;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    tree.build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
      scanf("%d", &ty);
      if (ty == 1) {
        scanf("%d%d%d", &x, &y, &k);
        // cout<<ty<<' '<<x<<' '<<y<<' '<<ty<<' '<<k;
        tree.update(1, 0, n - 1, x - 1, y - 1, ty, k);
      } else if (ty == 2) {
        scanf("%d%d%d", &x, &y, &k);
        // cout<<ty<<' '<<x<<' '<<y<<' '<<ty<<' '<<k;
        tree.update(1, 0, n - 1, x - 1, y - 1, ty, k);
      } else {
        scanf("%d%d", &x, &y);
        printf("%lld\n", tree.query(1, 0, n - 1, x - 1, y - 1));
      }
    }
  }
  return 0;
}
