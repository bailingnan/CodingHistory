#include<cstdio>//可通过PAT，牛客网内存超限;
#include<stack>
#include<cstring>
using namespace std;
struct Node {
	int data;
	Node*l;
	Node*r;
};
Node *root;
stack<int> s;
char ph[5] = "Push", pp[4] = "Pop";
int p[31], i[31],N,pt[31],cnt=1;
Node* create(int pl, int pr, int il, int ir) {
	if (pl > pr || il > ir) {
		return NULL;
	}
	Node* root = new Node;
	root->data = p[pl];
	int k;
	for (k = 1; k <= N; k++) {
		if (i[k] == p[pl])
			break;
	}
	int nl = k - il;
	root->l = create(pl + 1, pl + nl, il, k - 1);
	root->r=create(pl + nl + 1, pr, k + 1, ir);
	return root;
}
void Pt(Node *root) {
	if (root == NULL)
		return;
	Pt(root->l);
	Pt(root->r);
	pt[cnt++] = root->data;
}
int main() {
	int temp,cnt1=1,cnt2=1;
	scanf("%d", &N);
	temp = 2*N;
	while (temp) {
		char str[5];
		scanf("%s", str);
		if (strcmp(str, ph) == 0) {
			int m;
			scanf("%d", &m);
			p[cnt1++] = m;
			s.push(m);
		}
		if (strcmp(str, pp) == 0) {
			int m = s.top();
			s.pop();
			i[cnt2++] = m;
		}
		temp--;
	}
	root = create(1, N, 1, N);
	Pt(root);
	for (int i = 1; i <= N; i++) {
		printf("%d", pt[i]);
		if (i < N)
			printf(" ");
	}
	return 0;
}
//算法笔记
#include <cstdio>//牛客网多处错误
#include <cstring>
#include <stack>
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
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}
int num = 0;
void postorder(node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
}
int main() {
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    node* root = create(0, n - 1, 0, n - 1);
    postorder(root);
    return 0;
}
