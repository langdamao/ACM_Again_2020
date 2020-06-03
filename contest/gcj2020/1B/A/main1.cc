#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
char ansdir[5]="NSEW";
struct node {
	int x,y,st,dir,be;
}q[1000005];
bool ok(int x,int y){
	return x>=-300 && x<=300 && y>=-300 && y<=300;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		int head=0,tail=0;
		node tnode;
		tnode.x=0;tnode.y=0;tnode.st=0;tnode.dir=-1;tnode.be=-1;
		q[head]=tnode;
		bool got=false;
		while(head<=tail && tail<=100000) {
			node tmp = q[head];
			if (tmp.x==x && tmp.y==y) {
				got=true;
				break;
			}
			for (int i=0;i<4;i++){
				int tmpx= dir[i][0]*(1<<tmp.st)+tmp.x;
				int tmpy= dir[i][1]*(1<<tmp.st)+tmp.y;
				if (ok(tmpx,tmpy) ){
					node tmpnode;
		            tmpnode.x=tmpx;tmpnode.y=tmpy;tmpnode.st=tmp.st+1;tmpnode.dir=i;tmpnode.be=head;
					q[++tail]=tmpnode;
				}
			}
			head++;
		}
		printf("Case #%d: ",ca++);
		if (got){
			int now=head;
			char ans[1005];
			int st=0;
			while(now>=0){
				if (q[now].be!=-1){
				ans[st++]=ansdir[q[now].dir];
				}
				now = q[now].be;
			}
			ans[st]='\0';
			for (int i=st-1;i>=0;i--){
				printf("%c",ans[i]);
			}
			printf("\n");
		}
		else printf("IMPOSSIBLE\n");
	}
}
