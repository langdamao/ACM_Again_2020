#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
class  LuckyElevator{
    public:
    bool Not(int x){
		while(x){
			if (x%10==4) return false;
			x=x/10;
		}
		return true;
	}
    int actualFloor(int buttonPressed) {
		int ans=0;
		for (int i=1;i<=buttonPressed;i++){
			if (Not(i)) ans++;
		}
        return ans;
    }
};
int main(){
	int n;
	LuckyElevator l;
	scanf("%d",&n);
	cout<<l.actualFloor(n)<<endl;
	return 0;
}
