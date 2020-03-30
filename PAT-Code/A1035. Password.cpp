#include<cstdio>
#include<cstring>
struct User{
	char nm[20];
	char pwd[20];
	int flag = 0;
}u[1010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s",u[i].nm,u[i].pwd);
	}
	int cnt = n;
	for (int i = 0; i < n; i++) {
		int len = strlen(u[i].pwd);
		for (int j = 0; j < len; j++) {
			if (u[i].pwd[j] == '1') {
				u[i].pwd[j] = '@';
				u[i].flag = 1;
				continue;
			}
			if (u[i].pwd[j] == '0') {
				u[i].pwd[j] = '%';
				u[i].flag = 1;
				continue;
			}
			if (u[i].pwd[j] == 'l') {
				u[i].pwd[j] = 'L';
				u[i].flag = 1;
				continue;
			}
			if (u[i].pwd[j] == 'O') {
				u[i].pwd[j] = 'o';
				u[i].flag = 1;
				continue;
			}
		}
		if (u[i].flag == 1) cnt--;
	}
	if (cnt == n) {
		if (cnt == 1)
			printf("There is %d account and no account is modified", n);
		else
			printf("There are %d accounts and no account is modified", n);
	}
	else {
		printf("%d\n", n - cnt);
		for (int i = 0; i < n; i++) {
			if (u[i].flag == 1)
				printf("%s %s\n", u[i].nm, u[i].pwd);
		}
	}
}
//算法笔记
#include <cstdio>
#include <cstring>
struct node {
    char name[20], password[20];
    bool ischange;
}T[1005];
void crypt(node& t, int& cnt) {
    int len = strlen(t.password);
    for(int i = 0; i < len; i++) {
        if(t.password[i] == '1') {
            t.password[i] = '@';
            t.ischange = true;
        } else if(t.password[i] == '0') {
            t.password[i] = '%';
            t.ischange = true;
        } else if(t.password[i] == 'l') {
            t.password[i] = 'L';
            t.ischange = true;
        } else if(t.password[i] == 'O') {
            t.password[i] = 'o';
            t.ischange = true;
        }
    }
    if(t.ischange) {
        cnt++;
    }
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s", T[i].name, T[i].password);
        T[i].ischange = false;
    }
    for(int i = 0; i < n; i++) {
        crypt(T[i], cnt);
    }
    if(cnt == 0) {
        if(n == 1) printf("There is %d account and no account is modified", n);
        else {
            printf("There are %d accounts and no account is modified", n);
        }
    }else {
        printf("%d\n", cnt);
        for(int i = 0; i < n; i++) {
            if(T[i].ischange) {
                printf("%s %s\n", T[i].name, T[i].password);
            }
        }
    }
    return 0;
}
