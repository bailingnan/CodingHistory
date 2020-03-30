#include<cstdio>
#include<cstring>
int main() {
	char str[10010];
	gets_s(str);
	int len = strlen(str), c[6] = { 0 };
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P')
			c[0]++;
		else if (str[i] == 'A')
			c[1]++;
		else if (str[i] == 'T')
			c[2]++;
		else if (str[i] == 'e')
			c[3]++;
		else if (str[i] == 's')
			c[4]++;
		else if (str[i] == 't')
			c[5]++;
	}
	for (int i = 0;; i++) {
		if (c[0]) {
			printf("P");
			c[0]--;
		}
		if (c[1]) {
			printf("A");
			c[1]--;
		}
		if (c[2]) {
			printf("T");
			c[2]--;
		}
		if (c[3]) {
			printf("e");
			c[3]--;
		}
		if (c[4]) {
			printf("s");
			c[4]--;
		}
		if (c[5]) {
			printf("t");
			c[5]--;
		}
		if (c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0 && c[4] == 0 && c[5] == 0)
			break;
	}
	return 0;
}
//算法笔记
#include<cstdio>
#include<cstring>
const int maxn = 10010;
//字符串，字典
char str[maxn], dict[6] = { 'P','A','T','e','s','t' };
int hashtable[6] = { 0 };//记录PATest这6个字符的个数
int main() {
	gets(str);//输入字符串
	int len = strlen(str), sum = 0;//长度，总共需要输出的字符个数
	for (int i = 0; i < len; i++) {//str[i]
		for (int j = 0; j < 6; j++) {//遍历dict字典
			if (str[i] == dict[j]) {//str[i]在字典中下标为j；
				hashtable[j]++;//个数加1
				sum++;//需要输出的字符个数为1
			}
		}
	}
	while (sum > 0) {//当输出的字符个数变成0时退出
		for (int i = 0; i < 6; i++) {//遍历hashtable数组
			if (hashtable[i] > 0) {//hashtable[i]>0
				printf("%c", dict[i]);//输出该字符
				hashtable[i]--;//个数减1
				sum--;//需要输出的字符个数减1
			}
		}
	}
	return 0;
}
