#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[1005][1005];
int n;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int sum=0;
		for (int i=0;i<n;i++){
			sum+=a[i][i];
		}
		int r=0,c=0;
		int tmp[1005];
		for (int i=0;i<n;i++){
			memset(tmp,0,sizeof(tmp));
			for (int j=0;j<n;j++){
				if (tmp[a[i][j]]!=0){
					r++;
					break;
				}
				tmp[a[i][j]]++;
			}
		}
		for (int i=0;i<n;i++){
			memset(tmp,0,sizeof(tmp));
			for (int j=0;j<n;j++){
				if (tmp[a[j][i]]!=0){
					c++;
					break;
				}
				tmp[a[j][i]]++;
			}
		}
		printf("Case #%d: %d %d %d\n",ca++,sum,r,c);
	}
	return 0;
}
