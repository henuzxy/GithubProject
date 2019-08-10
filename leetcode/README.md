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

