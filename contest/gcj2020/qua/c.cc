#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
struct node {
	int st;
	int ed;
	int wei;
	char ans;
}a[1005];
inline bool cmp(const node &x,const node &y){
	if (x.ed!=y.ed) return x.ed<y.ed;
	return x.st<y.st;
}
inline bool cmpwei(const node &x,const node &y){
	if (x.wei!=y.wei) return x.wei<y.wei;
	return x.st<y.st;
}
int n;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d%d",&a[i].st,&a[i].ed);
			a[i].wei=i;
		}
		sort(a,a+n,cmp);
		int nowc=0,nowj=0;
		bool can=true;
		for (int i=0;i<n;i++){
			cout<<a[i].st<<' '<<a[i].ed<<' '<<nowc<<' '<<nowj<<endl;
			if (a[i].st>=nowc&& (nowc>=nowj || a[i].st<nowj)){
				a[i].ans='C';
				nowc=max(a[i].ed,nowc);
			}
			else if (a[i].st>=nowj&& (nowj>nowc || a[i].st<nowc)){
				a[i].ans='J';
				nowj=max(a[i].ed,nowj);
			}
			else if (a[i].st<nowc&&a[i].st<nowj){
				can=false;
				break;
			}
		}
		if (!can){
			printf("Case #%d: IMPOSSIBLE\n",ca++);
		}
		else {
			printf("Case #%d: ",ca++);
			sort(a,a+n,cmpwei);
			for (int i=0;i<n;i++){
				printf("%c",a[i].ans);
			}
			printf("\n");
		}
	}
	return 0;
}
