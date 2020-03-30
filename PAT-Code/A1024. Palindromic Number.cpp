#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bn {
	int b[1000];
	int len;
	bn() {
		fill(b, b + 1000, 0);
		len = 0;
	}
};
bn cg(char a[]) {
	bn m;
	m.len = strlen(a);
	for (int i = 0; i < m.len; i++) {
		m.b[i] = a[m.len - 1 - i] - '0';
	}
	return m;
}
bool isp(bn a) {
	for (int i = 0; i < a.len / 2; i++) {
		if (a.b[i] != a.b[a.len - 1 - i])
			return false;
	}
	return true;
}
bn add(bn a, bn b) {
	bn c;
	int m = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = a.b[i] + b.b[i] + m;
		c.b[c.len++] = temp % 10;
		m = temp / 10;
	}
	if (m != 0) {
		c.b[c.len++] = m;
	}
	return c;
}
bn re(bn a) {
	for (int i = 0; i < a.len/2; i++) {
		int temp = a.b[i];
		a.b[i] = a.b[a.len - 1 - i];
		a.b[a.len - 1 - i] = temp;
	}
	return a;
}
int main() {
	int N;
	char str[11];
	scanf("%s%d", str, &N);
	bn a = cg(str);
	int cnt;
	if (isp(a)) {
		for (int i = a.len - 1; i >= 0; i--) {
			printf("%d", a.b[i]);
		}
		printf("\n");
		printf("0");
	}
	else {
		for (cnt = 1; cnt <= N; cnt++) {
			bn b = add(a, re(a));
			if (isp(b)) {
				a = b;
				break;
			}
			else
				a = b;
		}
		for (int i = a.len - 1; i >= 0; i--) {
			printf("%d", a.b[i]);
		}
		printf("\n");
		if (cnt <= N) {
			printf("%d", cnt);
		}
		else printf("%d", cnt - 1);
	}
	return 0;
}
//算法笔记
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for(int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}
bool Judge(bign a) {
    for(int i = 0; i <= a.len / 2; i++) {
        if(a.d[i] != a.d[a.len - 1 - i]) {
            return false;
        }
    }
    return true;
}
void print(bign a) {
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}
int main() {
    char str[1000];
    int T, k = 0;
    scanf("%s %d", str, &T);
    bign a = change(str);
    while(k < T && Judge(a) == false) {
        bign b = a;
        reverse(b.d, b.d + b.len);
        a = add(a, b);
        k++;
    }
    print(a);
    printf("%d\n", k);
    return 0;
}
