### leetcode 探索算法面试题汇总 

#### 字符串: 有效的字母异位词

[link](https://leetcode-cn.com/explore/interview/card/top-interview-quesitons-in-2018/275/string/1142/)

给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的字母异位词。

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

**说明:**
你可以假设字符串只包含小写字母。

**进阶:**
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

ASCII码的范围是0-127.所以对于每个我们要判断他是否在这个范围，如果不在这个范围，证明它与下一个字符构成一个unicode或其他编码。把两个连起来存。用二位数组标记。以及记录有效的字符有多少个。

**2019.8.10 17:46 字符串Over**

  ### 乘积最大子序列



给定一个整数数组 `nums` ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

**示例 1:**

```
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

**示例 2:**

```
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
```

这个题目要维护当前的最大值和最小值，切记。

Max = max(tempMax\*nums[i],tempMin\*nums[i]);

Min = max(tempMax\*nums[i],tempMin\*nums[i]);

以及与当前值在进行比较。用Max去更新res。

 求众数



给定一个大小为 *n* 的数组，找到其中的众数。众数是指在数组中出现次数**大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

**示例 1:**

```
输入: [3,2,3]
输出: 3
```

**示例 2:**

```
输入: [2,2,1,1,1,2,2]
输出: 2
```

这个题有两种做法，一种利用俩俩PK，最后剩余的一定是总数，还一种求第n/2小的树即可以得到。

  打乱数组



打乱一个没有重复元素的数组。

**示例:**

```
// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
```

- 直接利用C++库里面的random_shuffle(first,second);
- 对于当前位置，后面寻找一个随机位置进行交换。

**2019.8.13 17:13 数组Over**

数据流的中位数，可以利用两个优先队列。

  有序矩阵中第K小的元素



给定一个 *n x n* 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

**示例:**

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
```

**说明:** 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。



很有意思的一道题，从最小值和最大值这个区间进行二分，对于二分得到的数，利用对每行lower_bound和upper_bound得到 < 和 <= 的数，记为cnt1,cnt2,即cnt1 < k && cnt2 >= k时符合。

代码如下:

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        int M = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[N-1][M-1];
        while(l<r){
            int mid = (l+r)/2;
            int cnt1 =0,cnt2 = 0;
            for(int i=0;i<N;++i){
                vector<int>&vec = matrix[i];
                cnt1 += lower_bound(vec.begin(),vec.end(),mid)-vec.begin();//< mid
                cnt2 += upper_bound(vec.begin(),vec.end(),mid)-vec.begin();//<= mid
            }
            if(cnt1 < k && cnt2 >= k){
                return mid;
            }
            else if(cnt2 < k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
};
```

扁平化嵌套列表迭代器



给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的项或者为一个整数，或者是另一个列表。

**示例 1:**

```
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
```

**示例 2:**

```
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
```



通过递归把列表解包成一个数组，再进行输出。注意字列表递归完，回溯之后，仍要++，进入下一个元素。



**2019.8.15 11：58 堆，栈，队列 Over**

复制带随机指针的链表



给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的**深拷贝**。 

 

**示例：**

**![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/23/1470150906153-2yxeznm.png)**

```
输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
```

 

**提示：**

1. 你必须返回**给定头的拷贝**作为对克隆列表的引用。

这个题目是剑指offer上的一道题，自己按照思路模拟了一遍，写出来了。

做法：

- 把所有的节点拷贝一遍，接在原节点的后面，这里拷贝节点的random指针指向的也是原节点
- 对于拷贝节点，修改器random指针，即random不为空的话，指向起指针的下一个（即拷贝的节点）
- 把所有的拷贝节点复制下来。即从原链表中拆分出来。

代码如下，我写的可能有些麻烦。

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        while(p != nullptr){
            Node* temp = new Node(p->val,p->next,p->random);
            p->next = temp;
            p = temp->next;
        }
        p = head;
        int Count = 0;
        while(p != nullptr){
            Count++;
            if(Count % 2 == 0){
                if(p->random != nullptr)
                    p->random = p->random->next;
            }
            p = p->next;
        }
        Node* q = nullptr;
        p = head;
        Count = 0;
        Node* head_copy = nullptr;
        while(p != nullptr){
            Count++;
            if(Count % 2== 0){
                if(Count == 2){
                    head_copy = p;
                }
                q->next = p->next;
                if(p->next != nullptr){
                    p->next = p->next->next;
                }
            }
            if(q != nullptr)
                p = q->next;
            else{
                q = p;
                p = p->next;
            }
        }
        return head_copy;
    }
};
```

 删除链表中的节点



请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

现有一个链表 -- head = [4,5,1,9]，它可以表示为:

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)



**示例 1:**

```
输入: head = [4,5,1,9], node = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
```

**示例 2:**

```
输入: head = [4,5,1,9], node = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
```

 

**说明:**

- 链表至少包含两个节点。
- 链表中所有节点的值都是唯一的。
- 给定的节点为非末尾节点并且一定是链表中的一个有效节点。
- 不要从你的函数中返回任何结果。

这个题要注意，已经说了，给的节点不是尾节点。所以，我们把当前节点的值和下一个节点的值交换。再把下一个节点删去，这样就达到删除节点的目的了。

### 排序链表

在 *O*(*n* log *n*) 时间复杂度和常数级空间复杂度下，对链表进行排序。

**示例 1:**

```
输入: 4->2->1->3
输出: 1->2->3->4
```

**示例 2:**

```
输入: -1->5->3->4->0
输出: -1->0->3->4->5
```

做法有很多种，不过操作起来都很麻烦，目前没有找到能够常数空间下的做法，自己这里merge的时候，使用了递归，所以算是O(N)的时间复杂度。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* MergeSort(ListNode *now){
        if(now == nullptr || now->next == nullptr)
            return now;
        ListNode *fast = now,*slow = now;
        ListNode *Break = now;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            Break = slow;
            slow = slow->next;
        }
        Break->next = nullptr;
        ListNode *l = MergeSort(now);
        ListNode *mid = MergeSort(slow);
        return Merge(l,mid);
    }
    ListNode *Merge(ListNode* l,ListNode *m){
        if(l == nullptr)
            return m;
        else if(m == nullptr)
            return l;
        else if(l->val < m->val){
            l->next = Merge(l->next,m);
            return l;
        }
        else{
            m->next = Merge(l,m->next);
            return m;
        }
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};
```

**2019.8.19 15:50 链表 Over**

常数时间插入、删除和获取随机元素



设计一个支持在*平均* 时间复杂度 **O(1)** 下，执行以下操作的数据结构。

1. `insert(val)`：当元素 val 不存在时，向集合中插入该项。
2. `remove(val)`：元素 val 存在时，从集合中移除该项。
3. `getRandom`：随机返回现有集合中的一项。每个元素应该有**相同的概率**被返回。

**示例 :**

```
// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();
```

因为C++ 中rand() 获得区间是[0,RAND_MAX),而我们要得到[0,st.size());这个区间的随机数。

所以我们利用这个公式进行获得。当r是rand()获得的随机数，则p = r/RAND_MAX,表示在这个区间的位置。同理放到目标区间即p\*st.size();即可得到目标区间对应的结果。

代码如下:

```cpp
/** Get a random element from the set. */
    int getRandom() {
        int r = rand();
        int k = r*1.0/RAND_MAX*st.size();
        unordered_set<int>::iterator it = st.begin();
        for(int i=1;i<=k;++i)
            it++;
        return *it;
    }
private:
    unordered_set<int> st;
```

**2019.8.19 16:43 哈希与映射 Over**



  天际线问题



城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城市风光照片（图A）上**显示的所有建筑物的位置和高度**，请编写一个程序以输出由这些建筑物**形成的天际线**（图B）。

[![Buildings](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/skyline1.png) ](https://leetcode-cn.com/static/images/problemset/skyline1.jpg)[![Skyline Contour](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/skyline2.png)](https://leetcode-cn.com/static/images/problemset/skyline2.jpg)

每个建筑物的几何信息用三元组 `[Li，Ri，Hi]` 表示，其中 `Li` 和 `Ri` 分别是第 i 座建筑物左右边缘的 x 坐标，`Hi` 是其高度。可以保证 `0 ≤ Li, Ri ≤ INT_MAX`, `0 < Hi ≤ INT_MAX` 和 `Ri - Li > 0`。您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：`[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] `。

输出是以 `[ [x1,y1], [x2, y2], [x3, y3], ... ]` 格式的“**关键点**”（图B中的红点）的列表，它们唯一地定义了天际线。**关键点是水平线段的左端点**。请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

例如，图B中的天际线应该表示为：`[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]`。

**说明:**

- 任何输入列表中的建筑物数量保证在 `[0, 10000]` 范围内。
- 输入列表已经按左 `x` 坐标 `Li`  进行升序排列。
- 输出列表必须按 x 位排序。
- 输出天际线中不得有连续的相同高度的水平线。例如 `[...[2 3], [4 5], [7 5], [11 5], [12 7]...]` 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：`[...[2 3], [4 5], [12 7], ...]`



思路：这个题把线段存入之后从左到右扫描一遍，因为要区分左端点和右端点，所以，我们把左端点存为负数（因为这样在有序容器时可以先取出左端点),记录上一个线段last，初始为{0,0}，如果当前最大值不等于last[1],即当前这个点是一个拐点，所以要加入进去。注意使用last[1] = Max,可以巧妙的把为0的右下端点也放入。

代码如下:

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        multiset<pair<int,int>>all;
        for(int i=0;i<buildings.size();++i){
            vector<int> &e = buildings[i];
            all.insert(make_pair(e[0],-e[2]));
            all.insert(make_pair(e[1],e[2]));
        }
        vector<int> last({0,0});
        multiset<int> now({0});
        for(pair<int,int> p:all){
            if(p.second < 0)
                now.insert(-p.second);
            else
                now.erase(now.find(p.second));
            int Max = *now.rbegin();
            if(last[1] != Max){
                last[0] = p.first;
                last[1] = Max;
                res.push_back(last);
            }
        }
        return res;
    }
};
```

**2019.8.24 10:58 树 Over**



最大数



给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

**示例 1:**

```
输入: [10,2]
输出: 210
```

**示例 2:**

```
输入: [3,30,34,5,9]
输出: 9534330
```

**说明:** 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

------


  前几天如果就把这个题做了，估计那次笔试就不是才83的通过了。要按照两个串相加后的大小排序。坚持。

寻找峰值



峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 `nums`，其中 `nums[i] ≠ nums[i+1]`，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 `nums[-1] = nums[n] = -∞`。

**示例 1:**

```
输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
```

**示例 2:**

```
输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
```

**说明:**

你的解法应该是 *O*(*logN*) 时间复杂度的。

这个题目，采用三分的方法。如下：

![三分](C:\Users\ch\Desktop\GithubProject\leetcode\img\三分.png)

```cpp
if(fun(mid) > f(mmid))
    r = mmid;
else
    l = mid;
//这时求峰值，如果求谷底的要根据题目适应。
```

因为这里存在有序的情况，所以我们对于相等时要特判。代码如下：

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        while(r-l > 1){
            int mid = (l+r)/2;
            int mmid = (mid+r)/2;
            if(nums[mid] > nums[mmid])
                r = mmid;
            else if(nums[mid] == nums[mmid]){
                if(nums[l] > nums[r])
                    r--;
                else
                    l++;
            }
            else
                l = mid;
        }
        return (nums[l] > nums[r]? l:r);
    }
};
```

