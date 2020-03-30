#include<cstdio>
int main()
{
	int T;
	scanf("%d", &T);
	for(int i=1;i<=T;i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a + b > c)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int T, tcase = 1;
    scanf("%d", &T);
    while(T--) {    //T--跟--T都可以
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a + b > c) {
            printf("Case #%d: true\n", tcase++);
        } else {
            printf("Case #%d: false\n", tcase++);
        }
    }
    return 0;
}
