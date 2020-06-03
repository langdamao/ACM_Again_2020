#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
//const int monNum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};	
const long long mod=1000000007;
class  TheUnexpectedSwap{
    public:
	int findExpectedResult(int digits, string prefN, int seed){
		long long a[200005],n[200005],shi[200005];
		a[0]=seed;
		for (int i=1;i<digits;i++){
			a[i]=(a[i-1]*1009+10009)%100019;
		}
		for (int i=0;i<prefN.length();i++){
			n[i]=prefN[i]-'0';
		}
		for (int i=prefN.length();i<digits;i++){
			n[i]=n[a[i]%i];
		}
		long long sum=0;
		for (int i=0;i<digits;i++) sum+=n[i];
		long long ans=0;
		shi[0]=1;
		long long other = (digits-1)*(digits-2)/2%mod;
		for (int i=1;i<digits;i++) shi[i]=shi[i-1]*10%mod;
		for (int i=0;i<digits;i++){
			long long tmp=shi[digits-1-i];
			long long qian = (n[i]*other%mod+(sum-n[i])%mod)%mod;
			ans+=qian*tmp%mod;
			ans%=mod;
		}
        return ans*2%mod;
    }
};
int main(){
	int n,n1;
	string str;
	TheUnexpectedSwap l;
	cin>>n>>str>>n1;
	cout<<l.findExpectedResult(n,str,n1)<<endl;
	return 0;
}
