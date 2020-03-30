//习题
//用栈求中缀表达式值
int getPriority(char op){
    if(op=='+'||op=='-')
        return 0;
    else return 1;
}
int calSub(float opnd1,char op,float opnd2,float &result){
    if(op=='+') result=opnd1+opnd2;
    if(op=='-') result=opnd1-opnd2;
    if(op=='*') result=opnd1*opnd2;
    if(op=='\'){
        if(fabs(opnd2)<MIN)   
            return 0;
        else{
            result=opnd1/opnd2;
        }
    }
    return 1;
}
int calStackTopTwo(float s1[],int &top1,char s2[],&top2){
    float opnd1,opnd2,result;
    char op;
    int flag;
    opnd2=s1[top1--];
    opnd1=s1[top2--];
    op=s2[top2--];
    flag=calSub(opnd1,op,opnd2,result);
    if(flag==0){
        std::cout<<"ERROR"<<endl;
    }
    s1[++top1]=result;
    return flag;
}
float calInfix(char exp[]){
    float s1[maxSize];
    int top1=-1;
    cahr s2[maxSize];
    int top=-1;
    int i=0;
    while(exp[i]!='\0){
        if('0'<=exp[i]&&exp[i]<='9'){
            s1[++top1]=exp[i]-'0';
            ++i;
        }
        else if(exp[i]=='('){
            s2[++top2]='(';
            ++i;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='\'){
            if(top2==-1||s2[top2]=='('||getPriority(exp[i])>getPriority(s2[top2])){
                s2[++top2]=exp[i];
                ++i;
            }
            else{
                int flag=calStackTopTwo(s1,top1,s2,top2);
                if(flag==0) return 0;
            }
        }
        else if(exp[i]==')'){
            while(s2[top2]!='('){
                int flag=calStackTopTwo(s1,top1,s2,top2);
                if(flag==0) return 0;
            }
            --top2;
            ++i;
        }
    }
    while(top2!=-1){
        while(s2[top2]!='('){
            int flag=calStackTopTwo(s1,top1,s2,top2);
                if(flag==0) return 0;
    }
    return s1[top1];
}
//用栈求后缀表达式值
int calSub(float opnd1,char op,float opnd2,float &result){
    if(op=='+') result=opnd1+opnd2;
    if(op=='-') result=opnd1-opnd2;
    if(op=='*') result=opnd1*opnd2;
    if(op=='\'){
        if(fabs(opnd2)<MIN)   
            return 0;
        else{
            result=opnd1/opnd2;
        }
    }
    return 1;
}
float calPostFix(char exp[]){
    float[maxSize];
    int top=-1;
    int i=0;
    for(int i=0;exp[i]!='\0';i++){
        if('0'<=exp[i]&&exp[i]<='9'){
            s[++top]=exp[i]='0';
        }
        else{
            float opnd1,opnd2,result;
            char op;
            int flag;
            opnd2=s[top--];
            opnd1=s[top--];
            op=exp[i];
            flag=calSub(opnd1,op,opnd2,result);
            if(flag==0){
                std::cout<<"ERROR"<<std::endl;
                return 0;
            }
        }
    }
}
//用栈求前缀表达式值
int calSub(float opnd1,char op,float opnd2,float &result){
    if(op=='+') result=opnd1+opnd2;
    if(op=='-') result=opnd1-opnd2;
    if(op=='*') result=opnd1*opnd2;
    if(op=='\'){
        if(fabs(opnd2)<MIN)   
            return 0;
        else{
            result=opnd1/opnd2;
        }
    }
    return 1;
}
float calPreFix(char exp[],int len){
    float[maxSize];
    int top=-1;
    int i=0;
    for(int i=len-1;i>=0;--i){
        if('0'<=exp[i]&&exp[i]<='9'){
            s[++top]=exp[i]='0';
        }
        else{
            float opnd1,opnd2,result;
            char op;
            int flag;
            opnd1=s[top--];
            opnd2=s[top--];
            op=exp[i];
            flag=calSub(opnd1,op,opnd2,result);
            if(flag==0){
                std::cout<<"ERROR"<<std::endl;
                return 0;
            }
        }
    }
}
//中缀转后缀
int getPriority(char op){
    if(op=='+'||op=='-')
        return 0;
    else return 1;
}
void infixToPostFix(char infix[],char s2[],int &top2){
    char s1[maxSize];
    int top1=-1;
    int i=0;
    while(infix!='\0'){
        if('0'<=infix[i]&&infix[i]<='9'){
            s2[++top2]=infix[i]-'0';
            ++i;
        }
        else if(infix[i]=='('){
            s1[++top1]='(';
            ++i;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='\'){
            if(top1==-1||s1[top1]=='('||getPriority(infix))>getPriority(s1[top1])){
                s1[++top1]=infix[i];
                ++i;
            }
            else
                s2[++top2]=s1[top1--];
        }
        else if(infix[i]==')'){
            while(s1[top1]!='('){
                s2[++top2]=s1[top--];
            }
            --top1;
            ++i;
        }
    }
}
//中缀转前缀
int getPriority(char op){
    if(op=='+'||op=='-')
        return 0;
    else return 1;
}
void infixToPostFix(char infix[],char s2[],int &top2){
    char s1[maxSize];
    int top1=-1;
    int i=len-1;
    while(infix!='\0'){
        if('0'<=infix[i]&&infix[i]<='9'){
            s2[++top2]=infix[i]-'0';
            --i;
        }
        else if(infix[i]==')'){
            s1[++top1]=')';
            --i;
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='\'){
            if(top1==-1||s1[top1]==')'||getPriority(infix])>=getPriority(s1[top1])){
                s1[++top1]=infix[i];
                ++i;
            }
            else
                s2[++top2]=s1[top1--];
        }
        else if(infix[i]=='('){
            while(s1[top1]!=')'){
                s2[++top2]=s1[top--];
            }
            --top1;
            --i;
        }
    }
}
//括号匹配
//eg1
int isMatched(char left,char right){
    if(left=='('&&right==')')
        return 1;
    if(left=='['&&right==']')
        return 1;
    if(left=='{'&&right=='}')
        return 1;
    return 0;
}
int isParenthesesBalanced(char exp[]){
    char s[maxSize];
    int top=-1;
    for(int i=0;exp[i]!='\0';++i){
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
            s[++top]=exp[i];
        if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            if(top==-1)
                return 0;
            char left=s[top--];
            if(isMatched(left,exp[i])==0)
                return 0;
        }
    }
    if(top>-1) return 0;
    return 1;
}
//eg2
bool check(char *str){
    stack s;
    initStack(s);
    int len=strlen(str);
    for(int i=0;i<len;++i){
        char a=str[i];
        switch(a){
            case '(':
            case '{':
            case '[':
                Push(s,a);
                break;
            case ')':
                if(Pop(S)!='(') return false;
                break;
            case '}':
                if(Pop(S)!='{') return false;
                break;
            case ']':
                if(Pop(S)!='[') return false;
                break;
        }
    }
    if(Empty(s)) return true;
    else return false;
}
//eg3
bool BracksCheck(char *str){
    InitStack(S);
    int i=0;
    while(str[i]!='\0'){
        switch(str[i]){
            case'(':Push(S,'(');break;
            case'[':Push(S,'[');break;
            case'{':Push(S,'{');break;
            case')':Pop(S,e);
                if(e!='(') return false;
                break;
            case']':Pop(S,e);
                if(e!='[') return false;
                break;
            case'}':Pop(S,e);
                if(e!='{') return false;
                break;
            default:
            break;
        }
        i++;
    }
    if(!IsEmpty(S)){
        return false;
    }
    else return true;
}
//计算问题
//F(0)=1,F(m)=m*F(m/3)
int calF(int m){
    int cum=1;
    int s[maxSize],top=-1;
    while(m!=0){
        s[++top]=m;
        m/=3;
    }
    while(top!=-1){
        cum*=s[top--];
    }
    return cum;
}
//判断出栈入栈操作是否合法
//eg1
bool Judge(char A[]){
    int i=0,cnt=0;
    for(;A[i]!='\0';i++){
        if(A[i]=='I') cnt++;
        if(A[i]=='O') cnt--;
        if cnt<0 return false;
    }if(cnt!=0) return false;
    return true;
}
//eg2
int judge(char ch[]){
    int i=0;
    int I=0,O=0;
    while(ch[i]!='\0'){
        if(ch[i]=='I')
            ++I;
        if(ch[i]=='O')
            ++O;
        if(O>I)
            return0;
        ++i;
    }
    if(I!=O)
        return 0;
    else 
        return 1;
}
//判断链表字符是否中心对称
//eg1
int Symmetry(LinkList L,int n){
    int i;
    char s[n/2];
    p=L->next;
    for(i=0;i<n/2;i++){
        s[i]=p->data;
        p=p->next;
    }
    i--;
    if(n%2==1) p=p->next;
    while(p!=NULL&&s[i]==p->data){
        i--;
        p=p->next;
    }
    if(i==-1) return 1;
    else return 0;
}
//eg2
int Str_sym(LinkList L,int n){
    Stack s;
    initstack(s);
    LNode *q,*p=L->next;
    for(i=1;i<=n/2;i++){
        push(p);
        p=p->next;
    }
    if(n%2==1) p=p->next;
    while(p!=NULL){
        q=pop(s);
        if(q->data==p->data) p=p->next;
        else break;
    }
    if(empty(s)) return 1;
    else return 0;
}
//所有元素都得到利用，用标志域tag标示队空和队满,0空1满
//入队
bool EnQueue1(SqQueue &Q,ElemType x){
    if(Q.front==Q.rear&&tag==1) return false;
    Q.data[rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    Q.tag=1;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear&&Q.tag==0) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSiZe;
    Q.tag=0;
    return true;
}
//共享栈
typedef struct{
    int elem[maxSize];
    int top[2];
}SqStack;
//入栈
int push(SqStack &st,int stNo,int x){
    if(st.top[0]+1<st.top[1]){
        if(stNo==0){
            ++(st.top[0]);
            st.elem[st.top[0]]=x;
            return 1;
        }
        else if(stNo==1){
            --(st.top[1]);
            st.elem[st.top[1]]=x;
            return 1;
        }
        else 
            return -1;
    }
    else return 0;
}
//出栈
int pop(SqStack &st,int stNo,int &x){
    if(stNo==0){
        if(st.top[0]!=-1){
            x=st.elem[st.top[0]];
            --(st.top[0]);
            return 1;
        }
        else 
            return 0;
        else if(stNo==1){
            if(st.top[1]!=maxSize){
                x=st.elem[st.top[1]];
                ++(st.top[1]);
                return 1;
            }
            else 
                return 0;
        }
    }
    else return -1;
}
//两个栈模拟一个队列
//王道
//入队
bool EnQueue(Stack &S1,Stack &S2,ElemType e){
    if(!StackOverFlow(S1)){
        Push(S1,e);
        return true;
    }
    if(StackOverFlow(S1)&&!StackOverFlow(S2)){
        printf("队列满");
        return false;
    }
    if(StackOverFlow(S1)&&StackOverFlow(S2)){
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    }   
    Push(S1,e);
    return true;
}
//出队
void DeQueue(Stack &S1,Stack &S2,ElemType &x){
    if(!StackEmpty(S2)){
        Pop(S2,x);
    }
    else if(StackEmpty(S1)){
        printf("队列为空")；
    }
    else{
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
        Pop(S2,x);
    }
}
//判断队列是否为空
bool QueueEmpty(Stack S1,Stack S2){
    if(StackEmpty(S1)&&StackEmpty(S2)){
        return true;
    }
    else return false;
}
//天勤
//出队
int enQueue(SqStack &s1,Sqstack &s2,int x){
    int y;
    if(s1.top==maxSize-1){
        if(!isEmpty(s2))
            return 0;
        else if(isEmpty(s2)){
            while(!isEmpty(s1)){
                pop(s1,y);
                push(s2,y);
            }
            push(s1,x);
            return 1;
        }
    }
    else{
        push(s1,x);
        return 1;
    }
}
//入队
int deQueue(SqStack &s2,SqStack &s1,int &x){
    int y;
    if(!isEmpty(s2)){
        pop(s2,x);
        return 1;
    }
    else{
        if(!isEmpty(s1))
            return 0;
        else{
            while(!isEmpty(s1)){
                pop(s1.y);
                push(s2,y);
            }
            pop(s2,x);
            return 1;
        }
    }
}
//判空
int isQueueEmpty(SqStack s1,SqStack s2){
    if(isEmpty(s1)&&isEmpty(s2))
        return 1;
    else
        return 0;
}
//十进制转换为二进制
int BaseTrans(int N){
    int i,reault=0;
    int stack[maxSize],top=-1;
    while(N!=0){
        i=N%2;
        N=N/2;
        stack[++top]=i;
    }
    while(top!=-1){
        i=stack[top];
        --top;
        result=result*10+i;
    }
    return result;
}
//循环队列，tag判断队列状态
//定义
typedef struct{
    int data[maxSize];
    int front,rear;
    int tag;
}Queue;
//队列要素
Queue qu;
qu.tag=0;
qu.front=qu.rear;//初始
qu.front==qu.rear&&qu.tag==0;
qu.front==qu.rear&&qu.tag==1;
//算法实现
void initQueue(Queue &qu){
    qu.front=qu.rear=0;
    qu.tag=0;
}
int isQueueEmpty(Queue qu){
    if(qu.front==qu.rear&&qu.tag==0)
        return 1;
    
    else
        return 0;
}
int QueueFull(Queue qu){
    if(qu.tag==1&&qu.front==qu.rear)
        return 1;
    else
        return 0;
}
int enQueue(Queue &qu,int x){
    if(QueueuFull(qu)==1)
        return 0;
    else{
        qu.rear=(qu.rear+1)%maxSize;
        qu.data[qu.rear]=x;
        qu.tag=1;
        return 1;
    }
}
int deQueue(Queue &qu,int &x){
    if(isQueueEmpty(qu)==1)
        return 0;
    else{
        qu.front=(qu.front+1)%maxSize;
        x=qu.data[qu.front];
        qu.tag=0;
        return 1;
    }
}                
