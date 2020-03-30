#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int N,num[maxn], minn[maxn], maxnb[maxn];
vector<int> v;
void ini() {
	maxnb[0] = num[0];
	for (int i = 1; i < N; ++i) {
		maxnb[i] = max(maxnb[i - 1], num[i]);
	}
	minn[N - 1] = num[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		minn[i] = min(minn[i + 1], num[i]);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num[i]);
	}
	ini();
	for (int i = 0; i < N; ++i) {
		if (i == 0) {
			if (minn[i+1] > num[i]) {
				v.push_back(num[i]);
			}
		}
		else if (i == N - 1) {
			if (maxnb[i - 1] < num[i]) {
				v.push_back(num[i]);
			}
		}
		else {
			if (maxnb[i - 1]<num[i] && minn[i + 1]>num[i]) {
				v.push_back(num[i]);
			}
		}
	}
  //算法笔记
  /*
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3fffffff;    // 一个很大的数
							   // a为序列，leftMax和rightMin分别为每一位左边最大的数和右边最小的数
int a[MAXN], leftMax[MAXN], rightMin[MAXN];
// ans记录所有主元，num为主元个数
int ans[MAXN], num = 0;
int main() {
	int n;
	scanf("%d", &n);    // 序列元素个数
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);    // 输入序列元素
	}
	leftMax[0] = 0;    // A[0]左边没有比它大的数
	for (int i = 1; i < n; i++) {
		leftMax[i] = max(leftMax[i - 1], a[i - 1]);    // 由i-1推得i
	}
	rightMin[n - 1] = INF;    // A[n-1]右边没有比它小的数
	for (int i = n - 2; i >= 0; i--) {
		rightMin[i] = min(rightMin[i + 1], a[i + 1]);    // 由i+1推得i
	}
	for (int i = 0; i < n; i++) {
		// 左边所有数比它小，右边所有书比它大
		if (leftMax[i] < a[i] && rightMin[i] > a[i]) {
			ans[num++] = a[i];    // 记录主元
		}
	}
	printf("%d\n", num);    // 输出主元个数
	for (int i = 0; i < num; i++) {
		printf("%d", ans[i]);    // 依次输出所有主元
		if (i < num - 1) printf(" ");
	}
	printf("\n");    // 必须要有换行
	return 0;
}
*/
	int length = (int)v.size();
	printf("%d\n", length);
	for (int i = 0; i < length; ++i) {
		printf("%d", v[i]);
		if (i < length - 1) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
