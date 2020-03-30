#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 50010;
struct Node {
	int v;
	Node *l, *r;
};
Node* NewNode(int v) {
	Node* root = new Node;
	root->v = v;
	root->l = root->r = NULL;
	return root;
}
int pre[maxn], in[maxn];
int N;
Node* Create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	Node *root=NewNode(pre[preL]);
	int k;
	for (k = inL; k<=inR;k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numleft = k - inL;
	root->l = Create(preL + 1, preL + numleft, inL, k - 1);
	root->r = Create(preL + numleft + 1, preR, k + 1, inR);
	return root;
}
vector<int> post;
void PostOrder(Node*root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->l);
	PostOrder(root->r);
	post.push_back(root->v);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
	}
	Node* root = NULL;
	root=Create(1, N, 1, N);
	PostOrder(root);
	printf("%d", post[0]);
	return 0;
}
