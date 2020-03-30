#include<cstdio>
#include<cstring>
struct Person {
	char str[20];
	int flag=1;
	int Num[17];
}P[100];
bool IsNum(char a) {
	return(a >= '0'&&a <= '9');
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", P[i].str);
		int len = strlen(P[i].str);
		for (int j = 0; j < len-1; j++) {
			if (!IsNum(P[i].str[j])) {
				P[i].flag = 0;
				break;
			}
			else {
				P[i].Num[j] = P[i].str[j] - '0';
			}
		}
		if (P[i].flag == 0) continue;
		else {
			int sum = 0;
			int coe[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
			char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
			for (int k = 0; k < 17; k++) {
				sum += P[i].Num[k] * coe[k];
			}
			int Z = sum % 11;
			if (P[i].str[17] != M[Z])
				P[i].flag = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (P[i].flag == 0) {
			printf("%s\n", P[i].str);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("All passed\n");
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char change[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main() {
    int n;
    scanf("%d", &n);
    bool flag = true;
    char str[20];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        int j, last = 0;
        for(j = 0; j < 17; j++) {
            if(!(str[j] >= '0' && str[j] <= '9')) break;
            last = last + (str[j] - '0') * w[j];
        }
        if(j < 17) {
            flag = false;
            printf("%s\n", str);
        } else {
            if(change[last % 11] != str[17]) {
                flag = false;
                printf("%s\n", str);
            }
        }
    }
    if(flag == true) {
        printf("All passed\n");
    }
    return 0;
}
