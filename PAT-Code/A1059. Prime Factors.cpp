#include<cstdio>
#include<cmath>
const int maxn = 1000001;
int p[maxn] = { 0 },pe[maxn],cnt=0;
void fp() {
	p[1] = p[0] = 1;
	for (int i = 0; i < maxn; i++) {
		if (p[i] == 0) {
			pe[cnt++] = i;
			for (int j = i + i; j < maxn; j += i)
				p[j] = 1;
		}
	}
}
struct prm{
	int x, cnt=0;
}pm[10];
int main() {
	fp();
	int n,temp,sqr,num=0;
	scanf("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	temp = n;
	sqr = (int)sqrt(1.0*n);
	for (int i = 0; pe[i] <=sqr; i++) {
		if (n%pe[i] == 0) {
			pm[num].x = pe[i];
			while (n%pe[i] == 0) {
				pm[num].cnt++;
				n /= pe[i];
			}
			num++;
		}
	}
	if (n != 1) {
		pm[num].x = n;
		pm[num].cnt++;
	}
	else num--;
	printf("%d=", temp);
	for (int i = 0; i <=num; i++) {
		if (i > 0)
			printf("*");
		printf("%d", pm[i].x);
		if (pm[i].cnt > 1)
			printf("^%d", pm[i].cnt);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <math.h>
const int maxn = 100010;
bool is_prime(int n) {
    if(n == 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int prime[maxn], pNum = 0;
void Find_Prime() {
    for(int i = 1; i < maxn; i++) {
        if(is_prime(i) == true) {
            prime[pNum++] = i;
        }
    }
}
struct factor {
    int x, cnt;
}fac[10];
int main() {
    Find_Prime();
    int n, num = 0;
    scanf("%d", &n);
    if(n == 1) printf("1=1");
    else {
        printf("%d=", n);
        int sqr = (int)sqrt(1.0 * n);
        for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
            if(n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while(n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if(n == 1) break;
        }
        if(n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for(int i = 0; i < num; i++) {
            if(i > 0) printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt > 1) {
                printf("^%d", fac[i].cnt);
            }
        }
    }
    return 0;
}
