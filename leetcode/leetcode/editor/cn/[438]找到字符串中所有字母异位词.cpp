//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 862 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> smap,has;
        smap.clear(); has.clear();
        for (auto& ch:p){
            smap[ch]++;
        }
        int left = 0;
        int num=0;
        vector<int>ret;
        for (int i = 0;i<s.length();i ++){
            char ch = s[i];
            if (smap.find(ch) == smap.end()) {
                has.clear();
                num=0;
                left = i+1;
                continue;
            }
            has[ch]++;
            if (smap[ch] == has[ch]) num++;
            while (smap[ch] < has[ch] && left<=i){
                if (has[s[left]] == smap[s[left]]) num--;
                has[s[left]]--;
                left++;
            }
            if (num == smap.size()) ret.push_back(left);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
