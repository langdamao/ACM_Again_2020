#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct node {
  node(int _x, int _k) : x(_x), k(_k){};
  long long x, k;
};
vector<node> a[2005];
long long visit[2005], mlen[2005], klen[2005], qu[2005], dp[3005][2005];
int n, m, q;
const long long mod = 1e9 + 7;
void calk(int x) {
  for (int i = 0; i < a[x].size(); i++) {
    klen[x] = max(klen[x], a[x][i].k);
  }
}
void bfs() {
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  for (int i = 1; i <= 3000; i++) {
    for (int j = 1; j <= n; j++) {
      for (int kk = 0; kk < a[j].size(); kk++) {
        int tmp = a[j][kk].x;
        if (dp[i - 1][tmp] != -1) {
          dp[i][j] = max(dp[i][j], dp[i - 1][tmp] + a[j][kk].k);
        }
        // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
      }
    }
  }
}
long long calstop(int x, long long now) {
  long long ret = 1e18;
  for (int i = 1; i <= n; i++) {
    if (klen[i] > klen[x] && mlen[i] != -1) {
      long long jiao =
          (mlen[x] - mlen[i] + klen[i] - klen[x] - 1) / (klen[i] - klen[x]) +
          3000;
      if (jiao > now && jiao < ret) {
        ret = jiao;
      }
    }
  }
  return ret;
}
long long calans(int x, long long st, long long en) {
  long long l = (en - st) % mod;
  long long mm = mlen[x] % mod * l % mod;
  long long kkn = l * (l - 1) / 2 % mod + (st - 3000) * l % mod;
  long long kk = kkn % mod * klen[x] % mod;
  // cout<<l<<' '<<mm<<' '<<kkn<<' '<<kk<<endl;
  return (mm + kk) % mod;
}
const double eps = 1e-8;
int doublecmp(double x, double y) {
  if (x + eps < y)
    return -1;
  if (x - eps > y)
    return 1;
  return 0;
}
int findMax(long long now) {
  int ret = -1;
  long long maxtmp = 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = klen[i] * (now - 3000) + mlen[i];
    if ((tmp > maxtmp || (tmp == maxtmp && klen[i] > klen[ret])) &&
        mlen[i] != -1) {
      ret = i;
      maxtmp = tmp;
    }
  }
  return ret;
}
int main() {
  while (scanf("%d%d%d", &n, &m, &q) != EOF) {
    int x, y, k;
    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &x, &y, &k);
      a[x].push_back(node(y, k));
      a[y].push_back(node(x, k));
    }
    memset(visit, -1, sizeof(visit));
    memset(mlen, 0, sizeof(mlen));
    memset(klen, 0, sizeof(klen));
    bfs();
    long long ans = 0;
    long long tmp = 0;
    for (int i = 1; i <= 3000; i++) {
      if (i > q)
        break;
      tmp = 0;
      for (int j = 1; j <= n; j++) {
        tmp = max(tmp, dp[i][j]);
      }
      // cout<<i<<' '<<tmp<<' '<<ans<<endl;
      ans += tmp % mod;
      ans %= mod;
    }
    tmp = 0;
    long long now = -1;
    for (int i = 1; i <= n; i++) {
      mlen[i] = dp[3000][i];
      calk(i);
    }
    long long nowx = 3001;
    while (1 && nowx <= q) {
      now = findMax(nowx);
      long long jiao = calstop(now, nowx);
      // cout<<"end"<<now<<' '<<jiao<<' '<<ans<<endl;
      if (jiao > q)
        jiao = q + 1;
      ans += calans(now, nowx, jiao);
      // cout<<"end"<<now<<' '<<jiao<<' '<<ans<<endl;
      ans %= mod;
      nowx = jiao;
      if (jiao > q)
        break;
    }
    if (nowx <= q) {
      ans += calans(now, nowx, q + 1);
      ans %= mod;
    }
    printf("%lld\n", ans);
  }
}
