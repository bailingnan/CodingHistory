#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
vector<int> v;
int num[maxn];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp, sum = 0;
		scanf("%d", &temp);
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		v.push_back(sum);
	}
	sort(v.begin(), v.begin() + N);
	int cnt = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			continue;
		}
		else {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	printf("%d", v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) {
			continue;
		}
		else {
			printf(" %d", v[i]);
		}
	}
	return 0;
}
//#include <cstdio>
//#include <set>
//using namespace std;
//set<int> st;
//int getSum(int x) {
//	int sum = 0;
//	while (x) {
//		sum += x % 10;
//		x /= 10;
//	}
//	return sum;
//}
//int main() {
//	int n, x;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &x);
//		st.insert(getSum(x));
//	}
//	printf("%d\n", st.size());
//	for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
//		if (it != st.begin()) {
//			printf(" ");
//		}
//		printf("%d", *it);
//	}
//	return 0;
//}
