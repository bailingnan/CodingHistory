#include<cstdio>//通过
#include<algorithm>
using namespace std;
int main() {
	int N, p,m=1, n[100010];
	scanf("%d%d", &N, &p);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}
	sort(n, n + N);
	for (int i = 0; i < N; i++) {
		int left = i, right = N;
		while (left < right) {
			int mid = (left + right) / 2;
			if (n[mid] > (long long)n[i] * p)
				right = mid;
			else
				left = mid + 1;
		}
		m = max(m, left - i);
	}
	printf("%d", m);
	return 0;
}
/*
#include<cstdio>//运行超时，扣3分；
#include<algorithm>
using namespace std;
int main() {
	int N, p, n[100010];
	scanf("%d%d", &N, &p);
	int len = 0, m = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}
	sort(n, n + N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (n[j]<=(long long)n[i] * p) {
				len = j - i+1;
				m = max(m, len);
			}
			else break;
		}
	}
	printf("%d", m);
}
//算法笔记
//方法一：two points
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
    int n, p, a[maxn];
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int i = 0, j = 0, count = 1;
    while(i < n && j < n) {
        while(j < n && a[j] <= (long long)a[i] * p) {
            count = max(count, j - i + 1);
            j++;
        }
        i++;
    }
    printf("%d\n", count);
    return 0;
}
方法二：二分查找
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int binarySearch(int i, long long x) {
    if(a[n - 1] <= x) return n;
    int l = i + 1, r = n - 1, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(a[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int j = binarySearch(i, (long long)a[i] * p);
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}
方法三：二分查找（使用upper_bound函数）
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int main() {
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}
*/
