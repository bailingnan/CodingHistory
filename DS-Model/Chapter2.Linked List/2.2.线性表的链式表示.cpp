//基本操作
//王道
//链表
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//头插法建立单链表
LinkList CreatList1(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//尾插法建立单链表
LinkList CreatList2(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    return L;
}
//按序号查找结点值
LNode* GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0)
        return L;
    if(i<1) return NULL;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}
//按值查找结点
LNode *LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)
        p=p->next;
    return p;
}
//插入结点操作(后插)
p=GetElem(L,i-1);
s->next=p->next;
p->next=s;
//前插
s->next=p->next;
p->next=s;
temp=p->data;
p->data=s->data;
s->data=temp;
//删除结点操作
p=GetElem(L,i-1);
q=p->next;
p->next=q->next;
free(q);
//通过删除*p后继结点的操作删除结点*p
q=p->next;
p->data=p->next->data;
p->next-q->next;
free(q);
//双链表
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
//插入操作
s->next=p->next;
p->next->prior=s;
s->prior=p;
p->next=s;
//删除操作
p->next=q->next;
q->next->prior=p;
free(q);
//静态链表
#define MaxSize 50
typedef struct {
    ElemType data;
    int next;
}SLinkList[MaxSize];
//天勤
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;
//双链表
typedef struct DLNode{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;
LNode *A=(LNode*)malloc(sizeof(LNode));
//尾插法
void createlistR(LNode *&C,int a[],int n){
    LNode *s,*r;
    int i;
    C(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    r=c;
    for(i=0;i<n;++i){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
//头插法
void createlistH(LNode *&C,int a[],int n){
    LNode *s;
    int i;
    C=(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    for(i=0;i<n;++i){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=C->next;
        C->next=s;
    }
}
//尾插法建立双链表
void createDlistR(DLNode *&L,int a[],int n){
    DLNode *s,*r;
    int i;
    L=(DLNode*)malloc(sizeof(DLNode));
    L->prior=NULL;
    L->next=NULL;
    r=L;
    for(i=0;i<n;++i){
        s=(DLNode*)malloc(sizeof(DLNode));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}
//查找结点
DLNode* findNode(DLNode *C,int x){
    DLNode *p=C->next;
    while(p!=NULL){
        if(p->data==x)
            break;
        p=p->next;
    }
    return p;
}
//插入结点
s->next=p->next;
s->prior=p;
p->next=s;
s->next->prior=s;
//删除结点
q=p->next;
p->next=q->next;
q->next->prior=p;
free(q);
//习题
//有序表合并
void merge(LNode *A,LNode *B,LNode *&C){
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *r;
    C=A;
    C->next=NULL;
    free(B);
    r=C;
    while(p!=NULL&&q!=NULL){
        if(p->data<=q->data){
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else{
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;
    if(p!=NULL) r->next=p;
    if(q!=NULL) r->next=q;
}

//不带头结点链表中递归删除值为x的结点
void Del_x_3(LinkList &L,ElemType x){
    LNode *p;
    if(L==NULL)
        return;
    if(L->data==x){
        p=L;
        L=L->next;
        free(p);
        Del_x_3(L,x);
    }
    else 
        Del_x_3(L->next,x);
}
//带头结点链表删除值为x的结点
//eg1.1
void Del_x_1(LinkList &L,ElemType x){
    LNode *p=L->next,*pre=L,*q;
    while(p!=NULL){
        if(p->data==x){
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}
//eg1.2
int findAndDelete(LNode *C,int x){
    LNode *p,*q;
    p=C;
    while(p->next!=NULL){
        if(p->next->data==x)
            break;
        p=p->next;
    }
    if(p->next==NULL) return 0;
    else{
        q=p->next;
        p->ext=p->next->next;
        free(q);
        return 1;
    }
}
//eg2
void Del_x_2(LinkList &L,ElemType x){
    LNode *p=L->next,*r=L,*q;
    while(p!=NULL){
        if(p->data!=x){
            r->next=p;
            r=p;
            p=p->next;
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
    r->next=NULL;
}
//带头结点链表逆序输出
void R_Print(LinkList L){
    if(L->next!=NULL){
        R_Print(L->next);
    }
    print(L->data);
}
//删除带头结点链表最小值结点
LinkList Delete_Min(LinkList &L){
    LNode *pre=L,*p=L->next;
    LNode *minpre=L,*minp=p;
    while(p!=NULL){
        if(p->data<minp->data){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}
//带头结点链表逆置
//eg1
LinkList Reverse_1(LinkList L){
    LNode *p,*r;
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}
//eg2
LinkList Reverse_2(LinkList L){
    LNode *pre,*p=L->next,*r=p->next;
    p->next=NULL;
    while(r!=NULL){
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;
    return L;
}
//带头结点链表排序
void Sort(LinkList &L){
    LNode *p=L->next,*pre;
    LNode *r=p->next;
    p->next=NULL;
    p=r;
    while(p!=NULL){
        r=p->next;
        pre=L;
        while(pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p
        p=r;
    }
}
//求两链表公共结点
typedef struct Node{
    char data;
    struct Node *next;
}SNode;
int listlen(SNode *head){
    int len=0;
    while(head->next!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
SNode* find_addr(SNode *str1,SNode *str2){
    int m,n;
    SNode *p,*q;
    m=listlen(str1);
    n=listlen(str2);
    for(p=str1;m>n;m--)
        p=p->next;
    for(q=str2;m<n;n--)
        q=q->next;
    while(p->next!=NULL&&p->next!=q->next){
        p=p->next;
        q=q->next;
    }
    return p->next;
}
//按递增次序输出带头结点链表
void Min_Delete(LinkList &head){
    while(head->next!=NULL){
        pre=head;
        p=pre->next;
        while(p->next!=NULL){
            if(p->next->data<pre->next->data){
                pre=p;
            }
            p=p->next;
        }
        print(pre->next->data);
        u=pre->next;
        pre->next=u->next;
        free(u);
    }
    free(head);
}
//n个元素不重复建表
void createLinkNoSameElem(LNode *&head){
    head=(LNode*)malloc(sizeof(LNode));
    head->next=NULL;
    LNode *p;
    int n;
    char ch;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>ch;
        p=head->next;
        while(p!=NULL){
            if(p->data==ch)
                break;
            p=p->next;
        }
        if(p==NULL){
            p=(LNode*)malloc(sizeof(LNode));
            p->data=ch;
            p->next=head->next;
            head->next=p;
        }
    }
}
//带头结点链表A分解为两个带头结点的链表A和B
LinkList DisCreat_1(LinkList &A){
    i=0;
    B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    LNode  *ra=A,*rb=B;
    p=A->next;
    A->next=NULL;
    while(p!=NULL){
        i++;
        if(i%2==0){
            rb->next=p;
            rb=p;
        }
        else{
            ra->next=p;
            ra=p;
        }
        p=p->next;
    }
    ra->next=NULL;
    rb->next=NULL;
    return B;
}
//带头结点链表拆分为两部分，A为奇数项顺序，B为偶数项逆序
LinkList DistCreat_2(LinkList &A){
    LinkList B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    LNode *p=A->next,*q;
    LNode *ra=A;
    while(p!=NULL){
        ra->next=p;
        ra=p;
        p=p->next;
        q=p->next;
        p->next=B->next;
        B->next=p;
        p=q;
    }
    ra->next=NULL;
    return B;
}
//A含data域为奇数，B含data域为偶数
void split (LNode *A,LNode *&B){
    LNode *p,*q,*r;
    B=(LNode*)malloc(sizeof(LNode));
    B->next=NULL;
    r=b;
    p=A;
    while(p->next!=NULL){
        if(p->next->data%2==0){
            q=p->next;
            p->next=q->next;
            q->next=NULL;
            r->next=q;
            r=q;
        }
        else p=p->next;
    }
}
//有序表删除重复元素
//eg1
void Del_Same(LinkList &L){
    LNode *p=L->next,*q;
    if(p=NULL) return;
    while(p->next!=NULL){
        q=p->next;
        if(p->data==q->data){
            p->next=q->next;
            free(q);
        }
        else
            p=p->next;
    }
}
//eg2
void del(LNode *L){
    LNode *p=L->next,*q=L->next->next,*r;
    while(q!=NULL){
        while(q!=NULL&&q->data==p->data)
            q=q->next;
        if(q!=NULL){
            p=p->next;
            p->data=q->data;
        }
    }
    q=p->next;
    p->next=NULL;
    while(q!=NULL){
        r=q;
        q=q->next;
        free(r);
    }
}
//递增链表归并为递减链表
//eg1
void merge(LNode *A,LNode *B,LNode *&C){
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *s;
    C=A;
    C->next=NULL;
    free(B);
    while(p!=NULL&&q!=NULL){
        if(p->data<=q->data){
            s=p;
            p=p->next;
            s->next=C->next;
            C->next=s;
        }
        else{
            s=q;
            q=q->next;
            s->next=C->next;
            C->next=s;
        }
    }
    while(p!=NULL){
        s=p;
        p->next;
        s->next=C->next;
        C->next=s;
    }
    while(q!=NULL){
        s=q;
        q=q->next;
        s->next=C->next;
        C->next=s;
    }
}
//eg2
void MergeList(LinkList &La,LinkList &Lb){
    LNode  *r,*pa=La->next,*pb=Lb->next;
    La->next=NULL;
    while(pa&&pb){
        if(pa->data<=pb->data){
            r=pa->next;
            pa->next=La->next;
            La->next=pa;
            pa=r;
        }
        else{
            r=pb->next;
            pb->next=La->next;
            La->next=pb;
            pb=r;
        }
    }
    if(pa)
        pb=pa;
    while(pb){
        r=pb->next;
        pb->next=La->next;
        La->next=pb;
        pb=r;
    }
    free(Lb);
}
//AB两链表公共元素成C链表
void Get_common(LinkList A,LinkList B){
    LNode *p=A->next,*q=B->next,*r,*s;
    LinkList C=(LinkList)malloc(sizeof(LNode));
    r=C;
    while(p!=NULL&&q!=NULL){
        if(p->data<q->data){
            p=p->next;
        }
        else if(p->data>q->data){
            q=q->next;
        }
        else{
            s=(LNode*)malloc(sizeof(LNode));
            s->data=p->data;
            r->next=s;
            r=s;
            p=p->next;
            q=q->next;
        }
    }
}
//AB归并为A链表
LinkList Union(LinkList &la,LinkList &lb){
    pa=la->next;
    pb=lb->next;
    pc=la;
    while(pa&&pb){
        if(pa->data==pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            u=pb;
            pb=pb->next;
            free(u);
        }
        else if(pa->data<pb->data{
            u=pa;
            pa=pa->next;
            free(u);
        }
        else{
            u=pb;
            pb=pb->next;
            free(u);
        }
        while(pa){
            u=pa;
            pa=pa->next;
            free(pa);
        }
        while(pb){
            u=pb;
            pb=pb->next;
            free(u);
        }
        pc->next=NULL;
        free(lb);
        return la;
    }
}
//判断链表B是否为链表A的连续子序列
int Pattern (LinkList A,LinkList B){
    LNode *p=A;
    LNode *pre=p;
    LNode *q=B;
    while(p&&q){
        if(p->data==q->data){
            p=p->next;
            q=q->next;
        }
        else{
            pre=pre->next;
            p=pre;
            q=B;
        }
    }
    if(q==NULL)
        return 1;
    else 
        return 0;
}
//判断循环双链表是否对称
int Symmetry(DLinkList L){
    DNode *p=L->next,*q=L->prior;
    while(p!=q&&q->next!=p){
        if(p->data==q->data){
            p=p->next;
            q=q->next;
        }
        else 
            return 0;
    }
    return 1;
}
//合并两个循环单链表
LinkList Link(LinkList &h1,LinkList &h2){
    LNode *p,*q;
    p=h1;
    while(p->next!=h1)
        p=p->next;
    q=h2;
    while(q->next!=h2)
        q=q->next;
    p->next=h2;
    q->next=h1;
    return h1;
}
//循环单链表反复删除最小结点，最后释放头结点
void Del_All(LinkList &L){
    LNode *p,*pre,*minp,*minpre;
    while(L->next!=L){
        p=L->next;
        pre=L;
        minp=p;
        minpre=pre;
        while(p!=L){
            if(p->data<minp->data){
                minp=p;
                minpre=pre;
            }
            pre=p;
            p=p->next;
        }
        printf("%d",minp->data);
        pinpre->next=minp->next;
        free(minp);
    }
    free(L);
}
//按访问频度(freq)顺序排列，最近访问的结点排在频度相同的结点的前面
//eg1
DLinkList Locate(DLinkList &L,ElemType x){
    DNode *p=L->next,*q;
    while(p&&p->data!=x){
        p=p->next;
    }
    if(!p){
        printf("ERROR");
        exit (0);
    }
    else{
        p->freq++;
        p->next->pred=p->pred;
        p->pred->next=p->next;
        q=p->pred;
        while(q!=L&&q->freq<=p->freq)
            q=q->pred;
        p->next=q->next;
        q->next->pred=p;
        p->pred=q;
        q->next=p;
    }
    return p;
}
//eg2
DLNode *locate(DLNode *&DL,int x){
    DLNode *p=DL->next,*q;
    while(p!=NULL&&p->data!=x) p=p->next;
    if(p!=NULL){
        ++(p->freq);
        q=p;
        q->prior->next=q->next;
        q->next->prior=q->prior;
        p=q->prior;
        while(p!=DL&&q->freq>p->freq) p=p->prior;
        q->next=p->next;
        q->prior=p;
        p->next->prior=q;
        p->next=q;
        return q;
    }
    else return NULL;
}
//查找倒数第k个结点
//eg1
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *link;
}LNode,*LinkList;
int Search_k(LinkList list,int k){
    LNode *p=list->link,*q=list->link;
    int count=0;
    while(p!=NULL){
        if(count<k) count++;
        else q=q->link;
        p=p->link;
    }
    if(count<k)
        return 0;
    else{
        printf("%d",q->data);
        return 1;
    }
}
//eg2
int findElem(LNode *head,int k){
    LNode *p1=head_next,*p=head;
    int i=1;
    while(p1!=NULL){
        p1=p1->next;
        ++i;
        if(i>k) p=p->next;
    }
    if(p==head) return 0;
    else{
        cout<<p->data;
        return 1;
    }
}
//删除链表中重复的值
typedef struct node{
    int data;
    struct node *link;
}NODE;
Typedef NODE *PNODE;
void func(PNODE h,int n){
    PNODE p=h,r;
    int *q,m;
    q=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++){
        *(q+i)=0;
    }
    while(p->link!=NULL){
        m=p->link->data>0?p->link->data:-p->data->link->data;
        if(*(q+m)==0){
            *(q+m)=1;
            p=p->link;
        }
        else{
            r=p->link;
            p->link=r->link;
            free(r);
        }
        free(q);
    }
}
//递增有序两单链表差集(仅在A中出现而不在B中出现)
void difference(LNode *A,LNode *B){
    LNode *p=A->next,*q=B->next;
    LNode *pre=A;
    LNode *r;
    while(p!=NULL&&q!=NULL){
        if(p->data<q->data){
            pre=p;
            p=p->next;
        }
        else if(p->data>q->data)
            q=q->next;
        else{
            pre->next=p->next;
            r=p;
            p=p->next;
            free(r);
        }
    }
}
//求最大元素
int getMax(LNode *L){
    if(L->next==NULL)
        return L->data;
    int temp=getMax(L->next);
    if(L->data>temp)
        return L->data;
    else return temp;
}
//求结点个数
int getNum(LNode *L){
    if(L->next==NULL)
        return 1;
    return 1+getNUm(L->next);
}
//求所有整数的平均值
float getAvg(LNode *L,int n){
    if(L->next==NULL)
        return (float)(L->data);
    else{
        float sum=getAvg(L->next,n-1)*(n-1);
        return (float)(L->data+Sum)/n;
    }
}
//双链表将最大值结点移动至最前端
void maxFirst(DLNode *head){
    DLNode *p=head->rlink,*q=p;
    int max=p->data;
    while(p!=NULL){
        if(max<p->data){
            max=p->data;
            q=p;
        }
        p=p->rlink;
    }
    DLNode *l=q->llink,*r=rlink;
    l->rlink=r;
    if(r!=NULL)
        r->link=l;
    q->llink=head;
    q->rlink=head->rlink;
    head->rlink=q;
    q->rlink->llink=q;
}
//(交大课件)写一算法将单链表中值重复的结点删除，使所得的结果链表中所有结点的值均不相同
void DeleteList(LinkList &L){
    ListNode *p,*q,*s;
    p=L->next;
    while(p->next&&p->next->next){
        q=p;
        while(q->next){
            if(p->data==q->next->data){
                s=q->next;
                q->next=s->next;
                free(s);
            }
            else q=q->next;            
        }
        p=p->next;
    }
}
