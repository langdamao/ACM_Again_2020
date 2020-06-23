#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 65;
const int M = 3200 + 5;
struct node {
  int v, p, q;
} a[N];
vector<int> v[N];
int dp[M];
int n, m;
void dfs(int x, int dp[]) {
  int f[M];
  for (int i = 0; i < a[x].v; i++)
    f[i] = -1;
  for (int i = a[x].v; i <= m; i++) {
    if (dp[i - a[x].v] != -1)
      f[i] = dp[i - a[x].v] + a[x].v * a[x].p;
  }
  for (int j = 0; j < v[x + 1].size(); j++) {
    dfs(v[x + 1][j], f);
  }
  for (int i = 0; i <= m; i++) {
    dp[i] = max(dp[i], f[i]);
  }
}
int main() {
  while (scanf("%d%d", &m, &n) != EOF) {
    m = m / 10;
    for (int i = 0; i <= n; i++)
      v[i].clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &a[i].v, &a[i].p, &a[i].q);
      a[i].v /= 10;
      if (a[i].q != 0) {
        v[a[i].q].push_back(i);
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      if (a[i].q == 0) {
        dfs(i, dp);
      }
    }
    printf("%d\n", dp[m] * 10);
  }
}