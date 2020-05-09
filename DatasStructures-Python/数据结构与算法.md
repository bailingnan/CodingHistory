<!-- TOC -->

- [线性结构](#线性结构)
  - [栈](#栈)

<!-- /TOC -->
# 线性结构
## 链表

## 栈

```python
class stack:
    def __init__(self):
        self.items=[]
    def is_empty(self):
        return self.items==[]
    def push(self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def peek(self):
        return self.items[len(self.items)-1]
    def size(self):
        return len(self.items)
```

通用括号匹配(`()`,`{}`,`[]`)：

```python
def parChecker(symbolString):
    s=Stack()
    balanced=True
    index=0
    while index<len(symbolString) and balanced:
        symbol=symbolString[index]
        if symbol in '({[':
            s.push(symbol)
        else:
            if s.is_empty:
                balanced=False
            else:
                top=s.pop()
                if not matches(top,symbol):
                    balanced=False
        index+=1
    if balanced and s.is_empty():
        return True
    else:
        return False

    def matches(open,close):
        opens="([{"
        closers=")]}"
        return opens.index(open)==opens.index(closers)
```


