//串的存储结构
//定长
typedef struct{
    char str[maxSize+1];
    int length;
}Str;
//变长
typedef struct{
    char *ch;
    int length;
}Str;
Str S;
S.length=L;
S.ch=(char*)malloc((L+1)*sizeof(char));
free(S.ch);
//串的存储结构
//定长
typedef struct{
    char str[maxSize+1];
    int length;
}Str;
//变长
typedef struct{
    char *ch;
    int length;
}Str;
Str S;
S.length=L;
S.ch=(char*)malloc((L+1)*sizeof(char));
free(S.ch);
//赋值操作
void strassign(Str& str,char *ch){
    if(str.ch)
        free(str.ch);
    int len=0;
    char *c=ch;
    while(*c){
        ++len;
        ++c;
    }
    if(len==0){
        str.ch=NULL;
        str.length=0;
        return 1;
    }
    else{
        str.ch=(char*)malloc(sizeof(char)*(len+1));//取len+1是为了分配一个空间存放"\0"字符
        if(str.ch==NULL)
            return 0;
        else{
            c=ch;
            for(int i=0;i<=len;++i,++c)//之所以用"<="是为了将ch最后的'\0'复制到新串中作为结束标记
                str.ch[i]=*c;
            str.length=len;
            return 1;
        }
    }
}
//串比较
int strcompare(Str s1,Str s2){
    for(int i=0;i<s1.length&&i<s2.length;++i){
        if(s1.ch[i]!=s2.ch[i])
            return s1.ch[i]-s2.ch[i];
        return s1.length-s2.length;
    }
}
//串连接
int concat(Str& str,Str str1,Str str2){
    if(str.ch){
        free(str.ch);
        str.ch=NULL;
    }
    str.ch(char*)malloc(sizeof(char)*(str1.length+str2.length));
    if(str.ch==NULL)
        return 0;
    int i=0;
    while(i<str1.length){
        str.ch[i]=str1.ch[i];
        ++i;
    }
    int j=0;
    while(j<=str2.length){
        str.ch[i+j]=str2.ch[j];
        ++j;
    }
    str.length=str1.length+str2.length;
    return 1;
}
//求pos位置开始，长度为len的子串
int substring(Str &str,Str str,int pos,int len){
    if(pos<0||pos>=str.length||len<0||len>str.length-pos){
        return 0;
    }
    if(substr.ch){
        free(substr.ch);
        substr.ch=NULL;
    }
    if(len==0){
        substr.ch=NULL;
        substr.length=0;
        return 1;
    }
    else{
        substr.ch=(char*)malloc(sizeof(char)*(len+1));
        int i=pos;
        int j=0;
        while(i<pos+len){
            substr.ch[j]=str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j]='\0';
        substr.length=len;
        return 1;
    }
}
//定长顺序存储表示串，编写一个函数，删除串中从下标为i的字符开始，如果第i个字符后没有足够的j个字符，则有几个删除几个
void del(Str2 &str,int i,int j){
    if(i<str.length&&i>=0&&j>=0){
        for(int k=i+j;k<str.length;++k)
            str.ch[k-j]=str.ch[k];
        str.length-=(str.length-i<j?str.length-i:j);
        str.ch[str.length]='\0';
    }
}
//从串的pos位置起，求出与substr串匹配的子串的位置
int KMP(Str str,Str substr,int pos){
    int i=pos,j=1;
    while(i<=str.lenght&&j<=substr.length){
        if(j==0||str.ch[j]==substr.ch[j]){
            ++i;
            ++j;
        }
        else 
            j=next[j];
    }
    if(j>substr.length)
         return i-substr.length;
    else 
        return -1;
}
//删除str中值为ch的所有字符
//eg1
void del1(Str& str,char ch){
    if(str.length!=0){
        int sum=0;
        int i,j;
        for(i=0;i<str.length;++i){
            if(str.ch[i]==ch)
                ++sum;
        }
        if(sum!=0){
            char *temp_ch=(char*)malloc(sizeof(char)*(str.length-sum+1));
            for(i=0,j=0;i<str.length;++i){
                if(str.ch[i]!=ch)
                    temp_ch[j++]=str.ch[i];
            }
            temp_ch[j]='\0';
            str.length=str.length-sum;
            free(str.ch);
            str.ch=temp_ch;
        }
    }
}
//eg2
typedef struct{
    char ch[maxSize];
    int length;
}Str2;
void del2(Str2& str,char ch){
    if(str.length!=0){
        for(int i=0;i<str.length;){
            if(str.ch[i]==ch){
                for(int j=i;j<str.length-1;++j)
                    str.ch[j]=str.ch[j+1];
                --str.length;
            }
            else 
                ++i;
        }
        str.ch[str.length]='\0';
    }
}
//eg3
void del3(Str2 &str,char ch){
    if(str.length!=0){
        int ch_num=0;
        int i,j;
        i=0;
        while(str.ch[i]!='\0'){
            if(str.ch[i]==ch){
                ++ch_num;
                for(j=i+1;str.ch[j]!ch&&str.ch[j]!='\0';++j){
                    str.ch[j-ch_num]=str.ch[j];
                    i=j;
                    --str.length;
                }
            }
            else 
                ++i;
        }
        str.ch[str.length]='\0';
    }
}
//采用顺序存储方式存储串，编写一个函数，将串str1中的下标i到下标j之间的字符用str2串替换
int concat(Str &str,Str str1,Str str2){
    if(str.ch){
        free(str.ch);
        str.ch=NULL;
    }
    str.ch=(char*)malloc(sizeof(char)*(str1.length+str2.length+1));
    if(str.ch==NULL)
        return false;
    int i=0;
    while(i<str1.length){
        str.ch[i]=str1.ch[i];
        ++i;
    }
    int j=0;
    while(j<=str2.ch[j]){
        str.ch[i+j]=str2.ch[j];
        ++j;
    }
    str.length=str1.length+str2.length;
    return true;
}
int substring(Str &strsub,Str str,int pos,int len){
    if(pos<0||pos>=str.length||len<0||len>str.length-pos){
        return false;
    }
    if(substr.ch){
        free(substr.ch);
        substr.ch=NULL;
    }
    if(len==0){
        substr.ch=NULL;
        substr.length=0;
        return true;
    }
    else{
        substr.ch=(char*)malloc(sizeof(char)*(len+1));
        int i=pos;
        int j=0;
        while(i<pos+len){
            substr.ch[j]=str.ch[i];
            ++i;
            ++j;
        }
        substr.ch[j]=NULL;
        return true;
    }
}
int stuff(Str& str1,Str str2,int i,int j){
    Str strl1;strl1.ch=NULL;str11.length=0;
    Str strl2;strl2.ch=NULL;strl2.length=0;
    Str temp_str;
    if(!substring(strl1,str1,0,i))
        return 0;
    if(!substring(strl2,str1,j+1,str1.lengrth-1))
        return 0;
    if(!concat(temp_str,strl1,str2))
        return 0;
    if(!concat(str1,temp_str,strl2))
        return 0;
    return 1;
}
//计算一个子串在主串中出现的次数，不考虑子串重叠
//eg1
int index(Str str,Str substr){
    int i=1,j=1,k=1,sum=0;
    while(i<=str.length){
        if(str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=1;
            i=++k;
        }
        if(j>substr.length){
            j=1;
            ++sum;
        }
    }
    return sum;
}
//eg2
int KMP(Str str,Str substr){
    i=1,j=1,sum=0;
    while(i<str.length){
        if(j==0||str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];
        }
        if(j>substr.length){
            j=1;
            ++sum;
        }
    }
    return sum;
}
//构造串的链表结点数据结构，找出串str1中第一个不在str2中出现的字符
typedef struct SNode{
    char data;
    struct SNode *next;
}SNode;
char findfirst(SNode *str1,SNode *str2){
    for(SNode *p=str1;p!=NULL;p=p->next){
        bool flag=false;
        for(SNode *q=str2;q!=NULL;q=q->next;){
            if(p->data==q->data){
                flag=true;
                break;
            }
        }
        if(flag==false)
            return p->data;
    }
    return  '\0';
}
