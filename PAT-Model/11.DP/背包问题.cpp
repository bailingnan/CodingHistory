//01背包问题：有n件物品,每件重量w[i],价值c[i]，容量为V背包，每件物品仅有1件，使包内物品总价值最大
//dp[i][v]表示前i件物品恰好装入容量为v的背包中所能获得的最大价值
//边界dp[0][v]=0,枚举dp[n][v](0<=v<=V)
//时间和空间复杂度均为O(nV)
for (int i = 1; i <= n; i++) {
	for (int v = w[i]; v <= V; v++) {
		dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[i]);
	}
 }
 //滚动数组
for (int i = 1; i <= n; i++) {
	for (int v = V; v >= w[i]; v--) {//一定是逆序枚举v
		dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
	}
}
//完整代码
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100;//物品最大件数
const int maxv = 1000;//V的上限
int w[maxn], c[maxn], dp[maxv];
int main() {
	int n, v;
	scanf("%d%d", &n, &v);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	//边界
	for (int v = 0; v <= V; v++) {
		dp[v] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int v = V; v >= w[i]; v--) {
			dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
		}
	}
	//寻找dp[0...V]中最大的即为答案
	int max = 0;
	for (int v = 0; v <= V; v++) {
		if (dp[v] > max) {
			max = dp[v];
		}
	}
	printf("%d\n", max);
	return 0;
}
//完全背包问题：有n件物品,每件重量w[i],价值c[i]，容量为V背包，每件物品有无数件，使包内物品总价值最大
//状态转移方程：dp[i][v]=max(dp[i-1][v],dp[i][v-w[i]]+c[i])
 //滚动数组
for (int i = 1; i <= n; i++) {
	for (int v = w[i]; v<=V; v++) {//正向枚举v
		dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
	}
}
//N枚硬币去支付价值M的商品
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxv = 110;
int w[maxn], dp[maxv] = {0};
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        for(int v = m; v >= w[i]; v--) {
            if(dp[v] <= dp[v - w[i]] + w[i]) {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = 1;
            }
            else choice[i][v] = 0;
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        int k = n, num = 0, v = m;
        while(k >= 0) {
            if(choice[k][v] == 1) {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else flag[k] = false;
            k--;
        }
        for(int i = n; i >= 1; i--) {
            if(flag[i] == true) {
                printf("%d", w[i]);
                num--;
                if(num > 0) printf(" ");
            }
        }
    }
    return 0;
}
