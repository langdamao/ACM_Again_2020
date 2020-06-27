#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[105];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", str);
    int l = strlen(str);
    int num[2] = {0, 0};
    for (int i = 0; i < l; i++) {
      num[str[i] - '0']++;
    }
    int ans = min(num[0], num[1]);
    if (ans & 1)
      printf("DA\n");
    else
      printf("NET\n");
  }
  return 0;
}
