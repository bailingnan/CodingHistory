#include<cstdio>
int main()
{
	int N,mark,Num[1000], A[5] = { 0 }, cnt[5] = { 0 };
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d", &Num[i]);
		switch (Num[i] % 5)
		{
		case 0:
			if (Num[i] % 2 == 0)
			{
				cnt[0]++;
				A[0] += Num[i];
			}
			break;
		case 1:
			cnt[1]++;
			mark = 1;
			if (cnt[1] % 2==0)
				mark = -1;
			A[1] += mark * Num[i];
			break;
		case 2:
			cnt[2]++;
			A[2] = cnt[2];
			break;
		case 3:
			cnt[3]++;
			A[3] += Num[i];
			break;
		case 4:
			cnt[4]++;
			if (Num[i] > A[4])
				A[4] = Num[i];
			break;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(cnt[i]==0)
		{
			printf("%c",'N');
			if (i < 4)
				printf(" ");
		}
		else
		{
			if (i != 3)
			{
				printf("%d", A[i]);
				if (i < 4)
					printf(" ");
			}
			else
			{
				printf("%.1f", double(A[3]) / double(cnt[3]));
				printf(" ");
			}
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int count[5] = {0};
    int ans[5] = {0};
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp % 5 == 0) {
            if(temp % 2 == 0) {
                ans[0] += temp;
                count[0]++;
            }
        } else if(temp % 5 == 1) {
            if(count[1] % 2 == 0) {
                ans[1] += temp;
            } else {
                ans[1] -= temp;
            }
            count[1]++;
        } else if(temp % 5 == 2) {
            count[2]++;
        } else if(temp % 5 == 3) {
            ans[3] += temp;
            count[3]++;
        } else {
            if(temp > ans[4]) {
                ans[4] = temp;
            }
            count[4]++;
        }
    }
    if(count[0] == 0) printf("N ");
    else printf("%d ", ans[0]);
    if(count[1] == 0) printf("N ");
    else printf("%d ", ans[1]);
    if(count[2] == 0) printf("N ");
    else printf("%d ", count[2]);
    if(count[3] == 0) printf("N ");
    else printf("%.1f ", (double)ans[3] / count[3]);
    if(count[4] == 0) printf("N");
    else printf("%d", ans[4]);
    return 0;
}
