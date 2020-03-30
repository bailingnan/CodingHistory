#include<cstdio>//最后一个测试用例不通过，扣2分。
#include<cstring>
int main() {
	char A[110], B[110], C[110], num[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
	scanf("%s %s", A, B);
	int len1 = strlen(A);
	int len2 = strlen(B);
	int cnt = 1;
	int len = (len1 > len2 ? len1 : len2);
	int i, j, k;
	for (i = len1 - 1, j = len2 - 1,k=len-1; i >= 0 && j >= 0; i--, j--,k--) {
		if (cnt % 2 == 1) {
			C[k] = num[(A[i] - '0' + B[j] - '0') % 13];
			cnt++;
		}
		else {
			if (B[j] - A[i] < 0) {
				C[k] = B[j] - A[i] + 10 + '0';
				cnt++;
			}
			else {
				C[k] = B[j] - A[i] + '0';
				cnt++;
			}
		}
	}
	if (i < 0&&j>=0) {
		for (int m = 0; m < len2 - len1; m++) {
			C[m] = B[m];
		}
	}
	if (j < 0 && i >= 0) {
		for (int m = len1-len2-1; m>=0; m--) {
			if (cnt % 2 == 0) {
				C[m] = -1*(A[m] - '0') + 10+'0';
				cnt++;
			}
			else {
				C[m] = A[m];
				cnt++;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%c", C[i]);
	}
	return 0;
}
//算法笔记
/*
#include<cstdio>]
#include<cstring>
const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = { 0 };
void reverse(char s[]) {    
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		int temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
int main() {
	scanf("%s %s", A, B);
	reverse(A);
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int len = lenA > lenB ? lenA : lenB;
	for (int i = 0; i < len; i++) {
		int numA = i < lenA ? A[i] - '0' : 0;
		int numB = i < lenB ? B[i] - '0' : 0;
		if (i % 2 == 0) {
			int temp = (numB + numA) % 13;
			if (temp == 10)ans[i] = 'J';
			else if (temp == 11) ans[i] = 'Q';
			else if (temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		else {
			int temp = numB - numA;
			if (temp < 0) temp += 10;
			ans[i] = temp + '0';
		}
	}
	reverse(ans);
	puts(ans);
	return 0;
}
*/
