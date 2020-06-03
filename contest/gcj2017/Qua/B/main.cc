#include <cstdio>
#include <cstring>

char str[100];

int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		int l=strlen(str);
		int i=0;
		while(i+1<l&&str[i]<=str[i+1]) i++;
		if(i+1<l){
			while(i>0&&str[i]-str[i-1]<1) i--;
			str[i]=str[i]-1;
			for (int j=i+1;j<l;j++){
				str[j]='9';
			}
		}
		i=0;
		while(i<l&&str[i]=='0') i++;
		printf("Case #%d: ",ca++);
		for (;i<l;i++) printf("%c",str[i]);
		puts("");
	}
}
