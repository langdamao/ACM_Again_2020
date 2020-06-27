#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
char str[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", str);
    int l = strlen(str);
    int now = 0;
    long long ans = 0;
    int min_now = 0;
    for (int i = 0; i < l; i++) {
      if (str[i] == '+')
        now++;
      else
        now--;
      if (now < min_now) {
        ans += i + 1;
        min_now = now;
      }
    }
    printf("%lld\n", ans + l);
  }
  return 0;
}
