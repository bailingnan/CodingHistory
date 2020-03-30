//将有向无环图G的所有顶点排成一个线性序列，使得对图G的任意两个顶点u、v，如果存在边u->v,在序列中u一定在前面，这个序列称为拓扑序列。
//可用于判断是否是有向无环图
vector<int> G[MAXV]//邻接表
int n, m, inDegree[MAXV];//顶点数，入度
//拓扑排序
bool topologicalSort() {
	int num = 0;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);//将所有入度为0的顶点入队
		}
	}
	while (!q.empty()) {
		int u = q.front();//取队首顶点u
		//printf("%d",u);此处可输出顶点u，作为拓扑序列中的顶点
		q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];//u的后继结点u
			inDegree[v]--;//顶点v的入度减1
			if (inDegree[v] == 0) {//顶点v的入度减为0则入队
				q.push(v);
			}
		}
		G[u].clear();//清空顶点u的所有出边(如无必要可不写)
		num++;
	}
	if (num == n) return true;//加入拓扑序列的顶点数为n，说明拓扑排序成功
	else return false;//加入拓扑排序的顶点数小于n，说明拓扑排序失败
}
