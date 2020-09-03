#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100000;
int T, n;
long long a[N];
int main() {

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      long long tmp = a[i + 1] - a[i];
      ans += tmp * (i + 1) * (n - i - 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
