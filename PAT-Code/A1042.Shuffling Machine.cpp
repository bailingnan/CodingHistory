#include<cstdio>
struct poker
{
	char mark;
	int num;
}Poker[54],EX[54];
int main()
{
	for(int i=0;i<13;i++)
	{
		Poker[i].mark = 'S';
		Poker[i].num = i+1;
	}
	for(int i=13;i<26;i++)
	{
		Poker[i].mark = 'H';
		Poker[i].num = i - 12;
	}
	for(int i=26;i<39;i++)
	{
		Poker[i].mark = 'C';
		Poker[i].num = i - 25;
	}
	for(int i=39;i<52;i++)
	{
		Poker[i].mark = 'D';
		Poker[i].num = i - 38;
	}
	for(int i=52;i<54;i++)
	{
		Poker[i].mark = 'J';
		Poker[i].num = i - 51;
	}
	int K, Num[54];
	scanf("%d", &K);
	for(int i=0;i<54;i++)
	{
		scanf("%d", &Num[i]);
	}
	for(int i=0;i<K;i++)
	{	
		if (i % 2 == 0)
		{
			for (int j = 0; j < 54; j++)
			{
				EX[Num[j] - 1] = Poker[j];
			}
		}
		else
		{
			for (int j = 0; j < 54; j++)
			{
				Poker[Num[j] - 1] = EX[j];
			}
		}
	}
	for(int i=0;i<54;i++)
	{
		if (K % 2 == 1)
		{
			printf("%c%d", EX[i].mark, EX[i].num);
			if (i < 53)
				printf(" ");
		}
		else
		{
			printf("%c%d", Poker[i].mark, Poker[i].num);
			if (i < 53)
				printf(" ");
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int start[N+1], end[N+1], next[N+1];
int main() {
    int K;
    scanf("%d", &K);
    for(int i = 1; i <= N; i++) {
        start[i] = i;
    }
    for(int i = 1; i <= N; i++) {
        scanf("%d", &next[i]);
    }
    for(int step = 0; step < K; step++) {
        for(int i = 1; i <= N; i++) {
            end[next[i]] = start[i];
        }
        for(int i = 1; i <= N; i++) {
            start[i] = end[i];
        }
    }
    for(int i = 1; i <= N; i++) {
        if(i != 1) printf(" ");
        start[i]--;
        printf("%c%d", mp[start[i] / 13] , start[i] % 13 + 1);
    }
    return 0;
}
