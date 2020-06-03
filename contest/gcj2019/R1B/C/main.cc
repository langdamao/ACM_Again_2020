#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k;
int a[100005],b[100005];
bool find(int l,int r){
	int maxa=a[l];
	int maxb=b[l];
	for (int i=l;i<=r;i++)maxa = max(maxa,a[i]);
	for (int i=l;i<=r;i++)maxb = max(maxb,b[i]);
	return abs(maxa-maxb)<=k;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=0;i<n;i++) {
			scanf("%d",&b[i]);
		}
		int ans=0;
		for (int i=0;i<n;i++){
			for (int j=i;j<n;j++){
			    if (find (i,j)) ans++;
			}
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}
