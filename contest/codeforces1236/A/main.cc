#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if (n==1) { printf("-1\n"); continue;}
		string str="9";
		for (int i=1;i<n;i++){
			str="2"+str;
		}
		if ((n-1)%9==0) str[0]='3';
		printf("%s\n",str.c_str());
	}
	return 0;
}
