#include<cstdio>
#include<cstring>
int main() {
	int N, K, GD[101], temp;
	memset(GD, 0, sizeof(GD));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		GD[temp]++;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &temp);
		printf("%d", GD[temp]);
		if (i < K - 1)
			printf(" ");
	}
	return 0;
}
