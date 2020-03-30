//时间复杂度O(ElogE),适合顶点数较多，边数较少的稀疏图
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 110;
const int MAXE = 10010;
//边集定义部分
struct edge {
	int u, v;//边的两个端点编号
	int cost;//边权
}E[MAXE];
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}
//并查集部分
int father[MAXV];//并查集数组
int findfather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	//路径压缩
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
//kruskal部分，返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n, int m) {
	//ans为所求边权之和，Num_Edge为当前生成树的边数
	int ans = 0, Num_Edge = 0;
	for (int i = 0; i < n; i++) {
		father[i] = i;//并查集初始化
	}
	sort(E, E + m, cmp);
	for (int i = 0; i < m; i++) {
		int faU = findfather(E[i].u);//查询测试边两个端点所在集合的根节点
		int faV = findfather(E[i].v);
		if (faU != faV) {//如果不在一个集合中
			father[faU] = faV;//合并集合(即把测试边加入最短生成树中)
			ans += E[i].cost;//边权之和增加测试边的边权
			Num_Edge++;//当前生成树的边数加1
			if (Num_Edge == n - 1) break;//边数等于顶点数减1时结束算法
		}
	}
	if (Num_Edge != n - 1) return -1;//无法连通时返回-1
	else return ans;//返回最小生成树的边权之和
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);//顶点数，边数
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);//两个端点编号，边权
	}
	int ans = kruskal(n, m);//kruskal算法入口
	printf("%d\n", ans);
	return 0;
}
