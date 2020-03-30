#include<cstdio>
#include<cstring>
int main(){
	char str1[200], str2[200];
	int num[100] = { 0 };
	gets(str1);
	gets(str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	int i=0,j = 0;
	for (; i < len2; i++) {
		for (; j < len1; j++) {
			if (str1[j] != str2[i]) {
				if (str1[j] >= '0'&&str1[j] <= '9') {
					if (num[26 + str1[j] - '0'] == 0)
						printf("%c", str1[j]);
					num[26 + str1[j] - '0']++;
				}
				else if (str1[j] >= 'a'&&str1[j] <= 'z') {
					if (num[str1[j] - 'a'] == 0)
						printf("%c", 'A'+str1[j]-'a');
					num[str1[j] - 'a']++;
				}
				else if (str1[j] >= 'A'&&str1[j] <= 'Z') {
					if (num[str1[j] - 'A'] == 0)
						printf("%c", str1[j]);
					num[str1[j] - 'A']++;
				}
				else if (str1[j] == '_') {
					if (num[36] == 0)
						printf("_");
					num[36]++;
				}
			}
			else {
				j++;
				break;
			}
		}
	}
	if (j < len1) {
		for (; j < len1; j++) {
			if (str1[j] >= '0'&&str1[j] <= '9') {
				if (num[26 + str1[j] - '0'] == 0)
					printf("%c", str1[j]);
				num[26 + str1[j] - '0']++;
			}
			else if (str1[j] >= 'a'&&str1[j] <= 'z') {
				if (num[str1[j] - 'a'] == 0)
					printf("%c", 'A' + str1[j] - 'a');
				num[str1[j] - 'a']++;
			}
			else if (str1[j] >= 'A'&&str1[j] <= 'Z') {
				if (num[str1[j] - 'A'] == 0)
					printf("%c", str1[j]);
				num[str1[j] - 'A']++;
			}
			else if (str1[j] == '_') {
				if (num[36] == 0)
					printf("_");
				num[36]++;
			}
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int main() {
    char str1[100], str2[100];
    bool HashTable[128] = {false};
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0; i < len1; i++) {
        int j;
        char c1, c2;
        for(j = 0; j < len2; j++) {
            c1 = str1[i];
            c2 = str2[j];
            if(c1 >= 'a' && c1 <= 'z') c1 -= 32;
            if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if(c1 == c2) break;
        }
        if(j == len2 && HashTable[c1] == false) {
            printf("%c", c1);
            HashTable[c1] = true;
        }
    }
    return 0;
}
