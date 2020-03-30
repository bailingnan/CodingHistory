//直接插入排序,O(n^2)
//王道
void InsertSort(ElemType A[],int n){
    int i,j;
    for(i=2;i<=n;++i){
        if(A[i].key<A[i-1].key){
            A[0]=A[i];
            for(j=i-1;A[0].key<A[j].key;--j){
                A[j+1]=A[j];
            }
            A[j+1]=A[0];
        }
    }
}
//天勤
void InsertSort(int R[],int n){
    int i,j,temp;
    for(i=1;i<n;++i){
        temp=R[i];
        for(j=i-1;j>=0&&temp<R[j];--j){
            R[j+1]=R[j];
        }
        R[j+1]=temp;
    }
}
//折半插入排序
void InsertSort(ElemType A[],int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;++i){
        A[0]=A[i];
        low=1;
        high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(A[mid].key>A[0].key)
                high=mid-1;
            else low=mid+1;
        }
        for(j=i-1;j>=high+1;++j){
            A[j+1]=A[j];
        }
        A[high+1]=A[0];
    }
}
//希尔排序
//王道
void ShellSort(ElemType A[],int n){
    for(dk=n/2;dk>=1;dk/=2){
        for(i=dk+1;i<=n;++i){
            if(A[i].key<A[i-dk].key){
                A[0]=A[i];
                for(j=i-dk;j>0&&A[0].key<A[j].key;j-=dk){
                    A[j+dk]=A[j];
                }
                A[j+dk]=A[0];
            }
        }
    }
}
//天勤
//王道
void shellSort(int arr[],int n){
    int temp;
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            temp=arr[i];
            int j;
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
//链表进行插入排序
void CreateLink(LNode *&h,char R[],int n){
    int i;
    LNode *s,*t;
    h=(LNode*)malloc(sizeof(LNode));
    h->next=NULL;
    t=h;
    for(i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=R[i];
        t->next=s;
        t=s;
    }
    t->next=NULL;
}
void Sort(LNode *h){
    LNode *p,*p1,*q,*pre;
    if(h->next!=NULL){
        p=h->next->next;
        h->next->next=NULL;
        while(p!=NULL){
            pre=h;
            q=pre->next;
            while(q!=NULL&&q->data<p->data){
                pre=q;
                q=q->next;
            }
            p1=p->next;
            p->next=pre->next;
            pre->next=p;
            p=p1;
        }
    }
}
