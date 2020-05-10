<!-- TOC -->

- [LeetCode206.反转链表](#leetcode206反转链表)
  - [题目描述](#题目描述)
  - [参考解法](#参考解法)
  - [自己解法](#自己解法)
    - [解法一](#解法一)
  - [相关题目](#相关题目)

<!-- /TOC -->
# LeetCode206.反转链表
## 题目描述
- [LeetCode206.反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
![](https://picgp.oss-cn-beijing.aliyuncs.com/img/20200510042838.png)
## 参考解法
## 自己解法
### 解法一
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
## 相关题目
- [LeetCode92.反转链表II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
- [LeetCode156.上下翻转二叉树](https://leetcode-cn.com/problems/binary-tree-upside-down/)
- [LeetCode234.回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)