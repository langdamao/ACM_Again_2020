#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[11] = "codeforces";
long long a[11], ans[11];
int main() {
  long long n;
  while (scanf("%lld", &n) != EOF) {
    long long t = pow(n, 0.1);
    long long now = 1;
    for (int i = 0; i < 10; i++) {
      a[i] = t;
      now *= t;
    }
    // cout<<t<<endl;
    for (int i = 0; i < 10; i++) {
      if (now < n) {
        now = now / a[i];
        a[i]++;
        now *= a[i];
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < a[i]; j++) {
        printf("%c", str[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
