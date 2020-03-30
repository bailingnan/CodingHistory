#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll Num[2000010];
int main() {
	int N1,N2,m;
	scanf("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf("%lld", &Num[i]);
	}
	scanf("%d", &N2);
	for (int i = N1; i < N1 + N2; i++) {
		scanf("%lld", &Num[i]);
	}
	sort(Num, Num + N1 + N2);
	if ((N1 + N2) % 2 == 1) {
		m = (N1 + N2) / 2 + 1;
	}
	else {
		m = (N1 + N2) / 2;
	}
	printf("%lld", Num[m - 1]);
	return 0;
}
//算法笔记
#include <cstdio>
const int maxn = 1000010;
const int INF = 0x7fffffff;
int S1[maxn], S2[maxn];
int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &S1[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &S2[i]);
    }
    S1[n] = S2[m] = INF;
    int medianPos = (n + m - 1) / 2;
    int i = 0, j = 0, count = 0;
    while(count < medianPos) {
        if(S1[i] < S2[j]) i++;
        else j++;
        count++;
    }
    if(S1[i] < S2[j]) {
        printf("%d\n", S1[i]);
    } else {
        printf("%d\n", S2[j]);
    }
    return 0;
}
