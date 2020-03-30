#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn];
int N;
int main() {
	scanf("%d", &N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
	}
	sort(num, num + N);
	int n, s;
	if (N % 2 == 0) {
		n= 0;
		int s1=0, s2;
		for (int i = 0; i < N / 2; i++) {
			s1 += num[i];
		}
		s2 = sum - s1;
		s = s2 - s1;
	}
	else {
		n = 1;
		int m = num[N / 2];
		int s1=0, s2;
		for (int i = 0; i < N / 2; i++) {
			s1 += num[i];
		}
		s2 = sum - s1 - m;
		s = max(abs(s1 + m - s2), abs(s1 - s2 - m));
	}
	printf("%d %d", n, s);
	return 0;
}
//算法笔记
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 100010;
//int n, a[maxn];    // 数组a存放所有整数，n为其个数
//int main() {
//	int sum = 0, sum1 = 0;    // sum为所有元素的和，sum1为前n/2小的元素之和
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//		sum += a[i];    // 累计sum
//	}
//	sort(a, a + n);    // 从小到大排序
//	for (int i = 0; i < n / 2; i++) {
//		sum1 += a[i];    // 累计前n/2小的元素之和
//	}
//	printf("%d %d\n", n % 2, sum - sum1 - sum1);    // 输出|n1-n2|和|S2-S1|
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 100010;
//int n, a[maxn];    // 数组a存放所有整数，n为其个数
//int main() {
//    // sum和sum1记录所有整数之和与切分后前n/2个元素之和
//    int sum = 0, sum1 = 0;
//    scanf("%d", &n);    // 整数个数
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);    // 输入整数
//        sum += a[i];    // 累计所有整数之和
//    }
//    nth_element(a, a + n / 2, a + n);    // 寻找第n/2大的数，并进行切分
//    for(int i = 0; i < n / 2; i++) {
//        sum1 += a[i];    // 累计较小的子集合中元素之和
//    }
//    printf("%d %d\n", n % 2, (sum - sum1) - sum1);    // 求两个子集合的元素和之差
//    return 0;
//}
