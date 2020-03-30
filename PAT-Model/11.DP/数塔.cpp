//第n层有n个数字，从第1层走到第n层，每次只能走向下一层连接的两个数字的一个，求所有数字的最大和。
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;
int f[maxn][maxn], dp[maxn][maxn];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &f[i][j]);//输入数据
		}
	}
	//边界
	for (int j = 1; j <= n; j++) {
		dp[n][j] = f[n][j];
	}
	//从第n-1层不断向上计算出dp[i][j]
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			//状态转移方程
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
		}
	}
	printf("%d\n", dp[1][1]);
	return 0;
}
//递归写法
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 1000000000;
int f[maxn][maxn], dp[maxn][maxn];
int init(int m, int n) {
	if (dp[m][n] == INF)
		return dp[m][n] = max(init(m + 1, n), init(m + 1, n + 1)) + f[m][n];
	else return dp[m][n];
}
int K;
int main() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; i <= i; j++) {
			dp[i][j] = INF;
		}
	}
	scanf("%d", &K);
	for (int i = 0; i <K; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &f[i][j]);
		}
	}
	int max = -1, sum = 0;
	for (int i = 0; i < K; i++) {
		dp[K - 1][i] = f[K - 1][i];
	}
	printf("%d", init(0, 0));
	return 0;
}
