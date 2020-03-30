#include<cstdio>//超时，扣7分
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 50010;
int cnt[maxn] = { 0 };
bool cmp(int a,int b) {
	if (cnt[a] != cnt[b]) {
		return cnt[a] > cnt[b];
	}
	else return a < b;
}
vector<int> v;
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	int temp;
	scanf("%d", &temp);
	cnt[temp]++;
	v.push_back(temp);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &temp);
		int size = v.size();
		int m =min(size,M);
		sort(v.begin(), v.end(), cmp);
		printf("%d: ", temp);
		for (int j = 0; j < m; j++) {
			printf("%d", v[j]);
			if (j < m - 1) {
				printf(" ");
			}
			else printf("\n");
		}
		if (cnt[temp] == 0)
			v.push_back(temp);
		cnt[temp]++;
	}
	return 0;
}
/*
#include <cstdio>
#include <set>
using namespace std;
int book[50001];
struct node {
	int value, cnt;
	node(int a, int b) :value(a), cnt(b) {}
	bool operator < (const node &a) const {
		return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
	}
};
int main() {
	int n, k, num;
	scanf("%d%d", &n, &k);
	set<node> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (i != 0) {
			printf("%d:", num);
			int tempCnt = 0;
			for (auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
				printf(" %d", it->value);
				tempCnt++;
			}
			printf("\n");
		}
		auto it = s.find(node(num, book[num]));
		if (it != s.end()) s.erase(it);
		book[num]++;
		s.insert(node(num, book[num]));
	}
	return 0;
}
*/
