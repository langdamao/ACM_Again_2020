#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100005];
int n,m;
int getNext(int x,int id){
	return x+id+1;
}
int getBegin(int x){
	int tmp = (x+2)*2;
	int start = max(1,(int)sqrt(tmp)-5);
	for (int i=start;i*i<=tmp;i++){
		if ((i*(i+1))==tmp) return i-1;
	}
	return -1;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for (int i=0;i<m;i++) scanf("%d",&a[i]);
		int begin = getBegin(a[0]);
		if (begin == -1 ) printf("no\n");
		else {
			int now=a[0];
			bool get = false;
			for (int i=begin+1;i<begin+m;i++){
				now  = getNext(now,i);
				if (a[i-begin]!=now) {
					get = true;
					break;
				}
			}
			if (get) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}

