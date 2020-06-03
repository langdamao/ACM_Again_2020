#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int num[4]={1,2,3,5};
double a[5];
double dp[100];
int n;
double cal(double x,int t){
	double ret=pow((1+a[t]),num[t])*x;
	return ret;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for (int i=0;i<4;i++) scanf("%lf",&a[i]);
		dp[0]=1.0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<4;j++){
				if(i>=num[j]){
					dp[i]=max(dp[i],cal(dp[i-num[j]],j));
				}
			}
		}
		printf("%.5lf\n",dp[n]);
	}
	return 0;
}

