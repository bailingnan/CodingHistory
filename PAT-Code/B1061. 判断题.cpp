#include<cstdio>
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int sc[110], ans[110];
	for (int i = 0; i < M; i++) {
		scanf("%d", &sc[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &ans[i]);
	}
	for (int k = 0; k < N; k++) {
		int sum = 0;
		for (int i = 0; i < M; i++) {
			int temp;
			scanf("%d", &temp);
			if (temp == ans[i]) {
				sum += sc[i];
			}
		}
		printf("%d\n", sum);
	}
}
