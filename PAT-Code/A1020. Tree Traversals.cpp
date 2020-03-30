#include<cstdio>
#include<queue>
using namespace std;
struct Node {
	int data;
	Node *l;
	Node *r;
};
int p[31], i[31],c[31],cnt=0;
Node *root;
queue<Node*> q;
Node* create(int pl, int pr, int il, int ir) {
	if (pl > pr || il > ir) {
		return NULL;
	}
	Node* root = new Node;
	root->data = p[pr];
	int k;
	for (k = il;k<=ir; k++) {
		if (i[k] == p[pr])
			break;
	}
	int nl = k - il;
	root->l = create(pl, pl + nl - 1, il, k - 1);
	root->r = create(pl + nl, pr - 1, k + 1, ir);
	return root;
}
void BFS(Node *n) {
	q.push(n);
	while (!q.empty()) {
		Node *temp = q.front();
		q.pop();
		c[cnt++] = temp->data;
		if (temp->l != NULL)
			q.push(temp->l);
		if (temp->r != NULL)
			q.push(temp->r);
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	for (int j = 1; j <= N; j++) {
		scanf("%d", &i[j]);
	}
	root=create(1,N,1,N);
	BFS(root);
	for (int i = 0; i < N; i++) {
		printf("%d", c[i]);
		if (i < N - 1)
			printf(" ");
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}
int num = 0;
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if(num < n) printf(" ");
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    node* root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}
