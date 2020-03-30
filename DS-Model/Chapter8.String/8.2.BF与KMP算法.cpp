//BF算法
int BF(Str str,Str substr){
    int i=1,j=1,k=i;
    while(i<=str.length&&j<=substr.length){
        if(str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=1;
            i=++k;
        }
    }
    if(j>substr.length)
        return k;
    else return 0;
}
//KMP算法
void getNext(Str substr,int next[]){
    int j=1,t=0;
    next[1]=0;
    while(j<substr.length){
        if(t==0||substr.ch[j]==substr.ch[t]){
            next[j+1]=t+1;
            ++t;
            ++j;
        }
        else{
            t=next[t];
        }
    }
}
int KMP(Str str,Str substr,int next[]){
    int i=1,j=1;
    while(i<=str.length&&j<=substr.length){
        if(j==0||str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];
        }
    }
    if(j>substr.length)
        return i-substr.length;
    else return 0;
}
//改进的KMP算法
void getNextval(Str substr,int nextval[]){
    int j=1,t=0;
    nextval[1]=0;
    while(j<substr.length){
        if(t==0||substr.ch[j]==substr.ch[t]){
            if(substr.ch[j+1]!substr.ch[t+1])
                nextval[j+1]=t+1;
            else 
                nextval[j+1]=nextval[t+1];
            ++j;
            ++t;
        }
        else{
            t=nextval[t];
        }
    }
}
