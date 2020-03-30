//计算n!中有多少个质因子p，O(nlogn)
int cal(int n, int p) {
	int ans = 0;
	for (int i = 2; i<=n; i++) {
		int temp = i;
		while (temp%p == 0) {
			ans++;
			temp /= p;
		}
	}
	return ans;
}
//计算n!中有多少个质因子p,O(logn)
int cal(int n, int p) {
	int ans = 0;
	while (n) {
		ans += n / p;
		n /= p;
	}
	return ans;
}
//可快速计算出n!的末尾有多少个0,：由于末尾0的个数等于n!中因子10的个数，而这又等于n!中质因子5的个数，cal(n,5)即可得到结果。
//n!中质因子p的个数，实际上等于1~n中p的倍数的个数n/p加上n/p!中质因子p的个数
int cal(int n, int p) {
	if (n < p) return 0;//n<p时1~n中不可能有质因子p
	return n / p + cal(n / p, p);//返回n/p加上(n/p)！中质因子p的个数
}
//定义式直接计算
long long C(long long n, long long m) {
	long long ans = 1;
	for (long long i = 1; i <= n; i++) {
		ans *= i;
	}
	for (long long i = 1; i <= m; i++) {
		ans /= i;
	}
	for (long long i = 1; i <= n - m; i++) {
		ans /= i;
	}
	return ans;
}
//递归
long long C(long long n, long long m) {
	if (m == 0 || m == n) return 1;
	return C(n - 1, m) + C(n - 1, m - 1);
}
//递归优化
long long res[67][67] = { 0 };
long long C(long long n, long long m) {
	if (m == 0 || m == n) return 1;
	if (res[n][m] != 0) return res[n][m];
	return res[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}
//打表,O(n^2)
const int n = 60;
void calC() {
	for (int i = 0; i <= n; i++) {
		res[i][0] = res[i][i] = 1;//初始化边界
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
			res[i][i - j] = res[i][i - j];
		}
	}
}
//定义式变形
long long C(long long n, long long m) {//O(m)
	long long ans = 1;
	for (long long i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;//一定要先乘再除
	}
	return ans;
}
//计算组合数%p
long long res[67][67] = { 0 };
long long C(long long n, long long m) {
	if (m == 0 || m == n) return 1;
	if (res[n][m] != 0) return res[n][m];
	return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1))%p;
}
//递推
const int n = 60;
void calC() {
	for (int i = 0; i <= n; i++) {
		res[i][0] = res[i][i] = 1;//初始化边界
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			res[i][j] = (res[i - 1][j] + res[i - 1][j - 1])%p;
			res[i][i - j] = res[i][i - j];
		}
	}
}
