#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[105];
bool isdig(char ch) {
  if (ch >= '0' && ch <= '9')
    return true;
  return false;
}
bool isji(char ch) {
  if ((ch - '0') & 1)
    return true;
  return false;
}
bool iszimu(char ch) {
  if (ch >= 'a' && ch <= 'z')
    return true;
  return false;
}
bool isyuan(char ch) {
  if (ch == 'a')
    return true;
  if (ch == 'e')
    return true;
  if (ch == 'i')
    return true;
  if (ch == 'o')
    return true;
  if (ch == 'u')
    return true;
  return false;
}
int main() {
  while (scanf("%s", str) != EOF) {
    int l = strlen(str);
    int ans = 0;
    for (int i = 0; i < l; i++) {
      if (isdig(str[i]) && isji(str[i]))
        ans++;
      if (iszimu(str[i]) && isyuan(str[i]))
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
