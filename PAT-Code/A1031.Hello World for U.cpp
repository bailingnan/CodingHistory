#include<cstdio>
#include<cstring>
int main()
{
	char str[100];
	scanf("%s", str);
	int N = strlen(str);
	int a, b; //b = N + 2 - 2 * a,3<=b<=N,a<=b,a尽可能大
	a = (N + 2) / 3;
	b = N + 2 - 2 * a;
	for (int i = 0; i < a; i++)
	{
		if (i != a - 1)
		{
			printf("%c", str[i]);
			for (int j = 0; j < b - 2; j++)
				printf(" ");
			printf("%c\n", str[N - 1 - i]);
		}
		else
		{
			for (int k = a - 1; k < a + b - 1; k++)
				printf("%c", str[k]);
			printf("\n");
		}
	}
	return 0;
}
//算法笔记
//方法一：二维数组方式
#include <cstdio>
#include <cstring>
int main() {
    char str[100], ans[40][40];
    gets(str);
    int N = strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            ans[i][j] = ' ';
        }
    }
    int pos = 0;
    for(int i = 1; i <= n1; i++) {
        ans[i][1] = str[pos++];
    }
    for(int j = 2; j <= n2; j++) {
        ans[n1][j] = str[pos++];
    }
    for(int i = n3 - 1; i >= 1; i--) {
        ans[i][n2] = str[pos++];
    }
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//方法二：直接输出方式
#include <cstdio>
#include <cstring>
int main() {
    char str[100];
    gets(str);
    int N = strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]);
        for(int j = 0; j < n2 - 2; j++) {
            printf(" ");
        }
        printf("%c\n", str[N - i - 1]);
    }
    for(int i = 0; i < n2; i++) {
        printf("%c", str[n1 + i - 1]);
    }
    return 0;
}
