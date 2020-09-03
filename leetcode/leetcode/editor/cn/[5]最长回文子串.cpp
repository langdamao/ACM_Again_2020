//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    struct node {
//      node(){};
//      node(int _x,int _l,int _r):x(_x),l(_l),r(_r){};
//      int x=0;
//      int l,r;
//    }ans;
//    void updateAns(node x){
//      if (x.x>ans.x){
//        ans=x;
//      }
//    }
//    void getMaxLen(int x,string& s,int& len){
//      int i=0;
//      int ret=0;
//      while(x-i>=0 && x+i<len && s[x-i]==s[x+i]){
//        ret+=2;
//        i++;
//      }
//      updateAns(node(ret-1,x-i+1,x+i-1));
//      if (x==len-1) return ;
//      ret=0;
//      i=0;
//      while(x-i>=0&& x+i+1<len && s[x-i]==s[x+1+i]){
//        ret+=2;
//        i++;
//      }
//      updateAns(node(ret,x-i+1,x+i));
//      return;
//    }
//    string longestPalindrome(string s) {
//        int len = s.length();
//        if (len<=1) return s;
//
//        for (int i=0;i<len;i++) {
//          getMaxLen(i,s,len);
//        }
//        return s.substr(ans.l,ans.x);
//    }
      string longestPalindrome(string s) {
          int len = s.length();
          if (len<=1) return s;
          len = len*2+3;
          char str[2005];
          str[0]='$';
          str[1]='#';
          int now=2;
          for (char ch :s){
            str[now++]=ch;
            str[now++]='#';
          }
          str[now]='\0';
          int p[len];
          memset(p,0,sizeof(p));
          int id=-1;
          int mx=-1;
          int ret=0;
          int ansx;
          for (int i=1;i<len;i++){
            if (i<mx){
              p[i]=min(mx-i,p[id+id-i]);
            }
            else {
              p[i]=1;

            }
            while(str[i-p[i]]==str[i+p[i]]) p[i]++;
            if (p[i]+i>mx){
              mx=p[i]+i;
              id=i;
            }
            if (p[i]>ret){
              ansx=i;
              ret=p[i];
            }
          }
          return s.substr((ansx-ret)/2,ret-1);
      }
};
//leetcode submit region end(Prohibit modification and deletion)
