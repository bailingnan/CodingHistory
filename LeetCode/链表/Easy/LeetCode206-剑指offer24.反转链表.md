<!-- TOC -->

- [LeetCode206/剑指offer24.反转链表](#leetcode206剑指offer24反转链表)
  - [题目描述](#题目描述)
  - [Tag](#tag)
  - [参考解法](#参考解法)
    - [方法一：迭代](#方法一迭代)
      - [复杂度分析](#复杂度分析)
    - [方法二：递归](#方法二递归)
      - [复杂度分析](#复杂度分析-1)
  - [自己解法](#自己解法)
    - [方法一](#方法一)

<!-- /TOC -->
# LeetCode206/剑指offer24.反转链表
## 题目描述
- [LeetCode206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

![](https://picgp.oss-cn-beijing.aliyuncs.com/img/20200512010612.png)

## Tag
- 链表
- 递归
## 参考解法
### 方法一：迭代
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
            next_temp=curr.next
            curr.next=prev
            prev=curr
            curr=next_temp
        return prev
```
#### 复杂度分析
- 时间复杂度：$O(n)$，假设$n$是列表的长度，时间复杂度是$O(n)$。
- 空间复杂度：$O(1)$。
### 方法二：递归
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        p=self.reverseList(head.next)
        head.next.next=head
        head.next=None
        return p
```
#### 复杂度分析
- 时间复杂度：$O(n),$ 假设 $n$ 是列表的长度，那么时间复杂度为 $O(n)$
- 空间复杂度：$O(n)$，由于使用递归，将会使用隐式栈空间。递归深度可能会达到 $n$ 层。
## 自己解法
### 方法一
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
            next_temp=head.next
            head.next=ans.next
            ans.next=head
            head=next_temp
        return ans.next
```