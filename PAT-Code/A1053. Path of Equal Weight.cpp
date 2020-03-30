#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
int N, M, S, weight[maxn];
vector<int> tree[maxn],temp;
vector<vector<int>> p;
void DFS(int m,int v) {
	if (v == S&& (int)tree[m].size() == 0) {
		p.push_back(temp);
		return;
	}
	for (int i = 0; i < (int)tree[m].size(); i++) {
		int num = tree[m][i];
		if (v + weight[num] <= S) {
			temp.push_back(weight[num]);
			DFS(num, v + weight[num]);
			temp.pop_back();
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < M; i++) {
		int id, K;
		scanf("%d%d", &id, &K);
		for (int j = 0; j < K; j++) {
			int temp;
			scanf("%d", &temp);
			tree[id].push_back(temp);
		}
	}
	temp.push_back(weight[0]);
	DFS(0, weight[0]);
	sort(p.begin(), p.end());
	for (int i = p.size() - 1; i >= 0; i--) {
		for (int j = 0; j < p[i].size(); j++) {
			printf("%d", p[i][j]);
			if (j < p[i].size() - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 110;
struct node {
    int weight;
    vector<int> child;
} Node[MAXN];
bool cmp(int a, int b) {
    return Node[a].weight > Node[b].weight;
}
int n, m, S;
int path[MAXN];
void DFS(int index, int numNode, int sum) {
    if(sum > S) return;
    if(sum == S) {
        if(Node[index].child.size() != 0) return;
        for(int i = 0; i < numNode; i++) {
            printf("%d", Node[path[i]].weight);
            if(i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++) {
        int child = Node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode + 1, sum + Node[child].weight);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &S);
    for(int i = 0; i < n; i++) {
        scanf("%d", &Node[i].weight);
    }
    int id, k, child;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }
        sort(Node[id].child.begin(), Node[id].child.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, Node[0].weight);
    return 0;
}
*/
