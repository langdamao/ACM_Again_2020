#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
char str[1000005];
char str1[1000005];
char ans_str[1000005];
int nextt[1000005];
int T;
int find(int len){
    nextt[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len - 1)
    {
        if (k == -1 || str[j] == str[k])
        {
            ++k;
            ++j;
            nextt[j] = k;
        }
        else
        {
            k = nextt[k];
        }
    }
	int i=-1;
	j=len;
	int ans=0;
	while(i<j){
		int ii = i+1;
		int jj = j-1;
		if (str[ii]!=str[jj]){
			if (ii==0) j--;
			i = nextt[ii]-1;
		}
		else {
			i++;
			j--;
		}
	}
	if (i==j) return i*2+1;
	else return i*2;
}
int main(){
    scanf("%d",&T);
	while(T--){
	   scanf("%s",str);	
	   int l=strlen(str);
	   int i=-1;
	   int j=l;
	   while(i<j){
		   i++;
		   j--;
		   ans_str[i]=str[i];
		   if(i==j || str[i]!=str[j]) {
			   i--;
			   break;
		   }
	   }
	   int ans=i+1;
	   for (int k=i+1;k<l;k++){
		   str[k-i-1]=str[k];
	   }
	   l = l-ans*2;
	   int x = find(l);
	   for (int k=0;k<x;k++){
		   ans_str[ans+k]=str[k];
	   }
	   for (int k=0;k<ans;k++){
		   ans_str[ans+x+k]=ans_str[ans-1-k];
	   }
	   for (int k=0;k<l;k++){
		   str1[k]=str[l-1-k];
	   }
	   for (int k=0;k<l;k++){
		   str[k]=str1[k];
	   }
	   int y = find(l);
	   if (y>x){
		   for (int k=0;k<y;k++){
			   ans_str[ans+k]=str[k];
		   }
		   for (int k=0;k<ans;k++){
			   ans_str[ans+y+k]=ans_str[ans-1-k];
		   }
	   }
	   ans = ans*2+max(x,y);
	   ans_str[ans]='\0';
	   printf("%s\n",ans_str);
	}
	return 0;
}

