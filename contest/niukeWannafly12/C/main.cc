#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
char str[100005];
int dp[100005][11][2];
int n,m;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		scanf(" %s",str);
		memset(dp,-1,sizeof(dp));
		int nowa=0;
		int nowb=0;
		for (int i=n-1;i>=0;i--){
			if(str[i]=='a') nowa++;
			else nowb++;
			dp[i][0][0]=nowa;
			dp[i][0][1]=nowb;
		}
		for (int i=n-1;i>=0;i--){
			for (int j=1;j<=m;j++){
				int ty=(str[i]-'a');
				if(i==(n-1)) {
					dp[i][j][ty]=1;
					dp[i][j][ty^1]=0;
				}
				else {
					dp[i][j][ty]=max(dp[i+1][j][ty]+1,dp[i+1][j-1][ty^1]+1);
					dp[i][j][ty^1]=dp[i+1][j][ty^1];
				}

				//cout<<i<<' '<<j<<' '<<ty<<' '<<(ty^1)<<' '<<dp[i][j][ty]<<' '<<dp[i][j][ty^1]<<endl;
			}
		}
		printf("%d\n",dp[0][m][0]);
	}
	return 0;
}
