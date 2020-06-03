#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N=55;
int use[N];
int have[N][N];
int now[N];
int n,p;
bool toend(){
	for (int i=0;i<n;i++) if(now[i]>=p) return true;
	return false;
}
void alladd(){
	for (int i=0;i<n;i++) now[i]++;
}
double calbi(int i){
	return (double)have[i][now[i]]/(double)use[i];
}
void addsmall(){
	double sma=calbi(0);
	int one=0;
	for (int i=1;i<n;i++){
		double tmp = calbi(i);
		if(tmp<sma){
			sma=tmp;one=i;
		}
	}
	now[one]++;
}
bool can(){
	double tmp[55];
	for (int i=0;i<n;i++) tmp[i]=calbi(i);
	sort(tmp,tmp+n);
	int mi=tmp[0]/0.9;
	int ma=ceil(tmp[n-1]/1.1);
	if(mi>0&& mi>=ma) return true;
	return false;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		for (int i=0;i<n;i++) scanf("%d",&use[i]);
		for (int i=0;i<n;i++){
			for (int j=0;j<p;j++) scanf("%d",&have[i][j]);
			sort(have[i],have[i]+p);
		}
		memset(now,0,sizeof(now));
		int ans=0;
		while(true){
			if(toend()) break;
			if(can()) ans++,alladd();
			else addsmall();
		}
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}

