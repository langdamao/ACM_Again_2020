#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const long long INTMAX = (1LL << 62) - 1 + (1LL << 62);
int pre[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int prelen = 10;
int n, k;
long long cal(int st, int n, int k) {
  long long sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += pre[i + st];
  }
  int nn = n - sum;
  // cout<<st<<' '<<n<<' '<<k<<' '<<sum<<' '<<nn<<endl;
  if (nn < 0 || nn % (k + 1) != 0)
    return INTMAX;
  // cout<<nn<<endl;
  nn = nn / (k + 1);
  if (st + k >= 10)
    nn++;
  long long ret = 0LL;
  long long ten = 10LL;
  while (nn > 0) {
    int tmp = 9;
    if (nn < 9)
      tmp = nn;
    ret += tmp * ten;
    ten *= 10;
    nn -= 9;
  }
  long long xk = ret + pre[st + k];
  if (st + k >= 10)
    xk--;
  if (xk >= k)
    return xk - k;
  else
    return INTMAX;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    long long ans = INTMAX;
    // cout<<ans<<endl;
    for (int i = 0; i < prelen; i++) {
      long long tmp = cal(i, n, k);
      // cout<<i<<' '<<tmp<<' '<<ans<<endl;
      ans = min(tmp, ans);
    }
    if (ans == INTMAX)
      ans = -1;
    printf("%lld\n", ans);
  }
  return 0;
}
