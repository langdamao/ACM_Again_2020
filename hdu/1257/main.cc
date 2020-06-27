#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;
set<int> s;
set<int>::iterator it;
const int N = 1e6 + 5;
int a[N];
int n;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    s.clear();
    for (int i = 0; i < n; i++) {
      it = s.lower_bound(a[i]);
      if (it != s.end()) {
        s.erase(it);
      }
      s.insert(a[i]);
    }
    printf("%lu\n", s.size());
  }
  return 0;
}
