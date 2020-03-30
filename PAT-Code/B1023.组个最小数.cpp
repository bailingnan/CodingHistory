#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int cnt=0,num[60];
	for (int i = 0; i < 10; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j < temp; j++)
			num[cnt++] = i;
	}
	sort(num, num + cnt);
	int m;
	for (int i = 0; i < cnt; i++) {
		if (num[i] != 0) {
			printf("%d", num[i]);
			m = i;
			break;
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (i != m) {
			printf("%d", num[i]);
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    int count[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &count[i]);
    }
    for(int i = 1; i < 10; i++) {
        if(count[i] > 0) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d", i);
        }
    }
    return 0;
}
