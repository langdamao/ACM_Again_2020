#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  int a, b, n;
  while (T--) {
    scanf("%d%d%d", &a, &b, &n);
    int ans = 0;
    int next = a + b;
    a = min(a, b);
    b = next - a;
    while (b <= n) {
      next = a + b;
      a = max(a, b);
      b = next;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
