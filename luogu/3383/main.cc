#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e8 + 1;
int prime[N];
int v[N / 10];
void pri(int n) {
  memset(prime, 0, sizeof(prime));
  int num = 0;
  for (int i = 2; i <= n; i++) {
    if (prime[i] == 0) {
      v[num++] = i;
      prime[i] = i;
    }
    for (int j = 0; j < num && v[j] <= prime[i] && v[j] * i <= N; j++) {
      prime[i * v[j]] = v[j];
    }
  }
}
int main() {
  int n, m, t;
  while (scanf("%d%d", &n, &m) != EOF) {
    pri(n);
    for (int i = 0; i < m; i++) {
      scanf("%d", &t);
      printf("%d\n", v[t - 1]);
    }
  }
  return 0;
}
