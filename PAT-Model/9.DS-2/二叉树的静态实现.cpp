struct node {
	typename data;
	int lchild;
	int rchild;
}Node[maxn];
int index = 0;
int newNode(int v) {
	Node[index].data = v;
	Node[index].lchild = -1;
	Node[index].rchild = -1;
	return index++;
}
void search(int root, int x, int newdata) {
	if (root == -1) {
		return;
	}
	if (Node[root].data == x) {
		Node[root].data = newdata;
	}
	search(Node[root].lchild, x, newdata);
	search(Node[root].rchild, x, newdata);
}
void insert(int &root, int x) {
	if (root == -1) {
		root = newNode(x);
		return;
	}
	if (由二叉树的性质x应该插在左子树) {
		insert(Node[root].lchild, x);
	}
	else {
		insert(Node[root].rchild, x);
	}
}
int Create(int data[], int n) {
	int root = -1;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}
//先序遍历
void preorder(int root) {
	if (root == -1) {
		return;
	}
	printf("%d\n",Node[root].data);
	preorder(Node[root].lchild);
	preorder(Node[root].rchild);
}
//中序遍历
void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(Node[root].lchild);
	printf("%d\n", root->data);
	inorder(Node[root].rchild);
}
//后序遍历
void postorder(int root) {
	if (root == -1) {
		return;
	}
	postorder(Node[root].lchild);
	postorder(Node[root].rchild);
	printf("%d\n", root->data);
}
//层序遍历
void LayerOrder(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", Node[now].data);
		if (Node[now].lchild != -1) {
			q.push(Node[now].lchild);
		}
		if (Node[now].rchild != -1) {
			q.push(Node[now].rchild);
		}
	}
}
