#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int T;
  long long n, r;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &n, &r);
    long long x = min(r, n - 1);
    long long ans = x * (x + 1) / 2;
    if (n <= r)
      ans++;
    printf("%lld\n", ans);
  }
}
