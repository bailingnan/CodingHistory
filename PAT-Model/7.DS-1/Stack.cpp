//后缀表达式
#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node {
	double num;//操作数
	char op;//操作符
	bool flag;//true表示操作数，false表示操作符
};
string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char, int> op;
void Change() {//中缀表达式转换为后缀表达式
	node temp;
	for (int i = 0; i < str.length();) {
		if (str[i] >= '0'&&str[i] <= '9') {//如果是数字
			temp.flag = true;//标记是数字数
			temp.num = str[i++] - '0';//记录这个操作数的第一个数位
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0');//更新这个操作数
				i++;
			}
			q.push(temp);//将这个操作数压入后缀表达式的队列
		}
		else {//如果是操作符
			temp.flag = false;//标记是操作符
			//只要操作符栈的栈顶元素比该操作符的优先级高
			//就把操作符栈栈顶元素弹出到后缀表达式的队列中
			if (str[i] == '(') {
				temp.op = str[i];
				s.push(temp);
				i++;
			}
			else if (str[i] == ')') {
				while (!s.empty() && s.top().op != '(') {
					q.push(s.top());
					s.pop();
				}
				s.pop();
				i++;
			}
			else {
				while (!s.empty() && op[str[i]] <= op[s.top().op]&&s.top().op!='(') {
					q.push(s.top());
					s.pop();
				}
				temp.op = str[i];
				s.push(temp);
				i++;
			}
		}
	}
	//如果操作符栈中的还有操作符，就把它弹出到后缀表达式队列中
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}
double Cal() {//计算后缀表达式
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) s.push(cur);
		else {
			double temp2 = s.top().num;
			s.pop();
			double temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if (cur.op == '+') temp.num = temp1 + temp2;
			else if (cur.op == '-') temp.num = temp1 - temp2;
			else if (cur.op == '*') temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;
			s.push(temp);//把该操作数压入栈
		}
	}
	return s.top().num;
}
int main() {
	op['+'] = op['-'] = 1;//设定操作符的优先级
	op['*'] = op['/'] = 2;
	while (getline(cin, str), str!="0") {
		for (string::iterator it = str.begin(); it != str.end(); it++) {
			if (*it == ' ') str.erase(it);//把表达式中的空格全部去掉
		}
		while (!s.empty()) s.pop();//初始化栈
		Change();//将中缀表达式转换为后缀表达式
		printf("%.2f\n", Cal());//计算后缀表达式
	}
	return 0;
}
