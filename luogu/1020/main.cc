#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;
multiset<int> s;
set<int>::iterator it;
const int N = 1e5 + 5;
int a[N];
int n;
int b[N], c[N];
void cal2() {
  s.clear();
  for (int i = 0; i < n; i++) {
    it = s.lower_bound(a[i]);
    if (it != s.end()) {
      s.erase(it);
    }
    s.insert(a[i]);
  }
  printf("%lu\n", s.size());
}
struct node {
  node(){};
  node(int _x, int _wei) : x(_x), wei(_wei){};
  int x, wei;
} nodes[N];
inline bool cmp(const node &x, const node &y) {
  if (x.x != y.x)
    return x.x > y.x;
  return x.wei < y.wei;
}
int makesanlie() {
  for (int i = 0; i < n; i++) {
    nodes[i] = node(a[i], i);
  }
  sort(nodes, nodes + n, cmp);
  for (int i = 0; i < n; i++) {
    b[nodes[i].wei] = i + 1;
  }
  return n;
}
inline int lowbit(int x) { return x & -x; }
int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret = max(ret, c[x]);
    x -= lowbit(x);
  }
  return ret;
}
void update(int x, int k, int NN) {
  while (x < NN) {
    c[x] = max(c[x], k);
    x += lowbit(x);
  }
}
//树状数组
void cal1() {
  int num = makesanlie();
  memset(c, 0, sizeof(0));
  for (int i = 0; i < n; i++) {
    int l = sum(b[i] - 1) + 1;
    update(b[i], l, num + 5);
  }
  printf("%d\n", sum(num));
}
//二分贪心
void cal11() {
  s.clear();
  for (int i = 0; i < n; i++) {
    it = s.lower_bound(a[i]);
    if (it != s.begin()) {
      it--;
      s.erase(it);
    }
    s.insert(a[i]);
  }
  printf("%lu\n", s.size());
}
int main() {
  n = 0;
  while (scanf("%d", &a[n++]) != EOF)
    ;
  n--;
  // cal1();
  cal11();
  cal2();
  return 0;
}
