struct node {
	typename data;
	node* lchild;
	node* rchild;
};
node* root = NULL;
node* newNode(int v) {
	node* Node = new node;
	Node->data = v;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
void search(node* root, int x, int newdata) {
	if (root == NULL) {
		return;
	}
	if (root->data == x) {
		root->data = newdata;
	}
	search(root->lchild, x, newdata);
	search(root->rchild, x, newdata);
}
//注意根节点指针root要用引用，否则插入不成功
//如果函数中需要新建结点，即对二叉树的结构进行修改，就需要加引用；如果只是修改当前已有结点的内容，或仅仅是遍历树，就不用加引用。
void insert(node* &root, int x) {
	if (root == NULL) {//空树，说明查找失败，也即插入位置(递归边界)
		root = newNode(x);
		return;
	}
	if (由二叉树的性质, x应插在左子树) {
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
