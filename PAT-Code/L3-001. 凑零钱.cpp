#include <cstdio>//01背包问题
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxv = 110;
int w[maxn], dp[maxv] = { 0 };
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = m; v >= w[i]; v--) {
			if (dp[v] <= dp[v - w[i]] + w[i]) {
				dp[v] = dp[v - w[i]] + w[i];
				choice[i][v] = 1;
			}
			else choice[i][v] = 0;
		}
	}
	if (dp[m] != m) printf("No Solution");
	else {
		int k = n, num = 0, v = m;
		while (k >= 0) {
			if (choice[k][v] == 1) {
				flag[k] = true;
				v -= w[k];
				num++;
			}
			else flag[k] = false;
			k--;
		}
		for (int i = n; i >= 1; i--) {
			if (flag[i] == true) {
				printf("%d", w[i]);
				num--;
				if (num > 0) printf(" ");
			}
		}
	}
	return 0;
}
/*DFS剪枝，超时，扣5分；
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> temp, ans;
void DFS(int index, int value) {
	if (index == N) {
		return;
	}
	if (value+v[index]== M) {
		temp.push_back(v[index]);
		if (ans.size() == 0) {
			ans = temp;
		}
		return;
	}
	else if (value + v[index] < M) {
		temp.push_back(v[index]);
		DFS(index + 1, value + v[index]);
		temp.pop_back();
	}
	DFS(index + 1, value);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	DFS(0, 0);
	if (ans.size() == 0) {
		printf("No Solution");
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%d", ans[i]);
			if (i < ans.size() - 1) {
				printf(" ");
			}
		}
	}
	return 0;
}
*/
/*DFS，超时，扣5分
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
vector<int> temp, ans;
void DFS(int index, int value) {
	if (value == M) {
		if (ans.size() == 0) {
			ans = temp;
			return;
		}
	}
	if (value > M || index >= N) return;
	temp.push_back(v[index]);
	DFS(index + 1, value + v[index]);
	temp.pop_back();
	DFS(index + 1, value);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	DFS(0, 0);
	if (ans.size() == 0) {
		printf("No Solution");
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%d", ans[i]);
			if (i < ans.size() - 1) {
				printf(" ");
			}
		}
	}
	return 0;
}
*/
