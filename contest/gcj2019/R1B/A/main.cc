#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int xsize,ysize,nowx,nowy;
struct node {
	int x,dir;
}xarr[505],yarr[505];
inline bool cmp(const node &x,const node &y){
	if (x.x!=y.x) return x.x<y.x;
	return x.dir<y.dir;
}


void deal(int x,int y,char d){
	
	if (d=='W'){
		xarr[xsize].x=x;
		xarr[xsize].dir=-1;
		if (x>0) nowx++;
		xsize++;
	}
	else if (d=='E'){
		xarr[xsize].x=x+1;
		xarr[xsize].dir=1;
		xsize++;
	}
	else if (d=='N'){
		yarr[ysize].x=y+1;
		yarr[ysize].dir=1;
		ysize++;
	}
	else if (d=='S'){
		yarr[ysize].x=y;
		yarr[ysize].dir=-1;
		ysize++;
		if (y>0) nowy++;
	}
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int p,q;
		scanf("%d%d",&p,&q);
		memset(xarr,sizeof(xarr),0);
		memset(yarr,sizeof(yarr),0);
		xsize=0;
		ysize=0;
		nowx=0;nowy=0;
		int x,y;char d;
		for (int i=0;i<p;i++){
			scanf("%d%d",&x,&y);
			cin>>d;
			deal(x,y,d);
		}
		sort(xarr,xarr+xsize,cmp);
		sort(yarr,yarr+ysize,cmp);
		int bestx = nowx;
		int besty = nowy;
		int bx=0;
		int by=0;
		int now=nowx;
		for (int i=0;i<xsize;i++){
			//cout<<i<<" "<<xarr[i].x<<' '<<xarr[i].dir<<' '<<now<<endl;
			//cout<<bestx<<' '<<bx<<endl;
			now=now+xarr[i].dir;
			if (now>bestx) {
				bestx=now;
				bx=xarr[i].x;
			}
		}
		now=nowy;
		for (int i=0;i<ysize;i++){
			now=now+yarr[i].dir;
			if (now>besty) {
				besty=now;
				by=yarr[i].x;
			}
		}
		printf("Case #%d: %d %d\n",ca++,bx,by);
	}
}
