#include<cstdio>
int main()
{
	char str[3]= { 'W','T','L' };
	double pro=1.0,max, Num[3];
	int maxi[3];
	for(int i=0;i<3;i++)
	{	
		max = 0;
		for (int j = 0; j< 3; j++)
		{
			scanf("%lf", &Num[j]);
			if (Num[j] > max)
			{
				max = Num[j];
				maxi[i] = j;
			}
		}
		pro *= max;
	}
	pro = (pro*0.65 - 1.0) * 2.0;
	for(int i=0;i<3;i++)
	{
		printf("%c ", str[maxi[i]]);
	}
	printf("%.2lf\n", pro);
	return 0;
}
//算法笔记
#include <cstdio>
char S[3] = {'W', 'T', 'L'};
int main() {
    double ans = 1.0, tmp, a;
    int idx;
    for(int i = 0; i < 3; i++) {
        tmp = 0.0;
        for(int j = 0; j < 3; j++) {
            scanf("%lf", &a);
            if(a > tmp) {
                tmp = a;
                idx = j;
            }
        }
        ans *= tmp;
        printf("%c ", S[idx]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
