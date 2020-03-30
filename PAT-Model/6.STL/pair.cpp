struct pair{
  typename first;
  typename second;
}
#include<utility>/#include<map>
using namespace std;
pair<string,int> p("haha",5);
p=pair<string,int>("haha",5);
p=make_pair("haha",5);
p.first,p.second
//两个pair类型数据可以直接使用==,!=,<,<=,>,>=比较大小，比较规则是以first的大小作为标准，只有当first相等时才去判别second的大小
