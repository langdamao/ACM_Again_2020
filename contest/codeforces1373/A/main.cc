#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans1, ans2;
    if (a >= c)
      ans1 = -1;
    else
      ans1 = 1;
    if (((long long)a) * b > c) {
      ans2 = b;
    } else
      ans2 = -1;
    printf("%d %d\n", ans1, ans2);
  }
}
