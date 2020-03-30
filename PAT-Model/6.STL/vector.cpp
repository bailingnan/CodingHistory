#include<vector>
using namespace std;
//迭代器
vector<typename>::iterator it;
//vi[i]=*(vi.begin()+i)
//vi.end()取尾元素地址的下一个地址。
//++it和it++合法
//只有vector和string才允许使用vi.begin()+3这种迭代器加上整数的写法
vi.push_back(元素);//时间复杂度O(1)
vi.pop_back(元素);//时间复杂度O(1)
vi.size(vi)//返回unsigned类型，但仍可用%d.时间复杂度O(1)
vi.clear(vi)//清空所有元素，时间复杂度为O(N)
insert(it,x)//向任意迭代器it处插入元素x，时间复杂度O(N)
insert(vi.begin()+2,-1)
erase(it)//删除迭代器it处的元素。时间复杂度O(N)
erase(it1,it2）//删除[first,last)内的所有元素
