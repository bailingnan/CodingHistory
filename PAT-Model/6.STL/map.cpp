#include<map>
using namespace std;
map<typename1,typename2> mp;
map<string,int> mp;//字符串到整型的映射，必须使用string而不能用char数组
//可通过mp['c']的方式访问，map的键是唯一的
map<typename1,typename2>::iterator it;//使用it->first访问键,s使用it->second访问值
//map会以键从小到大的顺序自动排序
mp<char,int>::iterator it=mp.find('b');//返回键为key的映射的迭代器，O(logN)；
mp.erase(it)//it为需要删除的元素得迭代器，时间复杂度为O(1)
mp.erase(first,last)//删除[first,last),时间复杂度O(last-first)
mp.size()//map中映射的对数,O(1)
mp.clear()//清空mp,O(N)

