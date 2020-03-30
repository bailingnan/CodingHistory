#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
struct Node {
	int w,cnt;
	vector<int> v;
	Node() {
		w = 0;
		cnt = 0;
	}
}n[100010];
queue<int> q;
double sum = 0;
int N;
double P, r, rt;
void BFS(int root){
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (n[t].w != 0) {
			sum += n[t].w*P*pow(rt,n[t].cnt*1.0);
		}
		for (int i = 0; i < n[t].v.size(); i++) {
			n[n[t].v[i]].cnt = n[t].cnt+1;
			q.push(n[t].v[i]);
		}
	}
}
int main() {
	scanf("%d %lf %lf", &N, &P, &r);
	rt = 1 + 0.01*r;
	for (int i = 0; i < N; i++) {
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 0) {
			scanf("%d", &n[i].w);
		}
		else {
			for (int j = 0; j < cnt; j++) {
				int temp;
				scanf("%d", &temp);
				n[i].v.push_back(temp);
			}
		}
	}
	BFS(0);
	printf("%.1f", sum);
	return 0;
} 
//算法笔记
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    double data;
    vector<int> child;
} Node[maxn];
int n;
double p, r, ans = 0;
void DFS(int index, int depth) {
    if(Node[index].child.size() == 0) {
        ans += Node[index].data * pow(1 + r, depth);
        return;
    }
    for(int i = 0; i < Node[index].child.size(); i++) {
        DFS(Node[index].child[i], depth + 1);
    }
}
int main() {
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {
            scanf("%lf", &Node[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &child);
                Node[i].child.push_back(child);
            }
        }
    }
    DFS(0, 0);
    printf("%.1f\n", p * ans);
    return 0;
}
