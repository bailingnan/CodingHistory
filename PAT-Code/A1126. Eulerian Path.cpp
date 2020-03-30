#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 510;
int degree[maxn];
bool vis[maxn];
vector<int> v[maxn];
int N, M,block=0;
void DFS(int t) {
	vis[t] = true;
	for (int i = 0; i < v[t].size(); i++) {
		if (vis[v[t][i]] == false) {
			DFS(v[t][i]);
		}
	}
}
int main() {
	fill(degree, degree + maxn, 0);
	fill(vis, vis + maxn, false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		degree[t1]++;
		degree[t2]++;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	int even = 0, odd = 0;
	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
		printf("%d", degree[i]);
		if (i < N) {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i] == false) {
			DFS(i);
			block++;
		}
	}
	if (block > 1) {
		printf("Non-Eulerian");
	}
	else {
		if (even == N) {
			printf("Eulerian");
		}
		else if (odd == 2) {
			printf("Semi-Eulerian");
		}
		else {
			printf("Non-Eulerian");
		}
	}
	return 0;
}
