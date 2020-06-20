#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, x, y;
int main() {
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", n * 3 + 4);
    int x = 0;
    y = 0;
    printf("%d %d\n", x, y);
    for (int i = 1; i <= n + 1; i++) {
      printf("%d %d\n", x, y + 1);
      printf("%d %d\n", x + 1, y + 1);
      printf("%d %d\n", x + 1, y);
      x++;
      y++;
    }
  }
  return 0;
}
