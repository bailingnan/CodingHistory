#include<cstdio>
int main() {
	int n, f[110];
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		scanf("%d",&f[i]);
	}
	int sum = 0;
	f[0] = 0;
	for (int i = 1; i <=n; i++) {
		if (f[i] - f[i - 1] > 0)
			sum += 6 * (f[i] - f[i - 1]);
		else
			sum += 4 * (f[i - 1] - f[i]);
		sum += 5;
	}
	printf("%d", sum);
}
//算法笔记
#include <cstdio>
int main() {
    int n, total = 0, now = 0, to;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++) {
        scanf("%d", &to);
        if(to > now) {
            total += ((to - now) * 6);
        } else {
            total += ((now - to) * 4);
        }
        total += 5;
        now = to;
    }
    printf("%d\n", total);
    return 0;
}
