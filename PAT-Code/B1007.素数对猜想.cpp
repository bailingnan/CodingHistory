#include<cstdio>
#include<cmath>
bool IsS(int a) {
	if (a == 2) return true;
	int flag = 1;
	for (int i = 2; i <=sqrt(a); i++) {
		if (a%i == 0)
			flag = 0;
	}
	if (flag == 1) return true;
	else return false;
}
int main() {
	int N,cnt=0,temp=2;
	scanf("%d", &N);
	for (int i = 3; i <= N; i++) {
		if (IsS(i)) {
			if ((i - temp) == 2) {
				cnt++;
			}
			temp = i;
		}
	}
	printf("%d", cnt);
	return 0;
}
//算法笔记
#include <cstdio>
#include <cmath>
bool isPrime(int n) {
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main() {
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 3; i + 2 <= n; i += 2) {
        if(isPrime(i) == true && isPrime(i + 2) == true) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
