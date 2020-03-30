#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct fr {
	ll u, d;
};
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
fr add(fr a, fr b) {
	fr c;
	c.u = a.u*b.d + a.d*b.u;
	c.d = a.d*b.d;
	return c;
}
fr re(fr a) {
	if (a.d < 0) {
		a.u = -a.u;
		a.d = -a.d;
	}
	ll t = gcd(abs(a.u), abs(a.d));
	if (t != 1) {
		a.u /= t;
		a.d /= t;
	}
	return a;
}
void sw(fr a) {
	if (a.d == 1) {
		printf("%lld", a.u);
	}
	else if (abs(a.u) > a.d) {
		printf("%lld %lld/%lld", a.u / a.d, abs(a.u) % a.d, a.d);
	}
	else printf("%lld/%lld", a.u, a.d);
}
int main() {
	fr sum = { 0,1 };
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		fr temp;
		scanf("%lld/%lld", &temp.u, &temp.d);
		sum= add(sum, temp);
	}
	if (sum.u == 0)
		printf("0");
	else
		sw(re(sum));
	return 0;
}
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct Fraction {
    ll up, down;
};
Fraction reduction(Fraction result) {
    if(result.down < 0) {
        result.up = -result.up;
        result.down = - result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
void showResult(Fraction r) {
    reduction(r);
    if(r.down == 1) printf("%lld\n", r.up);
    else if(abs(r.up) > r.down) {
        printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        printf("%lld/%lld\n", r.up , r.down);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    Fraction sum, temp;
    sum.up = 0; sum.down = 1;
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum = add(sum, temp);
    }
    showResult(sum);
    return 0;
}
