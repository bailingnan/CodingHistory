//归并排序,O(nlogn)
//王道
void MergeSort(ElemType A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mi,high);
    }
}
ElemType *B=(ElemType*)malloc((n+1)sizeof(ElemType));
void Merge(ElemType A[],int low,int mid,int high){
    for(int k=low;k<=high;++k){
        B[k]=A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;++k){
        if(B[i]<=B[j]) A[k]=B[i++];
        else A[k]=B[++j];
    }
    while(i<=mid) A[k++]=B[i++];
    while(j<high) A[k++]=B[j++];
}
//天勤
void merge(int arr[],int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[low+1];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1&&j<n2){
        if(L[i]<=R[j])
            arr[k]=L[i++];
        else 
            arr[k]=R[j++];
        k++;
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(high+low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,low+1,high);
        merge(arr,low,mid,high);
    }
}
