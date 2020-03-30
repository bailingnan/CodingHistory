#include<cstdio>
struct Time
{
	char ID[20];
	int hh1;
	int mm1;
	int ss1;
	int hh2;
	int mm2;
	int ss2;
}exp1,exp2,temp;
void ini()
{
	exp1.hh1 = 23;
	exp1.mm1 = 59;
	exp1.ss1 = 59;
	exp2.hh2 = exp2.mm2 = exp2.ss2 = 0;
}
bool less(struct Time a,struct Time b)
{
	if (a.hh1 != b.hh1) return a.hh1 <= b.hh1;
	else if (a.mm1 != b.mm1) return a.mm1<=b.mm1;
	else return a.ss1 <= b.ss1;
}
bool more(struct Time a, struct Time b)
{
	if (a.hh2 != b.hh2) return a.hh2 >= b.hh2;
	else if (a.mm2 != b.mm2) return a.mm2>=b.mm2;
	else return a.ss2 >= b.ss2;
}
int main()
{
	ini();
	int M;
	scanf("%d", &M);
	for(int i=0;i<M;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d", temp.ID, &temp.hh1, &temp.mm1, &temp.ss1, &temp.hh2, &temp.mm2, &temp.ss2);
		if (less(temp, exp1)) exp1 = temp;
		if (more(temp, exp2)) exp2 = temp;
	}
	printf("%s %s", exp1.ID, exp2.ID);
	return 0;
}
//算法笔记
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct pNode{
    char id[20];
    int hh, mm, ss;
}temp, ans1, ans2;
bool great(pNode node1, pNode node2){
    if(node1.hh != node2.hh) return node1.hh > node2.hh;
    if(node1.mm != node2.mm) return node1.mm > node2.mm;
    return node1.ss > node2.ss;
}
int main(){
    int n;
    scanf("%d", &n);
    ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;
    ans2.hh = 0,  ans2.mm = 0,  ans2.ss = 0;
    for(int i = 0; i < n; i++){
        scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
        if(great(temp, ans1) == false) ans1 = temp;
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(great(temp, ans2) == true) ans2 = temp;
    }
    printf("%s %s\n",ans1.id, ans2.id);
    return 0;
}
