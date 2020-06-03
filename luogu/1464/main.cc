#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long f[25][25][25];
bool have[25][25][25];
long long dfs(long long a, long long b, long long c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return dfs(20, 20, 20);
  if (have[a][b][c])
    return f[a][b][c];
  if (a < b && b < c) {
    f[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
  } else {
    f[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) +
                 dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
  }
  have[a][b][c] = true;
  return f[a][b][c];
}

int main() {
  memset(f, 0, sizeof(f));
  memset(have, 0, sizeof(have));
  long long a, b, c;
  while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
    if (a == -1 && b == -1 && c == -1)
      break;
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
  }
  return 0;
}
