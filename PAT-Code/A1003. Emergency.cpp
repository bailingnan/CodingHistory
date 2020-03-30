#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 1000000000;
const int maxn = 510;
bool vit[maxn] = { 0 };
int num[maxn] = { 0 }, d[maxn], cnt[maxn] = { 0 }, w[maxn];
int N, M, s, tg;
struct City {
	int v, dis;
};
vector<City> vt[maxn];
void DJS(int s) {
	fill(d, d + N, INF);
	d[s] = 0;
	num[s] = 1;
	cnt[s] = w[s];
	for (int i = 0; i < N; i++) {
		int temp = -1, minn = INF;
		for (int k = 0; k < N; k++) {
			if (vit[k] == false && d[k] < minn) {
				minn = d[k];
				temp = k;
			}
		}
		if (temp == -1) return;
		vit[temp] = true;
		for (int j = 0; j < vt[temp].size(); j++) {
			int v = vt[temp][j].v;
			if (vit[v] == false && d[temp] + vt[temp][j].dis < d[v]) {
				d[v] = d[temp] + vt[temp][j].dis;
				num[v] = num[temp];
				cnt[v] = cnt[temp] + w[v];
			}
			else if (d[temp] + vt[temp][j].dis == d[v]) {
				if(cnt[temp] + w[v]>cnt[v])
					cnt[v] = cnt[temp] + w[v];
				num[v] += num[temp];
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &N, &M, &s, &tg);
	for (int i = 0; i < N; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < M; i++) {
		int t;
		City temp;
		scanf("%d%d%d", &t, &temp.v, &temp.dis);
		vt[t].push_back(temp);
		int m = temp.v;
		temp.v = t;
		vt[m].push_back(temp);
	}
	DJS(s);
	printf("%d %d", num[tg], cnt[tg]);
	return 0;
}
//SPFA,扣6分，两个测试点错误
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 510;
const int INF = (1 << 30)- 1;
struct City {
	int v, dis;
};
vector<City> city[MAXN];
set<int> st[MAXN];
bool vis[MAXN] = {false};
int weight[MAXN], d[MAXN], w[MAXN], cnt[MAXN] = { 0 };
int N, M, C1, C2, maxn = 0;
void SPFA(int m) {
	fill(d, d + N, INF);
	fill(w, w + N, 0);
	fill(cnt, cnt + N, 0);
	d[m] = 0;
	w[m] = weight[m];
	cnt[m] = 1;
	queue<int> q;
	q.push(m);
	vis[m] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < city[u].size(); i++) {
			int v = city[u][i].v;
			int dis = city[u][i].dis;
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				w[v] = w[u] + weight[v];
				st[v].clear();
				st[v].insert(u);
				cnt[v] = cnt[u];
				if (vis[v] == false) {
					q.push(v);
					vis[v] = true;
				}
			}
			else if (d[u] + dis == d[v]) {
				if (w[u] + weight[v] > w[v]) {
					w[v] = w[u] + weight[v];
				}
				cnt[v] = 0;
				st[v].insert(u);
				set<int>::iterator it;
				for (it = st[v].begin(); it != st[v].end(); it++) {
					cnt[v] += cnt[*it];
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, dis;
		scanf("%d%d%d", &c1, &c2, &dis);
		City temp;
		temp.v = c2;
		temp.dis = dis;
		city[c1].push_back(temp);
		temp.v = c1;
		city[c2].push_back(temp);
	}
	SPFA(C1);
	printf("%d %d",cnt[C2], w[C2]);
	return 0;
}
//算法笔记，方法一：Dijkstra算法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = {false};
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
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
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                } else if(d[u] + G[u][v] == d[v]) {
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}
方法二：BF算法
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAXV = 510;
const int INF = 0x3fffffff;
struct Node {
	int v, dis;
	Node(int _v, int _dis) :v(_v), dis(_dis) {}
};
vector<Node> Adj[MAXV];
int n, m, st, ed, weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];
set<int> pre[MAXV];
void Bellman(int s) {
	fill(d, d + MAXV, INF);
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s]=weight[s];
	num[s] = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;
				int dis = Adj[u][j].dis;
				if (d[u] + dis < d[v]) {
					d[v] = d[u] + dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}
				else if (d[u] + dis == d[v]) {
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
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
int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	int u, v, wt;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &u, &v, &wt);
		Adj[u].push_back(Node(v, wt));
		Adj[v].push_back(Node(u, wt));
	}
	Bellman(st);
	printf("%d %d\n", num[ed], w[ed]);
	return 0;
}
