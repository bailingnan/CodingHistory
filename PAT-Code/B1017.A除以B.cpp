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
	bn bnum;
	bnum.len= strlen(a);
	for (int i = 0; i < bnum.len; i++) {
		bnum.b[i] = a[bnum.len - 1 - i] - '0';
	}
	return bnum;
}
bn cf(bn a,int b,int &r) {
	bn m;
	m.len = a.len;
	for (int i = m.len - 1; i >= 0; i--) {
		r = r * 10 + a.b[i];
		if (r / b == 0)
			m.b[i] = 0;
		else {
			m.b[i] = r / b;
			r = r % b;
		}
	}
	while (m.len - 1 >= 1 && m.b[m.len - 1] == 0)
		m.len--;
	return m;
}
int main() {
	bn a, c;
	char str[1001];
	int m;
	scanf("%s%d", str,&m);
	a = cg(str);
	int r = 0;
	c = cf(a, m,r);
	for (int i = c.len - 1; i >= 0; i--) {
		printf("%d", c.b[i]);
	}
	printf(" %d", r);
	return 0;
}
/*
//算法笔记
#include <stdio.h>
#include <string.h>
struct bign {
    int d[1010];
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
bign divide(bign a, int b, int& r) {
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
void print(bign a) {
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}
int main() {
    char str1[1010], str2[1010];
    int b, r = 0;
    scanf("%s%d", str1, &b);
    bign a = change(str1);
    print(divide(a, b, r));
    printf(" %d", r);
    return 0;
}
*/
