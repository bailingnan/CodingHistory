#include<cstdio>
int main() {
	int C[3],M[31];
	for (int i = 0; i < 3; i++)
		scanf("%d", &C[i]);
	printf("#");
	for (int i = 0; i < 3; i++) {
		int num = 0;
		do {
			M[num++] = C[i] % 13;
			C[i] /= 13;
		} while (C[i]);
		for (int j = num - 1; j >= 0; j--) {
			if (num > 1) {
				if (M[j] < 10) printf("%d", M[j]);
				else {
					switch (M[j]) {
					case 10:printf("A");
						break;
					case 11:printf("B");
						break;
					case 12:printf("C");
						break;
					}
				}
			}
			else {
				if (M[j] < 10) printf("%02d", M[j]);
				else {
					switch (M[j]) {
					case 10:printf("0A");
						break;
					case 11:printf("0B");
						break;
					case 12:printf("0C");
						break;
					}
				}
			}
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
char radix[13] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};
int main() {
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    printf("#");
    printf("%c%c", radix[r / 13], radix[r % 13]);
    printf("%c%c", radix[g / 13], radix[g % 13]);
    printf("%c%c", radix[b / 13], radix[b % 13]);
    return 0;
}
