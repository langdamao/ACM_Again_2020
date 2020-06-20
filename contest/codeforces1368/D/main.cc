#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long a[200005];
int er[25];
int n;

void cal1(long long x) {
  int now = 0;
  while (x > 0) {
    if (x & 1)
      er[now]++;
    x >>= 1;
    now++;
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(er, 0, sizeof(er));
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      cal1(a[i]);
    }
    int has = 0;
    long long ans = 0;
    for (int i = 0; i < 20; i++)
      has += er[i];
    while (has > 0) {
      long long tmp = 0;
      for (int i = 0; i < 20; i++) {
        if (er[i] > 0) {
          tmp += (1 << i);
          er[i]--;
          has--;
        }
      }
      ans += tmp * tmp;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
