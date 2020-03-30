#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
struct Node {
	int cnt,flag=0;
	double pr;
	vector<int> v;
}node[100010];
int N,maxcnt=0;
double p, r, rt,maxn=0;
queue<int> q;
void BFS(int root) {
	q.push(root);
	node[root].cnt = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (node[temp].v.size() == 0) {
			node[temp].flag = 1;
			double pr = p * pow(rt, 1.0*node[temp].cnt);
			node[temp].pr = pr;
			if (pr > maxn)
				maxn = pr;
		}
		for (int i = 0; i < node[temp].v.size(); i++) {
			node[node[temp].v[i]].cnt = node[temp].cnt + 1;
			q.push(node[temp].v[i]);
		}
	}
}
int main() {
	scanf("%d %lf %lf", &N, &p, &r);
	rt = 1 + 0.01*r;
	int root;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == -1) {
			root = i;
		}
		else {
			node[temp].v.push_back(i);
		}
	}
	BFS(root);
	for (int i = 0; i < N; i++) {
		if (node[i].flag == 1) {
			if (node[i].pr ==maxn)
				maxcnt++;
		}
	}
	printf("%.2f %d", maxn,maxcnt);
	return 0;
}
//算法笔记
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
double p, r;
int n, maxDepth = 0, num = 0;
void DFS(int index, int depth) {
    if(child[index].size() == 0) {
        if(depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        } else if(depth == maxDepth) {
            num++;
        }
        return;
    }
    for(int i = 0; i < child[index].size(); i++) {
        DFS(child[index][i], depth + 1);
    }
}
int main() {
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &father);
        if(father != -1) {
            child[father].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
    return 0;
}
