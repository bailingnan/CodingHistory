#include<cstdio>
int main() {
	int N, b,n[31];
	scanf("%d %d", &N, &b);
	int num = 0,flag=1;
	do {
		n[num++] = N % b;
		N /= b;
	} while (N);
	for (int i = num - 1; i >=num/2; i--) {
		if (n[i] != n[num - 1 - i]) {
			flag = -1;
			break;
		}
	}
	if (flag == 1) printf("Yes\n");
	else printf("No\n");
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%d", n[i]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}
//算法笔记
#include <cstdio>
bool Judge(int z[], int num) {
    for(int i = 0; i <= num / 2; i++) {
        if(z[i] != z[num - 1 - i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n, b, z[40], num = 0;
    scanf("%d%d", &n, &b);
    do {
        z[num++] = n % b;
        n /= b;
    }while(n != 0);
    bool flag = Judge(z, num);
    if(flag == true) printf("Yes\n");
    else printf("No\n");
    for(int i = num - 1; i >= 0; i--) {
        printf("%d", z[i]);
        if(i != 0) printf(" ");
    }
    return 0;
}
