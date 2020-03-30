//王道
//BFS广度优先搜索
//eg1
bool visited[MAX_VERTEX_NUM];
void BFSTraverse(Graph G){
    for(int i=0;i<G.venum;++i){
        visited[i]=FALSE;
    }
    InitQueue(Q);
    for(int i=0;i<G.vexnum;++i){
        if(!visited[i]){
            BFS(G,i);
        }
    }
}
void BFS(Graph G,int v){
    visit(v);
    visited[v]=TRUE;
    EnQueue(Q,v);
    while(!Empty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(w);
                visited[w]=TRUE;
                EnQueue(Q,w);
            }
        }
    }
}
//eg2
#define MaxSize 100;
void BFSTraverse(Graph G){
    int i;
    for(int i=0;i<G->vexnum;i++){
        visited[i]=FALSE;
    }
    for(int i=0;i<G->vexnum;i++){
        if(!visited[i])
            BFS(G,i);
    }
}
bool visited[MaxSize];
void BFS(Graph G,int v){
    ArcNode *p;
    InitQueue(Q);
    visit[v];
    visited[v]=TRUE;
    Enqueue(Q,v);
    while(!IsEmpty(Q)){
        DeQueue(Q,v);
        p=G->adjList[v].firstedge;
        while(p){
            if(!visited[p->adjvex]){
                visit(p->adjvex);
                visited[p->adjvex]=TRUE;
                EnQueue(Q,p->adjvex);
            }
            p=p->next;
        }
    }
}
//BFS算法求解单源最短路径
void BFS_MIN_Distance(Graph G,int u){
    for(int i=0;i<G.vexnum;++i){
        d[i]=INF;//INF为无穷大
    }
    visited[u]=TRUE;
    d[u]=0;
    EnQueue(Q,u);
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w)){
            if(!visited[w]){
                visited[w]=TRUE;
                d[w]=d[u]+1;
                EnQueue(Q,w);
            }
        }
    }
}
//DFS深度优先搜索
//eg1
bool visited[MAX_VERTEX_NUM];
void DFSTraverse(Graph G){
    for(v=0;v<G.vexnum;++v){
        visited[v]=FALSE;
    }
    for(v=0;v<G.vexnum;++v){
        if(!visited[v]){
            DFS(G,v);
        }
    }
}
void DFS(Graph G,int v){
    visited(v);
    visited[v]=TRUE;
    for(w=FirstNeighbor(G,v);w>=0;w=Neighbor(G,v,w)){
        if(!visited[w]){
            DFS(G,w);
        }
    }
}
//eg2
#define MaxSize 100;
bool visited[MaxSize];
void DFSTraverse(Graph G){
    int i;
    for(i=0;i<G->vexnum;i++) visited[i]=false;
    for(i=0;i<G->vexnum;i++){
        if(!visited[i]) 
            DFS(G,i);
    }
}
void GFS(Graph G,int v){
    ArcNode *p;
    visited(v);
    visited[v]=TRUE;
    P=G->adjlist[v].firstarc;
    while(p!=NULL){
        if(!visited[p->adjvex]){
            DFS(G,p->adjvex);
        }
        p=p->nextarc;
    }
}
//天勤
//DFS
void DFS(int v,AGraph *G){
    visit[v]=1;
    Visit(v);
    ArcNode* q=G->adjList[v].first;
    while(q!=NULL){
        if(visit[q->adjV]==0){
            DFS(q->adjV,G);
        }
        q=q->next;
    }
}
//BFS
void BFS(AGraph *G,int v,int visit[maxSize]){
    ArcNode *p;
    int que[maxSize],front=0,rear=0;
    int j;
    Visit(v);
    visit[v]=1;
    rear=(rear+1)%maxSize;
    que[rear]=v;
    while(front!=rear){
        front=(front+1)maxSize;
        j=que[front];
        p=G->adjlist[j]->first;
        while(p!=NULL){
            if(visit[p->adjV]==0){
                Visit(P->adjV);
                visit[p->adjV]=1;
                rear=(rear+1)%maxSize;
                que[rear]=p->adjV;
            }
            p=p->next;
        }
    }
}
//判断无向图G是否为一棵树
//eg1
bool isTree(Graph &G){
    for(int i=i;i<=G.vexnum;i++){
        visited[i]=FALSE;
    }
    int Vnum=0,Enum=0;
    DFS(G,1,Vnum,Enum,visited);
    if(Vnum=G.vexnum&&Enum=2*(G.vexnum-1))
        return true;
        else return false;
}
DFS(Graph &G,int v,int &Vnum,int &Enum,int visited[]){
    visited[v]=True;
    Vnum++;
    for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        Enum++;
        if(!visited[w])
            DFS(G,w,Vnum,Enum,visited);
    }
}
//eg2
void DFS2(AGrph *G,int v,int &vn,int &en){
    ArcNode *p;
    visit[v]=1;
    ++vn;
    p=G->adjlist[v].firstarc;
    while(p!=NULL){
        ++en;
        if(visit[p->adjvex]==0)
            DFS2(G,p->adjvex,vn,en);
        p=p->nextarc;
    }
}
int GisTree(Agraph *G){
    int vn=0,en=0,i;
    for(i=0;i<G->n;++i)
        visit[i]=0;
    DFS2(G,1,vn,en);
    if(vn==G->n&&(G->n-1)==en/2);
        return 1;
    else 
        return 0;
}
//判断是否存在从i到j的路径
//DFS
int visited[MAXSIZE]={0};
int Exist_Path_DFS(ALGraph G,int i,int j){
    int p;
    if(i==j) return 1;
    else{
        visited[i]=1;
        for(p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,i,p)){
            if(!visited[p]&&Exist_Path_DFS(G,p,j))
                return 1;
        }
    }
    return 0;
}
//BFS
int visited[MAXSIZE]={0};
int Exist_Path_BFS(ALGraph G,int i,int j){
    InitQueue(Q);
    EnQueue(Q,i);
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        visited[u]=1;
        for(p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,p,j)){
            if(p==j) 
            return 1;
            if(!visited[p])
            EnQueue9Q,p);
        }
    }
    return 0;
}
//天勤
int DFSTrave(AGraph *G,int i,int j){
    int k;
    for(k=0;k<G->n;++k)
        visit[k]==0;
        DFS(G,i);//BFS(G,i);
        if(visit[j]==1)
            return 1;
        else 
            return 0;
}
//邻接表方式存储的有向图中是否存在由顶点Vi到顶点Vj的路径
int BFS(AGraph *G,int vi,int vj){
    ArcNode *p;
    int que[maxSize],front=0,rear=0;
    int visit[maxSize];
    int i,j;
    for(i=0;i<G->n;++i){
        visit[i]=0;
    }
    rear=(rear+1)%maxSize;
    que[rear]=vi;
    visit[vi]=1;
    while(front!=rear){
        front=(front+1)%maxSize;
        j=que[front];
        if(j==vj)
            return 1;
        p=G->adjlist[j].firstarc;
        while(p!=NULL){
            if(visit[p->adjvex]==0){
                rear=(rear+1)%maxSize;
                que[rear]=p->adjvex;
                visit[p->adjvex]=1;
            }
            p=p->nextarc;
        }
    }
    return 0;
}
//输出顶点Vi到顶点Vj的所有简单路径
void FindPath(AGraph *G,int u,int v,int path[],int d){
    int w,i;
    ArcNode *p;
    d++;
    path[d]=u;
    visited[u]=1;
    if(u==v)
        print(PATH[]);
    P=g->adjlist[u].firstarc;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w]==0)
            FindPath(G,w,v,path,d);
            p=p->nextarc;
    }
    visited[u]=0;
}
//输出图G中从顶点vi到vj的长度为L的所有简单路径
int visited[Vnum],A[Vnum];
void dfs1(graph *g,int vi,int vj,int L,int d){
    int v,i;
    arcnode *p;
    visited[vi]=1;
    d++;
    if(vi==vj&&d==L){
        cout<<"一条路径:";
        for(i=0;i<=d;i++)
            cout<<A[i]<<" ";
    }
    p=g->adjlist[vi].firstarc;
    while(p!=NULL){
        v=p->adjvex;
        if(visited[v]==0)
            dfs(g,v,vj,L,d);
        p=p->nextarc;
    }
    visited[vi]=0;
    --d;
}
//不带权无向连通图中距离顶点v最远的一个顶点
int BFS(AGraph *G,int v){
    ArcNode *p;
    int que[maxSize],front,rear;
    int visit[maxSize];
    int i,j;
    for(i=0;i<G->n;++i){
        visit[i]=0;
    }
    rear=(rear+1)%maxSize;
    que[rear]=v;
    visit[v]=1;
    while(front!=rear){
        front=(front+1)%maxSize;
        j=que[front];
        p=G->adjlist[j].firstarc;
        while(p!=NULL){
            if(visit[p->adjvex]==0){
                visit[p->adjvex]=1;
                rear=(rear+1)%maxSize;
                que[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
    return j;
}
//r到每个结点都有路径可达，则为根，求根
int visit[maxSize],sum;
void DFS(AGraph *G,int v){
    ArcNode *p;
    visit[v]=1;
    ++sum;
    p=G->adjlist[v].firstarc;
    while(p!=NULL){
        if(visit[p->adjvex]==0){
            DFS(G,p->adjvex);
        }
        p=p->next;
    }
}
void print(AGraph *G){
    int i,j;
    for(i=0;i<G->n;++i){
        visit[j]=0;
    }
    DFS(G,i);
    if(sum==G->n)
        cout<<i<<endl;
}
//以邻接表为存储结构的图的深度优先搜索DFS算法的非递归算法
void DFS1(AGrph *g,int v){
    ArcNode *p;
    int stack[maxSize],top=-1;
    int i,k;
    int visit[maxSize];
    for(i=0;i<g->n;++i){
        visit[i]=0;
    }
    Visit(v);
    visit[v]=0;
    stack[++top]=v;
    while(top!=-1){
        k=stack[top];
        p=g->adjlist[k].firstarc;
        while(p!=NULL&&visit[p->adjvex]==1)
            p=p->nextarc;
        if(p==NULL)
            --top;
        else{
            Visit(p->adjvex);
            visit[p->adjvex]=1;
            stack[++top]=p->adjvex;
        }
    }
}
