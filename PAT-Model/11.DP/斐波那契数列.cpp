//递归写法，复杂度O(2^N)
int F(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else return F(n - 1) + F(n - 2);
}
//记忆化搜索,复杂度O(N)
int MAXN = 1000000000;
int dp[MAXN];
fill(dp, dp + MAXN, -1);
int F(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (dp[n] != -1) return dp[n];
	else {
		dp[n] = F(n - 1) + F(n - 2);
		return dp[n];
	}
}
