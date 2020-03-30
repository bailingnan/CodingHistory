//顶点活动(Activity On Vertex,AOV)网指用顶点表示活动，用边集表示活动间优先关系的有向图；
//边活动(Activit On Edge,AOE)网指用带权的边集表示活动，用顶点表示事件的有向图，边权表示完成活动所需要的时间。
//AOE网中的最长路径称为关键路径，关键路径上的活动称为关键活动。
//设置数组e[r]和l[r]，分别表示活动ar的最早开始时间和最迟开始时间。若二者相等，则为关键活动。边表示活动。
//设置数组ve[i]和vl[i]，ve[i]和vl[i]分别表示事件i的最早发生时间和最晚发生时间。点表示事件。
对活动ar来说，只要在事件Vi最早发生时马上开始，就可以使活动ar的开始时间最早，因此e[r]=ve[i];
如果l[r]是活动ar的最迟发生时间，那么l[r]+length[r]就是事件Vj的最迟发生时间(length[r]表示活动ar的边权),因此l[r]=vl[j]-length[r];
//拓扑序列
stack<int> topOrder;
//拓扑排序，顺便求ve数组
bool topologicalSort() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topOrder.push(u);//将u加入拓扑序列
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;//u的i号后继结点编号为v
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
			}
			//用ve[u]来更新u的所有后继结点v
			if (ve[u] + G[u][i].w > ve[v]) {
				ve[v] = ve[u] + G[u][i].w;
			}
		}
	}
	if (topOrder.size() == n) return true;
	else return false;
}
fill(vl,vl+n,ve[n-1])//vl数组初始化，初始值为终点的ve值
//直接使用topOrder出栈即为逆拓扑序列，求解vl数组
while (!topOrder.empty()) {
	int u = topOrder.top();//栈顶元素为u
	topOrder.pop();
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;//u的后继结点v
		//用u的所有后继结点v的vl值来更新vl[u]
		if (vl[u] - G[u][i].w < vl[u]) {
			vl[u] = vl[v] - G[u][i].w;
		}
	}
}
//先求点，再夹边
//1.按拓扑排序和逆拓扑排序分别计算各顶点（事件）的最早发生时间和最迟发生时间
//最早（拓扑序）:ve[j]=max{ve[i]+length[i->j]}
//最迟(逆拓扑序)：vl[i]=min{vl[j]-length[i->j]}
//2.用上面的结果计算各边（活动）的最早开始时间和最迟开始时间:
//最早e[i->j]=ve[i];
//最迟：l[i->j]=vl[j]-length[i->j]
//3.e[i->j]=l[i->j]的活动即为关键活动
//适用汇点确定且唯一的情况，以n-1号顶点为汇点为例：
//关键路径，不是有向无环图返回-1，否则返回关键路径长度
int CriticalPath() {
	memset(ve, 0, sizeof(ve));//ve数组初始化
	if (topologicalSort() == false) {
		return -1;//不是有向无环图，返回-1
	}
	fill(vl, vl + n, ve[n - 1]);//vl数组初始化，初始值为汇点的ve值
	//直接使用topOrder出栈即为逆拓扑序列，求解vl数组
	while (!topOrder.empty()) {
		int u = topOrder.top();
		topOrder.pop();
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v;
			if (vl[v] - G[u][i].w < vl[u]) {
				vl[u] = vl[v] - G[u][i].w;
			}
		}
	}
	//遍历邻接表的所有边，计算活动的最早开始时间e和最迟开始时间l
	for (int u = 0; u < n; u++) {
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v, w = G[u][i].w;
			//活动的最早开始时间e和最迟开始时间l
			int e = ve[u], l = vl[v] - w;
			//如果e==l,说明活动u->v是关键活动
			if (e == l) {
				printf("%d->%d\n", u, v);//输出关键活动
			}
		}
	}
	return ve[n - 1];//返回关键路径长度
}
//若事先不知道汇点编号，取ve数组的最大值，可修改为：
int maxLength = 0;
for (int i = 0; i < n; i++) {
	if (ve[i] > maxLength) {
		maxLength = ve[i];
	}
}
fill(vl, vl + n; maxLength);
