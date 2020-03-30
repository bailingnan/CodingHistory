#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int K, N,num[maxn];
int main() {
	scanf("%d", &K);
	for (int j = 0; j < K; j++) {
		scanf("%d", &N);
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num[i]);
			for (int k = 1; k < i; k++) {
				if (num[k]==num[i]||abs(i - k) == abs(num[i] - num[k])) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
