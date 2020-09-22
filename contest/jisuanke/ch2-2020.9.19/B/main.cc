#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1005;
int n;
int ans[N];
int p[N], w[N], ceng[N], have[N][N];

int findceng(int x) {
  if (ceng[x] != 0)
    return ceng[x];
  ceng[x] = findceng(p[x]) + 1;
  return ceng[x];
}
void record(int x, int y) {
  int fx = p[x];
  int fy = p[y];
  while (fx != fy) {
    fx = p[fx];
    fy = p[fy];
  }
  while (fx != 0 && have[fx][ceng[x]] == false) {
    ans[fx]++;
    have[fx][ceng[x]] = true;
    fx = p[fx];
  }
  return;
}
int getans() {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += (i ^ (n - ans[i]));
  }
  return ret % 998244353;
}
int main() {
  int x;
  scanf("%d%d", &n, &x);
  p[1] = 0;
  memset(have, 0, sizeof(have));
  memset(ans, 0, sizeof(ans));
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  memset(ceng, 0, sizeof(ceng));
  ceng[1] = 1;
  for (int i = 2; i <= n; i++) {
    findceng(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j && ceng[i] == ceng[j] && (w[i] ^ w[j]) == x) {
        record(i, j);
      }
    }
  }
  printf("%d\n", getans());

  return 0;
}
