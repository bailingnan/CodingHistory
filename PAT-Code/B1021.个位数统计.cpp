#include<cstdio>
#include<cstring>
int main() {
	char str[1010];
	scanf("%s", str);
	int len = strlen(str);
	int Num[10] = { 0 };
	for (int i = 0; i < len; i++) {
		switch (str[i]) {
		case '0':Num[0]++;
			break;
		case '1':Num[1]++;
			break;
		case '2':Num[2]++;
			break;
		case '3':Num[3]++;
			break;
		case '4':Num[4]++;
			break;
		case'5':Num[5]++;
			break;
		case'6':Num[6]++;
			break;
		case '7':Num[7]++;
			break;
		case'8':Num[8]++;
			break;
		case '9':Num[9]++;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (Num[i])printf("%d:%d\n", i, Num[i]);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int main() {
    char str[1010];
    gets(str);
    int len = strlen(str);
    int count[10] = {0};
    for(int i = 0; i < len; i++) {
        count[str[i] - '0']++;
    }
    for(int i = 0; i < 10; i++) {
        if(count[i] != 0){
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}
