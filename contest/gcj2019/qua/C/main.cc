#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,l;
int pro[105];
char ans[105];
int gcd(int x,int y){
	int tmp;
	while(x!=0){
		tmp = y%x;
		y=x;
		x=tmp;
	}
	return y;
}
struct node{
	int x;
	int wei;
}pri[105];
inline bool cmp(const node&x,const node &y){
	if (x.x!=y.x) return x.x<y.x;
	return x.wei<y.wei;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&l);
		for (int i=0;i<l;i++){
			scanf("%d",&pro[i]);
		}
		int got=l+l;
		for (int i=1;i<l;i++){
			if (pro[i]!=pro[i-1]){
				pri[i].x=gcd(pro[i],pro[i-1]);
				pri[i].wei=i;
				got=i;
			}
		}
		for (int i=got-1;i>=0;i--){
			pri[i].x=pro[i]/pri[i+1].x;
			pri[i].wei=i;
		}
		for (int i=got+1;i<=l;i++){
			pri[i].x=pro[i-1]/pri[i-1].x;
			pri[i].wei=i;
		}
		sort(pri,pri+l+1,cmp);
		char nowch='A';
		int now=pri[0].x;
		for (int i=0;i<=l;i++){
			if(pri[i].x!=now) {
				now=pri[i].x;
				nowch++;
			}
			ans[pri[i].wei]=nowch;
		}
		ans[l+1]='\0';
		printf("Case #%d: %s\n",ca++,ans);
	}
	return 0;
}
