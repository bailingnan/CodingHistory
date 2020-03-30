#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int N,sum[11],cnt[11],num[1010],m,t=0,prt[1010];
struct Node {
	int m;
	Node *l;
	Node *r;
};
Node* pt(int l, int r) {
	if (l > r)
		return NULL;
	int ct=r-l+1,c,nl,nr,temp;
	for (int i = 1; i <= 10; i++) {
		if (sum[i] > ct) {
			c= i - 1;
			break;
		}
	}
	nr=nl = sum[c - 1];
	temp = ct-sum[c];
	if (temp <= cnt[c + 1] / 2) {
		nl += temp;
	}
	else {
		nl += cnt[c + 1] / 2;
		nr += temp - cnt[c + 1] / 2;
	}
	Node *root = new Node;
	root->m= num[nl + l];
	root->l=pt(l, l + nl - 1);
	root->r=pt(1 + nl + l, r);
	return root;
}
void BFS(Node *root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		t++;
		printf("%d", temp->m);
		if (t < N)
			printf(" ");
		if(temp->l!=NULL)
			q.push(temp->l);
		if (temp->r!= NULL)
			q.push(temp->r);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num + 1, num + N + 1);
	for (int i = 1; i <= 10; i++) {
		sum[i] = (int)pow(2.0, 1.0*i)-1;
		cnt[i] = (int)pow(2.0, 1.0*(i - 1));
	}
	Node *root = NULL;
	root = pt(1, N);
	BFS(root);
	return 0;
}
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, number[maxn], CBT[maxn], index = 0;
void inOrder(int root) {
    if(root > n) return;
    inOrder(root * 2);
    CBT[root] = number[index++];
    inOrder(root * 2 + 1);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }
    sort(number, number + n);
    inOrder(1);
    for(int i = 1; i <= n; i++) {
        printf("%d", CBT[i]);
        if(i < n) printf(" ");
    }
    return 0;
}
