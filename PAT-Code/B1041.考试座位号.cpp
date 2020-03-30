#include<cstdio>
struct Student
{
	char Num[14];
	int N1;
	int N2;
}stu[1000];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s%d%d", stu[i].Num, &stu[i].N1, &stu[i].N2);
	int M, m[1000];
	scanf("%d", &M);
	for(int i=0;i<M;i++)
	{
		scanf("%d", &m[i]);
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if (stu[j].N1 == m[i])
			{
				printf("%s %d\n", stu[j].Num, stu[j].N2);
				break;
			}
		}
	}
	return 0;
}
//算法笔记
#include<cstdio>
const int maxn = 1010;
struct Student
{
	long long id;
	int examSeat;
}testSeat[maxn];
int main()
{
	int n, m, seat, examSeat;
	long long id;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %d %d", &id, &seat, &examSeat);
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d", &seat);
		printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examSeat);
	}
	return 0;
}
