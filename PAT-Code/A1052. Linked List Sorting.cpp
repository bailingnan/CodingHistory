#include<cstdio>
#include<algorithm>
using namespace std;
struct Node {
	int add, data, next;
}node[100010], t[100010];
bool cmp(Node a, Node b) {
	return a.data < b.data;
}
int main() {
	int N, add;
	scanf("%d%d", &N, &add);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		node[temp].add = temp;
		scanf("%d%d", &node[temp].data, &node[temp].next);
	}
	if (add == -1) {
		printf("0 -1\n");
		return 0;
	}
	t[0] = node[add];
	Node tt = node[add];
	int cnt = 1;
	while (tt.next != -1) {
		t[cnt++] = node[tt.next];
		tt = node[tt.next];
	}
	sort(t, t + cnt, cmp);
	for (int i = 0; i < cnt - 1; i++) {
		t[i].next = t[i + 1].add;
	}
	t[cnt - 1].next = -1;
	printf("%d %05d\n", cnt, t[0].add);
	for (int i = 0; i < cnt; i++) {
		if (i < cnt - 1)
			printf("%05d %d %05d\n", t[i].add, t[i].data, t[i].next);
		else
			printf("%05d %d %d", t[i].add, t[i].data, t[i].next);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node {
    int address, data, next;
    bool flag;
}node[maxn];
bool cmp(Node a, Node b) {
    if(a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}
int main() {
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int count = 0, p = begin;
    while(p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count == 0) {
        printf("0 -1");
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].address);
        for(int i = 0; i < count; i++) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }
    return 0;
}
