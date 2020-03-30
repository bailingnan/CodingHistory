//会超过PAT100ms的限制扣3分（大概会有几个测试点150ms左右），但是会通过牛客网1000ms的测试。
#include<cstdio>
void Swap(int* a, int* b);
int main()
{
	int N, Dis[100010];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &Dis[i]);
	int M,RC[10000];
	scanf("%d", &M);
	for(int i=0;i<M;i++)
	{
		int a, b,dis1=0,dis2=0,dis21=0,dis22=0;
		scanf("%d %d", &a, &b);
		if (a == b)
			RC[i] = 0;
		else
		{
			if (a > b)
				Swap(&a, &b);
			for (int i = a; i < b; i++)
				dis1 += Dis[i];
			for (int i = b; i < N; i++)
				dis21 += Dis[i];
			for(int i=1;i<a;i++)
			{
				dis22 += Dis[i];
			}
			dis2 = dis22 + Dis[N] + dis21;
			if (dis1 > dis2)
				RC[i] = dis2;
			else RC[i] = dis1;
		}
		
	}
	for (int i = 0; i < M; i++)
	{
		printf("%d\n", RC[i]);
	}
}
void Swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//算法笔记
/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int dis[MAXN], A[MAXN];
int main() {
    int sum = 0, query, n, left, right;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
        dis[i] = sum;
    }
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        scanf("%d%d", &left, &right);
        if(left > right) swap(left, right);
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(temp, sum - temp));
    }
    return 0;
} 
*/
