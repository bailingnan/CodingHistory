#include<cstdio>
#include<cstring>
int main() {
	int N, gd[1010] = { 0 },max=0,maxn=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num, p, temp;
		scanf("%d-%d%d", &num, &p, &temp);
		gd[num] += temp;
		if (gd[num] > max) {
			max = gd[num];
			maxn = num;
		}
	}
	printf("%d %d", maxn, max);
	return 0;
}
