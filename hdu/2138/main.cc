#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
// int pow(int a,int d,int n){
// if (d==1) return a%n;
// int tmp = pow(a,d/2,n);
// if ((d&1)==0) return ((long long)tmp)*tmp%n;
// else return ((long long)tmp)*tmp%n*a%n;
//}
int pow(int a, int d, int n) {
  long long ans = 1L;
  long long now = (long long)a % n;
  while (d > 0) {
    if ((d & 1) == 1)
      ans *= now;
    now *= now;
    ans %= n;
    now %= n;
    d >>= 1;
  }
  return ans;
}
int isPrime(int n) {
  if (n == 2)
    return true;
  if (n < 2 || (n & 1) == 0)
    return false;
  int d = n - 1;
  int r = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }
  for (int t = 0; t < 10; t++) {
    int a = rand() % (n - 3) + 2;
    int tmp = pow(a, d, n);
    // cout<<tmp<<' '<<a<<' '<<' '<<d<<' '<<n<<endl;
    int tmp_next;
    for (int i = 0; i < r; i++) {
      tmp_next = ((long long)tmp) * tmp % n;
      // cout<<i<<' '<<tmp<<' '<<tmp_next<<endl;
      if (tmp_next == 1 && (tmp != 1 && tmp != (n - 1))) {
        return false;
      }
      tmp = tmp_next;
    }
    if (tmp != 1)
      return false;
  }
  return true;
}
int main() {
  int n, x;

  while (scanf("%d", &n) != EOF) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (isPrime(x))
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
