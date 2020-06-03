#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int pos(int x,int y){
	return abs(x)+abs(y);
}
map<char,int> dirx;
map<char,int> diry;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	dirx.clear();
	dirx['S']=0;dirx['N']=0;dirx['W']=-1;dirx['E']=1;
	diry.clear();
	diry['S']=-1;diry['N']=1;diry['W']=0;diry['E']=0;
	while(T--){
		int x,y;
		char str[10000];
		scanf("%d%d %s",&x,&y,str);
		int now=0;
		int len= strlen(str);
		while(now<=len&& pos(x,y)>now){
			if (now<len){
				x +=dirx[str[now]];
				y +=diry[str[now]];
			}
			now++;
		}
		printf("Case #%d: ",ca++);
		if (now>len){
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n",now);
		}
	}
	return 0;
}
