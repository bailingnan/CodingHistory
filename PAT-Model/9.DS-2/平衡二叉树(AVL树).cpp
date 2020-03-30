struct node {
	int v, height;//当前结点高度
	node* lchild, *rchild;
};
node* newNode(int v) {
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root) {
	if (root == NULL) {
		return 0;
	}
	return root->height;
}
int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(node*root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
void search(node*root, int x) {
	if (root == NULL) {
		printf("search failed");
		return;
	}
	if (x == root->data) {
		printf("%d\n", root->data);
	}
	else if (x < root->data) {
		search(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}
//左旋(Left Rotation)
void L(node* &root) {
	node *temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
//右旋(Right Rotation)
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
//树型:LL 判定条件:BF(root)=2,BF(root->lchild)=1,调整方法:对root进行右旋
//树型:LR 判定条件:BF(root)=2,BF(root->lchild)=-1,调整方法:先对root->lchild进行左旋，再对root进行右旋
//树型:RR 判定条件:BF(root)=-2,BF(root->lchild)=-1,调整方法:对root进行左旋
//树型:LR 判定条件:BF(root)=-2,BF(root->lchild)=1,调整方法:先对root->lchild进行右旋，再对root进行左旋
void insert(node*&root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (v < root->v) {
		insert(root->lchild, v);
		updateHeight(root);
		if (getBalenceFactor(root) == 2) {
			if (getBalenceFactor(root->lchild) == 1) {
				R(root);
			}
			else if(getBalanceFactor(root-.lchild==-1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(root->rchild, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == -1) {
				L(root);
			}
			else if (fetBalanceFactor(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}
node* Create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}
