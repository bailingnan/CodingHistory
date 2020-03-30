//邻接矩阵版
//主要是外层循环O(V)(V就是顶点个数n)与内层循环(寻找最小的d[u]需要O(V)，枚举v需要O(V))
//总复杂度为O(V*(V+V))=O(V^2)
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];//优化d[v]
			}
		}
	}
}
//邻接表版
//主要是外层循环O(V)与内层循环(寻找最小的d[u]需要O(V),枚举v需要O(adj[u].size()))产生的。
//对整个程序来说，枚举v的总次数为O(E)，总复杂度为O(V^2+E);
struct Node {
	int v, dis;//v为边的目标顶点,dis为边权
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int j= 0; j< Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			if (vis[v] == false&& d[u] + Adj[u][j].dis< d[v]) {
				d[v] = d[u] + Adj[u][j].dis;//优化d[v]
			}
		}
	}
}
//记录最短路径
const int MAXV = 1000;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];//起点到达各点的最短路径长度
int pre[MAXV];//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
bool vis[MAXV] = { false };
void Dijkstra(int s) {//s为起点
	fill(d, d + MAXV, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];//优化d[v]
				pre[v] = u;
			}
		}
	}
}
//递归输出路径
void DFS(int s, int v) {//s为起点编号,v为当前访问的顶点编号(从终点开始递归)
	if (v == s) {
		printf("%d\n", s);
		return;
	}
	DFS(s, pre[v]);
	printf("%d\n", v);
}
//若有两条及以上可到达最短距离的路径，会给出一个第二标尺。
//1.给每条边增加一个边权，求在最短路径有多条时要求路径上的花费最小(或最大);
//2.给每个点增加一个点权，求在最短路径有多条时要求路径上的点权之和最大(或最小);
//3.有多少条最短路径;
//1.新增边权,初始化c[s]=0,,其余均为INF，cost[u][v]记录边权;
for (int v = 0; v < n; v++) {
	if (vis[v] == false && G[u][v] != INF) {
		if (d[u] + G[u][v] < d[v]) {
			d[v] = d[u] + G[u][v];
			c[v] = c[u] + cost[u][v];
		}
		else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
			c[v] = c[u] + cost[u][v];
		}
	}
}
//2.新增点权,weight[u]表示点权,初始化w[s]=weight[s]，其余均为0;
for (int v = 0; v < n; v++) {
	if (vis[v] == false && G[u][v] != INF) {
		if (d[u] + G[u][v] < d[v]) {
			d[v] = d[u] + G[u][v];
			w[v] = w[u] +weight[u][v];
		}
		else if (d[u] + G[u][v] == d[v] && w[u] + weight[u][v]>c[v]) {
			w[v] = w[u] + weight[u][v];
		}
	}
}
//3.求最短路径条数。增加数组num[],令从起点s到达顶点u的最短路径条数为num[u],初始化num[s]=1,其余均为0;
for (int v = 0; v < n; v++) {
	if (vis[v] == false && G[u][v] != INF) {
		if (d[u] + G[u][v] < d[v]) {
			d[v] = d[u] + G[u][v];
			num[v] = num[u];
		}
		else if (d[u] + G[u][v] == d[v]) {
			num[v] += num[u];
		}
	}
}
//Dijkstra+DFS
vector<int> pre[MAXV]
if (d[u] + G[u][v] < d[v]) {
	d[v] = d[u] + G[u][v];
	pre[v].clear();
	pre[v].push_back(u);
}
else if (d[i] + G[u][v] == d[v]) {
	pre[v].push_back(u);
}
int optvalue;//第二标尺最优值
vector<int> pre[MAXV];//存放结点的前驱结点
vector<int> path, tempPath;//最优路径，临时路径
void DFS(int v) {//v为当前访问结点
	//递归边界
	if (v == st) {//如果到达了叶子结点st(即路径的起点)
		tempPath.push_back(v);//将起点st加入临时路径tempPath的最后面
		int value;
		//计算路径tempPath上的value值;
		if (value优于optvalue) {
			optvalue = value;//更新第二标尺最优值与最优路径
			path = tempPath;
		}
		tempPath.pop_back();//将刚加入的结点删除
		return;
	}
	tempPath.push_back(v);//将当前访问结点加入临时路径tempPath的最后面
	for (int i = 0; i < pre[v].size(); v++) {
		DFS(pre[v][i]);//结点v的前驱结点pre[v][i],递归
	}
	tempPath.pop_back();//遍历完所有前驱结点,将当前结点v删除
}
//边权之和
int value = 0;
for (int i = tempPath.size() - 1; i > 0; i--) {//倒着访问结点，循环条件为i>0
	//当前结点id,下一个结点idNext
	int id = tempPath[i], idNext = tempPath[i - 1];
	value += V[id][idNext];//value增加id->idNext的边权
}
//点权之和
int value = 0;
for (int i = tempPath.size() - 1; i >= 0; i--) {//倒着访问结点，循环条件为i>=0
	int id = tempPath[i];//当前结点id
	value += W[id];//value增加结点id的点权
}
