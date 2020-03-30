#include<cstdio>
#include<algorithm>
using namespace std;
struct Node {
	int add, data, next;
}n[100010],t1[100010],t2[100010];
int num[10001] = { 0 };
int main() {
	int add, N;
	scanf("%d%d", &add, &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		n[temp].add = temp;
		scanf("%d%d", &n[temp].data, &n[temp].next);
	}
	int p = add,cnt1=0,cnt2=0;
	while (p != -1) {
		if (num[abs(n[p].data)] == 0) {
			t1[cnt1++] = n[p];
			num[abs(n[p].data)] = 1;
		}
		else {
			t2[cnt2++] = n[p];
		}
		p = n[p].next;
	}
	for (int i = 0; i < cnt1-1; i++) {
		t1[i].next = t1[i + 1].add;
	}
	t1[cnt1 - 1].next = -1;
	for (int i = 0; i < cnt2 - 1; i++) {
		t2[i].next = t2[i + 1].add;
	}
	t2[cnt2 - 1].next = -1;
	for (int i = 0; i < cnt1; i++) {
		if (i < cnt1 - 1)
			printf("%05d %d %05d\n", t1[i].add, t1[i].data, t1[i].next);
		else
			printf("%05d %d -1\n", t1[i].add, t1[i].data);
	}
	for (int i = 0; i < cnt2; i++) {
		if (i < cnt2 - 1)
			printf("%05d %d %05d\n", t2[i].add, t2[i].data, t2[i].next);
		else
			printf("%05d %d -1\n", t2[i].add, t2[i].data);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int TABLE = 1000010;
struct Node {    // 定义静态链表（第一步）
    int address, data, next;
    int order;    // 结点在链表上的序号，无效结点记为2*maxn
}node[maxn];
bool isExist[TABLE] = {false};    // 绝对值是否已经出现
bool cmp(Node a, Node b) {
    return a.order < b.order;    // 按order从小到大排序
}
int main() {
    memset(isExist, false, sizeof(isExist));    // 初始化isExist为未出现
    for(int i = 0; i < maxn; i++) {    // 初始化（第二步）
        node[i].order = 2 * maxn;    // 表示初始时均为无效结点
    }
    int n, begin, address;
    scanf("%d%d", &begin, &n);    // 起始地址，结点个数
    for(int i = 0; i < n; i++) {    // 输入所有结点
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    // 未删除的有效结点个数、已删除的有效结点个数
    int countValid = 0, countRemoved = 0, p = begin;
    while(p != -1) {    // 枚举链表（第三步）
        if(!isExist[abs(node[p].data)]){    // data的绝对值不存在
            isExist[abs(node[p].data)] = true;    // 标记为已存在
            node[p].order = countValid++;    // 不删除，编号从0开始
        } else {    // data的绝对值已存在
            node[p].order = maxn + countRemoved++;    // 被删除，编号从maxn开始
        }
        p = node[p].next;    // 下一个结点
    }
    sort(node, node + maxn, cmp);    // 按order从小到大排序（第四步）
    // 输出结果（第五步）
    int count = countValid + countRemoved;    // 有效结点个数
    for(int i = 0; i < count; i++) {
        if (i != countValid - 1 && i != count - 1) {    // 非最后一个结点
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
        } else {    // 最后一个结点单独处理
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}
