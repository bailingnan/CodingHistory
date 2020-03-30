//Bellman-Ford算法只有当某个顶点u的d[u]值改变时，从它出发的边的邻接点v的d[v]值才有可能改变。
//如果负环不可达，则需要添加一个辅助顶点C，并添加一条从源点到达C的有向边以及V-1条从C到达除源点外各顶点的有向边才能判断负环是否存在。
//时间复杂度为O(kE),k是一个常数，很多情况下不超过2，若有源点可达的负环，则退化为O(VE);
vector<Node> Adj[MAXV];//图G的邻接表
int n, d[MAXV], num[MAXV];//num数组记录顶点的入队次数
bool inq[MAXV];//顶点是否在队列中
bool SPFA(int s) {
	//初始化部分
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	fill(d, d + MAXV, INF);
	//源点入队部分
	queue<int> Q;
	Q.push(s);//源点入队
	inq[s] = true;//源点已入队
	num[s]++;//源点入队次数加1
	d[s] = 0;//源点d值为0
	while (!Q.empty()) {
		int u = Q.front();//队首顶点编号为u
		Q.pop();//出队
		inq[u] = false;//设置u为不在队列中
		//遍历u的所有邻接边v
		for (int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			int dis = Adj[u][j].dis;
			//松弛操作
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {//如果v不在队列中
					Q.push(v);//v入队
					inq[v] = true;//设置v在队列中
					num[v]++;//v的入队次数加1
					if (num[v] >= n) return false;//有可达负环
				}
			}
		}
	}
	return true;
}
