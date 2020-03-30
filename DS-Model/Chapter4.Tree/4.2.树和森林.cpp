//天勤
//树的顺序存储
typedef struct{
    int data;
    int pIdx;//父结点下标
}TNode;
TNode tree[maxSize];
//树的链式存储
typedef struct Branch{
    int cIdx;
    Branch *next;
}Branch;
typedef struct{
    int data;
    Branch *first;
}TNode;
//树的先序遍历
void preOrder(TNode *p,TNode tree[]){
    if(p!=NULL){
        visit(p);
        Branch *q;
        q=p->first;
        while(q!=NULL){
            preOrder(&tree[q->cIdx],tree);
            q=q->next;
        }
    }
}
//后序遍历
void preOrder(TNode *p,TNode tree[]){
    if(p!=NULL){
        Branch *q;
        q=p->first;
        while(q!=NULL){
            preOrder(&tree[q->cIdx],tree);
            q=q->next;
        }
        visit(p);
    }
}
//树的层次遍历代码
void level(TNode *tn,TNode Tree[]){
    int front,rear;
    TNode *que[maxSize];
    front=rear=0;
    TNode *p;
    if(tn!=NULL){
        rear=(rear+1)%maxSize;
        que[rear]=tn;
        while(front!=rear){
            front=(front+1)%maxSize;
            p=que[front];
            visit(p);
            Branch *q=p->first;
            while(q!=NULL){
                rear=(rear+1)%maxSize;
                que[rear]=&tree[q->cIdx];
                q=q->next;
            }
        }
    }
}
//双亲表示法
#define MAX_TREE_SIZE 100
typedef struct{
    ElemType data;
    int parent;
}PTNode;
typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;
//孩子表示法
typedef char Elemtype;
typedef struct CNode{
    int child;
    struct CNode *next;
}CNode,*Child;
typedef struct{
    ElemType data;
    Child firstchild;
}TNode;
//孩子兄弟表示法
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextchild;
}CSNode,*CSTree;
//并查集结构定义
#define SIZE 100
int UFSets[SIZE];
//并查集初始化
void Initial(int S[]){
    for(int i=0;i<size;i++){
        S[i]=-1;
    }
}
//Find操作
int Find(int S[],int x){
    while(S[x]>=0)
        x=S[x];
    return x;
}
//Union操作
void Union(int S[],int Root1,int Root2){
    S[root2]=Root1;
}
//E1.孩子兄弟表示法森林或树的叶子节点数
typedef struct node{
    ElemType data;
    struct node *fch,*nsib;
}*Tree;
int Leaves(Tree t){
    if(t==NULL) return 0;
    if(t->fch==NULL){
        return 1+Leaves(t->nsib);
    }
    else return Leaves(t->fch)+Leaves(t->nsib);
}
//E2.孩子兄弟表示法表示的树的高度
Height(CSTree bt){
    int hc,hs;
    if(bt==NULL)
        return 0;
    else{
        hc=Height(bt->firstchild);
        hs=Height(bt->nextsibling);
        if(hc+1>hs)
            return hc+1;
        else 
            return hs;
    }
}
