#include<cstdio>//最后一个测试点超时
struct Node {
	int add, next;
	char data;
}node[100010],t1[100010],t2[100010];
int main() {
	int add1, add2, N;
	scanf("%d%d%d", &add1, &add2, &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		getchar();
		node[temp].add = temp;
		scanf("%c%d", &node[temp].data, &node[temp].next);
	}
    if (add1 == -1 || add2 == -1) {
	printf("-1\n");
	return 0;
    }
	Node t = node[add1];
	t1[0] = t;
	int cnt = 1;
    while (t.next != -1) {
		t1[cnt++] = node[t.next];
		t = node[t.next];
	}
	int len1 = cnt;
	t = node[add2];
	t2[0] = t;
	cnt = 1;
	while (t.next != -1) {
		t2[cnt++] = node[t.next];
		t = node[t.next];
	}
	int len2 = cnt;
	int flag = 0;
	Node temp;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (t1[i].add== t2[j].add) {
				temp = t1[i];
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (flag == 1) {
		printf("%05d\n", temp.add);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
/*
#include<cstdio>//答案错误错2分；
struct Node {
	int add, next;
	char data;
}node[100010],t1[100010],t2[100010];
int main() {
	int add1, add2, N;
	scanf("%d%d%d", &add1, &add2, &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		getchar();
		node[temp].add = temp;
		scanf("%c%d", &node[temp].data, &node[temp].next);
	}
    if (add1 == -1 || add2 == -1) {
	printf("-1\n");
	return 0;
}
	Node t = node[add1];
	t1[0] = t;
	int cnt = 1;
	while (t.next != -1) {
		t1[cnt++] = node[t.next];
		t = node[t.next];
	}
	int len1 = cnt;
	t = node[add2];
	t2[0] = t;
	cnt = 1;
	while (t.next != -1) {
		t2[cnt++] = node[t.next];
		t = node[t.next];
	}
	int len2 = cnt;
	int flag = 0;
	Node temp;
	for (int i = len1-1,j=len2-1; i>=0&&j>=0; i--,j--){
		if (t1[i].add != t2[j].add) {
			if (i == len1 - 1) {
				flag = 2;
				break;
			}
			else {
				temp = t1[i + 1];
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0) {
		if (len1 > len2)
			temp = t2[len2 - 1];
		else
			temp = t1[len1 - 1];
	}
	if (flag == 1||flag==0) {
		printf("%05d\n", temp.add);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
const int maxn = 100010;
struct NODE {
    char data;
    int next;
    bool flag;
}node[maxn];
int main() {
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    int address, next;
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for(p = s1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    for(p = s2; p != -1; p = node[p].next) {
        if(node[p].flag == true) break;
    }
    if(p != -1) {
        printf("%05d\n",p);
    } else {
        printf("-1\n");
    }
    return 0;
}
*/
