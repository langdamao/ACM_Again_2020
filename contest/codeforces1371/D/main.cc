#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int T;
  int n, k;
  int ans[305][305];
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    int now = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (now >= k)
          break;
        int jj = i - j;
        if (jj < 0)
          jj += n;
        ans[j][jj] = 1;
        now++;
      }
    }
    int x = k / n;
    int x1 = k % n == 0 ? x : x + 1;
    printf("%d\n", (x1 - x) * (x1 - x) * 2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%d", ans[i][j]);
      printf("\n");
    }
  }
  return 0;
}
