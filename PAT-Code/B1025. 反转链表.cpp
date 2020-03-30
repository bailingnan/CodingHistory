#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
struct Node {
	int now;
	int data;
	int next;
}node[100010],tp[100010],prt[100010],t;
int main() {
	int fstad, K, N;
	scanf("%d%d%d", &fstad, &N, &K);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		node[temp].now = temp;
		scanf("%d%d",&node[temp].data, &node[temp].next);
	}
	t = node[fstad];
	int cnt = 1;
	tp[0] = t;
	while (t.next!= -1) {
		tp[cnt++] = node[t.next];
		t = node[t.next];
	}
	int length = cnt;
	stack<Node> st;
	cnt = 0;
	for (int i = 0; i+K <=length; i+=K) {
		for (int j = i; j < i + K; j++) {
			st.push(tp[j]);
		}
		while (!st.empty()) {
			prt[cnt++] = st.top();
			st.pop();
		}
	}
	for (int i = cnt; i < length; i++) {
		prt[i] = tp[i];
	}
	for (int i = 0; i < length-1; i++) {
		prt[i].next = prt[i + 1].now;
	}
	prt[length- 1].next = -1;
	for (int i = 0; i <length; i++) {
		if(i<length-1)
			printf("%05d %d %05d\n", prt[i].now, prt[i].data, prt[i].next);
		else
			printf("%05d %d %d", prt[i].now, prt[i].data, prt[i].next);
	}
}
//算法笔记
/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int address, data, next;
	int order;
}node[maxn];
bool cmp(Node a, Node b) {
	if (a.order == -1 || b.order == -1) {
		return a.order > b.order;
	}
	else {
		return a.order < b.order;
	}
}
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].order = -1;
	}
	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K);
	for (int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin, count = 0;
	while (p != -1) {
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	n = count;
	for (int i = 0; i < n / K; i++) {
		for (int j = (i + 1) * K - 1; j > i * K; j--) {
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
		}
		printf("%05d %d ", node[i * K].address, node[i * K].data);
		if (i < n / K - 1) {
			printf("%05d\n", node[(i + 2) * K - 1].address);
		}
		else {
			if (n % K == 0) {
				printf("-1\n");
			}
			else {
				printf("%05d\n", node[(i + 1) * K].address);
				for (int i = n / K * K; i < n; i++) {
					printf("%05d %d ", node[i].address, node[i].data);
					if (i < n - 1) {
						printf("%05d\n", node[i + 1].address);
					}
					else {
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
*/

