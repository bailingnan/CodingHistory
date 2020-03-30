//整个DAG中的最长路径(即不限定起终点)
int DP(int i) {
	if (dp[i] > 0) return dp[i];//dp[i]已计算得到
	for (int j = 0; j < n; j++) {//遍历i的所有边
		if (G[i][j] != INF) {
			dp[i] = max(dp[i], DP(j) + G[i][j]);
		}
	}
	return dp[i];
}
//记录最长路径
int DP(int i) {
	if (dp[i] > 0) return dp[i];//dp[i]已计算得到
	for (int j = 0; j < n; j++) {//遍历i的所有出边
		if (G[i][j] != INF) {
			int temp = DP(j) + G[i][j];//单独计算，防止if中调用DP函数两次
			if (temp > dp[i]) {//可以获得最长路径
				dp[i] = temp;
				choice[i] = j;//i号顶点的后继顶点是j
			}
		}
	}
}
//调用printPath前需要先得到最大的dp[i]，然后将i作为路径顶点传入
void printPath(int i) {
	printf("%d", i);
	while (choice[i] != -1) {//choice数组初始化为-1
		i = choice[i];
		printf("->%d", i);
	}
}
//固定终点，求DAG最长路径
//初始条件：终点为T，dp[T]=0,初始化dp数组为-INF
int DP(int i) {
	if (vis[i]) return dp[i];//dp[i]已计算得到
	vis[i] = true;
	for (int j = 0; j < n; j++) {//遍历i的所有出边
		if (G[i][j] != INF) {
			dp[i] = max(dp[i], DP(j) + G[i][j]);
		}
	}
	return dp[i];
}
