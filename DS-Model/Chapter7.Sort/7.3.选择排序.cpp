//简单选择排序,o(n^2)
//王道
void SelectSort(ElemType A[],int n){
    for(i=0;i<n-1;++i){
        min=i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i) swap(A[i],A[min]);
    }
}
//天勤
void selectSort(int arr[],int n){
    int i,j,k;
    int temp;
    for(i=0;i<n;i++){
        k=i;
        for(j=i+1;j<n;++j){
            if(arr[k]>arr[j])
                k=j;
        }
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}
//堆排序,O(nlogn)
void Sift(int R[],int low,int high){//天勤版本
    int i=low,j=2*i;
    int temp=R[i];
    while(j<=high){
        if(j<high&&R[j]<R[j+1]){
            ++j;
        }
        if(temp<R[j]){
            R[i]=R[j];
            i=j;
            j=j*2;
        }
        else break;
    }
    R[i]=temp;
}
void heapSort(int R[],int n){
    int i,temp;
    for(i=n/2;i>=1;--i){
        Sift(R,i,n);
    }
    for(i=n;i>=2;--i){
        temp=R[1];
        R[1]=R[i];
        R[i]=temp;
        Sift(R,1,i-1);
    }
}
void BuildMaxHeap(ElemType A[],int len){//王道版本
    for(int i=len/2;i>0;--i){
        AdjustDown(A,i,len);
    }
}
void AdjustDown(ElemType A[],int k,int len){
    A[0]=A[k];
    for(i=2*k;i<=len;i*=2){
        if(i<len&&A[i]<A[i+1])
            ++i;
        if(A[0]>=A[i]) break;
        else{
            A[k]=A[i];
            k=i;
        }
    }
    A[k]=A[0];
}
void HeapSort(ElemType A[],int len){
    BuildMaxHeap(A,len);
    for(i=len;i>1;i--){
        swap(A[i],A[1]);
        AdjustDown(A,1,i-1);
    }
}
//插入结点后向上调整堆
void AdjustUPp(ElemType A[],int k){
    A[0]=A[k];
    int i=k/2;
    while(i>0&&A[i]<A[0]){
        A[k]=A[i];
        k=i;
        i=k/2;
    }
    A[k]=A[0];
}
//判断是否为小顶堆
bool IsMinHeap(ElemType A[],int len){
    if(len%2==0){
        if(A]len/2]>A[len])
            return false;
        for(i=len/2-1;i>=1;--i){
            if(A[i]>A[2*i]||A[i]>A[2*i+1])
                return false;
        }
    }
    else{
        for(i=len/2;i>=1;--i){
            if(A[i]>A[2*i]||A[i]>A[2*i+1])
                return false;
        }
    }
    return true;
}
//链表上的简单选择排序
void SelectSort(LinkedList& L){
    LinkNode *h=L,*p,*q,*r,*s;
    L=NULL; 
    while(h!=NULL){
        p=s=h;q=r=NULL;
        while(p!=NULL){
            if(p->data>s->data) {
                s=p;
                r=q;
            }
            q=p;
            p=p->link;
        }
    if(s==h)
        h=h->link;
    else 
        r->link=s->link;
    s->link=L;
    L=s;
    }
}
