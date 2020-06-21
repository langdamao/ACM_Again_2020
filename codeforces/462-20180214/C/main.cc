#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double eps = 1e-8;
struct circle {
  int x, y, r;
} a[5];
int anss[5][5][5];
int n;
double getdir(int x, int y) {
  return sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) +
              (a[x].y - a[y].y) * (a[x].y - a[y].y));
}
int getty(int x, int y) {
  double dir = getdir(x, y);
  int maxr = max(a[x].r, a[y].r);
  int minr = min(a[x].r, a[y].r);
  if (dir < maxr - minr - eps)
    return 0;
  if (fabs(dir - (maxr - minr)) <= eps)
    return 1;
  if (dir > (maxr - minr) + eps && dir + eps < (maxr + minr))
    return 2;
  if (fabs(dir - (maxr + minr)) <= eps)
    return 3;
  if (dir > maxr + minr + eps)
    return 4;
  return 0;
}
int getans(int ty0, int ty1, int ty2) {
  if (ty1 > ty2)
    swap(ty1, ty2);
  if (ty0 > ty1)
    swap(ty0, ty1);
  if (ty1 > ty2)
    swap(ty1, ty2);
  return anss[ty0][ty1][ty2];
}

int main() {
  memset(anss, 0, sizeof(anss));
  anss[0][0][0] = 4;
  anss[0][0][1] = 4;
  anss[0][0][2] = 5;
  anss[0][0][3] = 4;
  anss[0][0][4] = 4;
  anss[0][1][1] = 4;
  anss[0][1][2] = 5;
  anss[0][1][3] = 4;
  anss[0][1][4] = 4;
  anss[0][2][2] = 6;
  anss[0][2][3] = 5;
  anss[0][2][4] = 5;
  anss[0][3][3] = 4;
  anss[0][3][4] = 4;
  anss[0][4][4] = 4;
  anss[1][1][1] = 4;
  anss[1][1][2] = 6;
  anss[1][1][3] = 5;
  anss[1][1][4] = 4;
  anss[1][2][2] = 7;
  anss[1][2][3] = 6;
  anss[1][2][4] = 5;
  anss[1][3][3] = 4;
  anss[1][3][4] = 4;
  anss[1][4][4] = 4;
  anss[2][2][2] = 8;
  anss[2][2][3] = 7;
  anss[2][2][4] = 6;
  anss[2][3][3] = 6;
  anss[2][3][4] = 5;
  anss[2][4][4] = 5;
  anss[3][3][3] = 5;
  anss[3][3][4] = 4;
  anss[3][4][4] = 4;
  anss[4][4][4] = 4;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
  }
  if (n == 1)
    printf("2\n");
  else if (n == 2) {
    int ty = getty(0, 1);
    // printf("%d\n",ty);
    if (ty == 2)
      printf("4\n");
    else
      printf("3\n");
  } else if (n == 3) {
    int ty0 = getty(0, 1);
    int ty1 = getty(1, 2);
    int ty2 = getty(0, 2);
    // printf("%d %d %d\n",ty0,ty1,ty2);
    printf("%d\n", getans(ty0, ty1, ty2));
  }
}
