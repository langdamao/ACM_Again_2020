//给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target 的索引。你可以假设给定的数字一定存在于数组中。 
//
// 实现 Solution 类： 
//
// 
// Solution(int[] nums) 用数组 nums 初始化对象。 
// int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i 。如果存在多个有效的索引，则每
//个索引的返回概率应当相等。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["Solution", "pick", "pick", "pick"]
//[[[1, 2, 3, 3, 3]], [3], [1], [3]]
//输出
//[null, 4, 0, 2]
//
//解释
//Solution solution = new Solution([1, 2, 3, 3, 3]);
//solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
//solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
//solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
// 
//
// 
//
// 
// 
// 
// 提示： 
//
// 
// 1 <= nums.length <= 2 * 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// target 是 nums 中的一个整数 
// 最多调用 pick 函数 10⁴ 次 
// 
// 
// 
// 
//
// 
// Related Topics 水塘抽样 哈希表 数学 随机化 👍 241 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<int,vector<int>> value;
    Solution(vector<int>& nums){
        for (int i=0;i<nums.size();i++){
            value[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
//        int inHand = -1;
//        int n=1;
//        for (int i =0;i<value[target].size();i++){
//            if (rand()%n==0) inHand=value[target][i];
//             n++;
//        }
        return value[target][rand()%value[target].size()];

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
//leetcode submit region end(Prohibit modification and deletion)
