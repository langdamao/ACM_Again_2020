#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int x,wei;
}sorts[105];
vector<node> v[105];
vector<int> wei[105];
int st[105],res[105],ans[1005];
bool cmp(const node& x,const node& y){
	if (x.x!=y.x) return x.x<y.x;
	return x.wei<y.wei;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);

	while(T--){
		int c,d;
		scanf("%d%d",&c,&d);
		for (int i=0;i<=c;i++) wei[i].clear();
		memset(res,0,sizeof(res));
		int nowi=0;
		for (int i=2;i<=c;i++){
			scanf("%d",&st[i]);
			if (st[i]<0){
				st[i]=-st[i];
				wei[st[i]].push_back(i);
			}
			else {
				res[i]=st[i];
				st[i]=0;
				node tmp;
				tmp.x = res[i];
				tmp.wei = i;
				sorts[nowi++] =  tmp;
			}
		}
		sort(sorts,sorts+nowi,cmp);
		int nowx=0,nowy=0;
		for (int i=1;i<c;i++){
			if (i<=nowy) continue;
			if (wei[i].size()==0){
				wei[i].push_back(sorts[nowx].wei);
				st[sorts[nowx].wei]=i;
				nowx++;
				nowy++;
			}
			else nowy+=wei[i].size();
		}
		st[1]=0;
		res[1]=0;
		int x,y;
		for (int i=0;i<=c;i++) v[i].clear();
		for (int i=0;i<d;i++){
			scanf("%d%d",&x,&y);
			node tmp;tmp.x=y;tmp.wei=i;
			v[x].push_back(tmp);
			tmp.x=x;
			v[y].push_back(tmp);
		}
		int now=0;
		for (int i=0;i<d;i++) ans[i]=1;
		for (int i=1;i<c;i++){
			if (wei[i].size()==0) continue;
			int nowbefore = now+1;
			for (int k=0;k<wei[i].size();k++){
				x=wei[i][k];
				for (int j=0;j<v[x].size();j++){
					y = v[x][j].x;
					if (st[y]<st[x]){
						if (res[x]!=0)
						ans[v[x][j].wei]=max(res[x]-res[y],1);
						else 
						ans[v[x][j].wei]=max(now+1-res[y],1);

					}
				}
				if (res[x]==0)
				res[x]=now+1;
				nowbefore = res[x];
			}
			now= nowbefore;
		}
		printf("Case #%d:",ca++);
		for (int i=0;i<d;i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
