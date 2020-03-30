const int MAXV = 1000;//最大顶点数
const int INF = 1000000000;//设INF为很大的一个数字
//邻接矩阵版
int n, G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = { false };//如果顶点i已经被访问，则vis[i]==true。初值为false;
void DFS(int u, int depth) {//u为当前访问的顶点标号，depth为深度。
	vis[u] = true;//设置u已被访问
	//如果需要对u进行一些操作，可以在这里进行
	//下面对所有从u出发能到达的分支顶点进行枚举
	for (int v = 0; v < n; v++) {//对每个顶点v
		if (vis[v] == false && G[u][v] != INF) {//如果v未被访问，且u可到达v
			DFS(v, depth + 1);
		}
	}
}
void DFSTrave() {//遍历图G
	for (int u = 0; u < n; u++) {//对每个顶点u
		if (vis[u] == false) {//如果u未被访问
			DFS(u, 1);//访问u和u所在的连通块，1表示初始为第一层
		}
	}
}
//邻接表版
vector<int> Adj[MAXV];//图G的邻接表
int n;//n为顶点数，MAXV为最大顶点数
bool vis[MAXV] = { false };//如果顶点i已被访问，则vis[i]==true。初值为false
void DFS(int u, int depth) {//u为当前访问的顶点编号，depth为深度
	vis[u] = true;
	//如果需要对u进行一些操作，可以在此处进行。
	for (int i = 0; i < Adj[u].size(); i++) {//对从u出发可以到达的所有顶点v
		int v = Adj[u][i];
		if (vis[u] == false) {//如果v未被访问
			DFS(v, depth + 1);
		}
	}
}
void DFSTrave() {//遍历图G
	for (int u = 0; u < n; u++) {//对每个顶点u
		if (vis[u] == false) {//如果u未被访问
			DFS(u, 1);//访问u和u所在的连通块，1表示初始为第一层
		}
	}
}
//有环的情况
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for(int i = 0; i < numPerson; i++) {
        if(G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
