#include<cstdio>
int binarySearch(int A[], int left, int right, int x) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] == x) return mid;
		else if (A[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main() {
	const int n = 10;
	int A[n] = { 1,3,4,6,7,8,12,24,45 };
	printf("%d %d\n", binarySearch(A, 0, n - 1, 6), binarySearch(A, 0, n - 1, 9));
	return 0;
}
//求出序列中第一个大于等于x的元素的位置L
//二分上下界为左闭右闭的[left,right],传入的初值为[0,n]
int lower_bound(int A[], int left, int right, int x) {
	int mid;
	while(left < right){//对[left,right]来说，left==right意味着找到唯一位置
		mid = (left + right) / 2;
		if (A[mid] >= x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
//返回第一个大于x的元素的位置
int upper_bound(int A[], int left, int right, int x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
//想要寻找最后一个满足条件C的元素的位置，可以先求第一个满足"条件!C"的元素的位置，再减1
//二分区间为左开右闭的(left,right]
//初值必须能覆盖解的所有可能取值，并且left比最小取值小1
int solve(int left, int right, int) {
	int mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (条件成立) {//条件成立，则第一个满足条件的元素的位置<=mid
			right = mid;
		}
		else {//条件不成立，则第一个满足条件的元素的位置>mid
			left = mid;
		}
	}
	return right;
}
//快速幂
//给定三个整数a,b,m(a<10^9,b<10^18,1<m<10^9),求a^b%m
typedef long long LL;
LL binaryPow(LL a, LL b, LL m) {
	if (b == 0) return 1;
	//b为奇数,转换为b-1
	if (b % 2 == 1) return a * binaryPow(a, b - 1, m) % m;//判断条件可以用(b&1)代替，执行速度较快
	else {
		LL mul = binaryPow(a, b / 2, m);
		return mul * mul%m;
	}
}
//迭代写法
typedef long long LL;
LL binaryPow(LL a, LL b, LL m) {
	LL ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans = ans * a%m;
		}
		a = a * a%m;
		b >>= 1;//即b=b/2
	}
	return ans;
}
