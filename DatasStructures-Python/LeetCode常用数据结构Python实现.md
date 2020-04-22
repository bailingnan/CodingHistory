<!-- TOC -->

- [有序序列](#有序序列)
  - [不可变序列](#不可变序列)
    - [`str`](#str)
    - [`tuple`](#tuple)
  - [可变序列](#可变序列)
    - [`list`](#list)
    - [`deque`](#deque)
    - [`bisect`](#bisect)
- [无序对象](#无序对象)
  - [字典](#字典)
    - [`dict`](#dict)
    - [`defaultdict`](#defaultdict)
    - [`Counter`](#counter)
    - [`OrderedDict`](#ordereddict)
  - [集合](#集合)
- [堆队列](#堆队列)
- [扩展](#扩展)
  - [`nametuple`](#nametuple)
  - [`ChainMap`](#chainmap)
  - [`queue`](#queue)

<!-- /TOC -->
# 有序序列 
## 不可变序列
### `str`
内置的数据结构, 可以直接使用, 不需要导入

常用函数：
```python
format(*args, **kwargs)  # 用法丰富多样, 算法中可用于字符串形式的进制转换
split(sep=None, maxsplit=-1)  # 以sep来分割字符串
strip([chars])  # 去除首末两端的字符, 默认是 \r,\n," "
join(iterable)  # 将iterable内的元素拼接成字符串,如','.join(['leet', 'code']) #="leet,code"
replace(old, new[, count])  # 字符串替换, old to new
count(sub[, start[, end]])  # 统计子字符串sub的个数
startswith(prefix[, start[, end]])  # 以prefix开始的字符串
endswith(suffix[, start[, end]])  # 以suffix结束的字符串
```
常用的功能:

- 拼接(加), `s1 + s2`
- 切片, `s[start: end: space]`
- 重复(乘), `s * 10`

### `tuple`
元组, 也叫静态列表. 内置的数据结构, 可以直接使用, 无须导入.

- 元组常用于多变量赋值和多值返回, 只是一般在使用的时候没有加上小括号
- 需要注意的是, 当`tuple`里只有一个元素时, 需要在该元素之后加上,, 如 `t=(1,)`, 否则它就不是`tuple`, 而是该元素的类型.
- 同样支持拼接, 切片, 重复等操作
- 提供的函数仅有`index`和`count`

## 可变序列

### `list`
经常使用的数据结构, 可以实现简单的队列, 栈等.

常用功能: 拼接, 重复, 切片

强大的切片功能, 可用于取值, 替换, 删除等

- `lst[i:j] = t`,:其中`t`是可迭代序列
- `del lst[i:j]`, 相当于 `lst[i:j] = []`

常用函数：

```python
lst.sort(*, key=None, reverse=False)#对 list 进行排序，在 list 长度小的时候使用插入排序，在长度大的时候使用快排，所以其时间复杂度可以视为 O(nlgn)。
lst.append(val)  # 在 list 的结尾追加一个元素,也可以 lst = lst + [val]
lst.clear()  # 清空列表
lst.count(val)  # val个数
lst.extend(t)  # or s += t  # += 其实调用的是 __iadd__ 方法
lst.pop(val=lst[-1])  # (默认)从末端移除一个值
lst.remove(val)  # 移除 val
lst.reverse()  # 反转
lst.insert(i, val)  # 在 i 处插入 val
```

### `deque`
一种链表的双向队列数据结构, 从该队列的头部或尾部插入或者删除一个元素, 时间复杂度是`O(1)`. 可以用来表示先进先出的队列 (`FIFO`).

常用函数

```python
from collections import deque
queue = deque([iterable[, maxlen]])
queue.append(val)  # 往右边添加一个元素
queue.appendleft(val)  # 往左边添加一个元素
queue.clear()  # 清空队列
queue.count(val)  # 返回指定元素的出现次数
queue.extend(iterable)  # 从队列右边扩展一个序列的元素
queue.extendleft(iterable)  #  从队列左边扩展一个列表的元素
queue.insert(val[, start[, stop]])  # 在指定位置插入元素
queue.pop()  # 获取最右边一个元素，并在队列中删除
queue.popleft()  # 获取最左边一个元素，并在队列中删除
queue.reverse()  # 队列反转
queue.remove(val)  # 删除指定元素
queue.rotate(n=1)  # 把右边元素放到左边
```
### `bisect`
一种高效的折半搜索算法的类. 在`list`上用`index`来查找某个元素, 所消耗的时间会与列表长度呈线性比例. 而`bisect`提供的`bisect_left`等函数, 使用了二分折半搜索算法, 能够在排序之后的元素中查找某个值, 由`bisect_left`函数所返回的索引, 表示待搜索的值在序列中的插入点.

```python
import bisect
lst = list(range(10**6))
index1 = lst.index(654321)
index2 = bisect.bisect_left(lst, 987654)
```

二分查找法的复杂度是对数级别的. 也就是说, 用`bisect`搜索100,000个元素的列表, 与用`index`搜索14个元素的列表用的时间差不多.

常用函数：

和折半查找一样, 使用这个模块的函数前先确保操作的列表是已排序的。

```python
import bisect
bisect.bisect_left(a, x, lo=0, hi=len(a))  # 返回将x插入a后的位置index(如果a中存在与x等值的元素，则插入到左侧), 默认从 0到-1
bisect.bisect_right(a, x, lo=0, hi=len(a))  # 返回将x插入a后的位置index(如果a中存在与x等值的元素，则插入到右侧)
bisect.bisect(a, x, lo=0, hi=len(a))  # 与 bisect_right 相同
bisect.insort_left(a, x, lo=0, hi=len(a))  # 将x插入a(如果a中存在与x等值的元素，则插入到左侧)
bisect.insort_right(a, x, lo=0, hi=len(a))  # 将x插入a(如果a中存在与x等值的元素，则插入到右侧)
bisect.insort(a, x, lo=0, hi=len(a))  # 与insort_left 相同, 将变量x插入到a中,并保持a升序
```

# 无序对象
## 字典
一般的字典是: 无序的(也有有序的字典`OrderedDict`), 键不可变, 值可变.

### `dict`
字典, 或映射, 以键值对形式存储. 想必不用过多介绍了吧.

常用函数

```python
pop(key[, default])  # 通过键去删除键值对(若没有该键则返回default(没有设置default则报错))
setdefault(key[, default])  # 设置默认值
update([other])  # 批量添加
get(key[, default])  # 通过键获取值(若没有该键可设置默认值, 预防报错)
pop(key[, default])  # 通过键删除值(若没有该键可设置默认值, 预防报错)
clear()  # 清空字典
keys()  # 将字典的键组成新的可迭代对象
values()  # 将字典中的值组成新的可迭代对象
items()  # 将字典的键值对凑成一个个元组, 组成新的可迭代对象
```

### `defaultdict`
在`dict`中取值时, 如果`key`不存在, 那么会报`KeyError`这样的错, 这时候可以使用`get`方法来解决, 或者捕获异常. 但是这样会感觉很麻烦, 易错, 而且没有体现出`python`的简洁风格.

这时候就该`defaultdict`登场了, 当试着去取不存在的值时, 就不会报错.

```python
from collections import defaultdict
d = defaultdict(lambda : value)
#当取一个不存在的 key 时, 会返回 value.
```
继承于`dict`, 所以它拥有`dict`一样的方法.

### `Counter`
用于统计值的个数

`Counter`类继承`dict`, 所以它能使用`dict`里的方法.

`Counter` 特有方法:

```python
from collections import Counter
cnt = Counter([iterable-or-mapping])
cnt.elements()  # 所有元素
cnt.most_common([n])  # 指定一个参数n，列出前n个元素，不指定参数，则列出所有
cnt.subtract([iterable-or-mapping])  # 原来的元素减去新传入的元素
cnt.update([iterable-or-mapping])  # 增加元素
```

### `OrderedDict`
有序字典, 使得插入的顺序有序. (官方解释: Dictionary that remembers insertion order)

同样也继承于 `dict`, 所以可以使用 `dict` 所拥有的方法.

添加的方法:
```python
popitem(last=True)  # (默认)从末尾去除一个元素
move_to_end(key, last=True)  # 将key移到(默认)末尾
```

## 集合
`set`, 主要用于去重的操作.

需要注意的是

- 它的定义. 只能使用实例的方式定义, 如`s= set();s={1,2,4,8}`, 而不能这样定义`s={}`. 因为这样定义的是一个字典, 不能使用集合的方法.
- 无序特性. 有时候你会在 `N` 次输出同一个集合的时候, 发现它是有序的, 但是请你也一定不要相信集合是有序的.

常用函数
```python
add(elem)  # 向集合中添加数据
update(*others)  # 迭代着增加
clear()  # 清空集合
discard(elem)  # 删除集合中指定的值(不存在则不删除)
```
# 堆队列

可实现优先级队列的数据结构. 可以解决 `top n` 问题, 如从1亿个数里面找出最大或最小的100个数
```python
import heapq
nums = [randint(1, 1000) for x in range(100)]
print(heapq.nlargest(3, nums))
print(heapq.nsmallest(3, nums))
```
常用函数
```python
import heapq
​
heap = []  # 建堆
heapq.heappush(heap,item)  # 往堆中插入新值
item = heapq.heappop(heap)  # 弹出最小的值
item = heap[0]  # 查看堆中最小的值, 不弹出
heapq.heapify(x)  # 以线性时间将一个列表转为堆
item = heapq.heapreplace(heap,item)  # 弹出一个最小的值, 然后将 item 插入到堆当中. 堆的整体的结构不会发生改变.
heapq.heappoppush(heap, item)  # 弹出最小的值.并且将新的值插入其中.
heapq.merge(*iterables, key=None, reverse=False)  # 将多个堆进行合并
heapq.nlargest(n, iterable, key=None)  # 从堆中找出最大的 n 个数，key的作用和sorted( )方法里面的key类似, 用列表元素的某个属性和函数作为关键字
heapq.nsmallest(n, iterable, key=None)  # 从堆中找出最小的 n 个数, 与 nlargest 相反
```
# 扩展
## `nametuple`
```
from collections import namedtuple
namedtuple(typename, field_names, *, rename=False, defaults=None, module=None)
```
## `ChainMap`
将多个字典连接在一起
## `queue`
队列
```python
from Queue import queue
```

