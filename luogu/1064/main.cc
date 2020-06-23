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
int dp[M], f[M];
int n, m;
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
        memset(f, 0, sizeof(f));
        for (int j = 0; j < a[i].v; j++)
          f[j] = -1;
        for (int j = a[i].v; j <= m; j++) {
          f[j] = dp[j - a[i].v] + a[i].v * a[i].p;
        }
        for (int k = 0; k < v[i + 1].size(); k++) {
          int tmp = v[i + 1][k];
          for (int j = m; j >= a[tmp].v; j--) {
            if (f[j - a[tmp].v] != -1) {
              f[j] = max(f[j], f[j - a[tmp].v] + a[tmp].v * a[tmp].p);
            }
          }
        }
        for (int j = 0; j <= m; j++) {
          dp[j] = max(dp[j], f[j]);
        }
      }
    }
    printf("%d\n", dp[m] * 10);
  }
}