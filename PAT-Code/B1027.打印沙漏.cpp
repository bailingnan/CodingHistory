#include<cstdio>
int main()
{
	int N, k, sum = 0;
	char C;
	scanf("%d %c", &N, &C);
	if (N < 7)
	{
		printf("%c\n%d\n", C, N - 1);
	}
	else
	{
		for (int i = 3;; i += 2)
		{
			sum += i;
			if ((1 + 2 * sum) > N)
			{
				k = i - 2;
				sum = sum - i;
				break;
			}
		}
		for (int i = k; i >= 1; i = i - 2)
		{
			for (int j = 0; j < (k - i) / 2; j++)
				printf(" ");
			for (int j = 0; j < i; j++)
				printf("%c", C);
			printf("\n");
		}
		for (int i = 3; i <= k; i = i + 2)
		{
			for (int j = 0; j < (k - i) / 2; j++)
				printf(" ");
			for (int j = 0; j < i; j++)
				printf("%c", C);
			printf("\n");
		}
		printf("%d\n", N - (1 + 2 * sum));
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cmath>
int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int bottom = (int)sqrt(2.0 * (n + 1)) - 1;
    if(bottom % 2 == 0) bottom--;
    int used = (bottom + 1) * (bottom + 1) / 2 - 1;
    for(int i = bottom; i >= 1; i -= 2) {
        for(int j = 0; j < (bottom - i) / 2; j++) {
            printf(" ");
        }
        for(int j = 0; j < i; j++) {
            printf("%c", c);
        }
        printf("\n");
    }
    for(int i = 3; i <= bottom; i += 2) {
        for(int j = 0; j < (bottom - i) / 2; j++) {
            printf(" ");
        }
        for(int j = 0; j < i; j++) {
            printf("%c", c);
        }
        printf("\n");
    }
    printf("%d\n", n - used);
    return 0;
}
