#include<cstdio>//DFS版本,超时，扣5分
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 10010;
const int INF = 1000000000;
int N, M, num[MAXN],flag=0;
vector<int> v, temp;
void DFS(int i, int sum) {
	if (sum == M) {
		if (temp[0] < v[0]) {
			v = temp;
			flag = 1;
			return;
		}
	}
	if (i > N - 1||sum>M)
		return;
	temp.push_back(num[i]);
	DFS(i + 1, sum + num[i]);
	temp.pop_back();
	DFS(i + 1, sum);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	v.push_back(INF);
	sort(num, num + N);
	DFS(0, 0);
	if (flag == 0)
		printf("No Solution");
	else {
		for (int i = 0; i < v.size(); i++) {
			printf("%d", v[i]);
			if (i < v.size() - 1) {
				printf(" ");
			}
		}
	}
	return 0;
}
//算法笔记
/*
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
*/
