#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int a[35][35];
bool out(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m)
    return true;
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 0;
    for (int i = 0; i < (n + m - 1) / 2; i++) {
      int suma = i;
      int sumb = (n + m - 2) - i;
      int sum[2] = {0, 0};
      for (int j = 0; j <= suma; j++) {
        if (out(j, suma - j))
          continue;
        sum[a[j][suma - j]]++;
      }
      for (int j = 0; j <= sumb; j++) {
        if (out(j, sumb - j))
          continue;
        sum[a[j][sumb - j]]++;
      }
      ans += min(sum[0], sum[1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
