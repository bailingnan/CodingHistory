#include<cstdio>
int main() {
	int M, N, A, B, T;
	int g[510][510];
	scanf("%d%d%d%d%d", &M, &N, &A, &B, &T);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &g[i][j]);
			if (g[i][j] >= A && g[i][j] <= B) {
				g[i][j] = T;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%03d", g[i][j]);
			if (j < N - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
