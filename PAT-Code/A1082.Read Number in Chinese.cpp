#include<cstdio>
int main() {
	char t[10][10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int num,n[10];
	scanf("%d", &num);
	if (num < 0) {
		printf("Fu ");
		num = -num;
	}
	int cnt = 0;
	if (num == 0)
		printf("%s", t[num]);
	else {
		int temp = num;
		while (num) {
			n[cnt++] = num % 10;
			num /= 10;
		}
		for (int i = cnt - 1; i >= 0; i--) {//80000008,80008000,80000000,808080808
			int flag, m;
			if (n[i] == 0) {
				flag = 0,m;
				for (int j = i; j >= 0; j--) {
					if (n[j] != 0) { 
						m = j;
						flag = 1; 
						break;
					}
				}
				if (flag == 0) {
					if (i >=4&&i<=6)
						printf(" Wan");
					break;
				}
				else {
						if (m <= 3)
						{	
							if (i == 7&&m==3)
								printf("ling ");
							if (i>=4&&i<=6)
								printf("Wan ");
							if (m < 3)
								printf("ling ");
						}
						else printf("ling ");
						i = m + 1;
				}
			}
			if (n[i] != 0) {
				printf("%s", t[n[i]]);
				if (i > 0) printf(" ");
				if (i + 1 == 9) {
					printf("Yi");
					if (temp % 100000000 != 0)
						printf(" ");
				}
				if (i + 1 == 8) {
					printf("Qian");
					if (temp % 10000000 != 0)
						printf(" ");
				}
				if (i + 1 == 7) {
					printf("Bai");
					if (temp % 1000000 != 0)
						printf(" ");
				}
				if (i + 1 == 6)
				{
					printf("Shi");
					if (temp % 100000 != 0)
						printf(" ");
				}
				if (i + 1 == 5)
				{
					printf("Wan");
					if (temp % 10000 != 0)
						printf(" ");
				}
				if (i + 1 == 4) {
					printf("Qian");
					if (temp % 1000 != 0)
						printf(" ");
				}
				if (i + 1 == 3) {
					printf("Bai");
					if (temp % 100 != 0)
						printf(" ");
				}
				if (i + 1 == 2) {
					printf("Shi");
					if (temp % 10 != 0)
						printf(" ");
				}
			}
		}
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <cstring>
char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
    char str[15];
    gets(str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if(str[0] == '-') {
        printf("Fu");
        left++;
    }
    while(left + 4 <= right) {
        right -= 4;
    }
    while(left < len) {
        bool flag = false;
        bool isPrint = false;
        while(left <= right) {
            if(left > 0 && str[left] == '0') {
                flag = true;
            } else {
                if(flag == true) {
                    printf(" ling");
                    flag = false;
                }
                if(left > 0) {
                    printf(" ");
                }
                printf("%s", num[str[left] - '0']);
                isPrint = true;
                if(left != right) {
                    printf(" %s", wei[right - left - 1]);
                }
            }
            left++;
        }
        if(isPrint == true && right != len - 1) {
            printf(" %s", wei[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }
    return 0;
}
*/
