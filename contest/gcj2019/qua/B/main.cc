#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
char str[50005],ans[50005];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",str);
		int len=strlen(str);
		for (int i=0;i<len;i++){
			if(str[i]=='S') ans[i]='E';
			else ans[i]='S';
		}
		ans[len]='\0';
		printf("Case #%d: %s\n",ca++,ans);
	}
	return 0;
}
