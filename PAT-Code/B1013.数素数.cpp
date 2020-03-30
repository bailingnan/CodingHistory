#include<cstdio>//超时，扣1分
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
	int M, N,cnt=0,c=0;
	scanf("%d%d", &M, &N);
	for (int i = 2;; i++) {
		if (IsS(i) == true) {
			cnt++;
			if (cnt == N) {
				printf("%d", i);
				break;
			}
			if (cnt >= M) {
				printf("%d", i);
				c++;
				if (c < 10)
					printf(" ");
				else {
					printf("\n");
					c = 0;
				}
			}
		}
	}
}
/*
//算法笔记
//方法一：暴力
#include <stdio.h>
#include <math.h>
const int maxn = 1000001;
bool isPrime(int n) {
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int prime[maxn], num = 0;
bool p[maxn] = {0};
void Find_Prime(int n) {
    for(int i = 1; i < maxn; i++) {
        if(isPrime(i) == true) {
            prime[num++] = i;
            p[i] = true;
            if(num >= n) break;
        }
    }
}
int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    for(int i = m; i <= n; i++) {
        printf("%d",prime[i - 1]);
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
//方法二：筛法
#include <stdio.h>
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};
void Find_Prime(int n) {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            prime[num++] = i;
            if(num >= n) break;
            for(int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}
int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    for(int i = m; i <= n; i++) {
        printf("%d",prime[i - 1]);
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
*/
