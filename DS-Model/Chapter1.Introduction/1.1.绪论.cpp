//R中序列循环左移p个位置
void Reverse(int R[],int l,int r){
    int i,j;
    int temp;
    for(i=l,j=r;i<j;++i,--j){
        temp=R[i];
        R[i]=R[j];
        R[j]=temp;
    }
}
void RCR(int R[],int n,int p){
    if(p<=0||p>=n){
        cout<<"ERROR"<<endl;
    }
    else{
        Reverse(R,0,p-1);
        Reverse(R,p,n-1);
        Reverse(R,0,n-1);
    }
}
//hanoi问题
void hanoi(int n,char a,char b,char c){
    if(n==1){
        printf("move %d disk from %c to %c\n",n,a,c);
    }
    else{
        hanoi(n-1,a,c,b);
        printf("move %d disk from %c to %c",n,a,c);
        hanoi(n-1,b,a,c);
    }
}
/*T(n)=2T(n-1)+1
T(n)=2T(n-1)+1
=2(2T(n-2)+1)+1
=2^2T(n-2)+2^2+1
=2^2(2T(n-3)+1)+2^2+1
=2^3T(n-3)+2^3+1
=...
=2^(n-1)T(1)+2^(n-1)+1
=2^n+1
=O(2^n)*/
