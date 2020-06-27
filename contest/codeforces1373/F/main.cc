#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1000006;
int n;
long long a[N], b[N], aa[N], c[N];
bool cal() {
  long long seng = 0LL;
  for (int i = 1; i <= n; i++) {
    seng = seng + b[i];
    if (a[i] >= seng) {
      a[i] -= seng;
      seng = 0;
    } else {
      seng -= a[i];
      a[i] = 0;
    }
    seng = min(seng, b[i]);
    c[i + 1] = seng;
  }
  bool ok;
  if (seng < a[1]) {
    ok = false;
  } else {
    ok = true;
    for (int i = 1; i <= n; i++)
      a[i] = aa[i];
    for (int i = 1; i <= n; i++) {
      seng = seng + b[i];
      if (a[i] > seng) {
        a[i] -= seng;
        seng = 0;
        return false;
      } else {
        seng -= a[i];
        a[i] = 0;
      }
      seng = min(seng, b[i]);
      c[i + 1] = seng;
    }
    if (seng < 0)
      return false;
  }
  return ok;
}
int main() {
  int T;
  scanf("%d\n", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
      aa[i] = a[i];
    for (int i = 1; i <= n; i++)
      scanf("%lld", &b[i]);
    bool ans = cal();
    // cout<<ans<<endl;
    for (int i = 1; i <= n + 1 - i; i++) {
      swap(b[i], b[n + 1 - i]);
    }
    for (int i = 2; i <= n + 2 - i; i++) {
      swap(aa[i], aa[n + 2 - i]);
    }
    for (int i = 1; i <= n; i++) {
      a[i] = aa[i];
      // cout<<a[i]<<' '<<b[i]<<endl;
    }
    ans = (ans || cal());
    // cout<<ans<<endl;
    if (ans)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
