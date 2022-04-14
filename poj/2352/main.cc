#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N =15005;
struct node {
	int x,y;
}a[N];
inline bool cmp(const node&x,const node&y){
	if (x.x!=y.x) return x.x<y.x;
	else return x.y<y.y;
}
const int M= 32005;

int d[M];
int ans[N];
inline int lowbit(int x) {
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
void update(int x){
	while(x<=M){
		d[x]+=1;
		x+=lowbit(x);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x++;
		a[i].y++;
	}
	sort(a,a+n,cmp);
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	for (int i=0;i<n;i++){
		int y = a[i].y;
		ans[sum(y)]++;
		update(y);
	}
	for (int i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
