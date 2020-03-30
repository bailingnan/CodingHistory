#incldue<queue>
using namespace std;
queue<int> q;
q.front(),q.back()//队首元素，队尾元素
q.push(x)//入队，O(1)
q.pop()//队首出队,O(1)
q.empty()//检测是否为空，O(1),使用front()和pop()函数前，必须用empty()判断是否为空
q.size()//元素个数,O(1)
priority_queue<typename> name;
priority_queue<int> q;
q.top()//只能通过top函数访问队首元素,O(1)
q.push(x)//入队，复杂度O(logN)
q.pop()//O(logN)
q.empty()//O(1)
q.size()//O(1)
//元素优先级设置
//队首元素一般是优先队列内元素最大的，char型则为字典序最大的
priority_queue<int> q;
#include<functional>；
priority_queue<int,vector<int>,less<int>> q;//二者等价，less<int>表示数字大的优先级大，greater<int>表示数字小的优先级大,要加functional头文件
struct fruit {
	string name;
	int price;
	friend bool operator <(fruit f1, fruit f2) {
		return f1.price < f2.price;
	}
};
//friend为友元，bool operator<(fruit f1,fruit f2)对操作符"<"进行了重载，(重载大于号会编译错误，从数学上来说只需要重载小于号，即f1>f2等价于f2<f1，f1==f2等价于判断!(f1<f2)&&！(f2,f1)
//return f1.price<f2.price  重载后小于号还是小于号的作用，内部为价格高的水果的优先级高，与sort函数中的cmp相反。
struct cmp {
	bool operator()(fruit f1, fruit f2) {
		return f1.price > f2.price;
	}
};
priority_queue < fruit, vector<fruit>, cmp) q;
//如果结构体内的数据较为庞大(例如出现了字符串或者数组),建议引用来提高效率，此时比较类的参数中需要加上"const"和"&"
friend bool operator<(const fruit &f1, const fruit &f2) {
	return f1.price > f2.price;
}
bool operator()(const fruit &f1, const fruit &f2) {
	return f1.price > f2.price;
}
