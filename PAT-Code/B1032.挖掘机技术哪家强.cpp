#include<cstdio>
int main()
{
	int n,Score[100000]={0};
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int Num, S;
		scanf("%d %d", &Num, &S);
		Score[Num] += S;
	}
	int mark=1,max=-1;
	for(int i=1;i<=n;i++)
	{
		if (Score[i] >max)
		{
			max = Score[i];
			mark = i;
		}
	}
	printf("%d %d\n", mark, Score[mark]);
	return 0;
}
//此代码在牛客网提交时会出现如下问题：
//测试用例：
//6
//3 65
//2 80
//100000 100
//2 70
//100000 40
//100000 40
//对应输出应该为：
//100000 180
//你的输出为：
//2 150
//经修改后为:
#include<cstdio>
int main()
{
	int n,maxid=0,Score[100001]={0};
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int Num, S;
		scanf("%d %d", &Num, &S);
		Score[Num] += S;
		if (Num > maxid)
			maxid = Num;
	}
	int mark=1,max=-1;
	for(int i=1;i<=maxid;i++)
	{
		if (Score[i] >max)
		{
			max = Score[i];
			mark = i;
		}
	}
	printf("%d %d\n", mark, Score[mark]);
	return 0;
}
//算法笔记
#include <cstdio>
const int maxn = 100010;
int school[maxn] = {0};
int main() {
    int n, schID, score;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &schID, &score);
        school[schID] += score;
    }
    int k = 1, MAX = -1;
    for(int i = 1; i <= n; i++) {
        if(school[i] > MAX) {
            MAX = school[i];
            k = i;
        }
    }
    printf("%d %d\n", k, MAX);
    return 0;
}
