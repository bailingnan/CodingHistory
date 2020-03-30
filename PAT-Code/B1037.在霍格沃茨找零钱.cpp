#include<cstdio>
struct Money {
	int G;
	int S;
	int K;
}M1,M2,M;
int main(){
	scanf("%d.%d.%d %d.%d.%d", &M1.G, &M1.S, &M1.K, &M2.G, &M2.S, &M2.K);
	int M1K = M1.G * 17 * 29 + M1.S * 29 + M1.K;
	int M2K= M2.G * 17 * 29 + M2.S * 29 + M2.K;
	int S = M2K - M1K, flag = 1;
	if (S < 0) {
		flag = -1;
		S = -S;
	}
	M.G = S / (17 * 29);
	M.S = S % (17 * 29) / 29;
	M.K = S % (17 * 29) % 29;
	printf("%d.%d.%d\n", flag*M.G, M.S, M.K);
	return 0;
}
