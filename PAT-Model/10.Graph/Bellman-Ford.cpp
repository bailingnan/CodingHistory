//求解有负权边的最短路径问题;
//设置一个数组d,用来存放从源点到各个顶点的最短距离，返回bool值，如果其中存在从源点可达的负环，返回false;
//若在某一轮操作时，所有边都没有被松弛，说明数组d中的所有值都已达到最优，不需要再继续，提前退出即可；
//统计最短路径条数的做法：由于该算法会在算法期间多次访问曾经访问过的顶点，若按照Dijkstra算法中num数组的写法；
//会反复累计已经计算过的顶点。需要设置记录前驱的数组set<int> pre[MAXV],当遇到一条和已有最短路径长度相同的路径时；
//必须重新计算最短路径条数。
//时间复杂度为O(VE)，v为顶点个数,E为边数
struct Node {
	int v, dis;
};
vector<Node> Adj[MAXN];
int n;
int d[MAXN];
bool Bellman(int s) {
	fill(d, d + MAXN, INF);
	d[s] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;//松弛操作
				}
			}
		}
	}
	//判断负环
	for (int u = 0; u < n; u++) {//对每条边进行判断
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;//邻接边的顶点
			int dis = Adj[u][j].dis;//邻接边的边权
			if (d[u] + dis < d[v]) {//如果仍然可以被松弛
				return false;//说明图中有源点可达的负环
			}
		}
	}
	return true;
}
//示例：
set<int> pre[MAXV];
for (int i = 0; i < n - 1; i++) {
	for (int u = 0; u < n; u++) {
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				w[v] = w[u] + weight[v];
				num[v] = num[u];
				pre[v].clear();//覆盖num[v]
				pre[v].insert(u);
			}
			else if (d[u] + dis == d[v]) {
				if (w[u] + weight[v] > w[v]) {
					w[v] = w[u] + weight[v];
				}
				pre[v].insert(u);
				num[v] = 0;
				set<int>::iterator it;
				for (it = pre[v].begin(); it != pre[v].end(); it++) {
					num[v] += num[*it];
				}
				}
			}
		}
	}
}
