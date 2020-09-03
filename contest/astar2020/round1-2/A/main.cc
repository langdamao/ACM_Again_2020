#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int T, n, m, k, p;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &p);
    int ans = 0;
    k = ceil(m * p / 100.0);
    while (n >= m) {
      ans += n / m;
      n = n - (k * (n / m));
    }
    printf("%d\n", ans);
  }
  return 0;
}
