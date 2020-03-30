#include<cstdio>
#include<cstring>
int main() {
	char str[10][10] = { "ling","yi", "er", "san","si","wu","liu","qi","ba","jiu" };
	char num[110];
	int sum = 0;
	scanf("%s", num);
	int len = strlen(num);
	int n[4], cnt = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i] - '0';
	}
	do{
		n[cnt++] = sum % 10;
		sum /= 10;
	} while (sum);
	for (int i = cnt-1; i>=0; i--) {
		printf("%s", str[n[i]]);
		if (i > 0) printf(" ");
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int main() {
    char str[110];
    gets(str);
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += str[i] - '0';
    }
    int num = 0, ans[10];
    while(sum != 0) {
        ans[num] = sum % 10;
        num++;
        sum /= 10;
    }
    char change[10][5] = {
        "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
    };
    for(int i = num - 1; i >= 0; i--) {
        printf("%s", change[ans[i]]);
        if(i != 0) printf(" ");
        else printf("\n");
    }
    return 0;
}
