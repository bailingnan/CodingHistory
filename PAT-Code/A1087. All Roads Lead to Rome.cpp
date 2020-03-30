#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
const int INF = 100000000;
const int maxn =100010;
using namespace std;
struct Node {
	int name, cost;
};
bool vit[maxn] = { 0 };
vector<Node> ct[maxn];
vector<int> pre[maxn],tpwy,wy;
map<string, int> strtonum;
map<int, string> numtostr;
int N, K, cnt = 0, num=0,hp[maxn],d[maxn],stt,maxh=-1,minc=0;
string st;
void convert(string str) {
	strtonum[str] = cnt;
	numtostr[cnt] = str;
	cnt++;
}
void DIJ(int s) {
	fill(d, d + N, INF);
	d[s] = 0;
	pre[s].push_back(s);
	for (int i = 0; i < N; i++) {
		int u = -1, minn = INF;
		for (int j = 0; j < N; j++) {
			if (vit[j] == false && d[j] < minn) {
				u = j;
				minn = d[j];
			}
		}
		if (u == -1) return;
		vit[u] = true;
		for (int k = 0; k < ct[u].size(); k++) {
			int v = ct[u][k].name;
			int t = ct[u][k].cost;
			if (vit[v] == false && d[u] + t < d[v]) {
				d[v] = d[u] + t;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (vit[v] == false && d[u] + t==d[v]) {
				pre[v].push_back(u);
			}
		}
	}
}
void DFS(int v) {
	if (v == stt) {
		num++;
		tpwy.push_back(v);
		int temp = 0;
		for (int i = 0; i < tpwy.size(); i++) {
			temp += hp[tpwy[i]];
		}
		if (temp > maxh) {
			maxh = temp;
			wy = tpwy;
			minc = tpwy.size();
		}
		else if (temp == maxh) {
			if (tpwy.size() < minc) {
				wy = tpwy;
			}
		}
		tpwy.pop_back();
		return;
	}
	tpwy.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tpwy.pop_back();
}
int main() {
	scanf("%d%d", &N, &K);
	cin >> st;
	convert(st);
	stt =strtonum[st];
	hp[strtonum[st]] = 0;
	for (int i = 0; i < N - 1; i++) {
		string str;
		cin >> str;
		convert(str);
		int temp;
		scanf("%d", &temp);
		hp[strtonum[str]] = temp;
	}
	for (int i = 0; i < K; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		int temp, m;
		scanf("%d", &temp);
		Node t;
		t.name = strtonum[str2];
		t.cost = temp;
		m = strtonum[str1];
		ct[m].push_back(t);
		t.name = strtonum[str1];
		m = strtonum[str2];
		ct[m].push_back(t);
	}
	int tg = strtonum["ROM"];
	DIJ(stt);
	DFS(tg);
	printf("%d %d %d %d\n",num, d[tg], maxh, maxh / (wy.size() - 1));
	for (int i = wy.size()-1; i>=0; i--) {
		cout << numtostr[wy[i]];
		if (i>0)
			printf("->");
	}
	return 0;
}
//算法笔记，方法一:使用Dijkstra + DFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;
int n, m, st, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], numPath = 0, maxW = 0;
double maxAvg = 0;
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> tempPath, path;
map<string, int> cityToIndex;
map<int, string> indexToCity;
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
        numPath++;
        int tempW = 0;
        for(int i = tempPath.size() - 2; i >= 0; i--) {
            int id = tempPath[i];
            tempW += weight[id];
        }
        double tempAvg = 1.0 * tempW / (tempPath.size() - 1);
        if(tempW > maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if(tempW == maxW && tempAvg > maxAvg) {
            maxAvg = tempAvg;
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
    string start, city1, city2;
    cin >> n >> m >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for(int i = 1; i <= n - 1; i++) {
        cin >> city1 >> weight[i];
        cityToIndex[city1] = i;
        indexToCity[i] = city1;
    }
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(0);
    int rom = cityToIndex["ROM"];
    DFS(rom);
    printf("%d %d %d %d\n", numPath, d[rom], maxW, (int)maxAvg);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << indexToCity[path[i]];
        if(i > 0) cout << "->";
    }
    return 0;
}
方法二：只使用Dijkstra
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;
int n, m, st, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV], pt[MAXV], pre[MAXV];
bool vis[MAXV] = {false};
map<string, int> cityToIndex;
map<int, string> indexToCity;
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    memset(pt, 0, sizeof(pt));
    for(int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    w[s] = weight[st];
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
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                } else if(d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pt[v] = pt[u] + 1;
                        pre[v] = u;
                    } else if(w[u] + weight[v] == w[v]) {
                        double uAvg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
                        double vAvg = 1.0 * w[v] / pt[v];
                        if(uAvg > vAvg) {
                            pt[v] = pt[u] + 1;
                            pre[v] = u;
                        }
                    }
                }
            }
        }
    }
}
void printPath(int v) {
    if(v == 0) {
        cout << indexToCity[v];
        return;
    }
    printPath(pre[v]);
    cout << "->" << indexToCity[v];
}
int main() {
    string start, city1, city2;
    cin >> n >> m >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for(int i = 1; i <= n - 1; i++) {
        cin >> city1 >> weight[i];
        cityToIndex[city1] = i;
        indexToCity[i] = city1;
    }
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(0);
    int rom = cityToIndex["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / pt[rom]);
    printPath(rom);
    return 0;
}
