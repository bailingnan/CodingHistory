//SPFA
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
const int maxn = 10020;
const int INF = (1<< 30) - 1;
struct Node {
	int v;
	double dis;
};
double Ds,d[maxn], mind[11], avg[11];
bool vis[maxn];
vector<Node> v[maxn];
vector<int> p;
bool cmp(int a, int b) {
	if (mind[a] != mind[b]) {
		return mind[a] > mind[b];
	}
	else if(avg[a]!=avg[b]){
		return avg[a] < avg[b];
	}
	else return a < b;
}
int N, M, K;
void SPFA(int m) {
	fill(d, d + maxn, INF);
	fill(vis, vis + maxn, false);
	queue<int> q;
	d[m] = 0;
	q.push(m);
	vis[m] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < (int)v[u].size(); i++) {
			int num= v[u][i].v;
			double dis = v[u][i].dis;
			if (d[u] + dis < d[num]) {
				d[num] = d[u] + dis;
				if (vis[num] == false) {
					q.push(num);
					vis[num] = true;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%lf", &N, &M, &K,&Ds);
	for (int i = 0; i < K; i++) {
		int t1, t2;
		string s1, s2;
		Node temp;
		cin >> s1 >> s2 >> temp.dis;
		if (isdigit(s1[0])) {
			t1 = stoi(s1);
		}
		else {
			s1.erase(s1.begin());
			t1 = stoi(s1)+N;
		}
		if (isdigit(s2[0])) {
			t2 = stoi(s2);
		}
		else {
			s2.erase(s2.begin());
			t2= stoi(s2)+N;
		}
		temp.v = t2;
		v[t1].push_back(temp);
		temp.v = t1;
		v[t2].push_back(temp);
	}
	for (int i = 1; i <= M; i++) {
		SPFA(N + i);
		double maxdis=-1,mindis=INF,sum=0;
		for (int j = 1; j <= N; j++) {
			maxdis = max(maxdis, d[j]);
			mindis = min(mindis, d[j]);
			sum += d[j];
		}
		if (maxdis<=Ds) {
			p.push_back(i);
			mind[i] = mindis;
			avg[i] = sum / N;
		}
	}
	sort(p.begin(), p.end(), cmp);
	if ((int)p.size() == 0) {
		printf("No Solution");
	}
	else {
		printf("G%d\n", p[0]);
		printf("%.1f %.1f", mind[p[0]], avg[p[0]]);
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 1020;
const int INF = 1000000000;
int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
void Dijkstra(int s) {
    memset(vis, false, sizeof(vis));
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}
int getID(char str[]) {
    int i = 0, len = strlen(str), ID = 0;
    while(i < len) {
        if(str[i] != 'G') {
            ID = ID * 10 + (str[i] - '0');
        }
        i++;
    }
    if(str[0] == 'G') return n + ID;
    else return ID;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    int u, v, w;
    char city1[5], city2[5];
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < k; i++) {
        scanf("%s %s %d", city1, city2, &w);
        u = getID(city1);
        v = getID(city2);
        G[v][u] = G[u][v] = w;
    }
    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for(int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {
            if(d[j] > DS) {
                minDis = -1;
                break;
            }
            if(d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if(minDis == -1) continue;
        if(minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
        } else if(minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if(ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    return 0;
}
*/
