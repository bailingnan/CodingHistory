#include<cstdio>
#include<cstring>
int main() {
	char str[1010];
	gets_s(str);
	int len = strlen(str), c[26] = { 0 };
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z')
			c[str[i] - 'A']++;
		if (str[i] >= 'a'&&str[i] <= 'z')
			c[str[i] - 'a']++;
	}
	int max = 0, maxn = 0;;
	for (int i = 25; i >= 0; i--) {
		if (c[i] >= max) {
			max = c[i];
			maxn = i;
		}
	}
	printf("%c %d", 'a' + maxn, max);
	return 0;
}
