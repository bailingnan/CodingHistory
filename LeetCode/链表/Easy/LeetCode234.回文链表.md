<!-- TOC -->

- [LeetCode234.回文链表](#leetcode234回文链表)
  - [题目描述](#题目描述)
  - [Tag](#tag)
  - [参考解法](#参考解法)
    - [方法一:将值复制到数组中后用双指针法](#方法一将值复制到数组中后用双指针法)
      - [复杂度分析](#复杂度分析)
  - [自己解法](#自己解法)
    - [解法一](#解法一)

<!-- /TOC -->
# LeetCode234.回文链表
## 题目描述
- [LeetCode234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/)
![](https://picgp.oss-cn-beijing.aliyuncs.com/img/20200512010234.png)
## Tag
- 链表
- 双指针
- 递归
## 参考解法
### 方法一:将值复制到数组中后用双指针法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
  def isPalindrome(self, head: ListNode) -> bool:
    vals = []
    current_node = head
    while current_node is not None:
        vals.append(current_node.val)
        current_node = current_node.next
    return vals == vals[::-1]
```
#### 复杂度分析
- 时间复杂度：$O(n)$,其中$n$指的是链表的元素个数。
  - 第一步： 遍历链表并将值复制到数组中，$O(n)$
  - 第二步：双指针判断是否为回文，执行了$O(n / 2)$次的判断，即$O(n)$。 
  - 总的时间复杂度：$O(2 n)=O(n)$
- 空间复杂度：O(n)，其中$n$指的是链表的元素个数，我们使用了一个数组列表存放链表的元素值。
## 自己解法
### 解法一

