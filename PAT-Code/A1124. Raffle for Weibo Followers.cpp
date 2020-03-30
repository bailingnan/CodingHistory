#include<string>
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<map>  
using namespace std;
int m, n, s;
string t[1001];
//用来记录被抽中的次数   
map<string, int> vis;
int main(){
	cin >> m >> n >> s;
	int cnt = 0;
	for (int i = 0; i<m; i++){
		cin >> t[i];
		vis[t[i]] = 0;
	}
	//flag用来标记是否有中奖者   
	int flag = 1;
	//i=s-1 直接从中奖者开始遍历   
	for (int i = s - 1; i<m; ) {
		if (vis[t[i]] == 0) {
			flag = 0;
			cout << t[i] << endl;
			vis[t[i]] = 1;
			//如果有中奖者 直接+n都下一个中奖者   
			i += n;
		}
		else {
			//如果该中奖者已经中过一次 则跳到下一个人   
			i += 1;
		}
	}
	if (flag) {
		puts("Keep going...");
	}
	return 0;
}
