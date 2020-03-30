#include<cstdio>
int main()
{
	int n, cnt = 0;
	scanf("%d", &n);
	for (; n != 1;)
	{
		if (n % 2)
			n = (3 * n + 1) / 2;
		else
			n /= 2;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int n, step = 0;
    scanf("%d", &n);
    while(n != 1) {
        if(n % 2 == 0) n = n / 2;
        else n = (3 * n + 1) / 2;
        step++;
    }
    printf("%d\n", step);
    return 0;
}
