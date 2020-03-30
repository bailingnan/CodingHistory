//二叉树的链式存储
typedef struct BitNode{
    ElemType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;
//先序遍历的递归算法
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历的递归算法
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//后序遍历的递归算法
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
//中序遍历的非递归算法
//王道
//eg1
void PreOrder(BiTree T){
    InitStack(S);
    BitTree p=T;
    while(p||!IsEmpty(S)){
        while(p!=NULL){
            push(S,p);
            p=p->lchild;
        }
        if(!IsEmpty(S)){
            pop(S,p);
            visit(p);
            p=p->rchild;
        }
    }
}
//eg2
void InOrder(BiTree T){
    InitStack(S);
    BitTree p=T;
    while(p||!IsEmpty(S)){
        if(p!=NULL){
            push(S,p);
            p=p->lchild;
        }
        else{
            pop(S,p);
            visit(p);
            p=p->rchild;
        }
    }
}
//天勤
void inorderNonrecursion(BTNode *bt){
    if(bt!=NULL){
        BTNode *Stack[MAXSIZE];
        int top=-1;
        BTNode *p=bt;
        while(p!=NULL||top!=-1){
            while(p!=NULL){
                Stack[++top]=p;
                p=p->lchild;
            }
            if(top!=-1){
                p=Stack[top--];
                Visit(p);
                p=p->rchild;
            }
        }
    }
}
//先序遍历的非递归算法
//王道
//eg1
void PreOrder(BiTree T){
    InitStack(S);
    BitTree p=T;
    while(p||!IsEmpty(S)){
        while(p!=NULL){
            visit(p);
            push(S,p);
            p=p->lchild;
        }
        if(!IsEmpty(S)){
            pop(S,p);
            p=p->rchild;
        }
    }
}
//eg2
void PreOrder(BiTree T){
    InitStack(S);
    BitTree p=T;
    while(p||!IsEmpty(S)){
        if(p!=NULL){
            visit(p);
            push(S,p);
            p=p->lchild;
        }
        else{
            pop(S,p);
            p=p->rchild;
        }
    }
}
//天勤
void preorderNonrecursion(BTNode *bt){
    if(bt!=NULL){
        BTNode *Stack[MAXSIZE];
        int top=-1;
        BTNode *p;
        Stack[++top]=bt;
        while(top!=-1){
            p=Stack[top--];
            Visit(p);
            if(p->rchild!=NULL){
                Stack[++top]=p->rchild;
            }
            if(p->lchild!=NULL){
                Stack[++top]=p->lchild;
            }
        }
    }
}
//后序遍历的非递归算法
//王道版本1
void PostOrder(BiTree T){
    InitStack(S);
    BiTree p,r;
    p=T;
    r=NULL;
    while(p!=NULL||!IsEmpty(S)){
        if(p!=NULL){
            push(S,p);
            p=p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild!=NULL&&p->rchild!=r){
                 p=p->rchild;
                 push(S,p);
                p=p->lchild;
                }
            else{
                pop(S,p);
                visit(p);
                r=p;
                p=NULL;
            }
        }
    }
}
//殷人昆版本
#define stackSize 20
void PostOrder(BinTree BT){
    BitNode *S[stackSize];
    int top=-1;
    BitTree *p=BT,*pre=NULL;
    while(p!=NULL||top!=-1){
        while(p!=NULL){
            S[++top]=p;
            p=p->lchild;
        }
        if(top>-1){
            p=S[top];
            if(p->rchild!=NULL&&p->rchild!=pre){
                p=p->rchild;
            }
            else{
                printf("%c",p->data);
                pre=p;
                p=NULL;
                top--;
            }
        }
    }
}
//王道版本2
typedef strcut{
    BTNode *p;
    int rvisited;
}SNode;
typedef struct{
    SNode Elem[MAXSIZE];
    int top;
}SqStack;
void PostOrder(BiTree T){
    SNode sn;
    BTNode *pt=T;
    InitStack(S);
    while(T!=NULL){
        Push(S,pt,0);
        pt=pt->lchild;
    }
    while(!S.IsEmpty()){
        sn=S.getTop();
        if(sn.p->rchild==NULL||sn.rvisited){
            Pop(S,pt);
            visit(pt);
        }
        else{
            sn.rvisited=1;
            pt=sn.p->rchild;
            while(pt!=NULL){
                Push(S,pt,0);
                pt=pt->lchild;
            }
        }
    }
}
//天勤版本
void postorderNonrecursion(BTNode *bt){
    if(bt!=NULL){
        BTNode *Stack1[maxSize],*Stack2[maxSize];
        int top1=-1,top2=-1;
        BTNode *p=NULL;
        Stack[++top1]=bt;
        while(top1!=-1){
            p=Stack1[top1--];
            Stack2[++top2]=p;
            if(p->lchild!=NULL){
                Stack1[++top1]=p->lchild;
            }
            if(p->rchild!=NULL){
                Stack1[++top2]=p->rchild;
            }
        }
        while(top2!=-1){
            p=Stack[top2--];
            visit(p);
        }
    }
}
//层次遍历
//王道
void levelOrder(BiTree T){
    InitQueue(Q);
    BitTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        Dequeue(Q,p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}
//天勤
void level(BTNode *bt){
    if(bt!=NULL){
        int front,rear;
        BTNode *que[maxSize];
        front=rear=0;
        BTNode *p;
        rear=(rear+1)%maxSize;
        que[rear]=bt;
        while(front!=rear){
            front=(front+1)%maxSize;
            p=que[front];
            Visit(p);
            if(p->lchild!=NULL){
                rear=(rear+1)%maxSize;
                que[rear]=p->lChild;
            }
            if(p->rchild!=NULL){
                rear=(rear+1)%maxSize;
                que[rear]=p->rChild;
            }
        }
    }
}
//线索二叉树
//王道
//存储结构
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
//中序遍历线索化
void InThread(ThreadTree &p,ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}
//线索二叉树的遍历
//求中序线索二叉树的第一个结点
ThreadNode *FirstNode(ThreadNode *p){
    while(p->lchild==0){
        p=p->lchild;
    }
    return p;
}
//求中序线索二叉树中结点p在中序序列下的后继结点
ThreadNode *NextNode(ThreadNode *p){
    if(p->rchild==0) return FirstNode(p->rchild);
    else return p->rchild;
}
//中序线索二叉树的中序遍历算法
void InOrder(ThreadNode *T){
    for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p)){
        visit(p);
    }
}
//天勤
//存储结构
typedef struct TBTNode{
    int data;
    int lTag,rTag;
    TBTNode* lChild;
    TBTNode* rChild;
}TBTNode;
//中序线索化
void inThread(TBTNode *p,TBTNode *&pre){
    if(p!=NULL){
        inTread(p->lChild,pre);
        if(p->lChild==NULL){
            p->lChild=pre;
            p->lTag=1;
        }
        if(pre!=NULL&&pre->rChild==NULL){
            pre->rChild=p;
            pre->rTag=1;
        }
        pre=p;
        inThread(p->rChild,pre);
    }
}
//前序线索化
void preThread(TBTNode *p,TBTNode *&pre){
    if(p!=NULL){
        if(p->lChild==NULL){
            p->lChild=pre;
            p->lTag=1;
        }
        if(pre!=NULL&&pre->rChild==NULL){
            pre->rChild=p;
            pre->rTag=1;
        }
        pre=p;
        if(p->lTag==0){
            preThread(p->lChild,pre);
        }
        if(p->rTag==0){
            preThread(p->lChild,pre);
        }
    }
}
//前序遍历线索二叉树
void preOrder(TBTNode *tbt){
    if(tbt!=NULL){
        TBTNode *p=tbt;
        while(p!=NULL){
            while(p->lTag==0){
                Visit(p);
                p=p->lchild;
            }
            Visit(p);
            p=p->rchild;
        }
    }
}
//后序线索化
void postThread(TBTNode *p,TBTNode *&pre){
    if(p!=NULL){
        postTread(p->lChild,pre);
        postThread(p->rChild,pre);
        if(p->lChild==NULL){
            p->lChild=pre;
            p->lTag=1;
        }
        if(pre!=NULL&&pre->rChild==NULL){
            pre->rChild=p;
            pre->rTag=1;
        }
        pre=p;
    }
}
//习题
//求二叉树高度
//递归算法
int GetDepth(BiTree T){
    if(T==NULL) return 0;
    int ldep=GetDepth(T->lchild);
    int rdep=GetDepth(T->rchild);
    return (ldep>rdep?ldep:rdep)+1;
}
//非递归算法
int Btdepth(BiTree T
    if(T==NULL) return 0;
    int front=-1,rear=-1;
    int last=0,level=0;
    BiTree Q[MAXSIZE];
    Q[++rear]=T;
    BiTree p;
    while(front<rear){
        p=Q[++front];
        if(p->lchild!=NULL){
            Q[++rear]=p->lchild;
        }
        if(p->rchild!=NULL){
            Q[++rear]=p->rchild;
        }
        if(front==last){
            level++;
            last=rear;
        }
    }
    return level;
}
//先序序列和中序序列确定一棵二叉树
//王道
BiTree PreInCreat(ElemType A[],ElemType B[],int l1,int h1,int l2,int h2){
    BiTree root=(BiTNode*)malloc(sizeof(BiTNode));
    root->data=A[l1];
    int i;
    for(i=l2;B[i]!=root->data;++i);
    int llen=i-l2;
    int rlen=h2-i;
    if(llen){
        root->lchild=PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen-1);
    }
    else root->lchild=NULL;
    if(rlen){
        root->rchild=PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    }
    else root->lchild=NULL;
    return root;
}
//天勤
BTNode *CreatBT1(char pre[],char in[],int L1,int R1,int L2,int R2){
    if(L1>R1) return NULL;
    BTNode *s=(BTNode*)malloc(sizeof(BTNode));
    s->lChild=s->rChild=NULL;
    s->data=pre[L1];
    int i;
    for(i=L2;i<=R2;++i){
        if(in[i]==pre[L1])
        break;
    }
    s->lChild=CreatBT1(pre,in,L1+1,L1+i-L2,L2,i-1);
    s->rChild=CteatBT1(pre,in,L1+i-L2+1,R1,i+1,R2);
    return s;
}
//先序和后序序列确定一棵二叉树
BTNode *CreatBT2(char post[],char in[],int L1,int R1,int L2,int R2){
    if(L1>R1) return NULL;
    BTNode *s=(BTNode*)malloc(sizeof(BTNode));
    s->lChild=s->rChild=NULL;
    s->data=pre[R1];
    int i;
    for(i=L2;i<=R2;++i){
        if(in[i]==post[L1])
        break;
    }
    s->lChild=CreatBT2(post,in,L1,L1+i-L2-1,L2,i-1);
    s->rChild=CreatBT2(post,in,L1+i-L2,R1-1,i+1,R2);
    return s;
}
//层次序列和中序序列确定二叉树
int search(char arr[],char key,int L,int R){
    int idx;
    for(idx=L;idx<=R;=++idx){
        if(arr[idx]==key)
            return idx;
    }
    return -1;
}
void getSubLevel(char subLevel[],char level[],char in[],int n,int L,int R){
    int k=0;
    for(int i=0;i<n;++i){
        if(search(in,level[i],L,R)!=-1)
            subLevel[k++]=level[i];
    }
}
BTNode *CreateBT3(char level[],char in[],n,int L,int R){
    if(L>R) return NULL;
    BTNode *s=(BTNode*)malloc(sizeof(BTNode));
    s->lChild=s->rChild=NULL;
    s->data=level[0];
    int i=search(in,level[0],L,R);
    int LN=i-L;
    char LLevel[LN];
    int RN=R-i;
    char RLevel[RN];
    getSubLevel(LLevel,level,in,n,L,i-1);
    getSublevel(RLevel,level,in,n,i+1,R);
    s->lChild=Create3(LLevel,in,LN,L,i-1);
    s->rChild=Create3(RLevel,in,RN,i+1,R);
    return s;
}
//树中双结点个数
int DsonNodes(BiTree b){
    if(b==NULL){
        return 0;
    }
    else if(b->lchild!=NULL&&b->rchild!=NULL){
        return DsonNodes(p->lchild)+DsonNodes(p->rchild)+1;
    }
    else{
        return DsonNodes(b->lchild)+DsonNodes(b->rchild);
    }
}
//判断是否为完全二叉树
bool IsComplete(BiTree T){
    InitQueue(Q);
    if(T==NULL)
        return 0;
    EnQueue(Q,T);
    BiTree p;
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        if(p!=NULL){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else{
            while(!IsEmpty(Q)){
                DeQueue(Q,p);
                if(p!=NULL)
                return 0
            }
        }
        return 1;
    }
}
//删除根结点的元素值为X的子树
void DeleteXTree(BiTree bt){
    if(bt!=NULL){
        DeleteXTree(bt->lchild);
        DeleteXTree(bt->rchild);
        free(bt);
    }
}
void Search(BiTree bt,ElemType x){
    BiTree p,Q[MAXSIZE];
    if(bt->data==X){
        DeleteXTree(bt);
        exit(0);
    }
    InitQueue(Q);
    EnQueue(Q,bt);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        if(p->lchild!=NULL){
            if(p->lchild->data==x){
                DeleteXTree(p->lchild);
                p->lchild=NULL;
            }
            else
                EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            if(p->rchild->data==X){
                DeleteXTree(p->rchild);
                p->rchild=NULL;
            }
            else 
                EnQueue(Q,p->rchild);
        }
    }
}
//删除二叉排序树中data域为x的结点
int remove(BTNode *&t,char x){
    BTNode *p,*q,*r;
    p=t;//p指向待比较结点
    q=NULL;//q指向p的前驱结点
    while(p!=NULL&&p->data!=x){//查找域为x的结点p
        if(x<p->data){
            q=p;
            p=p->lchild;
        }
        else{
            q=p;
            p=p->rchild;
        }
    }
    if(p==NULL)
        return 0;
    else if(p->lchild==NULL)
        if(q==NULL)
            t=p->rchild;
        else if(q->lchild==p)
            q->lchild=p->rchild;
        else 
            q->rchild=p->rchild;
        free(p);
    else{
        r=p->lchild;
        while(r->rchild!=NULL)
            r=r->rchild;
        r->rchild=p->rchild;
        if(q==NULL)
            t=p->lchild;
        else if(q->lchild==p)
            q->lchild=p->lchild;
        else
            q->rchild=p->lchild;
        free(p);
    }
}
//打印值为X的结点的祖先
typedef struct{
    BitTree t;
    int tag;
}stack;
void search(BiTree bt,Elemtype x){
    stack s[MAXSIZE];
    top=0;
    while(bt!=NULL||top>0){
        while(bt!=NULL&&bt->data!=x){
            s[++top]=bt;
            s[top].tag=0;
            bt=bt->lchild;
        }
        if(bt->data==x){
            for(int i=1;i<=top;++i){
                printf("%d",s[i].t->data);
                exit(1);
            }
        }
        while(top!=0&&[top].tag==1)
            top--;
        if(top!=0){
            s[top].tag=1;
            bt=s[top].t->rchild;
        }
    }
}
//p和q的最近公共祖先
typedef struct{
    BiTree t;
    int tag;
}stack;
stack s[MAXSIZE],s1[MAXSIZE];
BiTree Ancestor(BiTree ROOT,BiTNode *p,BiTNode *q){
    int top=0;
    BitTree bt=ROOT;
    while(bt!=NULL||top>0){
        while(bt!=NULL&&bt!=p&&bt!=q){
            s[++top]=bt;
            s[top].tag=0;
            bt=bt->lchild;
        }
        while(top!=0&&s[top].tag==1){
            if(s[top].t==p){
                for(int i=1;i<=top;++i){
                    s1[i]=s[i];
                    top1=top;
                }
            }
            if(s[top].t==q){
                for(i=top;i>0;i--){
                    for(j=top1;j>0;j--){
                        if(s1[j].t==s[i].t)
                            return s[i].t; 
                    }
                }
            }
            top--;
        }
        if(top!=0){
            s[top].tag=1;
            bt=s[top].t->rchild;
        }
    }
    return NULL;
}
//顺序二叉树，求编号为i和j的两个结点的最近公共祖先的值
ElemType Comm_Ancestor(SqTree T,int i,int j){
    if(T[i]!='#'&&T[j]!='#'){
        while(i!=j){
            if(i>j)
                i/=2;
            else 
                j/=2;
        }
        return T[i];
    }
}
//表达式树
void BtreeToE(BTree *root){
    BtreeToEXP(root,1);
}
void BTreeToEXP(BTree *root,int deep){
    if(root==NULL) return;
    else if(root->lchild==NULL&&root->rchild==NULL){
        printf("%s",root->data);
    }
    else{
        if(deep>1) printf("(");
        BTreeToEXP(root->lchild,deep+1);
        printf("%s",root->data);
        BTreeToEXP(root->rchild,deep+1);
        if(deep>1) printf(")");
    }
}
//二叉树的带权路径长度WPL(二叉树中所有叶节点的带权路径长度之和)
typedef struct BiTNode{
    int weight;
    struct BiTNode *lchild,*rchild;
}BiTNode,BiTree;
//先序遍历算法
int WPL(BiTree toot){
    return wol_PreOrder(root,0);
}
int wpl_PreOrder(BiTree root,int deep){
    static int wpl=0;
    if(root->lchild==NULL&&root->rchild==NULL){
        wpl+=deep*root->weight;
    }
    if(root->lchild!-NULL){
        wpl_PreOrder(root->lchild,deep+1);
    }
    if(root->rchild!=NULL){
        wpl_PreOrder(root->rchild,deep+1);
    }
    return wpl;
}
//层序遍历算法
#define MAXSIZE 100
int wpl_LevelOrder(BiTree root){
    BiTree q[MAXSIZE];
    int end1,end2;
    end1=end2=0;//头指针指向队头，尾指针指向队尾的后一个元素
    int wpl=0,deep=0;
    BiTree lastNode,newlastNode;
    lastNode=root;
    q[end2++]=root;
    while(end1!=end2){
        BiTree t=q[end1++];
        if(t->lchild==NULL&&t->rchild==NULL){
            wpl+=t->weight;
        }
        if(t->lchild!=NULL){
            q[end2++]=t->lchild;
            newlastNode=t->lchild;
        }
        if(t->rchild!=NULL){
            q[end2++]=t->rchild;
            newlastNode=t->rchild;
        }
        if(t==lastNode){
            lastNode=newlastNode;
            deep+=1;
        }
    }
    return wpl;
}
//二叉树宽度，最大的层结点总数
typedef struct{
    BiTree data[MAXSIZE];
    int level[MAXSIZE];
    int front,rear;
}Qu;
int BTWidth(BiTree b){
    BiTree p;
    int k,max,i,n;
    Qu.front=Qu.rear=-1;
    Qu.rear++;
    Qu.data[Qu.rear]=b;
    Qu.level[Qu.rear]=1;
    while(Qu.front<Qu.rear){
        Qu.front++;
        p=Qu.data[Qu.front];
        k=Qu.level[Qu.front];
        if(p->lchild!=NULL){
            Qu.rear++;
            Qu.data[Qu.rear]=p->lchild;
            Qu.level[Qu.rear]=k+1;
        }
        if(p->rchild!=NULL){
            QU.rear++;
            Qu.data[Qu.rear]=p->rchild;
            Qu.level[Qu.rear]=k+1;
        }
        max=0;i=0;
        k=1;
        while(i<=Qu.rear){
            n=0;
            while(i<=Qu.rear&&Qu.level[i]==k){
                n++;
                i++;
            }
        }
        k=Qu.level[i];
        if(n>max) max=n;
    }
    return max;
}
//满二叉树的前序遍历转换为后序遍历序列
void PreToPost(ElemType pre[],int l1,int h1,ElemType post[],int l2,int h2){
    int half;
    if(h1>=l1){
        post[h2]=pre[l1];
        half=(h1-l1)/2;
        PreToPost(pre,l1+1,l1+half,post,l2+half-1);
        PreToPost(pre,l1+half+1,h1,post,12+half,h2-1);
    }
}
//求根结点到给定某结点的路径
bool Ancestors(Node* root,int x){
    if(!root) return false;
    if(root->data==x) return true;
    if(Ancestors(root->lChild,x)||Ancestors(root->rChild,x)){
        cout<<root->data<<endl;
        return true;
    }
    return false;
}
//求表达式树的值
int calSub(float opand1,char op,float opand2,float &result){
    if(op=='+') result=opand1+opand2;
    if(op=='-') result=opand1-opand2;
    if(op=='*') result=opand1*opand2;
    if(op=='/') {
        if(fabs(opand2)<MIN) return 0;
        else result=opand1/opand2;
    }
    return 1;
}
float cal(BTNode *root){
    if(root->lChild==NULL&&root->rChild==NULL){
        return root->data-'0';
    }
    else{
        float opand1=cal(root->lChild);
        float opand2=cal(root->rChild);
        float result;
        calSub(opand1,root->data,opand2,result);
        return result;
    }
}
//删除所有值小于x的结点(一定存在值为x的结点)
void delete(BTNode *&t){
    if(t!=NULL){
        deleteBT(t->lchild);
        deleteBT(t->rchild);
        free(t);
        t=NULL;
    }
}
void findAndDeleteBT(BTNode *&t,int x){
    while(t!=NULL){
        if(t->data==x){
            deleteBT(t->lchild);
            return;
        }
        else if(t->data<x)
            t=t->rchild;
        else
            t=t->lchild;
    }
}
//正确调用方法
BTNode *temp=T;
findAndDeleteBT(T,x);
T=temp;
//求表达式的值
int comp(BTNode *p){
    int A,B;
    if(p!=NULL){
        if(p->lchild!=NULL&&p->rchild!=NULL){
            A=comp(p->lchild);
            B=comp(p->rchild);
            return op(A,B,p->data);
        }
        else{
            return p->data-'0';
        }
    }
}
//求二叉树宽度
typedef struct{
    BTNode *p;
    int lno;
}St;
int maxNode(BTNode *b){
    St que[maxSize];
    int front,rear;
    int Lno,i,j,n,max;
    front=rear=0;
    BTNode *q;
    if(b!=NULL){
        ++rear;
        que[rear].p=b;
        que[rear].lno=1;
        while(front!=rear){
            ++front;
            q=que[front].p;
            Lno=que[front].lno;
            if(q->lchild!=NULL){
                ++rear;
                que[rear].p=q->lchild;
                que[rear].lno=Lno+1;
            }
            if(q-.rchild!=NULL){
                ++rear;
                que[rear].p=q->rchild;
                que[rear].lno=Lno+1;
            }
        }
        max=0;
        for(i=0;i<=Lno;++i){
            n=0;
            for(j=1;j<=rear;++j){
                if(que[j].lno==i)
                    ++n;
                if(max<n)
                    max=n;
            }
        }
        return max;
    }
    else return 0;
}
//二叉树所有结点数
//eg1
int n=0;
void count(BTNode *p){
    if(p!=NULL){
        ++n;
        count(p->lchild);
        count(p->rchild);
    }
}
//eg2
int count(BTnode *P){
    int n1,n2;
    if(p==NULL)
        return 0;
    else{
        n1=count(p->lchild);
        n2=count(p->rchild);
        return n1+n2+1;
    }
}
//二叉树所有叶子结点数
//eg1
int n=0;
void count(BTNode *p){
    if(p!=NULL){
        if(p->lchild==NULL&&p->rchild==NULL)
            ++n;
        count(p->lchild);
        count(p->rchild);
    }
}
//eg2
int count(BTnode *P){
    int n1,n2;
    if(p==NULL)
        return 0;
    else if(p->lichid==NULL&&p->rchild==NULL)
        return 1;
    else{
        n1=count(p->lchild);
        n2=count(p->rchild);
        return n1+n2;
    }
}
//二叉树b中值为x的结点的层号
int L=1;
void leno(BTNode *p,char x){
    if(p!=NULL){
        if(p->data==x){
            cout<<L<<endl;
        }
        ++L;
        leno(p->lchild,x);
        leno(p->rchild,x);
        --L;
    }
}
//输出根结点到每个叶子节点的路径
int i;
int top=0;
char pathstack[maxSize];
void allpath(BTNode *p){
    if(p!=NULL){
        pathstack[top]=p->data;
        ++top;
        if(p>lchild==NULL&&p->rchild==NULL){
            for(i=0;i<top;++i)
                cout<<pathstack[i];
        }
        allpath(p->lchild);
        allpath(p->rchild);
        --top;
    }
}
