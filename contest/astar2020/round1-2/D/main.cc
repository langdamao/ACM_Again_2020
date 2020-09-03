#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, ans;
int a[10];
bool have[10];
void dfs(int st, int k, int now, int tmpans, int end) {
  // cout<<st<<' '<<k<<' '<<now<<' '<<tmpans<<endl;
  if (st == end) {
    ans = min(ans, tmpans);
    if (ans <= (int)(0.8 * n))
      return;
    return;
  }
  if (now > (n - ans))
    dfs(st + 1, 0, 0, max(tmpans, n - now), end);
  if (ans <= (int)(0.8 * n))
    return;
  for (int i = k; i < 10; i++) {
    if (!have[i]) {
      have[i] = true;
      dfs(st, i + 1, now + a[i], tmpans, end);
      if (ans <= (int)(0.8 * n))
        return;
      have[i] = false;
    }
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    int tmp;
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      a[tmp % 10]++;
    }
    // for (int i=0;i<10;i++){
    // scanf("%d",&a[i]);
    //}
    sort(a, a + 10);
    ans = 0;
    for (int i = 0; i < 5; i++) {
      ans = max(ans, n - a[i] - a[9 - i]);
    }
    if (a[5] == 0)
      printf("%d\n", ans);
    else {
      memset(have, 0, sizeof(have));
      dfs(0, 0, 0, 0, 5);
      printf("%d\n", ans);
    }
  }
  return 0;
}
