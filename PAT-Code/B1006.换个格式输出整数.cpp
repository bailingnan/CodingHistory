#include<cstdio>
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N / 100; i++)
		printf("B");
	for (int i = 0; i < N % 100 / 10; i++)
		printf("S");
	for (int i = 1; i <= N % 10; i++)
		printf("%d", i);
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int num = 0, ans[5];
    while(n != 0) {
        ans[num] = n % 10;
        num++;
        n = n / 10;
    }
    for(int i = num - 1; i >= 0; i--) {
        if(i == 2) {
            for(int j = 0; j < ans[i]; j++){
                printf("B");
            }
        } else if(i == 1) {
            for(int j = 0; j < ans[i]; j++){
                printf("S");
            }
        } else {
            for(int j = 1; j <= ans[i]; j++){
                printf("%d", j);
            }
        }
    }
    return 0;
}
