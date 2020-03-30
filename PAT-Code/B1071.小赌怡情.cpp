#include<cstdio>
int main()
{
	int T, K;
	scanf("%d%d", &T, &K);
	for(int i=0;i<K;i++)
	{
		int n1, b, t, n2;
		scanf("%d%d%d%d", &n1,&b, &t, &n2);
		if (t> T)
		{
			printf("Not enough tokens.  Total = %d.\n", T);
			continue;;
		}
		if (n1> n2)
		{
			if (b== 0)
			{
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
			else
			{
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}
		}
		else
		{
			if (b== 1)
			{
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
			else
			{
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}

		}
		if (T == 0)
		{
			printf("Game Over.");
			break;
		}
	}
	return 0;
}
