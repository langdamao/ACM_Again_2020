#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char n[105];
int len;
int ansa[105],ansb[105];
bool all0;
int ans[10][2]={
	0,0,
	0,1,
	1,1,
	1,2,
	2,2,
	2,3,
	3,3,
	2,5,
	3,5,
	3,6
};
void cal(int index){
	int x = n[index]-'0';
	ansa[index]=ans[x][0];
	ansb[index]=ans[x][1];
	if (ansa[index]!=0) all0=false;
	return ;
}
void print(int x[]){
	printf(" ");
	int i=0;
	while(i<len && x[i]==0) i++;
	for (;i<len;i++){
		printf("%d",x[i]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	int ca=1;
	while(T--){
		all0=true;
		scanf("%s",n);
		len=strlen(n);
		for (int i=0;i<len;i++){
			cal(i);
		}
		if (all0){
			ansb[0]--;
			for (int i=1;i<len;i++){
				if (n[i-1]=='1') {
					ansa[i]=5;
					ansb[i]=5;
				}
				else {
					ansa[i]=0;
					ansb[i]=0;
				}
			}
			if (n[len-1] == '1') ansb[len-1]++;
		}
		printf("Case #%d:",ca++);
		print(ansa);
		print(ansb);
		printf("\n");
	}
	return 0;
}

