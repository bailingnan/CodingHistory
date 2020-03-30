//冒泡排序,O(n^2)
//王道
void BubbleSort(ElemType A[],int n){
    for(i=0;i<n-1;++i){
        flag=false;
        for(j=n-1;j>i;--j){
            if(A[j-1].key>A[j].key){
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if(flag==false) return;
    }
}
//天勤
void BubbleSort(int R[],int n){
    int i,j,flag;
    int temp;
    for(i=n-1;i>=1;--i){
        flag=0;
        for(j=1;j<=i;++j){
            if(R[j-1]>R[j]){
                temp=R[j];
                R[j]=R[j-1];
                R[j-1]=temp;
                flag=1;
            }
        }
        if(flag==0) return;
    }
}
//快速排序,O(nlogn)
void QuickSort(ElemType A[],int low,int high){//王道
    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}
int Partition(ElemType A[],int low,int high){
    ElemType pivot=A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high&&A[low]<pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int R[],int low,int high){//天勤
    int temp;
    int i=low,j=high;
    if(low<high){
        temp=R[low];
        while(i<j){
            while(i<j&&R[j]>=temp) --j;
            if(i<j){
                R[i]=R[j];
                ++i;
            }
            while(i<j&&R[i]<temp) ++i;
            if(i<j){
                R[j]=R[i];
                --j;
            }
        }
        R[i]=temp;
        QuickSort(R,low,i-1);
        QuickSort(R,i+1,high);
    }
}
//非递归算法
void quickSortNonrecursion(int arr[],int n){
    int i,low,high;
    int stack[maxSize][2],top=-1;
    low=0,high=n-1;
    ++top;
    stack[top][0]=low;
    stack[top][1]=high;
    while(top>=0){
        low=stack[top][0];
        high=stack[top[1];
        --top;
        partition(arr,low,high,i);
        if(low<high){
            ++top;
            stack[top][0]=low;
            stack[top][1]=i-1;
            ++top;
            stack[top][0]=i+1;
            stack[top][1]=high;
        }
    }
}
//双向起泡
void BubbleSort(ElemType A[],int n){
    int low=0,high=n-1;
    bool flag=true;
    while(low<high&&flag){
        flag=false;
        for(i=low;i<high;++i){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
        high--;
        for(i=high;i>low;--i){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=true;
            }
        }
        low++;
    }
}
//所有奇数放到偶数前边
void move(ElemType A[],int len){
    int i=0,j=len-1;
    while(i<j){
        while(i<j&&A[i]%2!=0) ++i;
        while(i<j&&A[j]%2!=1) --j;
        if(i<j){
            swap(A[i],A[j]);
            ++i;
            --j;
        }
    }
}
//寻找第k小的元素
//eg1
int kth_elem(int a[],int low,int high,int k){
    int pivot=a[low];
    int low_temp=low,high_temp=high;
    while(low<high){
        while(low<high&&a[high]>=pivot) --high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) ++low;
        a[high]=a[low];
    }
    a[low]=pivot;
    if(low==k) return a[low];
    else if(low>k)
        return kth_elem(a,low_temp,low-1,k);
    else return kth_elem(a,low+1,high_temp,k-low);
}
//eg2
int getPos(int arr[],int n,int k){
    int i=0,j=n-1;
    int temp;
    while(i<=j){
        while(i<n&&arr[i]<=k) ++i;
        while(j>=0&&arr[j]>k) --j;
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            ++i;
            --j;
        } 
    }
    return j+1;
}
//红白蓝排序
typedef enum{RED,WHITE,BLUE} color;
void Flag_Arrange(color a[],int n){
    int i=0,j=0,k=n-1;
    while(j<=k){
        switch(a[j]){
            case RED:swap(a[i],a[j]);++i;++j;break;
            case WHITE:j++;break;
            case BLUE:swap(a[j],a[k]);k--;
        }
    }
}
//划分两个不相交子集：S1,S2,|n1-n2|最小且|S1-S2|最大
int setPartition(int a[],int n){
    int pivotkey,low=0,low0=0,high=n-1,high0=n-1,falg=1,k=n/2,i;
    int s1=0,s2=0;
    while(flag){
        pivotkey=a[low];
        while(low<high){
            while(low<high&&a[high>=povitkey) --high;
            if(low!=high) a[low]=a[high];
            while(low<high&&a[low]<=pivotkey) ++low;
            if(low!=high) a[high]=a[low];
        }
    }
    a[low]=pivotkey;
    if(low==k-1) flag=0;
    else{
        if(low<k-1){
            low0=++low;
            high=high0;
        }
        else{
            high0=--high;
            low=low0;
        }
    }
    for(i=0;i<k;i++) s1+=a[i];
    for(i=k;i<n;i++) s2+=a[i];
    return s2-s1;
}
