//栈
//王道
//顺序栈
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;
//判空
bool StackEmpty(SqStack S){
    if(s.top==-1) return true;
    else return false;
}
//进栈
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1) return false;
    else S.data[++S.top]=x;
}
//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1) return false;
    x=S.data[S.top--];
    return true;
}
//读取栈顶元素
bool GetTop(SqStack S,ElemType &x){
    if(S..top==-1) return false;
    x=S.data[S.top];
    return true;
}
//共享栈
#define MaxSize 100
typedef struct{
    ElemType data[MaxSize];
    int top1;
    int top2;
}SqDoubleStack;
//进栈
bool Push(SqDoubleStack &S,ElemType x,int stackNum){
    if(S.top1+1==S.top2) return false;
    if(stackNum==1) S.data[++S.top1]=x;
    else if(stackNum==2) S.data[--S.top2]=x;
    return true;
}
//链栈
typedef struct SNode{
    ElemType data;
    struct SNode *next;
}SNode,*SLink;
typedef struct LinkStack{
    SLink top;
    int count;
}LinkStack;
//进栈
bool Push(LinkStack *S,ElemType s){
    SLink p=(SLink)malloc(sizeof(SLink));
    p->data=x;
    p->next=S->top;
    S->top=p;
    S->count++;
}
//出栈
bool Pop(LinkStack &S,ElemType &x){
    if(S->top==NULL) return false;
    x=S->top->data;
    SLink p=S->top;
    S->top=S->top->next;
    free(p);
    S->count--;
    return true;
}
//顺序队列
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
//循环队列入队
bool EnQueue(SqQueue &Q,ElemType x){
    if(Q.rear+1)%MaxSize==Q.front) return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
//循环队列出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
//链式队列
typedef struct{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
//入队
void EnQueue(LinkQueue &Q,ElemType x){
    s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}
//出队
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==Q.rear) return false;
    p=Q->front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p) Q.rear=Q.front;
    free(q);
}
//天勤
//顺序栈定义
typedef struct{
    int data[maxSize];
    int top;
}SqStack;
//简洁定义
int stack[maxSize];
int top=-1;
//链栈结点定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;
//初始化栈
void initStack(SqStack &st){
    st.top=-1;
}
//判断栈空
int isEmpty(SqStack st){
    if(st.yop==-1)
        return 1;
    else 
        return 0;
}
//进栈代码
int push(SqStack &st,int x){
    if(st.top==maxSize-1)
        return 0;
    ++(st.top);
    st.data[st.top]=x;
    return 1;
}
//出栈代码
int pop(SqStack &st,int &x){
    if(st.top==-1)
    return 0;
    x=st.data[st.top];
    --(st.top);
    return 1;
}
//链栈
//初始化
void initStack(LNode *&lst){
    lst=(LNode*)malloc(sizeof(LNode));
    lst->next=NULL;
}
//判断栈空
int isEmpty(LNode *lst){
    if(lst->next==NULL) 
        return 1;
    else return 0;
}
//进栈
void push(LNode *lst,int x){
    LNode *p;
    p=(LNode)malloc(sizeof(LNode));
    p->next=NULL;
    p->data=x;
    p->next=lst->next;
    lst->next=p;
}
//出栈
int pop(LNode *lst,int &x){
    LNode *p;
    if(lst->next==NULL)
        return 0;
    p=lst->next;
    x=p->data;
    lst->next=p->next;
    free(p);
    return 1;
}
//顺序队列定义
typedef struct{
    int data[maxSize];
    int front;
    int rear;
}SqQueue;
//链队定义
//队结点类型定义
typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;
//链队类型定义
typedef struct{
    QNode *front;
    QNode *rear;
}LiQueue;
int queue[maxSize];
int front=0,rear=0;
//顺序队列
//入队
queue[++rear]=x;
//出队
x=queue[++front];
//循环队列
//初始化
void initQueue(SqQueue &qu){
    qu.front=qu.rear=0;
}
//判断队空
int isQueueEmpty(SqQueue qu){
    if(qu.front==que.rear)
        return 1;
    else 
        return 0;
}
//入队
int enQueue(SqQueue &qu,int x){
    if((qu.rear+1)%maxSize==qu.front)
        return 0;
    qu.rear=(qu.rear+1)%maxSize;
    qu.data[qu.rear]=x;
    return 1;
}
//出队算法
int  deQueue(SqQueue &qu,int &x){
    if(qu.front==qu.rear)
        return 0;
    qu.front=(qu.front+1)%maxSize;
    x=qu.data[qu.front];
    return 1;
}
//链队
//初始化链队
void initQueue(LiQueue *&lqu){
    lqu=(LiQueue)malloc(sizeof(LiQueue));
    lqu->front=lqu->rear=NULL;

}
//判断队空
int isQueueEmpty(LiQueue *lqu){
    if(lqu->rear==NULL||lqu->front==NULL)
        return 1;
    else 
        return 0;
}
//入队算法
void enQueue(LiQueue *lqu,int x){
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode));
    p->data=x;
    p->next=NULL;
    if(lqu->rear==NULL)
        lqu->front=lqu->rear=p;
    else{
        lqu->rear->next=p;
        lqu->rear=p;
    }
}
//出队代码
int deQueue(LiQueue *lqu,int &x){
    QNode *p;
    if(lqu->rear==NULL)
            return 0;
    else   
        p=lqu->front;
    if(lqu->front==lqu->rear)
        lqu->front=lqu->rear=NULL;
    else
        lqu->front=lqu->front->next;
    x=p->data;
    free(p);
    return 1;
}
