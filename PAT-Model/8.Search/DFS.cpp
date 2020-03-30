//背包问题
//有n件物品，每件物品的重量为w[i],价值为c[i],现在需要选出若干件物品放入一个
//容量为V的背包中，使得选入背包的物品重量和不超过容量V的前提下，让背包中物品
//的价值之和最大，求最大价值。
#include<cstdio>
const int maxn = 30;
int n, V, maxValue = 0;//物品件数n，背包容量V，最大价值maxValue;
int w[maxn], c[maxn];//w[i]为每件物品的重量，c[i]为每件物品的价值
//DFS,index为当前处理的物品编号
//sumW和sumC分别为当前总重量和当前总价值
void DFS(int index, int sumW, int sumC) {
	if (index == n) {//已完成对n件物品的选择
		if (sumW <= V && sumC > maxValue) {
			maxValue = sumC;//不超过背包容量时更新最大价值maxValue
		}
		return;
	}
	DFS(index + 1, sumW, sumC);//不选第index件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
}
int main() {
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	DFS(0, 0, 0);//初始时为第0件物品，当前总重量和总价值均为0
	printf("%d", maxValue);
	return 0;
}
//剪枝
void DFS(int index, int sumW, int sumC) {
	if (index == n) {
		return;
	}
	DFS(index + 1, sumW, sumC);//不选第index件物品
	//只有加入第index件物品后未超过容量V，才能继续
	if (sumW + w[index] <= V) {
		if (sumC + c[index] > ans) {
			ans = sumC + c[index];
		}
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}
//给定N个整数，从中选择K个数，使得这K个数之和恰好等于一个给定的整数X，如果有多种方案，选择元素平方和最大的一个。
int n, k, x, maxSumSqu = -1, A[maxn];
vector<int> temp, ans;
void DFS(int index, int nowK, int sum, int sumSqu) {
	if (nowK == k && sum == x) {
		if (sumSqu > maxSumSqu) {
			maxSumSqu = sumSqu;
			ans = temp;
		}
	}
	if (index == n || nowK > k || sum > x) {
		return;
	}
	temp.push_back(A[index]);
	DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	DFS(index + 1, nowK, sum, sumSqu);
}
//若每个整数可以被选择n次。
void DFS(int index, int nowK, int sum, int sumSqu) {
	if (nowK == k && sum == x) {
		if (sumSqu > maxSumSqu) {
			maxSumSqu = sumSqu;
			ans = temp;
		}
	}
	if (index == n || nowK > k || sum > x) {
		return;
	}
	temp.push_back(A[index]);
	DFS(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	DFS(index + 1, nowK, sum, sumSqu);
}
