abs(x)//返回x的绝对值，x必须是整数
fabs(x)//返回x的绝对值，x为浮点数，在math头文件下
reverse(it,it2)//将数组指针在[it,it2)之间的元素或容器的迭代器在[it,it2)范围内的元素进行反转。
int a[10]={1,2,3,4,5,6}
reverse(a,a+4);
string str="abasdjji"
reverse(str.begin()+2,str.begin()+6);
//next_permutation()给出一个序列在全排列中的下一个序列
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int a[10]={1,2,3];
  do{
    printf("%d%d%d\n",a[0],a[1],a[2]);
  }while(next_permutation(a,a+3));
   return 0;
 }
 //fill可以把数组或容器中的某一段区间赋为某个相同的值；
 fill(a,a+5,233);
 sort(vi.begin(),vi.end())//对vector排序
 sort(str,str+3)//对string排序
 //lower_bound()和upper_bound()需要用在一个有序数组或容器中。
//lower_bound(first,last,val)用来寻找在数组或容器的[first,last)范围内第一个值大于等于val的元素的位置，如果是数组，则返回该位置的指针；
//如果是容器，则返回该位置的迭代器
//upper_bound(first,last,val)用来寻找在数组或容器的[first,last)范围内第一个值大于val的元素的位置，如果是数组，则返回该位置的指针；
//如果是容器，则返回该位置的迭代器
//如果数组或容器中没有需要寻找的元素，则lower_bound()和upper_bound()均返回可以插入该元素的位置的指针或迭代器。
//复杂度均为O(log(last-first))
//如果只是想获得欲查元素的下标，就可以不用临时指针，而直接令返回值减去数组首地址即可。
