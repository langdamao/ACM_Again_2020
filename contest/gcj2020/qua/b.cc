#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[105],ans[100005];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		int now=0;
		int last=0;
		int len = strlen(str);
		for (int i=0;i<len;i++){
			int tmp = str[i]-'0';
			if (tmp>last){
				for (int j=0;j<tmp-last;j++){
					ans[now++]='(';
				}
			}
			else if (tmp<last){
				for (int j=0;j<last-tmp;j++){
					ans[now++]=')';
				}
			}
			ans[now++]=str[i];
			last=tmp;
		}
		if (str[len-1]-'0'>0){
			for (int j=0;j<str[len-1]-'0';j++){
				ans[now++]=')';
			}
		}
		ans[now++]='\0';
		printf("Case #%d: %s\n",ca++,ans);
	}
	return 0;
}
