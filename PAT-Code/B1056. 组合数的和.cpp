#include<cstdio>
int main() {
	int N, num[11];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	int sum = 0;
	for (int i = 0; i <N; i++) {
		for (int j= 0; j < N; j++) {
			if (num[i] == num[j]) {
				continue;
			}
			else {
				sum += num[i] * 10 + num[j];
			}
		}
	}
	printf("%d", sum);
	return 0;
}
