#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_ANS = 1e4;
int n, dp[10001][7];
int ans(int x) {
  int ret = MAX_ANS;
  for (int i = 1; i <= 6; i++) {
    ret = min(ret, dp[x][i]);
  }
  if (ret == MAX_ANS)
    return -1;
  return ret;
}
// Solution 2
int cal(int x) {
  int ret = (x * 2 - 1) / 11 + 1;
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  for (int i = 2; i <= 6; i++)
    dp[0][i] = MAX_ANS;
  for (int i = 1; i <= 10000; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[i][j] = MAX_ANS;
      for (int k = 1; k <= 6; k++) {
        if (j + k == 7 || j == k)
          continue;
        if (i < j)
          continue;
        dp[i][j] = min(dp[i][j], dp[i - j][k] + 1);
      }
    }
  }
  //	for (int i=1;i<=10000;i++) {
  //		if (ans(i)!=cal(i)){
  //			cout<<i<<' '<<ans(i)<<' '<<cal(i)<<endl;
  //		}
  //	}
  //	cout<<"end"<<endl;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", ans(n));
  }
  return 0;
}
