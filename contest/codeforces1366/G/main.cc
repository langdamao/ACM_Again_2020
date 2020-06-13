#include <cstring>
#include <iostream>
using namespace std;
char stra[10005], strb[10005];
int dp[10005][10005];
int pre[10005];
int main() {
  while (scanf("%s%s", stra, strb) != EOF) {
    int la = strlen(stra);
    int lb = strlen(strb);
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < la; i++) {
      if (stra[i] == '.') {
        int num = 0;
        for (int j = i; j >= 0; j--) {
          num += (stra[j] == '.') ? 1 : -1;
          if (num <= 0 && j != i) {
            pre[i] = j;
            break;
          }
        }
        // cout<<i<< ' '<<pre[i]<<endl;
      }
    }
    for (int i = 0; i <= la; i++) {
      std::fill(dp[i], dp[i] + lb + 1, 1e9);
    }
    dp[0][0] = 0;
    for (int i = 1; i <= la; i++) {
      for (int j = 0; j <= lb; j++) {
        dp[i][j] = dp[i - 1][j] + 1;
        if (j != 0 && stra[i - 1] == strb[j - 1])
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        if (stra[i - 1] == '.' && pre[i - 1] != -1) {
          dp[i][j] = min(dp[i][j], dp[pre[i - 1]][j]);
        }
        // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
      }
    }
    printf("%d\n", dp[la][lb]);
  }
  return 0;
}
