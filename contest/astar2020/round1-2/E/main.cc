#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 1000
using namespace std;
string types[6] = {"012", "021", "102", "120", "201", "210"};
int getIndex(string str) {
  for (int i = 0; i < 6; i++) {
    if (str == types[i])
      return i;
  }
  return 7;
}
int getCost(int i, int j) {
  if ((i == 0 || i == 1) && j == 0)
    return 1;
  if ((i == 2 || i == 4) && j == 0)
    return 2;
  if ((i == 5 || i == 3) && j == 0)
    return 3;
  if ((i == 2 || i == 3) && j == 1)
    return 1;
  if ((i == 0 || i == 5) && j == 1)
    return 2;
  if ((i == 1 || i == 4) && j == 1)
    return 3;
  if ((i == 4 || i == 5) && j == 2)
    return 1;
  if ((i == 1 || i == 3) && j == 2)
    return 2;
  if ((i == 0 || i == 2) && j == 2)
    return 3;
  return 0;
}

bool vis[MAXN];
int n, m, s, t;
int u, v, c, w;
int cost[MAXN], pre[MAXN], last[MAXN], flow[MAXN];
int maxFlow, minCost;
struct Edge {
  int from, to, flow, cost;
} edge[MAXN];

int head[MAXN], num_edge;

queue<int> q;

void addedge(int from, int to, int flow, int cost) {
  // cout<<from<<' '<<to<<' '<<flow<<' '<<cost<<endl;
  edge[++num_edge].from = head[from];
  edge[num_edge].to = to;
  edge[num_edge].flow = flow;
  edge[num_edge].cost = cost;
  head[from] = num_edge;

  edge[++num_edge].from = head[to];
  edge[num_edge].to = from;
  edge[num_edge].flow = 0;
  edge[num_edge].cost = -cost;
  head[to] = num_edge;
}

bool SPFA(int s, int t) {
  memset(cost, 0x7f, sizeof(cost));
  memset(flow, 0x7f, sizeof(flow));
  memset(vis, 0, sizeof(vis));
  q.push(s);
  vis[s] = 1;
  cost[s] = 0;
  pre[t] = -1;

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = 0;
    for (int i = head[now]; i != -1; i = edge[i].from) {
      if (edge[i].flow > 0 && cost[edge[i].to] > cost[now] + edge[i].cost) {
        cost[edge[i].to] = cost[now] + edge[i].cost;
        pre[edge[i].to] = now;
        last[edge[i].to] = i;
        flow[edge[i].to] = min(flow[now], edge[i].flow);
        if (!vis[edge[i].to]) {
          vis[edge[i].to] = 1;
          q.push(edge[i].to);
        }
      }
    }
  }
  return pre[t] != -1;
}

void MCMF() {
  while (SPFA(s, t)) {
    int now = t;
    maxFlow += flow[t];
    minCost += flow[t] * cost[t];
    while (now != s) {
      edge[last[now]].flow -= flow[t];
      edge[last[now] ^ 1].flow += flow[t];
      now = pre[now];
    }
  }
}

int num[10], a[10];
char str[4];
int main() {
  int T, nn;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &nn, &a[0], &a[1], &a[2]);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < nn; i++) {
      scanf("%s", str);
      num[getIndex(str)]++;
    }
    memset(head, -1, sizeof(head));
    num_edge = -1; //初始化
    n = 6 + 3 + 2;
    m = 6 + 6 * 3 + 3;
    s = 10;
    t = 11;
    maxFlow = 0;
    minCost = 0;
    for (int i = 0; i < 6; i++) {
      addedge(s, i + 1, num[i], 0);
    }
    for (int i = 0; i < 3; i++) {
      addedge(i + 7, t, a[i], 0);
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 3; j++) {
        addedge(i + 1, j + 7, nn, getCost(i, j));
      }
    }

    MCMF();
    cout << maxFlow << ' ' << minCost << endl;
    printf("%d\n", nn * 4 - minCost);
  }
  return 0;
}
