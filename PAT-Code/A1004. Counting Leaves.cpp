#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct Node {
	int cnt;
	vector<int> v;
}n[100];
int N, M, ht[100] = { 0 },maxn=1;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	n[root].cnt = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (n[temp].cnt > maxn)
			maxn = n[temp].cnt;
		if (n[temp].v.size() == 0) {
			ht[n[temp].cnt]++;
		}
		for (int i = 0; i < n[temp].v.size(); i++) {
			int it = n[temp].v[i];
			n[it].cnt = n[temp].cnt + 1;
			q.push(it);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp,cnt;
		scanf("%d%d", &temp,&cnt);
		for (int j = 0; j< cnt; j++) {
			int t;
			scanf("%d", &t);
			n[temp].v.push_back(t);
		}
	}
	BFS(1);
	for (int i = 1; i <=maxn; i++) {
		printf("%d", ht[i]);
		if (i < maxn)
			printf(" ");
	}
	return 0;
}
//算法笔记，方法一：BFS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 105;
vector<int> G[N];
int h[N] = {0};
int leaf[N] = {0};
int max_h = 0;
void BFS(){
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int id = Q.front();
        Q.pop();
        max_h = max(max_h, h[id]);
        if(G[id].size() == 0) {
            leaf[h[id]]++;
        }
        for(int i = 0; i < G[id].size(); i++) {
            h[G[id][i]] = h[id] + 1;
            Q.push(G[id][i]);
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int parent, k, child;
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    h[1] = 1;
    BFS();
    for(int i = 1; i <= max_h; i++) {
        if(i == 1) printf("%d", leaf[i]);
        else printf(" %d", leaf[i]);
    }
    return 0;
}
方法二：DFS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 110;
vector<int> G[N];
int leaf[N] = {0};
int max_h = 1;
void DFS(int index,int h){
    max_h = max(h, max_h);
    if(G[index].size() == 0){
        leaf[h]++;
        return;
    }
    for(int i = 0; i < G[index].size(); i++){
        DFS(G[index][i], h + 1);
    }
}
int main(){
    int n, m, parent, child, k;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    DFS(1,1);
    printf("%d", leaf[1]);
    for(int i = 2; i <= max_h; i++) printf(" %d", leaf[i]);
    return 0;
}
