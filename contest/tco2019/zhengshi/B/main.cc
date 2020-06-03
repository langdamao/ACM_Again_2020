#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int monNum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};	
class  SaturdayNightStay{
    public:
    int findDay(int day,int mon){
		int ret=0;
		for (int i=1;i<mon;i++){
			ret+=monNum[i];
		}
		ret+=day+1;
		//cout<<ret<<endl;;
		return ret;
	}
    int countOptions (int firstDay, int firstMonth, int lastDay, int lastMonth){
		int ans=0;
		int dayf = findDay(firstDay,firstMonth);
		int dayl = findDay(lastDay,lastMonth);
		for (int i=dayf;i<dayl;i++){
			if (i+(6-i%7)>dayl) continue;
			ans+=(dayl-i)-(6-i%7);
		//cout<<ans<<endl;
		}
        return ans;
    }
};
int main(){
	int n,n1,m,m1;
	SaturdayNightStay l;
	scanf("%d%d%d%d",&n,&n1,&m,&m1);
	cout<<l.countOptions(n,n1,m,m1)<<endl;
	return 0;
}
