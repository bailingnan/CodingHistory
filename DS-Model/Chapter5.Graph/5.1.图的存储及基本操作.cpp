//王道
//图的邻接矩阵存储结构
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;
//邻接表存储结构
#define MaxVertexNum 100
typedef struct ArcNode{//边表结点
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{//顶点表结点
    VertexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;//邻接表
    int vexnum,arcnum;
}ALGraph;
//有向图的十字链表
#define MaxVertexNum 100
typedef struct ArcNode{
    int tailvex,headvex;//弧的头尾结点
    struct ArcNode *hlink,*tlink;//分别指向弧头相同和弧尾相同的结点
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *firstin,*firstout;//指向第一条出弧和入弧
}VNode;
typedef struct{
    VNode xlist[MaxVertexNum];
    int vexnum,arcnum;
}GLGraph;
//无向图的邻接多重表
#define MaxVertexNum 100
typedef struct ArcNode{
    bool mark;//访问标记
    int ivex,jvex;
    struct ArcNode *ilink,*jlink;//分别指向两个顶点的下一条边
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *firstedge;//指向第一条依附该顶点的边
}VNode;
typedef struct{
    VNode adjmulist[MaxVertexNum];
    int vexnum,arcnum;
}AMLGraph;
//邻接表转换为邻接矩阵
void Convert(ALGraph &G,int arcs[M][N]){
    for(int i=0;i<n;++i){
        p=(G->v[i]).firstarc;
        while(p!=NULL){
            arcs[i][p->data]=1;
            p=p->nextarc;
        }
    }
}
//邻接矩阵转化为邻接表
void mattolist(int a[][maxSize],graph *g,int n){
    int i,j,m=0;
    arcnode *p;
    for(i=0;i<n;i++){
        g->adjlist[i].firstaec=NULL;
    }
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;--j){
            if(a[i][j]!=0){
                m++;
                p=(arcnode*)malloc(sizeof(arcnode));
                p->adjvex=j;
                p->nextarc=g->adjlist[i].firstarc;
                g->adjlist[i].firstarc=p;//头插法建表
            }
        }
    }
    g->vexnum=n;
    g->arcnum=m;
}
//天勤
//邻接矩阵
float MGraph[5][5];
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        MGraph[i][j]=MAX;
    }
}
//邻接表
typedef strcut ArcNode{
    int adjV;
    struct ArcNode* next;
}ArcNode;
typedef struct{
    int data;
    ArcNode *first;
}VNode;
typedef struct{
    int data;
    ArcNode *first;
}
typedef struct{
    VNode adjList[maxSize];
    int n,e;
}AGraph;
//邻接矩阵表示，求顶点k的入度
int count(AGraph *g,int k){
    ArcNode *p;
    int i,sum;
    sum=0;
    for(i=0;i<g->n;++i){
        p=g->adjlist[i].firstarc;
        while(p!=NULL){
            if(p->adjvex==k){
                ++sum;
                break;
            }
            p=p->nextarc;
        }
    }
    return sum;
}
