#include<cstdio>
int main()
{
	int N,M;
	char C;
	scanf("%d %c", &N, &C);
	if (N % 2 == 1)
		M = N / 2 + 1;
	else
		M = N / 2;
	for (int i = 0; i < M; i++)
	{
		if (i == 0 || i == M - 1)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%c", C);
				if (j == N - 1)
					printf("\n");
			}
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				if (j == 0 || j == N - 1)
					printf("%c", C);
				else
					printf(" ");
				if (j == N - 1)
					printf("\n");
			}
		}
	}
	return 0;
}
