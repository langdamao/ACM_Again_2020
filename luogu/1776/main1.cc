#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int n, m;
const int N = 100 + 5;
int v[N], w[N], c[N];
const int M = 40000 + 5;
int dp[M];
struct node {
  node(){};
  node(int _x, int _wei) : x(_x), wei(_wei){};
  int x, wei;
  bool operator<(const node &y) const {
    if (x != y.x)
      return x < y.x;
    return wei > y.wei;
  }
};

struct my_queue {
  node arr[M];
  int head, tail;
  void clear() {
    head = 0;
    tail = 0;
  }
  bool empty() { return head == tail; }
  void push(node x) {
    while (head != tail) {
      if (arr[tail - 1] < x)
        tail--;
      else
        break;
    }
    arr[tail] = x;
    tail++;
  }
  node pop() { return arr[head++]; }
  node top() { return arr[head]; }
} q;
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &v[i], &w[i], &c[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      for (int b = 0; b < w[i]; b++) {
        q.clear();
        int ci = 0;
        for (int k = m / w[i]; k >= 0; k--) {
          if (k * w[i] + b > m)
            continue;
          ci++;
          if (ci >= c[i])
            break;
          q.push(node(dp[k * w[i] + b] - k * v[i], k));
        }
        for (int k = m / w[i]; k >= 0; k--) {
          if (k * w[i] + b > m)
            continue;
          while (!q.empty() && q.top().wei > k)
            q.pop();
          if (k >= c[i])
            q.push(
                node(dp[(k - c[i]) * w[i] + b] - (k - c[i]) * v[i], k - c[i]));
          node tmp = q.top();
          dp[k * w[i] + b] = max(dp[k * w[i] + b], tmp.x + v[i] * k);
        }
      }
    }
    printf("%d\n", dp[m]);
  }
  return 0;
}
