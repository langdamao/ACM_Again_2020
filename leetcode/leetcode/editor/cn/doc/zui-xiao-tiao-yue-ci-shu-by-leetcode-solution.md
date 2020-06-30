## 题意概述：

给定一个数组 `jump`，长度为 `N`，在第 `i` 个位置可以选择跳到 `0..i-1` 和 `i + jump[i]`，问从 `0` 跳过 `n-1` 的最小跳跃次数是多少。

### 方法一：动态规划

我们可以利用一个巧妙的性质来使用动态规划：假设某一个位置只需要 `w` 步可以跳到，那么这个位置之前的步数，最多只需要 `w+1` 步。
所以我们可以用一个数组 `maxdis[w]` 表示 `w` 步可以跳到的最远位置。对于位置 `i`而言，满足 `maxdis[w] > i` 条件的最小 `w+1` 是往左跳到达 `i` 的最小操作次数。
因此递推方程为
1. `f[i] = min(f[i], w+1)`:  用往左跳到达 `i` 的最小操作数 `w+1`
2. `f[i+jump[i]] = min(f[i+jump[i],f[i]+1)`:  从 `i` 往右跳到 `i+jump[i]` 更新 `f[i+jump[i]]`
3. `maxdis[f[i+jump[i]]] = max(maxdis[f[i+jump[i]]], i+jump[i])`: 更新 `f[i+jump[i]]` 次操作到达最远距离。

我们知道 `maxdis` 是单调的，所以只需要一个单调指针维护对应的 `w` 即可。

```C++ []
class Solution {
private:
    int f[10000000 + 7];
    int maxdis[10000000 + 7];
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        int w = 0;
        int ans = 1000000000;

        for (int i=1; i<=n; ++i) {
            f[i] = 1000000000;
            maxdis[i] = 0;
        }
        f[1] = 0;
        maxdis[0] = 1;

        for (int i=1; i<=n; ++i) {
            if (i > maxdis[w]) { // 更新单调指针
                ++w;
            }
            f[i] = min(f[i], w+1); // 用 maxdis[w] 更新 f[i]
            int next = i + jump[i-1]; // 第一步跳跃更新

            if (next > n) {
                ans = min(ans, f[i] + 1);
            } else if (f[next] > f[i] + 1) {
                f[next] = f[i] + 1;
                maxdis[f[next]] = max(maxdis[f[next]], next);
            }
        }

        return ans;
    }
};
```

```Python []
class Solution:
    def minJump(self, jump: List[int]) -> int:
        res = n = len(jump)
        f = [n]*(n+1)
        f[0] = 0
        max_dis = [0]*(n+1) 
        curr_min_num = 0
        for i in range(0,n):
            if i>max_dis[curr_min_num]:
                curr_min_num += 1
            f[i] = min(f[i],curr_min_num+1)
            
            jump_tmp = i+jump[i]
            if jump_tmp>=n:
                res = min(res,f[i]+1)
            else:
                f[jump_tmp] = min(f[jump_tmp],f[i]+1)
                max_dis[f[i]+1] = max(max_dis[f[i]+1],jump_tmp)
        return res
```

```Go []
func minJump(jump []int) int {
    n := len(jump)
    res := len(jump)
    var f[1000001]int
    var max_dis[1000001]int
    for i:=0; i<=n; i++{
        f[i] = n+1;
        max_dis[i] = 0;
    }
    f[0] = 0
    curr_min_num := 0
    for i:=0; i<n; i++{
        if i>max_dis[curr_min_num]{
            curr_min_num += 1
        }
        f[i] = Min(f[i], curr_min_num+1)

        jump_tmp := i+jump[i]
        if jump_tmp>=n {
            res = Min(res,f[i]+1)
        }else{
            f[jump_tmp] = Min(f[jump_tmp],f[i]+1)
            max_dis[f[i]+1] = Max(max_dis[f[i]+1],jump_tmp)
        }
    }
    return res
}

func Min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
 
func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```


#### 复杂度分析

* 时间复杂度：*O(n)*。

* 空间复杂度：*O(n)*。



### 方法二：广度优先搜索
常规广度优先搜索在处理弹簧往左跳的情况时，时间复杂度到达 `O(N^2)`。
在常规广度优先搜索的基础上，我们可以记录一个最大的 `far` 值进行优化，用来表示当前从 `[0, far-1]` 均已被搜索到。 
因此当搜索到编号 `i` 弹簧时，往左跳的操作，仅需遍历 `[far, i-1]` 区间（ far <=  i-1 ）；搜索结束时，更新 `far = max(far, i+1)`。
由于 `far` 的更新操作，使往左跳操作的遍历区间是不存在重复的，因此往左跳遍历的总时间复杂度为 `O(N)`

```Python []
class Solution:
    def minJump(self, jump):
        res = n = len(jump)
        visited = [False]*(n+1)
        queue = [[0,1]]
        visited[0] = True
        curr, far = 0, 1
        while curr<len(queue):
            idx, step = queue[curr][0], queue[curr][1]
            curr += 1
            if idx + jump[idx] >= n:
                return step
            if not visited[idx+jump[idx]]:
                queue.append([idx+jump[idx], step+1])
                visited[idx+jump[idx]] = True
            for j in range(far, idx):
                if not visited[j]:
                    queue.append([j, step+1])
                    visited[j] = True
            far = max(far, idx+1)
        return -1
```

```Go []
func minJump(jump []int) int {
    if len(jump) == 0 {
        return 0
    }
    n := len(jump)
    queue := [][]int{}
    visited := map[int]int{}
    queue = append(queue, []int{0, 1})
    visited[0] = 1
    far := 1
    for i := 0; i < len(queue); i++ {
        idx, step := queue[i][0], queue[i][1]
        if idx + jump[idx] >= n {
           return step
        }
        if _, ok := visited[idx + jump[idx]]; !ok {
            queue = append(queue, []int{idx + jump[idx], step + 1})
            visited[idx + jump[idx]] = step + 1
        }
       
        for j := far; j < idx; j++ {
            if _, ok := visited[j]; !ok {
                queue = append(queue, []int{j, step + 1})
                visited[j] = step + 1
            }
        }
        far = Max(far, idx)
    }
    return -1
}
 
func Min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
 
func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

```

#### 复杂度分析

* 时间复杂度：*O(n)*。

* 空间复杂度：*O(n)*。


### 方法三：线段树

考虑第 `i` 个位置，可以直接跳到  `i+jump[i]`，也可以跳两步跳到所有的 `i+1 .. i+jump[i]-1`。所以就有了递推方程：
- `f[i+jump[i]] = max(f[i + jump[i]], f[i] + 1)` 向右跳
- `f[j] = max(f[j], f[i] + 2), i < j < i+jump[i]` 向左跳

那么区间更新，单点查询，可以用线段树来维护，具体操作如下:
- `clearT()` 线段树初始化。编号 `0` 弹簧操作数为 `0`；其余的最小操作数为 `-1`，表示暂不可到达
- `setTree(cl,cr,val)` 更新编号 `cl ~ cr` 之间弹簧的最小操作数为 `val`。如果内部弹簧最小操作数已经小于等于 `val`，则保持不变，否则更新为 `val`
- `getTree(curr)` 获得编号 `curr` 弹簧的跳跃最小值

最少需要 `num = getTree(i)` 次操作到编号 `i` 弹簧处，从 `i` 处跳跃的两种情况，即 `setTree(i+jump[i], i+jump[i], num+1)` 以及 `setTree(i+1, i+jump[i]-1, num+2)`

```Go []
var g[4000001]int
func minJump(jump []int) int {
    n := len(jump)
    res := n
    clearTree(0,0,n-1)
    for i:=0; i<n; i++{ 
        curr := getTree(0,0,n-1,i)
        if i + jump[i] >= n {
            res = min(res, curr+1)
        }else {
            setTree(0,0,n-1,i+jump[i],i+jump[i],curr+1)
        }
        if i+1<=i+jump[i]-1 {
            setTree(0,0,n-1,i+1,min(n-1,i+jump[i]-1),curr+2)
        }
    }
    return res
}

func setTree(index, l, r, cl, cr, val int){
    if g[index]!=-1 && g[index] <= val {
        return 
    }
    if cl<=l && r<= cr {
        if g[index]==-1 {
            g[index] = val
        } else {
            g[index] = min(g[index],val)
        }
        return 
    }
    mid := (l+r)/2
    if cl<=mid {
        setTree(index*2+1, l, mid, cl, cr, val)
    }
    if mid+1<=cr {
        setTree(index*2+2, mid+1, r, cl, cr, val)
    }
}

func getTree(index, l, r, curr int) int {
    if l==r {
        return g[index]
    }
    mid := (l+r)/2
    var res int;
    if curr<=mid {
        res = getTree(index*2+1, l, mid, curr)
    }else{
        res = getTree(index*2+2, mid+1, r, curr)
    }
    if g[index] != -1 {
        if res == -1 {
            res = g[index]
        } else {
            res = min(g[index],res)
        }
    }
    return res
}

func clearTree(index, l, r int){
    g[index] = -1
    if l==r {
        if l==0{
            g[index] = 0
        }
        return
    }
    mid := (l+r)/2
    clearTree(index*2+1, l, mid)
    clearTree(index*2+2, mid+1,r)
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
 
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```


#### 复杂度分析

* 时间复杂度：*O(n * log(n))*。

* 空间复杂度：*O(n)*。