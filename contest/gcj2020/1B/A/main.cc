#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
char dirx[3]="EW";
char diry[3]="NS";
int bu(int x){
	int tmp=1;
	while(tmp<=x){
		tmp<<=1;
	}
	int fan = (tmp-1)^x;
	return tmp+fan+1;
}
bool ok(int x,int y){
	if ((x&y)!=0) return false;
	int tmp = (x|y);
	while(tmp!=0){
		if (tmp%2==0) return false;
		tmp>>=1;
	}
	return true;
}
void getans(int ansx,int ansy,int ansi,int x,int y,int ca){
	printf("Case #%d: ",ca++);
	int sx=0,sy=0;
	if (x<0) sx=1-sx;
	if (y<0) sy=1-sy;
	if (ansi/2) sx=1-sx;
	if (ansi%2) sy=1-sy;
	char str[1005];
	int wei=0;
	while(ansx>0||ansy>0){
		if (ansx%2){
			if (ansx==1 && ansi/2>0){
				str[wei++]=dirx[1-sx];
			}
		    else		str[wei++]=dirx[sx];
		}
		if (ansy%2){
			if (ansy==1 && ansi%2>0){
				str[wei++]=diry[1-sy];
			}
			else
				str[wei++]=diry[sy];
		}
		ansx>>=1;
		ansy>>=1;
	}
	str[wei]='\0';
	printf("%s\n",str);
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	int x,y;
	while(T--){
		scanf("%d%d",&x,&y);
		int xx = abs(x);
		int yy = abs(y);
		int ansx,ansy,ansi;
		bool got=false;
		for (int i=0;i<4;i++){
			int tmpx = xx;
			int tmpy = yy;
			if (i%2>0) { 
				tmpy = bu(tmpy);
			}
			if (i/2>0){
				tmpx = bu(tmpx);
			}
			if (ok(tmpx,tmpy)){
				got = true;
				ansi= i;
				ansx=tmpx;
				ansy=tmpy;
				break;
			}
		}
		if (got){
		getans(ansx,ansy,ansi,x,y,ca);
		ca++;
		}
		else {
			printf("Case #%d: IMPOSSIBLE\n",ca++);
		}
	}
}

