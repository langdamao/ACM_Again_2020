#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int maxn = 1e7;
vector<int> prime;
int ans[500005][2];
int a[10000005];
void doprime() {
  int size = 0;
  memset(a, 0, sizeof(a));
  prime.clear();
  for (int i = 2; i <= maxn; i++) {
    if (!a[i]) {
      prime.push_back(i);
      size++;
    }
    for (int j = 0; prime[j] * i <= maxn && j < size; j++) {
      a[prime[j] * i] = prime[j];
      if (i % prime[j] == 0)
        break;
    }
  }
}
int main() {
  doprime();
  int n, x;
  // cout<<1<<endl;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      // cout<<x<<endl;
      if (a[x] == 0)
        ans[i][0] = ans[i][1] = -1;
      else {
        // cout<<x<<' '<<ans[i][0]<<endl;
        ans[i][0] = a[x];
        while (x % ans[i][0] == 0)
          x /= ans[i][0];
        if (x == 1)
          ans[i][0] = ans[i][1] = -1;
        else {
          ans[i][1] = x;
        }
      }
    }
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n; i++) {
        if (i == 0)
          printf("%d", ans[i][j]);
        else
          printf(" %d", ans[i][j]);
      }
      printf("\n");
    }
  }
}
