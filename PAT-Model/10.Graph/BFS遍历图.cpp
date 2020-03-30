//邻接矩阵版
int n, G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数
bool inq[MAXV] = { false };//若顶点i曾入过队列，则inq[i]=true,初值为false
void BFS(int u) {//遍历u所在的连通块
	queue<int> q;
	q.push(u);
	inq[u] = true;//设置u已被加入过队列
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v, n; v++) {
			if (inq[v] == false && G[u]][v] != INF) {
				q.push(v);
				inq[v] = true;//标记v为已被加入过队列
			}
		}
	}
}
void BFSTrave() {
	for (int u = 0; u < n; u++) {
		if (inq[u] == false) {
			BFS(q);
		}
	}
}
//邻接表版
vector<int> Adj[MAXV];
int n;
bool inq[MAXV] = { false };
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i];
			if (inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}
void BFSTrave() {
	for (int u = 0; u < n; u++) {
		if (inq[u] == false) {
			BFS(q);
		}
	}
}
//输出顶点层号
struct Node {
	int v;
	int layer;
};
vector<Node> Adj[MAXV];
int n;
bool inq[MAXV] = { false };
void BFS(int s) {
	queue<Node> q;
	Node start;
	start.v = s;
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while (!q.empty()) {
		Node  topNode = q.front();
		q.pop();
		int u = topNode.v;
		for (int i = 0; i < Adj[u].size(); i++) {
			Node  next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if (inq[next.v] == false) {
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}
void BFSTrave() {
	for (int u = 0; u < n; u++) {
		if (inq[u] == false) {
			BFS(q);
		}
	}
}
