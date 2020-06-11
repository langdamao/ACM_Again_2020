#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0 || b == 0) {
      printf("0\n");
      continue;
    }
    if (a < b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    if (a >= b * 2) {
      printf("%d\n", b);
      continue;
    } else {
      printf("%d\n", (a + b) / 3);
    }
  }
}
