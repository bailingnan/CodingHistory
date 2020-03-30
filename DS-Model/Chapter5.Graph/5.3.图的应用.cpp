//所有权值均不相等，或者有相等的边，但是在构造最小生成树的过程中权值相等的边都被
//并入生成树的图，其最小生成树唯一。
//最小生成树
//Prim算法,O(v^2),边稠密图
//王道
void Prim(MGraph g,int v0,int &sum){
    int lowcost[MAXSIZE],vset[MAXSIZE],v;
    int i,j,k,min;
    v=v0;
    for(i-0;i<g.n;++i){
        lowcost[i]=g.edges[v0][i];
        vset[i]=0;
    }
    vset[v0]=1;
    sum=0;
    for(i=0;i<g.n-1;++i){
        min=INF;
        for(j=0;j<g.n;++j){
            if(vset[j]==0&&lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
        }
        vset[k]=1;
        v=k;
        sum+=min;
        for(j=0;j<g.n;j++){
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])
            lowcost[j]=g.edges[v][j];
        }
    }
}
//天勤
void prim(int n,float MGraph[][n],int v0,float &sum){
    int lowCost[n],vSet[n];
    int v,k,min;
    for(int i=0;i<n;i++){
        lowCost[i]=MGraph[v0][i];
        vSet[i]=0;
    }
    v=v0;
    vSet[v]=1;
    sum=0;
    for(int i=0;i<n-1;i++){
        min=INF;
        for(int j=0;j<n;j++){
            if(vSet[j]==0&&lowCost[j]<min){
                min=lowCost[j];
                k=j;
            }
        }
        vSet[k]=1;
        v=k;
        sum+=min;
        for(int j=0;j<n;j++){
            if(vSet[j]==0&&MGraph[v][j]<lowCost[j]){
                lowCost[j]=MGraph[v][j];
            }
        }
    }
}
//Kruskal算法,O(ElogE),边稀疏图
//王道
//双亲表示法，road[]数组存放了图中各边及其所连接的两个顶点的信息，sort对E条边按从小到大排序
typedef struct{
    int a,b;
    int w;
}Road;
Road road[MAXSIZE];
int v[MAXSZIE];
int getRoot(int a){
    while(a!=v[a]) a=v[a];
    return a;
}
void Kruskal(MGraph Gg,int &sum,Road road[]){
    int i;
    int N,E,a,b;
    N=g.n;
    E=g.e;
    sum=0;
    for(int i=0;i<N;++i) v[i]=i;
    sort(road,E);
    for(i=0;i<E;++i){
        a=getRoot(road[i].a);
        b=getRoot(road[i].b);
        if(a!=b){
            v[a]=b;
            sum+=road[i].w;
        }
    }
}
//天勤
typedef struct {
    int a,b;
    int w;
}Road;
Road road[maxSize];
int getRoot(int p){
    while(p!=v[p]){
        p=v[p];
    }
    return p;
}
void Kruskal(Road road[],int n,int e,int &sum){
    int a,b;
    sum=0;
    for(int i=0;i<n;i++){
        v[i]=i;
    }
    sort(road,e);
    for(int i=0;i<e;i++){
        a=getRoot(road[i].a);
        b=getRoot(road[i].b);
        if(a!=b){
            v[a]=b;
            sum+=road[i].w;
        }
    }
}
//最短路径，Dijkstra算法，O(n^2)
//王道
void printPath(int path[],int a){
    int stack[MAXSIZE],top=-1;
    while(stack[a]!=-1){
        stack[++top]=a;
        a=path[a];
    }
    stack[++top]=a;
    while(top!=-1)
        printf("%d",stack[top--]);
}
void Dijkstra(MGraph g,int v,int dist[],int path[]){
    int set[MAXSIZE];
    int min,i,j,u;
    for(i=0;i<g.n;++i){//数组初始化
        dist[i]=g.edges[v][i];
        set[i]=0;
        if(g.edges[v][i]<INF)
            path[i]=v;
        else path[i]=-1;
    }
    set[v]=1;
    path[v]=-1;
    for(int i=0;i<g.n-1;++i){
        min=INF;
        for(j=0;j<g.n;++j){
            if(set[j]==0&&dist[j]<min){
                u=j;
                min=dist[j];
            }
        }
    }
    set[u]=1;
    for(j=0;j<g.n;++j){
        if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j]){
            dist[j]=dist[u]+g.edges[u][j];
            path[j]=u;
        }
    }
}
//Floyd算法，O(n^3)
void printPath(int u,int v,int path[][max]){
    if(path[u][v]==-1)
        print();
    else{
        int mid=payh[u][v];
        printPath(u,mid,path);
        printPath(mid,v,path);
    }
}
void Floyd(MGraph G,int Path[][MAXSIZE]){
    int i,j,k;
    int A[MAXSIZE][maxsize];
    for(i=0;i<g.n;++i){
        for(j=0;j<g.n;++j){
            A[i][j]=g.edges[i][j];
            Path[i][j]=-1;
        }
    }
    for(k=0;k<g.n;++k){
        for(i=0;i<g.n;++i){
            for(j=0;j<g.n;++j){
                if(A[i][j]>A[i][k]+A[k][j]){
                    A[i][j]=A[i][k]+A[k][j];
                    Path[i][j]=k;
                }
            }
        }
    }
}
//拓扑排序，O(V+E)
bool TopologicalSort(Graph G){//王道版本
    InitStack(S);
    for(int i=0;i<G.vexnum;++i){
        if(indegree[i]==0){
            Push(S,i);
        }
    }
    int count=0;
    while(!IsEmpty(S)){
        Pop(S,i);
        printf[count++]=i;
        for(p=G.vertices[i].firstarc;p;p=p->nextarc){
            v=p->adjvex;
            if(!(--indegree[v]))
                Push(S,v);
        }
    }
    if(count<G.vexnum)
        return false;
    else return true;
}
typedef struct{//天勤版本
    char data;
    int count;
    ArcNode *firstarc;
}VNode;
int TopSort(AGraph *G){
    int i,j,n=0;
    int stack[MAXSIZE],top=-1;
    ArcNode *p;
    for(i=0;i<G->n;++i){
        if(G->adjlist[i].count==0)
            stack[++top]=i;
    }
    while(top!=-1){
        i=stack[top--];
        ++n;
        count<<i<<" ";
        p=G.adjlist[i].firstarc;
        while(p!=NULL){
            j=p->adjvex;
            --(G->adjlist[i].count);
            if(G->adjlist[j].count==0)
                stack[++top]=j;
            p=p->nextarc;
        }
        if(n==G->n)
            return 1;
        else return 0;
    }
}
//深度优先遍历实现拓扑排序
bool visited[MAX_VERTEX_NUM];
void DFSTraverse(Graph G){
    for(v=0;v<G.vexnum;++v){
        visited[v]=false;
    }
    time=0;
    for(v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}
void DFS(Graph G,int v){
    visited[v]=true;
    visit(v);
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w]){
            DFS(G,w);
        }
    time=time+1;
    finishTime[v]=time;
}
//深度优先遍历实现逆拓扑排序
void DFS(int v,AGraph *G){
    visit[v]=1;
    ArcNode *q=G->adjList[v].first;
    while(q!=NULL){
        if(visit[q->adjV]==0)
            DFS(q->adjV,G);
        q=q->next;
    }
    Visit(v);
}
