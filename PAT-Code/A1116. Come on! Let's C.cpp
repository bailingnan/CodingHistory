#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
char str[5][100] = { "Minion","Chocolate","Mystery Award","Are you kidding?","Checked"};
const int maxn = 10010;
bool ht[maxn];
int cnt[maxn],st[maxn],rk[maxn];
int N, K;
bool isPrime(int m) {
	int sq = (int)sqrt(1.0*m);
	for (int i = 2; i <= sq; i++) {
		if (m%i == 0) {
			return false;
			break;
		}
	}
	return true;
}
int main() {
	fill(ht, ht + maxn, false);
	fill(cnt, cnt + maxn, 0);
	scanf("%d", &N);
	for (int i = 0; i <N; i++) {
		scanf("%d", &st[i]);
		ht[st[i]] =true;
		rk[st[i]] = i + 1;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%04d: ", temp);
		cnt[temp]++;
		if (ht[temp] == false) {
			printf("%s\n", str[3]);
		}
		else {
			if (cnt[temp] > 1) {
				printf("%s\n", str[4]);
			}
			else if (temp == st[0]) {
				printf("%s\n", str[2]);
			}
			else if (isPrime(rk[temp])==true) {
				printf("%s\n", str[0]);
			}
			else {
				printf("%s\n", str[1]);
			}
		}
	}
	return 0;
}
//算法笔记
/*const int maxn = 10010;
int IDtoAward[maxn] = { 0 };      // 每个ID对应的奖项编号,初始化为0,表示不在排名中
								  // 五个输出,分别对应(0)不在排名中(1)冠军(2)素数(3)非素数(4)已查找
char award[5][20] = { "Are you kidding?", "Mystery Award", "Minion", "Chocolate", "Checked" };
bool isPrime(int x) {   // idPrime函数判断是否为素数
	if (x <= 1) return false;    // 特判
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;   // 只要存在根号x范围内的因子,就是非素数
		}
	}
	return true;    // 不存在根号x范围内的因子,是素数
}
int main() {
	int n, ID;
	scanf("%d", &n);    // 排名人数
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ID);   // 排名人的ID
		if (i == 1) {                // 冠军
			IDtoAward[ID] = 1;      // 奖项编号为1
		}
		else if (isPrime(i)) {     // 素数
			IDtoAward[ID] = 2;      // 奖项编号为2
		}
		else {                    // 非素数
			IDtoAward[ID] = 3;      // 奖项编号为3
		}
	}
	int m, queryID;
	scanf("%d", &m);    // 查询数
	for (int i = 0; i < m; i++) {
		scanf("%d", &queryID);      // 查询ID
		printf("%04d: %s\n", queryID, award[IDtoAward[queryID]]);   // 输出ID和对应的奖项
		if (IDtoAward[queryID]) {        // 如果该ID在排名中
			IDtoAward[queryID] = 4;     // 设置为已查找
		}
	}
	return 0;
}*/
