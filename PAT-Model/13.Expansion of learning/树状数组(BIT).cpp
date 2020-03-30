//lowbit(x)=x&(-x)取x的二进制最右边的1和它右边所有的0;
//也可理解为能整除x的最大2的幂次
//getsum函数返回前x个整数之和
int getSum(int x) {//时间复杂度O(logN)
	int sum = 0;//记录和
	for (int i = x; i > 0; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
//update函数将第x个整数加上v，时间复杂度O(logN)
void update(int x, int v) {
	for (int i = x; i <= N; i += lowbit(i)) {
		c[i] += v;
	}
}
//给定一个有N个正整数序列A，对序列中的每个数，求出序列中它左边比它小的个数。
#include<cstdio>
#include<cstring>
const int maxn = 100010;
#define lowbit(i) ((i)&(-i))
int c[maxn];
void update(int x, int v) {
	for (int i = x; i <= N; i += lowbit(i)) {
		c[i] += v;
	}
}
int getSum(int x) {//时间复杂度O(logN)
	int sum = 0;//记录和
	for (int i = x; i > 0; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
int main() {
	int n, x;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		update(x, 1);
		printf("%d\n", getSum(x - 1));
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i)&(-i))
struct Node {
	int val;//序列元素的值
	int pos;//原始序号
}temp[maxn];//temp数组临时存放输入数据
int A[maxn];//离散化后的原始数组
int c[maxn];//树状数组
//update函数将第x个整数加上v
void update(int x, int v) {
	for (int i = x; i < maxn; i + lowbit(i)) {
		c[i] += v;
	}
}
//getSum函数返回前x个整数之和
int getSum(int x) {
	int sum = 0;
	for (int i = x; i > 0; i - lowbit(i)) {
		sum += c[i];
	}
}
bool cmp(Node a, Node b) {
	return a.val < b.val;
}
int main() {
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp[i].val);
		temp[i].pos = i;
	}
	//离散化
	sort(temp, temp + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i == 0 || temp[i] != temp[i - 1].val) {
			A[temp[i].pos] = i + 1;
		}
		else {
			A[temp[i].pos] = A[temp[i - 1].pos];
		}
	}
	for (int i = 0; i < n; i++) {
		update(A[i], 1);
		printf("%d", getSum(A[i] - 1));
	}
	return 0;
}
//求序列元素第K大
int findKthElement(int K) {
	int l = 1, r = MAXN, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (getSum(mid) >= K) r = mid;
		else l = mid + 1;
	}
	return l;
}
//二维树状数组
int c[maxn][maxn];
void update(int x, int y, int v) {
	for (int i = x; i < maxn; i += lowbit(i)) {
		for (int j = y; j < maxn; j += lowbit(j)) {
			c[i][j] += v;
		}
	}
}
//二维getSum函数返回(1,1)到(x,y)的子矩阵中元素之和
int getSum(int x, int y) {
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			sum += c[i][j];
		}
	}
	return sum;
}
//getSum(x),返回A[x]
//update(x,v),将A[1]~A[x]的每个数都加上v
//C[i]表示这段区间每个数当前被加了多少
int getSum(int x) {
	int sum = 0;
	for (int i = x; i < maxn; i += lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
//update函数将前x个整数都加上v
void update(int x, int v) {
	for (int i = x; i > 0; i -= lowbit(i)) {
		c[i] += v;
	}
}
