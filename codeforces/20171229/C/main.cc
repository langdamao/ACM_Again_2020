#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, r;
int a[1005];
double ansy[1005];
double cal(int x, int y) {
  if (abs(a[x] - a[y]) > r * 2)
    return r;
  return ansy[y] + sqrt(4.0 * r * r - ((double)a[x] - a[y]) * (a[x] - a[y]));
}
double gety(int x) {
  double ret = r;
  for (int i = 0; i < x; i++) {
    ret = max(ret, cal(x, i));
  }
  return ret;
}
int main() {
  while (scanf("%d%d", &n, &r) != EOF) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
      ansy[i] = gety(i);
    }
    for (int i = 0; i < n; i++) {
      if (i)
        printf(" ");
      printf("%.10lf", ansy[i]);
    }
    printf("\n");
  }
  return 0;
}
