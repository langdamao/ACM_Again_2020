#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const double eps = 1e-8;

double cal(double x, double y, double b) {
  double xx = x;
  double yy = y;
  if (xx <= eps && xx >= -eps)
    xx = 1.0;
  if (yy <= eps && yy >= -eps)
    yy = 1.0;
  return xx / yy * b;
}
int main() {
  double a, b;
  int n;
  scanf("%lf%lf%d", &a, &b, &n);
  double x = 0.0;
  double y = 0.0;
  double tmp = 0.0;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &tmp);
    if (tmp > 0) {
      x += tmp;
    } else {
      y -= tmp;
    }
    printf("%.3lf\n", cal(x, y, b));
  }
  return 0;
}
