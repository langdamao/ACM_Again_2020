#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N], aa[N];
set<int> s;
set<int>::iterator it;
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
      aa[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      c[i] = aa[b[i]];
    }
    s.clear();
    for (int i = 0; i < n; i++) {
      it = s.lower_bound(c[i]);
      if (it != s.end()) {
        s.erase(it);
      }
      s.insert(c[i]);
    }
    printf("%lu\n", s.size());
  }
  return 0;
}
