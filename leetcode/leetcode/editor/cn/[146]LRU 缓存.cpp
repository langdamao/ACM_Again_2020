//请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。 
//
// 实现 LRUCache 类： 
//
// 
// 
// 
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
//key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
// 
//
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
// 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10000 
// 0 <= value <= 10⁵ 
// 最多调用 2 * 10⁵ 次 get 和 put 
// 
// Related Topics 设计 哈希表 链表 双向链表 👍 2132 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//    模拟实现
//    int cap;
//    unordered_map<int,int> kv;
//    unordered_map<int,int> use;
//    deque<pair<int,int> > query;
//    int time=0;
//    LRUCache(int capacity) {
//        time = 0;
//        kv.clear();
//        use.clear();
//        query.clear();
//        cap = capacity;
//    }
//    void used(int key){
//        time++;
//        use[key] = time;
//        query.push_back(make_pair(key,time));
//    }
//    void clear(){
//        while(!query.empty()){
//            int key = query.front().first;
//            int qt = query.front().second;
//            query.pop_front();
//            if (use.find(key)!=use.end() && use[key] == qt && kv.find(key)!=kv.end()){
//                kv.erase(key);
//                use.erase(key);
//                break;
//            }
//        }
//    }
//
//    int get(int key) {
//        used(key);
//        if (kv.find(key)!=kv.end()){
//            return kv[key];
//        }
//        return -1;
//    }
//
//    void put(int key, int value) {
//        used(key);
//        kv[key]=value;
//        if (kv.size()>cap) clear();
//    }
struct Node {
    int key = 0,value = 0;
    Node *pre = nullptr;
    Node *next = nullptr;
    Node(){};
    Node(int _key, int _value):key(_key),value(_value){}
};
struct DList {
    Node* head;
    Node* tail;
    DList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    void remove(Node * node) {
        if (node->next && node->pre) {
            node->next->pre = node->pre;
            node->pre->next = node->next;
        }
    }
    void add2Tail(Node *node) {
        tail->pre->next = node;
        node->pre = tail->pre;
        node->next = tail;
        tail->pre =node;
    }
    Node* removeHead() {
        Node *p = head->next;
        head->next = p->next;
        p->next->pre = head;
        return p;
    }
};
class LRUCache {
public:
    unordered_map<int,Node* > kv;
    DList q ;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    void used(Node * node) {
        q.remove(node);
        q.add2Tail(node);
    }
    void clear() {
        Node* p = q.removeHead();
        kv.erase(p->key);
        delete p;
    }
    int get(int key) {
        if (kv.find(key)!=kv.end()) {
            used(kv[key]);
            return kv[key]->value;
        }
        return -1;
    }
    void put(int key, int value) {
        if (kv.find(key) != kv.end()) {
            used(kv[key]);
            kv[key]->value = value;
        } else {
            Node *node = new Node(key,value);
            kv[key] = node;
            if (kv.size() > cap) {
                clear();
            }
            used(node);
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
