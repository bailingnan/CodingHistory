#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100010;
struct Node {
	int add;
	int v;
	int next;
}node[100010];
int head, N, K;
vector<Node>v, ng, lk, gk;
int main() {
	scanf("%d%d%d", &head, &N, &K);
	for (int i = 0; i < N; i++) {
		Node temp;
		scanf("%d%d%d", &temp.add, &temp.v, &temp.next);
		node[temp.add] = temp;
	}
	int hd = head;
	while (hd != -1) {
		v.push_back(node[hd]);
		hd = node[hd].next;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].v < 0) {
			ng.push_back(v[i]);
		}
		else if (v[i].v<=K) {
			lk.push_back(v[i]);
		}
		else {
			gk.push_back(v[i]);
		}
	}
	for (int i = 0; i < lk.size(); i++) {
		ng.push_back(lk[i]);
	}
	for (int i = 0; i < gk.size(); i++) {
		ng.push_back(gk[i]);
	}
	for (int i = 0; i < ng.size(); i++) {
		if (i < ng.size() - 1)
			printf("%05d %d %05d\n", ng[i].add, ng[i].v, ng[i + 1].add);
		else
			printf("%05d %d -1", ng[i].add, ng[i].v);
	}
	return 0;
}
