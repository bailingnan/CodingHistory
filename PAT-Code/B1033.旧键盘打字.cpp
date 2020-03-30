#include<cstdio>
#include<cstring>
int main() {
	char c[100010], str[100010];
	gets(c);
	gets(str);
	int len = strlen(str), lenc = strlen(c);
	int flag = 0, num[128] = { 0 };
	for (int i = 0; i < lenc; i++) {
		if (c[i] >= '0'&&c[i] <= '9')
			num[26 + c[i] - '0'] = 1;
		else if (c[i] >= 'A'&&c[i] <= 'Z')
			num[c[i] - 'A'] = 1;
		else if (c[i] == '_')
			num[36] = 1;
		else if (c[i] == ',')
			num[37] = 1;
		else if (c[i] == '.')
			num[38] = 1;
		else if (c[i] == '-')
			num[39] = 1;
		else if (c[i] == '+')
			num[40] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0'&&str[i] <= '9') {
			if (num[26 + str[i] - '0'] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] >= 'a'&&str[i] <= 'z') {
			if (num[str[i] - 'a'] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] >= 'A'&&str[i] <= 'Z') {
			if (num[str[i] - 'A'] == 0 && num[40] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] == '_') {
			if (num[36] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] == ',') {
			if (num[37] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] == '.') {
			if (num[38] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] == '-') {
			if (num[39] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
		else if (str[i] == '+') {
			if (num[40] == 0) {
				printf("%c", str[i]);
				cnt++;
			}
		}
	}
	if (cnt == 0)
		printf("\n");
	return 0;
}
//算法导论
/*
#include <cstdio>
#include <cstring>
const int maxn = 100010;
bool hashTable[256];
char str[maxn];
int main() {
    memset(hashTable, true, sizeof(hashTable));
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        hashTable[str[i]] = false;
    }
    gets(str);
    len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            int low = str[i] - 'A' + 'a';
            if(hashTable[low] == true && hashTable['+'] == true) {
                printf("%c", str[i]);
            }
        } else if(hashTable[str[i]] == true) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
*/
