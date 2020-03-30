//三元组存储稀疏矩阵
typedef struct{
    int val;
    int i,j;
}Trimat;
Trimat trimat[maxterms+1];
//简洁定义
int trimax[maxterms+1][3];
//给定稀疏矩阵，建立对应的三元组存储
void createtrimat(float A[][maxSize],int m,int n,float B[][3]){
    int k=1;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(A[i][k]!=0){
                B[k][0]=A[i][j];
                B[k][1]=i;
                B[k][2]=j;
                ++k;
            }
        }
    }
    B[0][0]=k-1;
    B[0][1]=m;
    B[0][2]=n;
}
//打印
void print(float B[][3]){
    int k=1;
    for(int i=0;i<B[0][1];++i){
        for(int j=0;j<B[0][2];++j){
            if(i==(int)B[k][1]&&j==(int)B[k][2]){
                cout<<B[k][0]<<" ";
                ++k;
            }
            else 
                cout<<"0 ";
        }
    }
}
//十字链表
//普通结点结构定义
typedef struct OLNode{
    int row,col;
    struct OLNode *right,*down;
    float val;
}OLNode;
//头结点结构定义
typedef struct{
    OLNode *rhead,*chead;
    int m,n,k;
}CrossList;
//建立十字链表
int createcrosslist(flota A[][maxSize],int m,int n,int k,CrossList &M){
    if(M.rhead)
        free(M.rhead);
    if(M.chead)
        free(M.chead);
    M.m=m;
    M.n=n;
    M.k=k;
    if(!(M.rhead=(OLNode*)malloc(sizeof(OLNode)*m)))
        return 0;
    if(!(M.chead=(OLNode*)malloc(sizeof(OLNode)*m)))
        return 0;
    for(int i=0;i<m;++i){
        M.rhead[i].right=NULL;
        M.rhead[i].down=NULL;
    }
    for(int i=0;i<n;++i){
        M.chead[i].right=NULL;
        M.rhead[i].down=NULL;
    }
    OLNode *temp_r[maxsize];//建立列链表的辅助指针数组
    for(int j=0;j<n;++j){
        temp_r[j]=&(M.chead[j]);
    }
    for(int i=0;i<m;++i){
        OLNode *c=&(M.rhead[i]);
        for(int j=0;j<n;++j){
            if(A[i][j]!=0){
                OLNode *p=(OLNode)malloc(sizeof(OLNode));
                p->row=i;
                p->col=j;
                p->cal=A[i][j];
                p->down=NULL;
                p->right=NULL;
                c->right=p;
                c=p;
                temp_r[j]->down=p;
                temp_r[j]=p;
            }
        }
    }
    return 1;
}
//三元组矩阵转置
void transpose(int A[][],int B[][3]){
    int p,q,col;
    B[0][0]=A[0][0];
    B[0][1]=A[0][2];
    B[0][2]=A[0][1];
    if(B[0][0]>0){
        q=1;
        for(col=0;col<B[0][1];col++){
            foe(p=1;p<=B[0][0];++col){
                if(A[p][2]==col){
                    B[q][0]=A[p][0];
                    B[q][1]=A[p][2];
                    B[q][2]=A[p][1];
                    ++q;
                }
            }
        }
    }
}
//三元组矩阵相加
void add(int A[][3],int B[][3],int C[][3]){
    int i=1,j=1,k=1,m;
    while(i<=A[0][0]&&j<=B[0][0]){
        if(A[i][1]==B[j][1]){
            if(A[i][2]<B[j][2]){
                C[k][0]=A[i][0];
                C[k][1]=A[i][1];
                C[k][2]=A[i][2];
                ++k;
                ++i;
            }
            else if(A[i][2]>B[j][2]){
                C[k][0]=B[j][0];
                C[k][1]=B[j][1];
                C[k][2]=B[j][2];
                ++k;
                ++j;
            }
            else{
                m=A[i][0]+B[j][0];
                if(m!=0){
                    C[k][1]=B[j][1];
                    C[k][2]=B[j][2];
                    C[k][0]=m;
                    ++k;
                }
                ++i;
                ++j;
            }
        }
        else if(A[i][1]<B[j][1]){
            C[k][0]=A[i][0];
            C[k][1]=A[i][1];
            C[k][2]=A[i][2];
            ++k;
            ++i;
        }
        else{
            C[k][0]=B[j][0];
            C[k][1]=B[j][1];
            C[k][2]=B[j][2];
            ++k;
            ++j;
        }
    }
    while(i<=A[0][0]){
        C[k][0]=A[i][0];
        C[k][1]=A[i][1];
        C[k][2]=A[i][2];
        ++k;
        ++i;
    }
    while(j<=B[0][0]){
        C[k][0]=B[j][0];
        C[k][1]=B[j][1];
        C[k][2]=B[j][2];
        ++k;
        ++j;
    }
    C[0][0]=k-1;
    C[0][1]=A[0][1];
    C[0][2]=A[0][2];
}
//三元组矩阵相乘
int getvalue(int D[][maxsize],int i,int j){
    int k=1;
    while(k<=D[0][0]&&(D[k][i]!=i||D[k][2]!=j))
        k++:
    if(k<=D[0][0])
        return D[k][0];
    else return 0;
}
void mul(int A[][3],int B[][3],int C[][3],int m,int n,int k){
    int i,j,l,p=1,s;
    for(i=0;i<m;++i){
        foe(j=0;j<k;++j){
            s=0;
            for(l=0;l<n;++l)
                s+=getvalue(A,i,l)*getvalue(B,l,j);
            if(s!=0){
                C[p][1]=i;
                C]p][2]=j;
                C[p][0]=s;
                ++p;
            }
        }
    }
    c[0][1]=m;
    c[0][2]=k;
    c[0][0]=p-1;
}
