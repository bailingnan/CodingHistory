#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct Node {
	int cnt;
	vector<int> v;
}n[100];
int N, M,ht[100] = { 0 };
void BFS(int root) {
	queue<int> q;
	q.push(root);
	n[root].cnt = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ht[n[temp].cnt]++;
		for (int i = 0; i < n[temp].v.size(); i++) {
			n[n[temp].v[i]].cnt = n[temp].cnt + 1;
			q.push(n[temp].v[i]);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp, cnt;
		scanf("%d%d", &temp, &cnt);
		for (int j = 0; j < cnt; j++) {
			int t;
			scanf("%d", &t);
			n[temp].v.push_back(t);
		}
	}
	BFS(1);
	int maxn, maxcnt = 0;
	for (int i = 1; i <= 99; i++) {
		if (ht[i] > maxcnt) {
			maxn = i;
			maxcnt = ht[i];
		}
	}
	printf("%d %d", maxcnt, maxn);
	return 0;
}
//算法笔记
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];    // 树的静态写法，Node[i]存放结点i的孩子编号
int hashTable[MAXN] = {0};    // 记录每层的结点个数
void DFS(int index, int level) {
    hashTable[level]++;    // 第level层的结点个数加1
    for(int j = 0; j < Node[index].size(); j++) {
        DFS(Node[index][j], level + 1);    // 遍历所有孩子结点，进行递归
    }
}
int main() {
    int n, m, parent, k, child;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);    // 父亲编号，孩子个数
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);    // 孩子编号
            Node[parent].push_back(child);    // 建树
        }
    }
    DFS(1, 1);    // 根结点为1号结点，层号为1
    int maxLevel = -1, maxValue = 0;
    for(int i = 1; i < MAXN; i++) {    // 计算hashTable数组的最大值
        if(hashTable[i] > maxValue) {
            maxValue = hashTable[i];
            maxLevel = i;
        }
    }
    printf("%d %d\n", maxValue, maxLevel);    // 输出最大结点数与该层层号
    return 0;
}
