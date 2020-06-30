#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m;
struct node {
  int x, y, a, b, i, grp;
  int ansx, ansy;
  int calGrp() { return x / sqrt(n); }
  void printans() { printf("%d %d\n", ansx, ansy); }
  inline bool operator<(const node &an) const {
    if (grp != an.grp)
      return grp < an.grp;
    if (y != an.y)
      return y < an.y;
    return x < an.x;
  }
} b[N];
int a[N], w[N];
struct lowbitTree {
  int c[N];
  string name;
  lowbitTree(string _name) : name(_name){};
  void clear() { memset(c, 0, sizeof(c)); }
  inline int lowbit(int x) { return x & (-x); }
  void update(int k, int x) {
    // cout<<"update "<<name<<' '<<k<<' '<<x<<endl;
    while (k < n) {
      c[k] += x;
      k += lowbit(k);
    }
  }
  int sum(int k) {
    int ret = 0;
    while (k > 0) {
      ret += c[k];
      k -= lowbit(k);
    }
    return ret;
  }
  int query(int a, int b) { return sum(b) - sum(a - 1); }
} cnum("cnum"), csum("csum");
void fix(int &x, int y, int type) {
  int dir = 1;
  if (x > y) {
    dir = -1;
    type = -type;
  }
  // cout<<"fix "<<x<<' '<<y<<' '<<dir<<' '<<type<<endl;
  for (int i = x; i != y + dir; i = i + dir) {
    if ((type == 1 && i == x) || (type == -1 && i == y))
      continue;
    w[a[i]] += type;
    csum.update(a[i], type);
    if ((type == 1 && w[a[i]] == 1) || (type == -1 && w[a[i]] == 0)) {
      cnum.update(a[i], type);
    }
  }
  x = y;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    node tmp;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d%d", &tmp.x, &tmp.y, &tmp.a, &tmp.b);
      tmp.grp = tmp.calGrp();
      tmp.i = i;
      b[i] = tmp;
    }
    sort(b, b + m);
    // memset(w,0,sizeof(w));
    // cnum.clear();
    // csum.clear();
    int lastl = 1;
    int lastr = 0;
    for (int i = 0; i < m; i++) {
      // cout<<i<<' '<<lastl<<' '<<lastr<<' '<<b[i].x<<' '<<b[i].y<<endl;
      if (b[i].b < b[i].a || b[i].x > b[i].y) {
        printf("0 0\n");
        continue;
      }
      fix(lastl, b[i].x, -1);
      fix(lastr, b[i].y, 1);
      b[b[i].i].ansx = csum.query(b[i].a, b[i].b);
      b[b[i].i].ansy = cnum.query(b[i].a, b[i].b);
    }
    for (int i = 0; i < m; i++) {
      b[i].printans();
    }
  }
  return 0;
}
