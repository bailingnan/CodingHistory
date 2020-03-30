//翻译为集合，是一个内部有序且不含重复元素的容器。
#include<set>
using namespace std;
set<typename>::iterator it//只能通过迭代器访问
//不支持*(it+i)的访问方式。
for(set<int>::iterator it=st.begin();it!=st.end();it++){
    printf("%d",*it);
}
//set内的元素自动递增排序，且自动去除了重复元素
insert(x)//将x插入set容器中，自动递增排序和去重，时间复杂度O(logN);
find(value)返回set中对应值为value的迭代器，时间复杂度为O(logN)
set<int>::iterator it=st.find(2);//在set中查找2，返回其迭代器
st.erase(it)//it为所需要删除元素的迭代器,时间复杂度O(1)
st.erase(value)//删除元素value,时间复杂度O(logN)
st.erase(first,last)//first为所需要删除区间的起始迭代器，last为所需要删除区间的末尾迭代器的下一个地址，也即删除[first,last),O(last-first)
st.size()//元素个数，O(1)
st.clear()//清空，O(N)
