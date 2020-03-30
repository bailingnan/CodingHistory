#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 10010;
double num[maxn];
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &num[i]);
	}
	sort(num, num + N);
	double sum = num[0];
	for (int i = 1; i < N; i++) {
		sum = (sum + num[i]) / 2;
	}
	int len = floor(sum);
	printf("%d", len);
	return 0;
}
