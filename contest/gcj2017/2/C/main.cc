#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
char ma[55][55];
char ansmap[55][55];
bool ans;
bool have[55][55];
bool check(){
	memset(have,0,sizeof(have));
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(ma[i][j]=='-'){
				for (int k=j-1;k>=0;k--) {
					if(ma[i][k]=='.') have[i][k]=true;
					else if(ma[i][k]=='#') break;
					else return false;
				}
				for (int k=j+1;k<m;k++){
					if(ma[i][k]=='.') have[i][k]=true;
					else if(ma[i][k]=='#') break;
					else return false;
				}
			}
			if(ma[i][j]=='|'){
				for (int k=i-1;k>=0;k--) {
					if(ma[k][j]=='.') have[k][j]=true;
					else if(ma[k][j]=='#') break;
					else return false;
				}
				for (int k=i+1;k<m;k++){
					if(ma[k][j]=='.') have[k][j]=true;
					else if(ma[k][j]=='#') break;
					else return false;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if(ma[i][j]=='.' && (!have[i][j])) return false;
		}
	}
	return true;
}
void copymap(){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			ansmap[i][j]=ma[i][j];
		}
	}
}
void dfs(int x,int y){
	if(ans) return ;
	if(y>=m) {dfs(x+1,0); return;}
	if(x>=n) {
		if(check()) {ans=true;copymap();return;}
		return ;
	}
	dfs(x,y+1);
	if(ma[x][y]=='-') {ma[x][y]='|'; dfs(x,y+1);ma[x][y]='-';}
	if(ma[x][y]=='|') {ma[x][y]='-'; dfs(x,y+1);ma[x][y]='|';}
	return ;
}
void print(){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			printf("%c",ansmap[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf(" %s",ma[i]);
		ans=false;
		dfs(0,0);
		if(ans){
			printf("Case #%d: POSSIBLE\n",ca++);
			print();
		}
		else {
			printf("Case #%d: IMPOSSIBLE\n",ca++);
		}
	}
	return 0;
}

