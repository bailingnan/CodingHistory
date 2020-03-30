#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Node {
	int data;
	int level;
}n[1001];
vector<Node> node[1001],re;
bool vis[1001];
int cnt[1001] = { 0 };
int N, L;
void BFS(Node m,int d) {
	queue<Node> q;
	m.level = 0;
	q.push(m);
	vis[m.data] = true;
	while (!q.empty()) {
		Node nd = q.front();
		q.pop();
		if (nd.level <= d && nd.level > 0) {
			cnt[m.data]++;
		}
		for (int i = 0; i < node[nd.data].size(); i++) {
			Node t = node[nd.data][i];
			if (vis[t.data] == false) {
				t.level = nd.level + 1;
				q.push(t);
				vis[t.data] =true;
			}
		}
	}
}
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 1; i <=N; i++) {
		int temp;
		scanf("%d", &temp);
		n[i].data = i;
		for (int j = 0; j< temp; j++) {
			Node t;
			scanf("%d", &t.data);
			node[t.data].push_back(n[i]);
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		fill(vis + 1, vis + 1001, 0);
		BFS(n[temp], L);
		printf("%d\n", cnt[temp]);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node {
    int id;
    int layer;
};
vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};
int BFS(int s, int L) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for(int i = 0; i < Adj[u].size(); i++) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if(inq[next.id] == false && next.layer <= L) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;
}
int main() {
    Node user;
    int n, L, numFollow, idFollow;
    scanf("%d%d", &n, &L);
    for(int i = 1; i <= n; i++) {
        user.id = i;
        scanf("%d", &numFollow);
        for(int j = 0; j < numFollow; j++) {
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for(int i = 0; i < numQuery; i++) {
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int numForward = BFS(s, L);
        printf("%d\n", numForward);
    }
    return 0;
}
