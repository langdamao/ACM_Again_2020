#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int n, p;
vector<int> v;
struct node {
  node(int _x, int _y) : x(_x), y(_y){};
  int x, y;
  inline bool operator<(const node &an) const {
    if (x != an.x)
      return x > an.x;
    return y > an.y;
  }
};
bool cal(int x) {
  int ret = 1;
  for (int i = 0; i < n; i++) {
    int num = min(x + i - a[i] + 1, i + 1);
    ret *= num;
    ret %= p;
    if (ret % p == 0)
      return false;
  }
  return ret % p != 0;
}
set<int, greater<int>> s;
int num[N];

int main() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n);
  v.clear();
  int minx = a[0];
  for (int i = 0; i < n; i++) {
    minx = max(a[i] - i, minx);
  }
  s.clear();
  memset(num, 0, sizeof(num));
  for (int i = p - 1; i < n; i++) {
    b[i] = minx + i - a[i] + 1;
    num[b[i] % p]++;
  }
  for (int i = 0; i < p; i++) {
    if (num[i] == 0) {
      if (i == 0)
        s.insert(p);
      else
        s.insert(i);
    }
  }
  int nowx = minx;
  int k = 1;
  set<int, greater<int>>::iterator it;
  it = s.begin();
  nowx = k * p + minx - (*it);
  while (nowx < a[p - 1]) {
    v.push_back(nowx);
    it++;
    if (it == s.end()) {
      it = s.begin();
      k++;
    }
    nowx = k * p + minx - (*it);
  }
  printf("%lu\n", v.size());
  int len = v.size();
  for (int i = 0; i < len; i++) {
    if (i != 0)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
