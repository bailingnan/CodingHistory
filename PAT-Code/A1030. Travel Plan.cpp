#include<cstdio>
#include<algorithm>
#include<vector>
const int maxn = 1000;
const int INF = 1000000000;
using namespace std;
struct Node {
	int v, dis, w;
};
bool vit[maxn] = { 0 };
int d[maxn], N, M, S, V, tot = INF;
vector<int> pre[maxn], t, tt;
vector<Node> p[maxn];
void DJI(int s) {
	fill(d, d + N, INF);
	d[s] = 0;
	pre[s].push_back(s);
	for (int i = 0; i < N; i++) {
		int u = -1, minn = INF;
		for (int j = 0; j < N; j++) {
			if (vit[j] == false && d[j] <minn) {
				u = j;
				minn = d[j];
			}
		}
		if (u == -1) return;
		vit[u] = true;
		for (int k = 0; k < p[u].size(); k++) {
			int v = p[u][k].v;
			if (vit[v] == false && d[u] + p[u][k].dis < d[v]) {
				d[v] = d[u] + p[u][k].dis;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (vit[v] == false && d[u] + p[u][k].dis == d[v]) {
				pre[v].push_back(u);
			}
		}
	}
}
void DFS(int st, int v) {
	if (v == st) {
		tt.push_back(v);
		int temp = 0;
		for (int i = tt.size() - 1; i > 0; i--) {
			int k = tt[i], j = tt[i - 1];
			for (int m = 0; m < p[k].size(); m++) {
				if (p[k][m].v == j)
					temp += p[k][m].w;
			}
		}
		if (temp<tot) {
			tot = temp;
			t = tt;
		}
		tt.pop_back();
		return;
	}
	tt.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(st, pre[v][i]);
	}
	tt.pop_back();
}
int main() {
	scanf("%d%d%d%d", &N, &M, &S, &V);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		Node temp;
		temp.v = t2;
		scanf("%d%d", &temp.dis, &temp.w);
		p[t1].push_back(temp);
		temp.v = t1;
		p[t2].push_back(temp);
	}
	DJI(S);
	DFS(S, V);
	for (int i = t.size() - 1; i >= 0; i--) {
		printf("%d", t[i]);
		printf(" ");
	}
	printf("%d %d", d[V], tot);
	return 0;
}
//算法笔记，方法一：Dijkstra + DFS
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], minCost = INF;
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> tempPath, path;
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    for(int i = 0; i < n; i++) {
        pre[i].push_back(i);
    }
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v) {
    if(v == st) {
        tempPath.push_back(v);
        int tempCost = 0;
        for(int i = tempPath.size() - 1; i > 0; i--) {
            int id = tempPath[i], idNext = tempPath[i - 1];
            tempCost += cost[id][idNext];
        }
        if(tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(cost[0], cost[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], minCost);
    return 0;
}
方法二：Dijkstra算法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV], c[MAXV], pre[MAXV];
bool vis[MAXV] = {false};
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(c, c + MAXV, INF);
    for(int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                } else if(d[u] + G[u][v] == d[v]) {
                    if(c[u] + cost[u][v] < c[v]) {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void DFS(int v) {
    if(v == st) {
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}
