#include<cstdio>//运行超时，扣5分；
int main() {
	double n[100010];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &n[i]);
	}
	double sum = 0;
	for (int i = 0; i < N; i++) {
		double m = 0;
		for (int j = i; j < N; j++) {
			m += n[j];
			sum += m;
		}
	}
	printf("%.2f", sum);
	return 0;
}
/*
算法笔记//可推导出公式
#include <cstdio>
int main() {
    int n;
    double v, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &v);    // 第i位的值为v
        ans += v * i * (n + 1 - i);    // 第i位的总出现次数为v*i*(n+1-i)
    }
    printf("%.2f\n", ans);
    return 0;
}
*/
