#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[200005],b[200005];
int main(){
	while(scanf("%d",&n)!=EOF){
		for (int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		a[0]=b[0];
		a[1]=b[1]+b[0];
		int tmp = max(a[0],a[1]);
		for (int i=2;i<n;i++){
			a[i]=b[i]+tmp;
			tmp=max(tmp,a[i]);
		}
		for (int i=0;i<n;i++){
			if (i==0) printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
