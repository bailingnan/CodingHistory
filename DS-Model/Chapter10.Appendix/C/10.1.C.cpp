//键盘输入a,b,c,从小到大排序
#include<stdio.h>
void main(){
    int a,b,c,t;
    printf("请输入a,b,c的值：");
    scanf("%d %d %d",&a,&b,&c);
    if((a>=b)&&(a>=c)){
        if(b<=c){
            t=b;
            b=c;
            c=t;
        }
    }
    if((b>=a)&&(b>=c)){
        t=a;
        a=b;
        b=t;
        if(b<=c){
            t=b;
            b=c;
            c=t;
        }
    }
    if((c>=a)&&(c>=b)){
        t=a;
        a=c;
        c=t;
        if(b<=c){
            t=b;
            b=c;
            c=t;
        }
    }
    printf("3个数由小到大为：%d<%d<%d\n",c,b,a);
}
//任给一个自然数，将其分解为各个因子的乘积
#include<stdio.h>
void main(){
    int x,temp=2;
    printf("请输入自然数")；
    scanf("%d",&x);
    printf("%d=1",x);
    while(1){
        if(x%temp==0){
            printf("*%d",temp);
            x=x/temp;
        }
        else{
            temp++;
        }
        if(x==1)
            break;
    }
    printf("\n");
}
//对20个数据排序后输出，并给出现在每个元素所对应的原来的次序
#include<stdio.h>
void main(){
    int a[21],pos[21];
    int i,j,done;
    printf("输入:\n");
    for(i=1;i<=20;i++){
        scanf("%d",&a[i]);
        pos[i]=i;
    }
    i=1;
    do{
        done=1;
        for(j=20;j>=i+1;j--){
            if(a[j]<a[j]-1){
                done=0;
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                t=pos[j];
                pos[j]=pos[j-1];
                pos[j-1]=t;
            }
        }
        i++;
    }while(i!=20&&!done)
    printf("输出:\n");
    for(i=1;i<=20;i++){
        printf("%4d %2d\n",a[i],pos]i]);
    }
    printf("\n");
}
//给定两个一维数组a和b，每个数组由相异的整数元素组成，试将其公共的元素存入数组c中，
//数组a特有的元素存入数组d中，数组b中的特有元素存入数组e中
#include<stdio.h>
void main(){
    int a[20],b[20],c[20],d[20],e[20];
    int na=0,nb=0,nc=0,nd=0,ne=0;
    int i,j;
    printf("请输入a的长度：")；
    scanf("%d",&na);
    printf("请输入a的数值:\n");
    for(i=0;i<na;i++)
        scanf("%d",&a[i]);
    printf("请输入b的长度：")；
    scanf("%d",&nb);
    printf("请输入b的数值:\n");
    for(i=0;i<nb;i++)
        scanf("%d",&b[i]);
    for(i=0;i<na;i++){
        int b_has=0;
        for(j=0;j<nb;j++){
            if(a[i]==b[j]){
                b_has=1;
                c[nc]=a[i];
                nc++;
                break;
            }
        }
        if(!b_has){
            d[nd]=a[i];
            nd++;
        }
    }
    for(i=0;i<nb;i++){
        int a_has=0;
        for(j=0;j<nc;j++){
            if(b[i]=c[j]){
                a_has=1;
                break;
            }
        }
        if(!a_has){
            e[ne]=b[i];
            ne++;
        }
    }
    printf("\n 数组c:\n");
    for(i=0;i<nc;i++)
        printf("%3d",c[i]);
        printf("\n 数组d:\n");
    for(i=0;i<nd;i++)
        printf("%3d",d[i]);
        printf("\n 数组c:\n");
    for(i=0;i<ne;i++)
        printf("%3d",e[i]);
}
//约瑟夫问题。M个人围成一圈，从第一个人开始报数，数到n的人出圈，再由下一个人开始报数
//数到n的人出圈，打印出依次出圈的人的编号，M值预先选定，n的值由键盘输入
#include<stdio.h>
#define M 8
void main(){
    int a[M],i,j,k;
    int n;
    printf("M的值为8，请输入n的值");
    scanf("%d",&n);
    for(i=0;i<M;i++)
        a[i]=i+1;
    printf("依次出圈的编号是:\n");
    i=0;
    for(j=M;j>0;j--){
        i=(i+n-1)%j;
        printf("%d",a[i]);
        for(k=i;k<j-1;k++)
            a[k]=a[k+1];
    }
    printf("\n");
}
//从键盘上输入十个整型数，去掉重复的，将剩余的由大到小排序输出
#include<stdio.h>
void print(int n[],int length){
    int i;
    printf("结果是:\n");
    for(i=length-1;i>=0;i--){
        printf("%d",n[i]);
    }
    printf("\n");
}
void sort(){
    int num[10];
    int n[10];
    int length=0;
    int i,j,k;
    printf("请输入10个整型数:\n");
    for(i=0;i<10;i++)
        scanf("%d",&num[i]);
    for(i=0;i<10;i++){
        if(length==0||num[i]>n[length-1]){
            n[length]=num[i];
            length++;
        }
        else{
            for(j=0;j<length;j++){
                if(n[j]==num[i]){
                    break;
                }
                else if(num[i]<n[j]){
                    for(k=length;k>j;k--){
                        n[k]=n[k-1];
                    }
                    n[j]=num[i];
                    length++;
                    break;
                }
            }
        }
        print(n,length);
    }
    void main(){
        sort();
    }
}
//输入一个十进制的数，输出相应的二进制数，八进制数和十六进制数
#include<stdio.h>
#include<math.h>
char get(int x){
    char c;
    switch(x){
        case 0:c='0';break;
        case 1:c='1';break;
        case 2:c='2';break;
        case 3:c='3';break;
        case 4:c='4';break;
        case 5:c='5';break;
        case 6:c='6';break;
        case 7:c='7';break;
        case 8:c='8';break;
        case 9:c='9';break;
        case 10:c='A';break;
        case 11:c='B';break;
        case 12:c='C';break;
        case 13:c='D';break;
        case 14:c='E';break;
        case 15:c='F';break;
    }
    return c;
}
void turn(int x){
    int a[100],b[50];
    char c[20];
    int al=0,bl=0,cl=0;
    int j,k,t=0;
    for(k=0;k<100;k++)
        a[k]=0;
    for(k=0;k<50;k++)
        b[k]=0;
    for(k=0;k<20;k++)
        c[k]=' ';
    while(1){
        if(x==1){
            a[al]=1;
            break;
        }
        a[al]=x%2;
        al++;
        x=x/2;
    }
    printf("\n二进制:");
    for(j=al;j>=0;j--)
        printf("%d",a[j]);
    printf("\n\n");
    j=0;
    while(1){
        if(j+2<=al){
            if(a[j]!=0)
                b[bl]+=(int)pow(2,0);
            if(a[j+1]!=0)
                b[bl]+=(int)pow(2,1);
            if(a[j+2]!=0)
                b[bl]+=(int)pow(2,2);
            j=j+2;
        }
        else if(j+1<=al){
            if(a[j]!=0)
                b[bl]+=(int)pow(2,0);
            if(a[j+1]!=0)
                b[bl]+=(int)pow(2,1);
            j=j+1;
        }
        else if(j<=al){
            b[bl]=a[j];
        }
        bl++;
        j++;
        if(j>al)
        break;
    }
    printf("八进制：");
    for(k=bl-1;k>=0;k--)
        printf("%d",b[k]);
    printf("\n\n");
    j=0;
    while(1){
        if(j+3<=al){
            if(a[j]!=0)
                t+=(int)pow(2,0);
            if(a[j+1]!=0)
                t+=(int)pow(2,1);
            if(a[j+2]!=0)
                t+=(int)pow(2,2);
            if(a[j+3]!=0)
                t+=(int)pow(2,3);
            j+=3;
        }
        else if(j+2<=al){
            if(a[j]!=0)
                t+=(int)pow(2,0);
            if(a[j+1]!=0)
                t+=(int)pow(2,1);
            if(a[j+2]!=0)
                t+=(int)pow(2,2);
            j=j+2;
        }
        else if(j+1<=al){
            if(a[j]!=0)
                t+=(int)pow(2,0);
            if(a[j+1]!=0)
                t+=(int)pow(2,1);
            j+=1;
        }
        else if(j<=al){
            t=a[j];
        }
        c[cl]=get(t);
        t=0;
        cl++;
        j++;
        if(j>al)
            break;
    }
     printf("十六进制:");
        for(k=cl-1;k>=0;k--)
            printf("%c",c[k]);
        printf("\n\n");
}
void main(){
    int x;
    printf("请输入十进制数");
    scanf("%d",&x);
    turn(x);
}
//返回数n的从右边开始的第k个数字的值
#include<stdio.h>
#include<math.h>
#define MAX 1000
int digit(int n,int k){
    int i,s;
    for(i=1;i<k;i++){
        n=n/10;
        s=n%10;
    }
    return s;
}
void main(){
    int n,k;
    printf("请输入n和k的值：\nn=");
    scanf("%d",&n);
    printf("k=");
    scanf("%d",&k);
    printf("digit(%d,&d)=%d\n",n,k,digit(n,k));
}
//函数readoctal()读入八进制序列，转换成十进制正整数
//函数writeoctal()将十进制正整数转换成相应的八进制数字序列
#include<stdio.h>
#include<math.h>
int readoctal(char x[],int l){
    int temp=0;
    int i=0;
    for(i=0;i<l;i++)
        temp+=(int)(x[l-i-1]-48)*(int)pow(8,i);
    return temp;
}
void writeoctal(int y){
    int i,a[10],al=0;
    while(1){
        if(y==0){
            break;
        }
        a[al]=y%8;
        al++;
        y=y/8;
    }
    for(i=0;i<al;i++){
        printf("%d",a[al-i-1]);
    }
}
//查找字符串s2在字符串s1中第一次出现的位置，若找到则返回该位置，否则返回0
#include<stdio.h>
#include<string.h>
int Find(char str1[],char str2[]){
    if(strlen(str1)<strlen(str2))
        return -1;
    char *p1,*p2;
    int i,j,offset=0;
    p1=str1;
    p2=str2;
    for(i=0;i<(int)strlen(str1)-(int)strlen(str2)+1;i++){
        if(*(p1+1)==(*p2)){
            offset=i+1;
            for(j=1;j<(int)strlen(str2);j++){
                if(*(p1+i+j)!=*(p2+j))
                    break;
            }
            if(j==((int)strlen(str2)))
                return(offset);
        }
    }
    return -1;
}
//回形输出二维数组
#include <stdio.h>
#define maxN 101
int main(int argc, char *argv[])
{
    int row,col,i,j,k;
    int a[maxN][maxN];
    int count;
    
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    if(row==1)//只有一行
    {
        i=0;j=0; 
        for(k=1;k<=col;k++)
        { printf("%d\n",a[i][j]);j++;}
    }
    else if(col==1)//只有一列
    {
        i=0;j=0;
        for(k=1;k<=row;k++)
        { printf("%d\n",a[i][j]);i++;}
    }
    else
    {
        i=0;j=0;
        count=row*col;
        while(count>0)
        {
            for(k=1;k<col;k++)
            { count--; printf("%d\n",a[i][j]);j++;}  //输出一个环的上面那一条边 
            
            for(k=1;k<row;k++)
            { count--; printf("%d\n",a[i][j]);i++;}  //输出一个环的右侧那一条边
            
            for(k=1;k<col;k++)
            { count--; printf("%d\n",a[i][j]);j--;}  //输出一个环的下面那一条边
            
            for(k=1;k<row;k++)
            { count--; printf("%d\n",a[i][j]);i--;}  //输出一个环的左侧那一条边
            
            i++;
            j++;
            row-=2;
            col-=2;
            if(row==1)//只剩下一行
            {
                for(k=1;k<=col;k++)
                { count--; printf("%d\n",a[i][j]);j++;}
            }
            else if(col==1)//只剩下一列
            {
                for(k=1;k<=row;k++)
                { count--; printf("%d\n",a[i][j]);i++;}
            }
        }
    }
    return 0;
}
