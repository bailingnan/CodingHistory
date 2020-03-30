#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 210;
bool G[maxn][maxn] = { 0 };
int N, M,K,cnt[maxn];
vector<int> v;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		G[t1][t2] = true;
		G[t2][t1] = true;
	}
	scanf("%d", &K);
	for (int k = 0; k< K; k++) {
		fill(cnt, cnt + maxn, 0);
		int n, flag = 1;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}
		if (v[0] != v[n - 1]) {
			flag = 0;
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				cnt[v[i]]++;
				if (cnt[v[i]] > 1) {
					flag = 0;
					break;
				}
				if (G[v[i]][v[i + 1]] == false) {
					flag = 0;
					break;
				}
			}
			for (int i = 1; i <= N; i++) {
				if (cnt[i] != 1) {
					flag = 0;
					break;
				}
			}
		}
		v.clear();
		if (flag == 1) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
//算法笔记
/*#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 210;
bool G[maxn][maxn] = { false };
bool isInPath[maxn];
vector<int> nodes;
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int num, tempNode;
		scanf("%d", &num);
		nodes.clear();
		for (int j = 0; j < num; j++) {
			scanf("%d", &tempNode);
			nodes.push_back(tempNode);
		}
		if (num != n + 1 || nodes[0] != nodes.back()) {
			printf("NO\n");
		}
		else {
			memset(isInPath, false, sizeof(isInPath));
			bool isHamiltonianCycle = true;
			for (int j = 1; j < nodes.size(); j++) {
				isHamiltonianCycle &= !isInPath[nodes[j]];
				isHamiltonianCycle &= G[nodes[j - 1]][nodes[j]];
				isInPath[nodes[j]] = true;
			}
			printf(isHamiltonianCycle ? "YES\n" : "NO\n");
		}
	}
	return 0;
}*/
