//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window


//leetcode submit region begin(Prohibit modification and deletion)
#include <cmath>
#include <cstring>
#include <string>
#include <string>
class Solution {
public:
    int hash[256];
    int getHash(char c){
      return (int)c;
    }
    int lengthOfLongestSubstring(string s) {
      int len = s.length();
      int now=0;
      int last=-1;
      int ans=0;
      memset(hash,-1,sizeof(hash));
      for (int i=0;i<len;i++){
          char c = s[i];
          int hashCode = getHash(c);
          if (hash[hashCode]<=last){
            now++;
            ans = max(ans,now);
          }
          else {
            now = i-hash[hashCode];
            last = hash[hashCode];
          }
          hash[hashCode]=i;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
