<!-- TOC -->

- [LeetCode206/剑指offer24.反转链表](#leetcode206剑指offer24反转链表)
  - [题目描述](#题目描述)
  - [参考解法](#参考解法)
    - [方法一：迭代](#方法一迭代)
      - [复杂度分析](#复杂度分析)
    - [方法二：递归](#方法二递归)
  - [自己解法](#自己解法)
  - [相关题目](#相关题目)

<!-- /TOC -->
# LeetCode206/剑指offer24.反转链表
## 题目描述
- [LeetCode206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
![](https://picgp.oss-cn-beijing.aliyuncs.com/img/20200510042838.png)
## 参考解法
### 方法一：迭代
假设存在链表 `1 → 2 → 3 → Ø`，我们想要把它改成 `Ø ← 1 ← 2 ← 3`。
在遍历列表时，将当前节点的 `next` 指针改为指向前一个元素。由于节点没有引用其上一个节点，因此必须事先存储其前一个元素。在更改引用之前，还需要另一个指针来存储下一个节点。不要忘记在最后返回新的头引用！
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev=None;curr=head
        while(curr):
            nextTemp=curr.next
            curr.next=prev
            prev=curr
            curr=nextTemp
        return prev
```
#### 复杂度分析
- 时间复杂度：$O(n)$，假设$n$是列表的长度，时间复杂度是$O(n)$。
- 空间复杂度：$O(1)$。
### 方法二：递归
递归版本稍微复杂一些，其关键在于反向工作。假设列表的其余部分已经被反转，现在我该如何反转它前面的部分？
假设列表为：
$n_{1} \rightarrow \ldots \rightarrow n_{k-1} \rightarrow n_{k} \rightarrow n_{k+1} \rightarrow \ldots \rightarrow n_{m} \rightarrow \varnothing$
## 自己解法
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        ans=ListNode()
        while(head!=None):
            head_temp=head.next
            head.next=ans.next
            ans.next=head
            head=head_temp
        return ans.next
```
![](https://picgp.oss-cn-beijing.aliyuncs.com/img/20200510043429.png)

## 相关题目
- [LeetCode92.反转链表II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
- [LeetCode156.上下翻转二叉树](https://leetcode-cn.com/problems/binary-tree-upside-down/)
- [LeetCode234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)