#include<cstdio>
int main()
{
	const int N = 2;
	const double eps = 1e-8;
	double temp,Coe[1001]={0};
	int K,M;
	for(int i=0;i<N;i++)
	{
		scanf("%d", &K);
		for(int j=0;j<K;j++)
		{
			scanf("%d%lf", &M,&temp);
			Coe[M] += temp;
		}
	}
	int cnt = 0;
	for(int i=0;i<1001;i++)
	{
		if (Coe[i] - 0 > eps || Coe[i] - 0<-eps)
			cnt++;
	}
	printf("%d", cnt);
	if (cnt != 0)
	{	
		printf(" ");
		for (int i = 1000; i>=0; i--)
		{
			if (Coe[i] - 0 > eps || Coe[i] - 0 < -eps)
			{
				printf("%d %.1lf", i, Coe[i]);
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
const int max_n = 1111;
double p[max_n] = {};
int main() {
    int k, n, count = 0;
    double a;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %lf", &n, &a);
        p[n] += a;
    }
    for(int i = 0; i < max_n; i++) {
        if(p[i] != 0) {
            count++;
        }
    }
    printf("%d", count);
    for(int i = max_n - 1; i >= 0; i--) {
        if(p[i] != 0) printf(" %d %.1f", i, p[i]);
    }
    return 0;
