#include <cstring>
#include <cstdio>
long long n,k;
struct node{
	long long l1,n1,l2,n2;
	node(){
		l1=n1=l2=n2=0;
	}
	node(long long ll1,long long nn1,long long ll2,long long nn2){
		l1=ll1;n1=nn1;l2=ll2;n2=nn2;
	}
};
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		long long ans;
		scanf("%lld %lld",&n,&k);
		node t=node(n,1,0,0);
		while(k>0){
			node tmp;
			k-=t.n1;
			if(k<=0) { ans=t.l1;break;}
			if(t.l1&1) {
				tmp.l1=t.l1/2;
				tmp.n1=t.n1*2;
			}
			else {
				tmp.l1=t.l1/2;
				tmp.l2=(t.l1-1)/2;
				tmp.n1=tmp.n2=t.n1;
			}
			if(t.n2==0) {t=tmp;continue;}
			k-=t.n2;
			if(k<=0) { ans=t.l2;break;}
			if(t.l2&1){
				if(t.l2/2==tmp.l1){
					tmp.l1=t.l2/2;
					tmp.n1+=t.n2*2;
				}
				else {
					tmp.l2=t.l2/2;
					tmp.n2+=t.n2*2;
				}
			}
			else {
				tmp.l1=t.l2/2;
				tmp.l2=(t.l2-1)/2;
				tmp.n1+=t.n2;
				tmp.n2+=t.n2;
			}
			t=tmp;
		}
		printf("Case #%d: ",ca++);
		if(ans&1) printf("%lld %lld\n",ans/2,ans/2);
		else  printf("%lld %lld\n",ans/2,ans/2-1);
	}

	return 0;
}

