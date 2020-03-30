//N个只有小写字母的字符串，求其中不同的字符串个数
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;//模数:1e9+7
const int P = 10000019;//进制:1e7+19
vector<int> ans;
//字符串hash
long long hashFunc(string str) {
	long long H = 0;//使用long long避免溢出
	for (int i = 0; i < str.length(); i++) {
		H = (H*P + str[i] - 'a') % MOD;
	}
	return H;
}
int main() {
	string str;
	while (getline(cin, str), str != "#") {//输入str直到#时停止
		long long id = hashFunc(str);//将字符串str转换为整数
		ans.push_back(id);
	}
	sort(ans.begin(), ans.end());//排序
	int count = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0 || ans[i] != ans[i - 1])
			count++;
	}
	cout << count << endl;
	return 0;
}
//子串的hash值:H[i...j]=((H[j]-H[i-1]*p^(j-i+1)%MOD+MOD）%MOD
//求公共子串长度
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;//MOD为计算hash值时的模数
const LL P = 10000019;//P为计算hash值时的进制数
const LL MAXN = 1010;//MAXN为字符串最长长度
LL powP[MAXN],H1[MAXN]={0},H2[MAXN]={0};
//pr1存放str1的所有<子串hash值,子串长度>,pr2同理
vector<pair<int, int>> pr1, pr2;
//init函数初始化powP函数
void init(int len) {
	powP[0] = 1;
	for (int i = 1; i <= len; i++) {
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}
//calH函数计算字符串str的hash值
void calH(LL H[], string &str) {
	H[0] = str[0];//H[0]单独处理
	for (int i = 1; i < str.length(); i++) {
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}
//calSingleSubH计算H[i...j]
int calSingleSubH(LL H[], int i, int j) {
	if (i == 0) return H[j];
	return ((H[j] - H[i - 1])*powP[j - i + 1] % MOD + MOD) % MOD;
}
//calSubH计算所有子串的hash值，并将子串<子串hash值,子串长度>存入pr
void calSubH(LL H[], int len, vector<pair<int, int>>&pr) {
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			int hashValue = calSingleSubH(H, i, j);
			pr.push_back(make_pair(hashValue, j - i + 1));
		}
	}
}
//计算pr1和pr2中相同的hash值，维护最大长度
int getMax() {
	int ans = 0;
	for (int i = 0; i < pr1.size(); i++) {
		for (int j = 0; j < pr2.size(); j++) {
			if (pr1[i].first == pr2[j].first) {
				ans = max(ans, pr1[i].second);
			}
		}
	}
	return ans;
}
int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	init(max(str1.length(), str2.length()));//初始化powP数组
	calH(H1, str1);
	calH(H2, str2);
	calSubH(H1, str1.length(), pr1);//分别计算所有H1[i...j]和H2[i...j]
	calSubH(H2, str2.length(), pr2);
	printf("ans=%d\n", getMax());
	return 0;
}
