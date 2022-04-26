//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。 
//
// 换句话说，s1 的排列之一是 s2 的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入：s1 = "ab" s2 = "eidbaooo"
//输出：true
//解释：s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入：s1= "ab" s2 = "eidboaoo"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s1.length, s2.length <= 10⁴ 
// s1 和 s2 仅包含小写字母 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 👍 648 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char,int> smap,has;
    bool checkInclusion(string s1, string s2) {
        smap.clear(); has.clear();
        for (auto& ch:s1){
            smap[ch]++;
        }
        int left = 0;
        int num=0;
        for (int i = 0;i<s2.length();i ++){
            char ch = s2[i];
            if (smap.find(ch) == smap.end()) {
                has.clear();
                num=0;
                left = i+1;
                continue;
            }
            has[ch]++;
            if (smap[ch] == has[ch]) num++;
            if (num == smap.size()) return true;
            while (smap[ch] < has[ch] && left<=i){
                if (has[s2[left]] == smap[s2[left]]) num--;
                has[s2[left]]--;
                left++;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
