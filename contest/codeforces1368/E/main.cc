#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> v[200005], vb[200005];
vector<int> ans;
int dis[200005];
int num;
int n, m;

struct node {
  node() : x(0), y(0), z(0){};
  node(int _x, int _y, int _z) : x(_x), y(_y), z(_z){};
  int x, y, z;
  bool operator<(const node &right) const //重载<运算符
  {
    if (z != right.z)
      return z > right.z;
    if (y != right.y)
      return y > right.y;
    return x > right.x;
  }
};
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
      v[i].clear();
      vb[i].clear();
    }
    int x, y;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      v[x].push_back(y);
      vb[y].push_back(x);
    }
    dis[1] = 0;
    ans.clear();
    for (int i = 2; i <= n; i++) {
      dis[i] = 0;
      for (int j = 0; j < vb[i].size(); j++) {
        dis[i] = max(dis[i], dis[vb[i][j]] + 1);
      }
      if (dis[i] == 2) {
        ans.push_back(i);
        dis[i] = -1;
      }
    }
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
      if (i == 0)
        printf("%d", ans[i]);
      else
        printf(" %d", ans[i]);
    }
    printf("\n");
  }
}
