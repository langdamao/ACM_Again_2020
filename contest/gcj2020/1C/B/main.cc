#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int times[100],first[100];
bool has[100];

int main(){
	int T,ca=1,U;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&U);
		memset(has,0,sizeof(has));
		memset(times,0,sizeof(times));
		memset(first,0,sizeof(first));

		char x[1000],str[1000];
		for (int i=0;i<10000;i++){
			scanf("%s %s",x,str);
			first[str[0]-'A']=first[str[0]-'A']+1;
			if (( x[0]!='-' && strlen(x)==strlen(str)) || (x[0]=='-'&& strlen(str)==U)) {
				times[str[0]-'A']=times[str[0]-'A']+1;
			}
			for (int j=0;j<strlen(str);j++){
				has[str[j]-'A']=1;
			}
		}
		char ans[1000];
		for (int i=0;i<26;i++){
			if (has[i]&&first[i]==0) {
				ans[0]=(char)('A'+i);
				break;
			}
		}
		int now=1;
		while(now<10){
			int maxtime=0;
			int maxi = -1;
			for (int i=0;i<26;i++){
				if (times[i]>maxtime){
					maxtime = max(times[i],maxtime);
					maxi = i;
				}
			}
			ans[now]=(char)('A'+maxi);
			times[maxi]=0;
			now++;
		}
		ans[10]='\0';
		printf("Case #%d: %s\n",ca++,ans);
	}
}
