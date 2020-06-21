#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char ma[105][105];
int a[5];
int l;
char str[105];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int n, m;

struct node {
  int x;
  int y;
} s, e;
void findse() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ma[i][j] == 'S') {
        s.x = i;
        s.y = j;
      }
      if (ma[i][j] == 'E') {
        e.x = i;
        e.y = j;
      }
    }
  }
}
bool oka() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j)
        continue;
      if (a[i] == a[j])
        return false;
    }
  }
  return true;
}
node getnext(node x, int d) {
  node ret;
  ret.x = x.x + dir[d][0];
  ret.y = x.y + dir[d][1];
  return ret;
}
bool outsid(node x) {
  if (x.x < 0 || x.y < 0 || x.x >= n || x.y >= m)
    return true;
  if (ma[x.x][x.y] == '#')
    return true;
  return false;
}
bool getout() {
  node now = s;
  int i = 0;
  while (i < l) {
    now = getnext(now, a[str[i] - '0']);
    if (now.x == e.x && now.y == e.y)
      return true;
    if (outsid(now))
      return false;
    i++;
  }
  return false;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%s", ma[i]);
    findse();
    scanf("%s", str);
    l = strlen(str);
    int ans = 0;
    for (a[0] = 0; a[0] < 4; a[0]++) {
      for (a[1] = 0; a[1] < 4; a[1]++) {
        for (a[2] = 0; a[2] < 4; a[2]++) {
          for (a[3] = 0; a[3] < 4; a[3]++) {
            if (oka() && getout())
              ans++;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
