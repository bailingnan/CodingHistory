#include<cstdio>
#include<queue>
using namespace std;
struct Node {
	int d, l, r;
}node[11];
int N,rt,ht[11] = { 0 };
void rv() {
	for (int i = 0; i < N; i++) {
		int temp = node[i].l;
		node[i].l = node[i].r;
		node[i].r = temp;
	}
}
int num = 0;
queue<int> q;
void cx(int root) {
	q.push(root);
	while (!q.empty()) {
		Node temp = node[q.front()];
		q.pop();
		printf("%d", temp.d);
		if (num < N - 1)
			printf(" ");
		else printf("\n");
		num++;
		if (temp.l != -1)
			q.push(temp.l);
		if (temp.r != -1)
			q.push(temp.r);
	}
}
int cnt= 0;
void ino(int root) {
	if (root == -1)
		return;
	ino(node[root].l);
	printf("%d", node[root].d);
	if (cnt < N - 1)
		printf(" ");
	else printf("\n");
	cnt++;
	ino(node[root].r);
}
int main() {
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		node[i].d = i;
		char a, b;
		scanf("%c %c", &a,&b);
		getchar();
		if (a=='-') {
			node[i].l = -1;
		}
		else { 
			node[i].l = a - '0';
			ht[a - '0'] = 1;
		}
		if (b=='-') {
			node[i].r = -1;
		}
		else { 
			node[i].r = b - '0';
			ht[b - '0'] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (ht[i] == 0)
			rt = i;
	}
	rv();
	cx(rt);
	ino(rt);
	return 0;
}
//算法笔记
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {    // 二叉树的静态写法
    int lchild, rchild;
} Node[maxn];
bool notRoot[maxn] = {false};    // 记录是否不是根结点，初始均是根结点
int n, num = 0;    // n为结点个数，num为当前已经输出的结点个数
// print函数输出结点id的编号
void print(int id) {
    printf("%d", id);    // 输出id
    num++;    // 已经输出的结点个数加1
    if(num < n) printf(" ");    // 最后一个结点不输出空格
    else printf("\n");
}
// 中序遍历
void inOrder(int root) {
    if(root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    print(root);
    inOrder(Node[root].rchild);
}
// 层序遍历
void BFS(int root) {
    queue<int> q;  //注意队列里是存地址
    q.push(root);  //将根结点地址入队
    while(!q.empty()) {
        int now = q.front();  //取出队首元素
        q.pop();
        print(now);
        if(Node[now].lchild != -1) q.push(Node[now].lchild);  //左子树非空
        if(Node[now].rchild != -1) q.push(Node[now].rchild);  //右子树非空
    }
}
// 后序遍历，用以反转二叉树
void postOrder(int root) {
    if(root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    swap(Node[root].lchild, Node[root].rchild);    // 交换左右孩子
}
// 将输入的字符转换为-1或者结点编号
int strToNum(char c) {
    if(c == '-') return -1;    // “-”表示没有孩子结点，记为-1
    else {
        notRoot[c - '0'] = true;    // 标记c不是根结点
        return c - '0';    // 返回结点编号
    }
}
// 寻找根结点编号
int findRoot() {
    for(int i = 0; i < n; i++) {
        if(notRoot[i] == false) {
            return i;    // 是根结点，返回i
        }
    }
}
int main() {
    char lchild, rchild;
    scanf("%d", &n);    // 结点个数
    for(int i = 0; i < n; i++) {
        scanf("%*c%c %c", &lchild, &rchild);    // 左右孩子
        Node[i].lchild = strToNum(lchild);
        Node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();    // 获得根结点编号
    postOrder(root);    // 后序遍历，反转二叉树
    BFS(root);    // 输出层序遍历序列
    num = 0;    // 已输出的结点个数置0
    inOrder(root);    // 输出中序遍历序列
    return 0;
}
