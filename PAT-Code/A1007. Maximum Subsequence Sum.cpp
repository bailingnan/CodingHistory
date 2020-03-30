#include<cstdio>//注意测试用例：N=2 -1,0
#include<algorithm>
#include<vector>
using namespace std;
vector<int> temp, maxn;
int main() {
	int N,num[100010],flag=1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		if (num[i] >= 0)
			flag = 0;
	}
	int t = 0, maxm =-1;
	for (int i = 0; i < N; i++) {
		t += num[i];
		temp.push_back(num[i]);
		if (t> maxm) {
			maxm = t;
			maxn = temp;
		}
		if (t < 0) {
			t = 0;
			temp.clear();
		}
	}
	if (flag == 1) {
		printf("0 %d %d", num[0], num[N - 1]);
	}
	else {
		printf("%d %d %d", maxm, maxn[0], maxn[maxn.size() - 1]);
	}
	return 0;
}
#include<cstdio>
int main() {
	int num[10010], K,flag=0;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num[i]);
		if (num[i] >=0)
			flag = 1;
	}
	int maxsum = -1, sum = 0,st,ed,temp;
	for (int i = 0; i < K; i++) {
		if (sum == 0) {
			temp = num[i];
		}
		sum += num[i];
		if (sum < 0) {
			sum = 0;
		}
		else if (sum > maxsum) {
			maxsum = sum;
			st = temp;
			ed = num[i];
		}
	}
	if (flag == 0) {
		printf("0 %d %d", num[0], num[K - 1]);
	}
	else {
		printf("%d %d %d", maxsum,st,ed);
	}
	return 0;
}
//算法笔记
#include <cstdio>
const int maxn = 10010;
int a[maxn], dp[maxn];
int s[maxn] = {0};
int main() {
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] >= 0) flag = true;
    }
    if(flag == false) {
        printf("0 %d %d\n", a[0], a[n - 1]);
        return 0;
    }
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] + a[i] > a[i]) {
            dp[i] = dp[i - 1] + a[i];
            s[i] = s[i - 1];
        } else {
            dp[i] = a[i];
            s[i] = i;
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++) {
        if(dp[i] > dp[k]) {
            k = i;
        }
    }
    printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
    return 0;
}
