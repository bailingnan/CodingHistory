//区间不相交问题，给出N个开区间(x,y),从中选择尽可能多的开区间，使得这些开区间两两没有交集
//此为选择左端点最大的区间，也可选择右端点最小ed区间
//区间选点问题，给出N个闭区间[x,y]，求最少需要确定多少个点，才能使每个闭区间中都至少存在一个点。
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct Interval {
	int x, y;
}I[maxn];
bool cmp(Interval a, Interval b) {
	if (a.x != b.x) return a.x > b.x;
	else return a.y < b.y;
}
int main() {
	int n;
	while (scanf("%d", &n), n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &I[i].x, &I[i].y);
		}
		sort(I, I + n, cmp);
		int ans = 1, lastX = I[0].x;
		for (int i = 1; i < n; i++) {
			if (I[i].y <= lastX) {
				lastX = I[i].x;
				ans++;
			}
		}
		printf("%d", ans);
	}
	return 0;
}
