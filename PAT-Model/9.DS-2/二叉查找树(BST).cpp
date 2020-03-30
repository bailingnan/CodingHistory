//对二叉查找树进行中序遍历，遍历的结果是有序的。
void search(node* root, int x) {
	if (root == NULL) {
		printf("search failed");
		return;
	}
	if (x == root->data) {
		printf("%d", root->data);
	}
	else if (x < root->data) {
		search(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}
void insert(node*&root, int x) {
	if (root == NULL) {
		root = newNode(x);
		return;
	}
	else if(x < root->data) {
		insert(root->lchild, x);
	}
	else {
		insert(root->rchild, x);
	}
}
node* Create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}
//寻找以root为根结点的树中的最大权值结点
node* findMax(node* root) {
	while (root->rchild != NULL) {
		root = root->rchild;
	}
	return root;
}
//寻找以root为根结点的树中的最小权值结点
node* findMin(node* root) {
	while (root->lchild != NULL) {
		root = root->lchild;
	}
	return root;
}
void deleteNode(node* &root, int x) {
	if (root == NULL) return;
	if (root->data == x) {
		if (root->lchild == NULL && root->rchild == NULL) {
			root = NULL;
		}
		else if (root->lchild != NULL) {
			node*pre = findMax(root->lchild);
			root->data = pre->data;
			deleteNode(root->lchild, pre->data);
		}
		else if (root->rchild != NULL) {
			node*pre = findMin(root->rchild);
			root->data = pre->data;
			deleteNode(root->rchild, pre->data);
		}
	}
	else if (root->data > x) {
		deleteNode(root->lchild, x);
	}
	else {
		deleteNode(root->rchild, x);
	}
}
