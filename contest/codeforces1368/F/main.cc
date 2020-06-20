#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int ans[1005];
int k, num;
int main() {
  int n;
  v.reserve(1000);
  while (scanf("%d", &n) != EOF && n > 0) {
    int rn = n + 1;
    int best = 1;
    for (int i = 1; i <= n; i++) {
      int tmp = i + n / i + (n % i == 0 ? 0 : 1) - 1;
      if (rn > tmp) {
        rn = tmp;
        best = i;
      }
    }
    memset(ans, 0, sizeof(ans));
    int now = 1;
    int k = best;
    for (int i = 0; i < k; i++) {
      if (i >= n % k) {
        num = n / k;
      } else
        num = n / k + 1;
      ans[now++] = 0;
      for (int j = 1; j < num; j++) {
        ans[now++] = 1;
      }
    }
    int st = 0;
    k = n;
    while (st >= 0) {
      v.clear();
      for (int i = 0; i < k; i++) {
        int tmp = (i + st) % n;
        if (tmp == 0)
          tmp = n;
        if (ans[tmp] == 1) {
          v.push_back(tmp);
        }
      }
      if (v.size() < k) {
        k = v.size();
        printf("%lu", v.size());
        for (int i = 0; i < v.size(); i++) {
          printf(" %d", v[i]);
        }
        cout << endl;
        scanf("%d", &st);
      } else {
        cout << 0 << endl;
        st = -1;
        break;
      }
    }
  }
  return 0;
}
