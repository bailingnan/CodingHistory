//基本操作
//王道
//顺序表
#define MaxSize 50
typedef struct{
    ElemType data[Maxsize];
    int length;
}SqList;
#define InitSize 100
typedef struct{
    ElemType *data;
    int Maxsize,length;
}SeqList;
//C
L.data=(ElemType*)malloc(sizeof(ElemType)*InitSize);
//C++
L.data=new ElemType[InitSize];
//插入操作，在第i(1≤i≤L.length+1)个位置插入新元素e
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L,length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除操作，删除顺序表L中第i(1≤i≤L.length)个位置的元素
bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
    }
}
//按值查找
int LocateElem(SqList L,ElemType e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e)
            return i+1;
    return 0;
    }
}
//天勤
//结构体定义
#define maxSize 100;
typedef struct{
    int data[maxSize];
    int length;
}Sqlist;
//简洁定义
int A[maxSize];
int n;
//有序表插入x
//第一步：返回第一个比x大的元素的位置
int findElem(Sqlist L,int x){
    int i;
    for(i=0;i<L.length;++i){
        if(x<L.data[i]){
            return i;
        }
    }
    return i;
}
//第二步：移动和插入元素
void insertElem(Sqlist &L,int x){
    int p,i;
    p=findElem(L,x);
    for(i=L.length-1;i>=p;--i){
        L.data[i+1]=L.data[i];
    }
    L.data[p]=x;
    ++(L.length);
}
//按元素值查找
int findElem(Sqlist L.int e){
    int i;
    for(i=0;i<L.length;++i){
        if(e==L.data[i]){
            return i;
        }
    }
    return -1;
}
//第p(0≤p≤length)个位置上插入新元素e
int insertElem(Sqlist &L,int p,int e){
    int i;
    if(p<0||p>L.length||L.length==maxSize)
        return 0;
    for(i=L.length-1;i>=p;--i){
        L.data[i+1]=L.data[i];
    }
    L.data[p]=e;
    ++(L.length);
    return 1;
}
//删除下标为p(0≤p≤length-1)
int deleteElem(Sqlist &L,int p,int &e){
    int i;
    if(p<0||p>L.length-1)
        return 0;
    e=L.data[p];
    for(i=p;i<L.length-1;++i){
        L.data[i]=L.data[i+1];
    }
    --(L.length);
    return 1;
}
//初始化
void initList(Sqlist &L){
    L.length=0;
}
//求指定位置元素
int getElem(Sqlist;int p,int &e){
    if(p<0||p>L.length-1)
        return 0;
    e=L.data[p];
    return 1;
}
//习题
//删除顺序表中所有值为x的元素
//eg1
void del_x_1(SqList &L,ElemType x){
    int k=0;
    for(i=0;i<L.length;i++){
        if(L.data[i]=!=x){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
}
//eg2
void_del_x_2(SqList &L,ElemType x){
    int k=0,i=0;
    while(i<L.length){
        if(L.data[i]==x){
            k++;
        }
        else{
            L.data[i-k]=L.data[i];
        }
        i++;
    }
    L.length=L.length-k;
}
//有序表中删除给定值在s与t之间的元素
bool Del_s_t2(SqList &L,ElemType s,ElemType t){
    int i,j;
    if(s>=t||L.length==0)
        return false;
    for(i=0;i<L.length&&L.data[i]<s;i++);
    if(i>=L.length) return false;
    for(j=i;j<L.length&&L.data[j]<=t;j++);
    for(;j<L.length;i++,j++){
        L.data[i]=L.data[j];
    }
    L.length=i+1;
    return true;
}
//删除下标i~j的所有元素
void delete(Sqlist &L,int i,int j){
    int k,delta;
    delta=j-i+1;
    for(k=j+1;k<L.length;++k){
        L.data[k-delata]=L.data[k];
    }
    L.length-=delta;
}
//顺序表中删除给定值在s与t之间的元素
bool Del_s_t(SqList &L,ElemType s,ElemType t){
    int i,k=0;
    if(L.length==0||s>=t)
        return false;
    for(i=0;i<L.length;i++){
        if(L.data[i]>=s&&L.data[i]<=t)
            k++;
        else
        L.data[i-k]=L.data[i];
    }
    L.length-=k;
    return true;
}
//有序表删除所有值重复的元素
bool Delete_Same(SeqList &L){
    if(L.length==0)
        return false;
    int i,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j])
            L.data[++i]=L.data[j];
    }
    L.length=i+1;
    return true;
}
//两个有序顺序表合并成新的有序顺序表
bool Merge(SeqList A,SeqList B,SeqList &C){
    if(A.length+B.length>C.maxSize)
        return false;
        int i=0,j=0,k=0;
        while(i<A.length&&j<B.length){
            if(A.data[i]<=B.data){
                C.data[k++]=A.data[i++];
            }
            else 
                C.data[k++]=B.data[j++];
        }
        while(i<A.length)
            C.data[k++]=A.data[i++];
        while(j<B.length)
            C.data[k++]=B.data[j++];
        C.length=k;
        return true;
}
//两有序表合并，不另设新的顺序表存储空间
int comb(int A[],int &na,int B[],int nb){
    if(na+nb>maxSize){
        return -1;
    }
    int i=na,j=nb;
    while(j>0){
        if(i==0||A[i-1]<B[j-1]){
            A[i+j-1]=B[j-1];
            j--;
        }
        else{
            A[j+i-1]=A[i-1];
            --i;
        }
    }
    na=na+nb;
    return na;
}
//一维数组中线性表am和bn互换
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
    if(left>=right||right>=arraySize){
        return;
    }
    int mid=(left+right)/2;
    for(int i=0;i<mid=mid-left);i++){
        DataType temp=A[left+i];
        A[left+i]=A[right-i];
        A[right-i]=temp;
    }
}
void Exchange(DataType A[],int m,int n,int arraySize){
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-1,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}
//有序表查找x，找到与后一个元素交换，找不到则插入
void SearchExchangeInsert(ElemType A[],ElemType x){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(A[mid]==x) break;
        else if(A[mid]<x) low=mid+1;
        else high=mid-1;
    }
    if(A[mid]==x&&mid!=n-1){
        int t=A[mid];
        A[mid]=A[mid+1];
        A[mid+1]=t;
    }
    if(low>high){
        for(i=n-1;i>hihg;i++)
            A[i+1]=A[i];
        A[i+1]=x;
    }
}
//寻找主元素
int Majority(int A[],int n){
    int i,c,count=1;
    c=A[0];
    for(i=1;i<n;i++){
        if(A[i]==c)
            count++;
        else 
            if(count>0)
                count--;
            else{
                c=A[i];
                count=1;
            }
    }
    if(count>0)
        for(i=0;i<n;i++){
            if(A[i]==c)
                count++;
        }
    if(count>n/2) return c;
    else return -1;
}
//两升序表中位数,直接排序或者用归并亦可
int M_Search(int A[], int B[], int n) 
{
	int start1 = 0, end1 = n - 1, m1, start2 = 0, end2 = n - 1, m2;
	//分别表示序列A和B的首位数、末位数和中位数
	while (start1 != end1 || start2 != end2)
	{
		m1 = (start1 + end1) / 2;
		m2 = (start2 + end2) / 2;
		if (A[m1] == B[m2])
			return A[m1];   //满足条件 1)
 
		if (A[m1]<B[m2]) // 满足条件 2)
		{  
			if ((start1 + end1) % 2 == 0)  //若元素个数为奇数
			{  
				start1 = m1;  //舍弃A中间点以前的部分且保留中间点
				end2 = m2;  //舍弃B中间点以后的部分且保留中间点
			}
			else				//元素个数为偶数
			{ 
				start1 = m1 + 1;  //舍弃A中间点及中间点以前部分
				end2 = m2;  //舍弃B中间点以后部分且保留中间点
			}
		}
		else
		{  //满足条件3)
			if ((start2 + end2) % 2 == 0)   //若元素个数为奇数
			{ 
				end1 = m1;    //舍弃A中间点以后的部分且保留中间点
				start2 = m2;    //舍弃B中间点以前的部分且保留中间点
			}
			else     //元素个数为偶数
			{  
				end1 = m1;    //舍弃A中间点以后部分且保留中间点
				start2 = m2 + 1;    //舍弃B中间点及中间点以前部分
			}
		}
	}
	return  A[start1]<B[start2] ? A[start1] : B[start2];
}
//顺序表前m和后n个元素均递增有序，使整个顺序表有序
void insertElem(int A[],int m,int n){
    int i,j;
    int temp;
    for(i=m;i<m+n;++i){
        temp=A[i];
        for(j=i-1;i>=0&&temp<A[j];--j)
            A[j+1]=A[j];
        A[j+1]=temp;
    }
}
//顺序表小于表头前半部分，大于表头的后半部分
void move(Sqlist &L){
    int temp;
    int i=0,j=L.length-1;
    temp=L.data[i];
    while(i<j){
        while(i<j&&L.data[i]>temp) --j;
        if(i<j){
            L.data[i]=L.data[j];
            ++i;
        }
        while(i<j&&L.data[i]<temp) ++i;
        if(i<j){
            L.data[j]=L.data[i];
            --j;
        }
    }
    L.data[i]=temp;
}
//1个变量i找出N个个位整数中的最小值
void findMin(int A[],int &i){
    i=A[0];
    while(i/10<=M-1){
        if(i%10>A[i/10]){
            i=i-i%10;
            i=i+A[i/10];
        }
        i=i+10;
    }
    i=i%10;
}
//比较两顺序表大小
int compare(float A[],int An,float B[],int Bn){
    int i=0;
    while(i<An&&i<Bn){
        if(fabs(A[i]-B[i])<min) ++i;
        else break;
    }
    if(i>An&&i>=Bn)
        return 0;
    else if((i>=An&&i<Bn)||A[i]<B[i])
        return -1;
    else return 1;
}
//前移数组非零元素
void Move(int A[],int n){
    int p=0;
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            if(i!=p){
                A[p]=A[i];
                A[i]=0;
            }
        }
        ++p;
    }
}
//大整数加法运算
//数据输入
int input(int A[],int &na){
    int i;
    for(i=0;i<maxSize;++i){
        A[i]=0;
    }
    std::cout<<"输入一个正整数的各位(以-1结束)"<<std::endl;
    i=0;
    while(i<maxSize){
        std::cin>>A[i];
        if(A[i]<0)
            break;
        ++i;
    }
    if(i>=maxSize)
        return 0;
    else{
        na=i;
        for(i=0;i<na;++i){
            A[maxSize-i-1]=A[na-i-1];
            A[na-i-1]=0;
        }
        return 1;
    }
}
//加法
void add(int A[],int na,int B[],int nb,int C[],int &nc){
    int i;
    for(i=0;i<maxSize;++i){
        C[i]=0;
    }
    if(na>nb)
        nc=na;
    else 
        nc=nb;
    i=maxSize-1;
    int result=0,carry=0;
    while(i>=maxSize-nc){
        result=A[i]+B[i]+carry;
        carry=result/10;
        result=result%10;
        C[i]=result;
        --i;
    }
    if(carry>0){
        if(i<0)
            std::cout<<"overflow"<<std::endl;
        else{
            C[i]=carry;
            ++nc;
        }
    }
}
//数组的第i个元素存放多项式的i次幂项的系数
typedef struct node{
    float coef[maxSize];
    int order;
}polynomial;
//多项式加法
void add(polynomial &A,polynomial &B,polynomial &C){
    int m=A.order,n=B.order;
    for(i=0;i<=m;&&i<=n;++i)
        C.coef[i]=A.coef[i]+B.coef[i];
    while(i<=m){
        C.coef[i]=A.coef[i];
        ++i;
    }
    while(i<=n){
        C.coef[i]=B.coef[i];
        ++i;
    }
    C.order=(m>n)?m:n;
}
//多项式乘法
void mul(polynomial &A,polynomial &B,polynomial &C){
    int m=A.order,n=B.order;
    if(m+n+1>maxSize){
        cout<<"error"<<endl;
        return;
    }
    for(int i=0;i<=m+n;++i){
        C.coef[i]=0.0;
    }
    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j)
            C.coef[i+j]+=A.coef[i]*B.coef[j];
    }
    C.order=m+n;
}
