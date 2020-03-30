//给定中缀表达式二叉树，输出中缀表达式。需要注意的是括号（parentheses）的输出，二叉树的根节点和叶子结点不需要输出括号。在程序中加以限制即可。
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 21;
bool vis[maxn] = { 0 };
int N;
vector<string> rcd;
struct Node {
	string str;
	int l, r;
}tree[maxn];
int Root;
void InOrder(int root) {
	if (root == -1)return;
	if (root != Root && (tree[root].l != -1 || tree[root].r != -1)) cout << "(";
	InOrder(tree[root].l);
	cout<<tree[root].str;
	InOrder(tree[root].r);
	if (root != Root && (tree[root].l != -1 || tree[root].r != -1)) cout << ")";
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <=N; i++) {
		cin >> tree[i].str;
		scanf("%d%d", &tree[i].l, &tree[i].r);
		if (tree[i].l != -1)
			vis[tree[i].l] = true;
		if (tree[i].r != -1)
			vis[tree[i].r] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i] == false) {
			Root = i;
			break;
		}
	}
	InOrder(Root);
	return 0;
}
