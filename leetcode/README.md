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