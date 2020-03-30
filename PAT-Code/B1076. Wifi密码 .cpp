#include<cstdio>
#include<cstring>
int N, pd[101],cnt=0;
int main() {
	scanf("%d", &N);
	int num[4] = { 1,2,3,4 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			char str[3];
			scanf("%s", &str);
			if (str[2] == 'T') {
				pd[cnt++] = num[str[0]- 'A'];
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d", pd[i]);
	}
	return 0;
}
