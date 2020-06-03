#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
char str[30][30];
int n,m;
char now;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%s",str[i]);
		for (int i=0;i<n;i++){
			now='?';
			for (int j=0;j<m;j++){
				if(str[i][j]=='?') 
					str[i][j]=now;
				else {
					if(now=='?'){
						for (int k=0;k<j;k++) str[i][k]=str[i][j];
					}
					now=str[i][j];
				}
			}
		}
		for (int j=0;j<m;j++){
			now='?';
			for (int i=0;i<n;i++){
				if(str[i][j]=='?') 
					str[i][j]=now;
				else {
					if(now=='?'){
						for (int k=0;k<i;k++) str[k][j]=str[i][j];
					}
					now=str[i][j];
				}
			}
		}
		printf("Case #%d:\n",ca++);
		for (int i=0;i<n;i++){
			printf("%s\n",str[i]);
		}
	}
	return 0;
}
