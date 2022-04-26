//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 10⁵ 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 👍 1821 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char,int> smap;
    unordered_map<char,int> has;
    int num = 0;
    bool update(char ch){
        if (smap.find(ch)==smap.end())  return num>=smap.size();
        has[ch]++;
        if (has[ch] == smap[ch]) num++;
        return num>=smap.size();
    }
    void calLeft(int & left, int i, string& s){
        while(left<i){
            if (smap.find(s[left])==smap.end()){
                left++;
                continue;
            }
            if (has[s[left]] <= smap[s[left]]){
                break;
            }
            has[s[left]]--;
            left++;
        }
    }
    string minWindow(string s, string t) {
        smap.clear(); has.clear();
        for (auto& c : t){
            smap[c]++;
        }
        int len = s.length();
        int left =0;
        string ans(len+1,'a');
        for (int i = 0;i<len;i++) {
            if (update(s[i])) {
                calLeft(left, i, s);
                if (i - left + 1 < ans.length()) {
                    ans = s.substr(left, i - left + 1);
                }
            }
        }
        if (ans.length()>len) return "";
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
