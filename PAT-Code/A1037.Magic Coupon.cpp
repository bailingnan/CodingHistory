#include<cstdio>//可通过PAT，牛客网。
#include<algorithm>
using namespace std;
bool cmp(long long a, long long b) {
	return a > b;
}
int main() {
	int N, M;
	long long a[100010], b[100010];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &b[i]);
	}
	sort(a, a + N, cmp);
	sort(b, b + M, cmp);
	long long sum = 0;
	for (int i = 0; i < N&&i < M; i++) {
		if (a[i] > 0 && b[i] > 0)
			sum += a[i] * b[i];
	}
	sort(a, a + N);
	sort(b, b + M);
	for (int i = 0; i < N&&i < M; i++) {
		if (a[i] < 0 && b[i] < 0)
			sum += a[i] * b[i];
	}
	printf("%lld", sum);
	return 0;
}
//算法笔记，可通过PAT,完全通不过牛客网。
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int coupon[maxn], product[maxn];
int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &product[i]);
    }
    sort(coupon, coupon + n);
    sort(product, product + m);
    int i = 0, j, ans = 0;
    while(i < n && i < m && coupon[i] < 0 && product[i] < 0) {
        ans += coupon[i] * product[i];
        i++;
    }
    i = n - 1;
    j = m - 1;
    while(i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0) {
        ans += coupon[i] * product[j];
        i--, j--;
    }
    printf("%d\n", ans);
    return 0;
}
