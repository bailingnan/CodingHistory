//先序遍历
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
//中序遍历
void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d\n", root->data);
	inorder(root->lchild);
	inorder(root->rchild);
}
//后序遍历
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n", root->data);
}
//层序遍历
struct node {
	int data;
	int layer;
	node* lchild;
	node* rchild;
};
void LayerOrder(node* root) {
	queue<node*> q;
	root->layer = 1;
	q.push(root);
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		if (now->lchild != NULL) {
			now->lchild->layer = now->layer + 1;
			q.push(now->lchild);
		}
		if (now->rchild != NULL) {
			now->rchild->layer = now->layer + 1;
			q.push(now->rchild);
		}
	}
}
//根据二叉树的先(后)序遍历序列和中序遍历序列，重建这颗二叉树。
//当前先序序列区间为[preL,preR],中序序列区间为[inL,inR],返回根结点地址
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;//先序序列长度小于等于0时，直接返回
	}
	node* root = new node;//新建结点，存放当前二叉树的根结点
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == pre[preL]) {//在中序序列中找到in[k]==pre[L]的结点d
			break;
		}
	}
	int numLeft = k - inL;//左子树的结点个数
	//左子树的先序区间为[preL+1,preL+numLeft],中序区间为[inL,k-1]
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	//右子树的先序区间为[preL+numLeft+1，preR],中序区间为[k+1，inR]
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
