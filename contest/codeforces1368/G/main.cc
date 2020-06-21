#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e7;
int ans;
string a[200005];
int n, m;
struct node {
  node(){};
  node(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2){};
  int x1, y1;
  int x2, y2;
  void adjust() {
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (x1 == x2 && y1 > y2) {
      swap(y1, y2);
    }
  }
  int getHashCode() {
    return (((long long)x1 * m + y2) * n * m + x2 * m + y2) % N;
  }
  bool equals(node y) {
    return (x1 == y.x1 && x2 == y.x2 && y1 == y.y1 && y2 == y.y2);
  }
};
node hashArr[N + 5];
bool has[N];
int find(node x) {
  int i = 1;
  int hashCode = x.getHashCode();
  while (has[hashCode]) {
    if (x.equals(hashArr[hashCode])) {
      return true;
    } else {
      hashCode = (hashCode + i * i) % N;
      i++;
    }
  }
  hashArr[hashCode] = x;
  has[hashCode] = true;
  ans++;
  return false;
}
node getNode(int x, int y) {
  if (a[x][y] == 'U')
    return node(x, y, x + 1, y);
  return node(x, y, x, y + 1);
}
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
string dirChar = "DURL";
bool ok(int x, int y) { return (x >= 0 && y >= 0 && x < n && y < m); }
int check(int x, int y, int xx, int yy, node tmpNodes[4]) {
  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int tmpx = x + dir[i][0];
    int tmpy = y + dir[i][1];
    if (ok(tmpx, tmpy) && a[tmpx][tmpy] == dirChar[i] &&
        (tmpx != xx || tmpy != yy)) {
      node tmpNode = node(xx, yy, tmpx + dir[i][0], tmpy + dir[i][1]);
      tmpNode.adjust();
      tmpNodes[ret] = tmpNode;
      ret++;
    }
  }
  return ret;
}
void dfs(node x) {
  node tmpNodes[4];
  int num = check(x.x1, x.y1, x.x2, x.y2, tmpNodes);
  for (int i = 0; i < num; i++) {
    if (!find(tmpNodes[i]))
      dfs(tmpNodes[i]);
  }
  num = check(x.x2, x.y2, x.x1, x.y1, tmpNodes);
  for (int i = 0; i < num; i++) {
    if (!find(tmpNodes[i]))
      dfs(tmpNodes[i]);
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    ans = 0;
    memset(has, 0, sizeof(has));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'U' || a[i][j] == 'L') {
          node tmp = getNode(i, j);
          if (!find(tmp)) {
            char ch1, ch2;
            ch1 = a[tmp.x1][tmp.y1];
            ch2 = a[tmp.x2][tmp.y2];
            a[tmp.x1][tmp.y1] = '\0';
            a[tmp.x2][tmp.y2] = '\0';
            dfs(tmp);
            a[tmp.x1][tmp.y1] = ch1;
            a[tmp.x2][tmp.y2] = ch2;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}
