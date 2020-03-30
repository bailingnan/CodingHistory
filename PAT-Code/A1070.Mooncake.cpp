#include<cstdio>
#include<algorithm>
using namespace std;
struct MC {
	double k, s, p;
}m[1010];
bool cmp(MC a, MC b) {
	return a.p > b.p;
}
int main() {
	int N;
	double D;
	scanf("%d%lf", &N, &D);
	for (int i = 0; i < N; i++) {
		scanf("%lf", &m[i].k);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lf", &m[i].s);
	}
	for (int i = 0; i < N; i++) {
		m[i].p = m[i].s / m[i].k;
	}
	sort(m, m + N, cmp);
	double sum = 0;
	for (int i = 0; i < N; i++) {
		if (m[i].k >= D) {
			sum += D * m[i].p;
			break;
		}
		else {
			D = D - m[i].k;
			sum += m[i].s;
		}
	}
	printf("%.2f", sum);
	return 0;
}
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
struct mooncake {
    double store;
    double sell;
    double price;
}cake[1010];
bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}
int main() {
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].store);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].sell);
        cake[i].price = cake[i].sell / cake[i].store;
    }
    sort(cake, cake + n, cmp);
    double ans = 0;
    for(int i = 0; i < n; i++) {
        if(cake[i].store <= D) {
            D -= cake[i].store;
            ans += cake[i].sell;
        } else {
            ans += cake[i].price * D;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
