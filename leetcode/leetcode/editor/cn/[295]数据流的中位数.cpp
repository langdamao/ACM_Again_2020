//中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。 
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例： 
//
// addNum(1)
//addNum(2)
//findMedian() -> 1.5
//addNum(3) 
//findMedian() -> 2 
//
// 进阶: 
//
// 
// 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？ 
// 
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 675 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
public:
    multiset<int> s;
    multiset<int>::iterator t1,t2;
    MedianFinder() {
       s.clear();
       t1 = s.begin();
       t2 = s.end();
    }
    
    void addNum(int num) {
        // 相同的值时，后来的会添加到后面
        s.insert(num);
        if (t1 == s.end()) t1=t2=s.begin();
        else if (num<(*t1)){
            if (t1==t2) t1--;
            else t2--;
        }
        else if (num>=(*t1) && num<(*t2)){
            t1++;
            t2--;
        }
        else {
            if (t1==t2) t2++;
            else t1++;
        }
    }
    
    double findMedian() {
       return (*t1+(*t2))/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)
