#include<cstdio>
int main()
{
	int Coe[1000], Index[1000]={0};
	int cnt=-1;
	do
	{
		cnt++;
		scanf("%d%d", &Coe[cnt], &Index[cnt]);
	} while (Index[cnt] != 0);
	for(int i=0;i<=cnt;i++)
	{
		if(Index[i]>0)
		{
			Coe[i] = Coe[i] * Index[i];
			Index[i]--;
		}
	}
	if (cnt == 0)
		printf("%d %d", 0, 0);
	else
	{
		for (int i = 0; i <= cnt - 1; i++)
		{
			printf("%d %d", Coe[i], Index[i]);
			if (i < cnt - 1)
				printf(" ");
		}
	}
	return 0;
}
//改进版
#include<cstdio>
int main()
{
	int Coe[1000], Index[1000]={0};
	int cnt=-1;
	do
	{
		cnt++;
		scanf("%d%d", &Coe[cnt], &Index[cnt]);
	} while (Index[cnt] != 0);
	for(int i=0;i<=cnt;i++)
	{
		Coe[i] = Coe[i] * Index[i];
		Index[i]--;
	}
	if (cnt == 0&&Index[0]==-1)
		printf("%d %d", 0, 0);
	else
	{
		for (int i = 0; i <= cnt ; i++)
		{	
			if (Index[i] != -1)
			{
				printf("%d %d", Coe[i], Index[i]);
				if (i < cnt&&Index[i+1]!=-1)
					printf(" ");
			}
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int a[1010] = {0};
    int k, e, count = 0;
    while(scanf("%d%d", &k, &e) != EOF) {
        a[e] = k;
    }
    a[0] = 0;
    for(int i = 1; i <= 1000; i++) {
        a[i - 1] = a[i] * i;
        a[i] = 0;
        if(a[i - 1] != 0) count++;
    }
    if(count == 0) printf("0 0");
    else{
        for(int i = 1000; i >= 0; i--) {
            if(a[i] != 0) {
                printf("%d %d", a[i], i);
                count--;
                if(count != 0) printf(" ");
            }
        }
    }
    return 0;
}
//在牛客网提交时，会考虑指数为负数的情况，修改如下：
#include<cstdio>
int main()
{
	int Coe[1000], Index[1000]={0};
	int cnt=0;
	while (scanf("%d%d", &Coe[cnt], &Index[cnt])!=EOF)
	{
		 cnt++;
	}
	for(int i=0;i<cnt;i++)
	{
		Coe[i] = Coe[i] * Index[i];
		Index[i]--;
	}
	if (cnt == 1&&Index[0]==-1)
		printf("%d %d", 0, 0);
	else
	{
		for (int i = 0; i <cnt ; i++)
		{	
			if (Index[i] != -1)
			{
				printf("%d %d", Coe[i], Index[i]);
				if (i < cnt-1&&Index[i+1]!=-1)
					printf(" ");
			}
		}
	}
	return 0;
}
