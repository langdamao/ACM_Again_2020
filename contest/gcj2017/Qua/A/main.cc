#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;
char str[1005];
int k;
char changenot(char ch){
	if(ch=='+') return '-';
	else return '+';
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s %d",str,&k);
		int l=strlen(str);
		int ans=0;
		for (int i=0;i+k<=l;i++){
			if(str[i]=='+') continue;
			for (int j=0;j<k;j++) str[i+j]=changenot(str[i+j]);
			ans++;
		}
		for (int i=l-1;i+k>l;i--){
			if(str[i]=='-') {ans=-1;break;}
		}
		if(ans>=0) printf("Case #%d: %d\n",ca++,ans);
		else printf("Case #%d: IMPOSSIBLE\n",ca++);
	}
}

