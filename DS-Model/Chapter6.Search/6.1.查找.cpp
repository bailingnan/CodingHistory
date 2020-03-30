//顺序查找
typedef struct{//王道版本
    ElemType *elem;//0号单元留空
    int TableLen;
}SSTable;
int Search_Seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//哨兵
    for(int i=ST.TableLen;ST.elem[i]!=key;--i);
    return i;
}
//天勤版本
int Search(int a[],int n,int k){
    for(int i=1;i<=n;++i){
        if(a[i]==k){
            return i;
        }
    }
    return 0;
}
//二分查找,ASL=log(n+1)-1;
int Binary_Search(SeqList L,ElemType key){//王道版本
    int low=0,high=L.TableLen-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(L.elem[mid]==key)
        return mid;
        else if(L.elem[mid]>key)
            high=mid-1;
        else low=mid+1;
    }
    return -1;
}
//递归版本
int BinSearchRec(SSTable ST,ElemType key,int low,int high){
    if(low>high)
        return 0;
    int mid=(low+high)/2;
    if(key>St.elem[mid])
        BinSearchRec(ST,key,mid+1,high);
    else if(key<ST.elem[mid])
        BinSearchRec(ST,key,low,mid-1);
    else return mid;
}
int Bsearch(int R[],int low,int high,int k){//下标从1开始存储
    int mid;
    while(low<=high){
        mid=(high+low)/2;
        if(R[mid]==k)
            return mid;
        else if(R[mid]>k)
            high=mid-1;
        else low=mid+1;
    }
    return 0;
}
//天勤
int BSearch(int arr[],int low,int high,int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return key;
        else if(arr[mid]>key)
            high=mid-1;
        else 
            low=mid+1;
    }
    return -1;
}
//分块查找
typedef struct{
    int key;
    int low,high;
}indexElem;
indexElem index[MAXSIZE];
//链地址法构造散列表
typedef struct HNode{
    int key;
    struct HNode *next;
}HNode;
HNode ht[maxSize];
int x[]={数组元素};
void chash(HNode ht[],int x[],int n){
    HNode *p;
    for(int i=0;i<maxSize;++i){
        ht[i].next=NULL;
    }
    for(int i=0;i<n;++i){
        p=(HNode*)malloc(sizeof(HNode));
        p->key=x[i];
        int j=(x[i])%maxSize;//散列函数
        p->key=x[i];
        p->next=ht[j].next;
        ht[j].next=p;
    }
}
//二分查找法插入元素k
void binInsert(int A[],int k,int n){
    int low=0,high=n-1,mid;
    int inplace,find=0;
    while(low<=high&&find==0){
        mid=(low+high)/2;
        if(k<A[mid])
            high=mid-1;
        else if(k>A[mid])
            low=mid+1;
        else find=1;
    }
    if(find)
        inplace=mid;
    else
        inplace=low;
    for(int i=n-1;i>=inplace;--i){
        A[i+1]=A[i];
    }
    A[inpalce]=k;
}
