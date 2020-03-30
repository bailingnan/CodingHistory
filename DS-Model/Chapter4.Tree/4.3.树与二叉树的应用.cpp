//二叉树递归查找
BTNode *BSTSearch(BTNode *p,int key){
    if(p==NULL)
        return NULL;
    else{
        if(p->key==key) return p;
        else if(key<p->key){
            return BSTSearch(p->lchild,key);
        }
        else{
            return BTSSearch(p->rchild,key);
        }
    }
}
//二叉排序树的非递归查找
BSTNode *BST_Search(BiTree T,ElemType key,BSTNode *&p){
    p=NULL;//指向被查找结点的双亲，用于插入和删除操作
    while(T!=NULL&&T->data!=key){
        p=NULL;
        if(key<T->data)
            T=T->lchild;
        
        else
            T=->rchild;
    }
    return T;
}
//二叉排序树的插入
int BST_Insert(BiTree &T,KeyType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BiTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key)
        return 0;
    else if(k<T->key){
        return BST_Insert(T->lchild,k);
    }
    else return BST_Insert(T->rchild,k);
}
//二叉排序树的构造
void Create_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}
//平衡二叉树操作
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
//E1.递归判断是否为二叉排序树
KeyType predt=-32767;//当前所访问结点的前驱结点
int JudgeBST(BiTree bt){
    int b1,b2;
    if(T==NULL){
        return 1;
    }
    b1=JudgeBST(bt->lchild);
    if(b1==0||predt>=bt->data)
        return 0;
    predata=bt->data;
    b2=JudgeBST(bt->rchild);
    return b2;
}
//E2.非递归查找结点P在二叉排序树中的层次
int level(BiTree bt,BSTNode *p){
    int n=0;
    BiTree t=bt;
    if(p!=NULL){
        n++;
        while(t->data!=p->data){
            if(t->data<p->data)
                t=t->lchild;
            else t=t->rchild;
            n++;
        }
    }
    return n;
}
//E3.判定给定的二叉树是否为平衡二叉树
void Judge_AVL(BiTree bt,int &balance,int &h){
    int bl=0,br=0,hl=0,hr=0;
    if(bt==NULL){
        h=0;
        balance=1;
    }
    else if(bt->lchild==NULL&&bt->rchild==NULL){
        h=1;
        balance=1;
    }
    else{
        Judge_AVL(bt->lchild,bl,hl);
        Judge_AVL(bt->rchild,br,hr);
        h=(hl>hr?hl:hr)+1;
        if(abs(hl-hr)<2)
            balance=bl&&br;
        else 
            balance=0;
    }
}
//E4.最小和最大关键字结点
KeyType MinKey(BSTNode *bt){
    while(bt->lchild!=NULL){
        bt=bt->lchild;
    }
    return bt->data;
}
KeyType MaxKey(BSTNode *bt){
    while(bt->rchild!=NULL){
        bt->rchild;
    }
    return bt->data;
}
//E5.查找第k小的元素,count存储以该结点为根的子树上的结点个数
BSTNode *Search_Small(BSTNode *t,int k){
    if(k<1||k>t->count) return NULL;
    if(t->lchild==NULL){
        if(k==1) return t;
        else return (t->rchild,k-1);
    }
    else{
        if(t->lchild->count==k-1) return t;
        if(t->lchild->count>k-1) return Serach_Small(t->lchild,k);
        if(t->rchild->count<k-1) return Search_Small(t->rchild,k-(t->lchild->count+1));
    }
}
//E6.判断是否为二叉排序树的搜索序列
//分成小于或等于x和大于X的两部分S1和S2，如果S1单调递减S2单调递增，且与X的大小关系正确
typedef struct{
    int elem[maxSize];
    int len;
}Sequence;
void reduce(Sequence &S,Sequence &S1,Sequence &S2){
    int i=0,j=0,k=0;
    do{
        while(i+1<S.len&&S.elem[i]<S.elem[i]<S.elem[i+1])
            S1.elem[j++]==S.elem[i++];
        while(i+1<S.len&&S.elem[i]>S.elem[i+1])
            S2.elem[k++]=S.elem[i++];
    }while(i+1<S.len);
    S1.len=j;
    S2.len=k;
}
int judge(Sequence& S1,Sequence &S2,int x){
    int i,flag;
    flag=1;
    i=0;
    while(flag&&i+1<S1.len){
        if(S1.elem[i]>S1.elem[i+1]||S1.elem.x)
            flag=0;
        else ++i;
    }
    while(flag&&i+1<S2.len){
        if(S2.elem[i]<S2.elem[i+1]||S2.elem[i]<x)
            flag=0;
        else ++i;
    }
    return flag;
}
int issearch(Sequence &S,Sequence &S1,Sequence &S2,int x){
    reduce(S,S1,S2);
    return judge(S1,S2,x);
}
//E7.插入结点，修改count域
void insert(BTNode *&T,BTNode *&pr,int x){
    BTNode *p=t;
    while(p!=NULL){
        if(p->data!=x){
            pr=p;
            if(x<p->data)
                P=P->lchild;
            else 
                p=p->rchild;
        }
        else{
            ++(p->count);
            return;
        }
    }
    BTNode *s=(BTNode*)malloc(sizeof(BTNode));
    s->data=x;
    s->count=1;
    s->lchild=s->rchild=NULL;
    if(pr==NULL) t=s;
    else if(x<pr->data)
        pr->lchild=s;
    else
        pr->rchild=s;
}
