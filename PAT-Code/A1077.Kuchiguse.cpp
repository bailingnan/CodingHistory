#include<cstdio>
#include<cstring>
void re(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char t = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = t;
	}
}
int main() {
	char str[110][300];
	int n;
	scanf("%d", &n);
	getchar();
	int min = 300;
	for (int i = 0; i < n; i++) {
		gets(str[i]);
		re(str[i]);
		if (strlen(str[i]) < min)
			min = strlen(str[i]);
	}
	int i,flag=1;
	for (i = 0; i < min; i++) {
		for (int j = 0; j < n; j++) {
			if (str[j][i] != str[0][i]) {
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	int cnt = i - 1;
	if (cnt ==-1)
		printf("nai\n");
	else {
		for (int k = cnt; k >= 0; k--) {
			printf("%c", str[0][k]);
			if (k == 0) printf("\n");
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int n, minLen = 256, ans = 0;
char s[100][256];
int main() {
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        gets(s[i]);
        int len = strlen(s[i]);
        if(len < minLen) minLen = len;
        for(int j = 0; j < len / 2; j++) {
            char temp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = temp;
        }
    }
    for(int i = 0; i < minLen; i++) {
        char c = s[0][i];
        bool same = true;
        for(int j = 1; j < n; j++) {
            if(c != s[j][i]) {
                same = false;
                break;
            }
        }
        if(same) ans++;
        else break;
    }
    if(ans) {
        for(int i = ans - 1; i >= 0; i--) {
            printf("%c", s[0][i]);
        }
    } else {
        printf("nai");
    }
    return 0;
}
