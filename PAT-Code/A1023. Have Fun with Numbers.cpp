#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bn {
	int b[30];
	int len;
	bn() {
		fill(b, b + 30, 0);
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
bn mul(bn a, int b) {
	bn c;
	int m=0; 
	for (int i = 0; i < a.len; i++) {
		int temp = a.b[i]*b+m;
		c.b[c.len++] = temp % 10;
		m = temp / 10;
	}
	while (m) {
		c.b[c.len++] = m % 10;
		m /= 10;
	}
	return c;
}
int main() {
	char str[30];
	int num1[10] = { 0 }, num2[10] = { 0 };
	scanf("%s", str);
	bn a,b;
	a = cg(str);
	for (int i = 0; i < a.len; i++) {
		num1[a.b[i]]++;
	}
	b = mul(a, 2);
	for (int i = 0; i < b.len; i++) {
		num2[b.b[i]]++;
	}
	int flag = 1;
	for (int i = 0; i < 10; i++) {
		if (num1[i] != num2[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		printf("Yes\n");
	}
	else printf("No\n");
	for (int i = b.len-1; i>=0; i--) {
		printf("%d", b.b[i]);
	}
	return 0;
}
//算法笔记
#include <stdio.h>
#include <string.h>
struct bign {
    int d[21];
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
bign multi(bign a, int b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
bool Judge(bign a, bign b) {
    if(a.len != b.len) return false;
    int count[10] = {0};
    for(int i = 0; i < a.len; i++) {
        count[a.d[i]]++;
        count[b.d[i]]--;
    }
    for(int i = 0; i < 10; i++) {
        if(count[i] != 0) {
            return false;
        }
    }
    return true;
}
void print(bign a) {
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}
int main() {
    char str[21];
    gets(str);
    bign a = change(str);
    bign mul = multi(a, 2);
    if(Judge(a, mul) == true) printf("Yes\n");
    else printf("No\n");
    print(mul);
    return 0;
}
