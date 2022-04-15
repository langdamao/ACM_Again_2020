#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N =50005;
int a[N],d[N];
int n,x,y,ca;
char str[10];

inline int lowbit(int &x){
	return x&(-x);
}
int sum(int x){
	int ret=0;
	while(x>0){
		ret+=d[x];
		x-=lowbit(x);
	}
	return ret;
}
void update(int x,int k){
	while(x<=n){
		d[x]+=k;
		x+=lowbit(x);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	ca=1;
	while(T--){
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			update(i+1,a[i]);
		}
		printf("Case %d:\n",ca++);
		while(scanf(" %s",str)!=EOF){
			if (str[0]=='E') break;
			if (str[0]=='Q'){
				scanf("%d%d",&x,&y);
				printf("%d\n",sum(y)-sum(x-1));
			}
			else if (str[0]=='A'){
				scanf("%d%d",&x,&y);
				update(x,y);
			}
			else {
				scanf("%d%d",&x,&y);
				update(x,-y);
			}
		}
	}
	return 0;
}
