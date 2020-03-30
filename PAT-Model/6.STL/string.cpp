#incldue<string>
using namespace std;
string str="abcd";
//可以像字符数组一样通过str[i]访问，读入和输出字符串，只能用cin和cout
printf("%s\n",str.c_str());//将string型str使用c_str()变为字符数组
string iterator::it;//str.begin()+1的写法可行
str3=str1+str2;
str1+=str2;//将string直接拼接上来
//可以直接使用==、!=、<,<=,>,>=比较大小，比较规则为字典序。
str.length()/str.size()//字符长度
str.insert(3,str2);
str.insert(3,"abv");//在某位插入字符串,O(N)
insert(it1,it2,it3);//it为原字符串的欲插入位置，it2和it3为待插字符串的首尾迭代器，表示串[it2,it3)将被插在it的位置上
str.erase(it)//时间复杂度O(N)
str.erase(first,last)//删除[first,last),时间复杂度O(N)
str.erase(pos,length)//pos为需要开始删除的开始位置，length为需要删除的字符个数，时间复杂度O(N)
str.clear();//清空string,O(1);
str.substr(pos,len);//返回从pos位开始，长度为len的子串，时间复杂度为O(len)
//string::npos是一个常数，其本身的值为-1，但由于是unsigned_int类型，实际上也可以认为是unsigned_int类型的最大值。
//string::npos用以作为find函数失配时的返回值，可以认为等于-1或4294967295
str.find(str2)//当str2是str的子串时，返回其在str中第一次出现的位置，如果str2不是str的子串，返回string::npos;
str.find(pos,str2)//从str的pos号位开始匹配str2,返回值与上相同，时间复杂度为O(nm)
str.replace(pos,len,str2)//把str从pos号位开始，长度为len的子串替换为str2;
str.replace(it,it2,str2)//把str的迭代器[it1,it2)范围的子串替换为str2,时间复杂度为O(str.length());
//stoi函数，将数字字符串转换为数字。
