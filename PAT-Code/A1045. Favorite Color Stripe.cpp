#include<cstdio>
#include<algorithm>
using namespace std;
int order[210], col[10010],dp[10010],N, M, L;
int check(int m) {
	for (int i = 1; i <= M; i++) {
		if (order[i] == m)
			return i;
	}
	return 0;
}
int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &order[i]);
	}
	scanf("%d", &L);
	int cnt = 1;
	for (int i = 1; i <= L; i++) {
		int m;
		scanf("%d", &m);
		int temp = check(m);
		if (temp > 0) {
			col[cnt++] = temp;
		}
	}
	int ans = -1;
	for (int i = 1; i <cnt; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (col[j] <= col[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}
//算法笔记，方法一：最长不下降子序列(LIS)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int HashTable[maxc];
int A[maxn], dp[maxn];
int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    memset(HashTable, -1, sizeof(HashTable));
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        HashTable[x] = i;
    }
    int L, num = 0;
    scanf("%d", &L);
    for(int i = 0; i < L; i++) {
        scanf("%d", &x);
        if(HashTable[x] >= 0) {
            A[num++] = HashTable[x];
        }
    }
    int ans = -1;
    for(int i = 0; i < num; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(A[j] <= A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
方法二：最长公共子序列(LCS)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int A[maxc], B[maxn], dp[maxc][maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &A[i]);
    }
    int L;
    scanf("%d", &L);
    for(int i = 1; i <= L; i++) {
        scanf("%d", &B[i]);
    }
    for(int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= L; j++) {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= L; j++) {
            int MAX = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            if(A[i] == B[j]) {
                dp[i][j] = MAX + 1;
            } else {
                dp[i][j] = MAX;
            }
        }
    }
    printf("%d\n", dp[m][L]);
    return 0;
}
