#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N=1e5+5;
int n;
int x,y;
int d[N];
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
	while(scanf("%d",&n)!=EOF && n!=0){
		memset(d,0,sizeof(d));
		for (int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			update(x,1);
			update(y+1,-1);
		}
		for (int i=1;i<=n;i++){
			if (i!=1) printf(" ");
			printf("%d",sum(i));
		}
		puts("");
	}
	return 0;
}
