bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
#include<cstdio>//筛法求素数表，复杂度O(nloglogn)
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };
void Find_Prime() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + 1; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}
int main() {
	Find_Prime();
	for (int i = 0; i < pNum; i++) {
		printf("%d", prime[i]);
	}
	return 0;
}
