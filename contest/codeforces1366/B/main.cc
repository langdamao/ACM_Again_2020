#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void cal(int &l, int &r, int x, int y) {
  if (x > r)
    return;
  if (y < l)
    return;
  l = min(l, x);
  r = max(r, y);
}
int main() {
  int T;
  scanf("%d", &T);
  int n, xx, m;
  while (T--) {
    scanf("%d%d%d", &n, &xx, &m);
    int l = xx;
    int r = xx;
    int x, y;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      cal(l, r, x, y);
    }
    printf("%d\n", r - l + 1);
  }
  return 0;
}
