#include<cstdio>
int main()
{
	const double eps = 1e-8;
	double temp, Coe1[1001] = { 0 },Coe2[1001]={0},Coe3[2001]={0};
	int K, M;
	scanf("%d", &K);
	for (int j = 0; j < K; j++)
	{
		scanf("%d", &M);
		scanf("%lf", &Coe1[M]);
	}
	scanf("%d", &K);
	for (int j = 0; j < K; j++)
	{
		scanf("%d", &M);
		scanf("%lf", &Coe2[M]);
	}
	for(int i=0;i<1001;i++)
	{
		if(Coe1[i] - 0 > eps || Coe1[i] - 0 < -eps)
		{
			for(int j=0;j<1001;j++)
				if(Coe2[j] - 0 > eps || Coe2[j] - 0 < -eps)
				{
					Coe3[i + j] += Coe1[i] * Coe2[j];
				}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (Coe3[i] - 0 > eps || Coe3[i] - 0 < -eps)
			cnt++;
	}
	printf("%d", cnt);
	if (cnt != 0)
	{
		printf(" ");
		for (int i = 2000; i >= 0; i--)
		{
			if (Coe3[i] - 0 > eps || Coe3[i] - 0 < -eps)
			{
				printf("%d %.1lf", i, Coe3[i]);
				cnt--;
				if (cnt == 0)
					break;
				else
					printf(" ");
			}
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
struct Poly {
    int exp;
    double cof;
} poly[1001];
double ans[2001];
int main() {
    int n, m, number = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %lf", &poly[i].exp, &poly[i].cof);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int exp;
        double cof;
        scanf("%d %lf", &exp, &cof);
        for(int j = 0; j < n; j++) {
            ans[exp + poly[j].exp] += (cof * poly[j].cof);
        }
    }
    for(int i = 0; i <= 2000; i++) {
        if(ans[i] != 0.0) number++;
    }
    printf("%d", number);
    for(int i = 2000; i >= 0; i--) {
        if(ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
