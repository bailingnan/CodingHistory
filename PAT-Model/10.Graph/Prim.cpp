//给定一个无向图G(V,E)，求1棵树T，使得这棵树拥有图G中的所有顶点，且所有边都是来自图G中的边，并且满足整棵树的边权之和最小。
//时间复杂度为O(V^2),适合稠密图：顶点数目少，边数多；
const int MAXV = 1000;
const int INF = 1000000000;
//邻接矩阵版
int n, G[MAXV][MAXV];
int d[MAXV];//顶点与集合S的最短距离
bool vis[MAXV] = { false };
int prim() {
	fill(d, d + MAXV, INF);
	d[0] = 0;
	int ans = 0;//存放最小生成树的边权之和
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，则剩下的顶点和集合S不连通
		if (u == -1) return -1;
		vis[u] = true;
		ans += d[u];//将与集合S距离最小的边加入最小生成树
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF && G[u][v] < d[v]) {
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}
//邻接表版
vector<int> Adj[MAXN];
int n;
int d[MAXV];//顶点与集合S的最短距离
bool vis[MAXV] = { false };
int prim() {
	fill(d, d + MAXV, INF);
	d[0] = 0;
	int ans = 0;//存放最小生成树的边权之和
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		//找不到小于INF的d[u]，则剩下的顶点和集合S不连通
		if (u == -1) return -1;
		vis[u] = true;
		ans += d[u];//将与集合S距离最小的边加入最小生成树
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			if (vis[v] == false && Adj[u][j].dis < d[v]) {
				d[v] = Adj[u][j].dis;
			}
		}
	}
	return ans;
}
