#include<cstdio>
#include<cstring>
int main() {
	char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN" };
	char str1[61], str2[61], str3[61], str4[61];
	scanf("%s%s%s%s", str1, str2, str3, str4);
	int len1, len2, len3, len4;
	len1 = strlen(str1);
	len2 = strlen(str2);
	len3 = strlen(str3);
	len4 = strlen(str4);
	int len = (len1 > len2 ? len2 : len1);
	int w,h,flag=1;
	for (int i = 0; i < len; i++) {
		if (str1[i] == str2[i] && str1[i] >= 'A'&&str1[i] <= 'G'&&flag==1) {
			w = str1[i] - 'A';
			flag=0;
			continue;
		}
		if (str1[i] == str2[i] && (str1[i] >= '0'&&str1[i] <= '9' || str1[i] >= 'A'&&str1[i] <= 'N')&&flag==0) {
			if (str1[i] >= '0'&&str1[i] <= '9') { 
				h = str1[i] - '0'; 
				break;
			}
			if (str1[i] >= 'A'&&str1[i] <= 'N') {
				h = str1[i] - 'A' + 10;
				break;
			}
		}
	}
	len = (len3 > len4 ? len4 : len3);
	int m;
	for (int i = 0; i < len; i++) {
		if (str3[i] == str4[i] && (str3[i] >= 'a'&&str3[i] <= 'z' || str3[i] >= 'A'&str3[i] <= 'Z')) {
			m = i;
			break;
		}	
	}
	printf("%s %02d:%02d\n", week[w], h, m);
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
int main() {
    char week[7][5] = {
        "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
    };
    char str1[70], str2[70], str3[70], str4[70];
    gets(str1);
    gets(str2);
    gets(str3);
    gets(str4);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    int i;
    for(i = 0; i < len1 && i < len2; i++) {
        if(str1[i] == str2[i] && str1[i] >='A' && str1[i] <= 'G') {
            printf("%s ", week[str1[i] - 'A']);
            break;
        }
    }
    for(i++; i < len1 && i < len2; i++) {
        if(str1[i] == str2[i]) {
            if(str1[i] >= '0' && str1[i] <= '9') {
                printf("%02d:", str1[i] - '0');
                break;
            } else if(str1[i] >= 'A' && str1[i] <= 'N') {
                printf("%02d:", str1[i] - 'A' + 10);
                break;
            }
        }
    }
    for(i = 0; i < len3 && i < len4; i++) {
        if(str3[i] == str4[i]) {
            if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')) {
                printf("%02d", i);
                break;
            }
        }
    }
    return 0;
}
