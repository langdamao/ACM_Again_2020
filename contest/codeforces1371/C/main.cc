#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int T;
  long long n, m, a, b;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    bool ans = (m <= min(a, b)) && (n + m <= a + b);
    if (ans)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
