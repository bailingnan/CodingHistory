#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	int N,maxnum=-1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		maxnum = max(maxnum, temp);
		v.push_back(temp);
	}
	int K = min(maxnum, N);
	for (; K > 0; K--) {
		int cnt = 0;
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >K) {
				cnt++;
				if (cnt >=K) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) {
			break;
		}
	}
	printf("%d", K);
	return 0;
}
//算法笔记
/*#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int miles[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &miles[i]);
	}
	sort(miles + 1, miles + n + 1, cmp);
	int E = 1;
	while (E <= n && miles[E] > E) {
		E++;
	}
	printf("%d\n", E - 1);
	return 0;
}
// 10 9 8 8 7 7 6 6 3 2
// n = 1, E = 0
// E = n
*/
