//素数
bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
//d为最大公约数，则最小公倍数为a/d*b;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a%b);
}
int gcd(int m,int n){
    if(m<=0||n<=0) return 0;
    while(n>0){
        int r=m&n;
        m=n;
        n=r;
    }
    return m;
}
//斐波那契数列
//递归
int Fibonacci_recursion(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return Fibonacci_recursion(n-1)+Fibonacci_recursion(n-2);
}
//非递归
int Fibonacci_loop(int n){
    int *a=new int[n]{1,1};
    for(int i=2;i<n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n-1];
}
//日期差值
//计算两日期的差值
#include<cstdio>
int month[13][2] = {//平年和闰年的每个月的天数
	{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},
{31,31},{30,30},{31,31},{30,30},{31,31}
}
bool isLeap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) ||year % 400 == 0);
}
int main() {
	int time1, y1, m1, d1;//假设第一个日期早于第二个日期,格式19890604
	int time2, y2, m2, d2;
	scanf("%d%d", &time1, &time2);
	y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
	y2= time2 / 10000, m2= time2 % 10000 / 100, d2= time2 % 100;
	int ans = 1;
	while (y1 < y2 || m1 < m2 || d1 < d2) {
		d1++;
		if (d1 == month[m1][isLeap(y1)] + 1) {
			m1++;
			d1 = 1;
		}
		if (m1 == 13) {
			y1++;
			m1 = 1;
		}
		ans++;
	}
	printf("%d", ans);
	return 0;
}
#include<cstdio>
struct Time {
	int y;
	int m;
	int d;
}t1,t2;
bool Is366(int year){
	return (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0);
}
int month(int year, int month){
	int Is31[7] = { 1,3,5,7,8,10,12 };
	for (int i = 0; i < 7; i++){
		if (Is31[i] == month)
			return 31;
	}
	if (month == 2){
		if (Is366(year))
			return 29;
		else return 28;
	}
	else return 30;
}
void swap(struct Time *a, struct Time *b) {
	struct Time temp;
	temp=*a;
	*a = *b;
	*b = temp;
}
int main(){	
	int val;
	while (scanf("%4d%2d%2d %4d%2d%2d", &t1.y, &t1.m, &t1.d, &t2.y, &t2.m, &t2.d) != EOF) {
		if (t1.y > t2.y) swap(&t1, &t2);
		else if(t1.y==t2.y){
			if (t1.m > t2.m) swap(&t1, &t2);
			else if(t1.m==t2.m)
				if(t1.d>t2.d) swap(&t1, &t2);
		}
		if (t1.y == t2.y) {
			if (t1.m == t2.m)
				val = t2.d - t1.d + 1;
			else {
				val = month(t1.y, t1.m) - t1.d + 1 + t2.d;
				for (int i = t1.m + 1; i <= t2.m - 1; i++)
					val += month(t1.y, i);
			}
		}
		else {
			val = month(t1.y, t1.m) - t1.d + 1;
			for (int i = t1.m + 1; i <= 12; i++)
				val += month(t1.y, i);
			for (int i = t1.y + 1; i < t2.y; i++) {
				if (Is366(i)) val += 366;
				else val += 365;
			}
			for (int i = 1; i < t2.m; i++)
				val += month(t2.y, i);
			val += t2.d;
		}
		printf("%d\n", val);
	}
	return 0;
}
//进制转换
int y = 0, product = 1;//p进制转换为10进制
while (x != 0) {
	y = y + (x % 10)*product;
	x = x / 10;
	product = product * p;
}
//十进制数y转化为Q进制
int z[40], num = 0;
do {
	z[num++] = y % Q;//除基取余
	y = y / Q;
} while (y != 0);
//质因子分解
bool isPrime(int n) {
	if (n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
#include<cstdio>//筛法求素数表，复杂度O(nloglogn)
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = { 0 };
void Find_Prime() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + 1; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}
struct factor {
	int x, cnt;
}fac[10];
int main() {
	Find_Prime();
	int n, num = 0;
	scanf("%d", &n);
	if (n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0*n);
		for (int i = 0; i < pNum&&prime[i] <= sqr; i++) {
			if (n%prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n%prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1) {
			fac[num].x = n;
			fac[num].cnt = 1;
		}
		for (int i = 0; i < num; i++) {
			if (i > 0) printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1) {
				printf("^%d", fac[i].cnt);
			}
		}
	}
	return 0;
}
//DFS
//背包问题
//有n件物品，每件物品的重量为w[i],价值为c[i],现在需要选出若干件物品放入一个
//容量为V的背包中，使得选入背包的物品重量和不超过容量V的前提下，让背包中物品
//的价值之和最大，求最大价值。
#include<cstdio>
const int maxn = 30;
int n, V, maxValue = 0;//物品件数n，背包容量V，最大价值maxValue;
int w[maxn], c[maxn];//w[i]为每件物品的重量，c[i]为每件物品的价值
//DFS,index为当前处理的物品编号
//sumW和sumC分别为当前总重量和当前总价值
void DFS(int index, int sumW, int sumC) {
	if (index == n) {//已完成对n件物品的选择
		if (sumW <= V && sumC > maxValue) {
			maxValue = sumC;//不超过背包容量时更新最大价值maxValue
		}
		return;
	}
	DFS(index + 1, sumW, sumC);//不选第index件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index件物品
}
int main() {
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	DFS(0, 0, 0);//初始时为第0件物品，当前总重量和总价值均为0
	printf("%d", maxValue);
	return 0;
}
//剪枝
void DFS(int index, int sumW, int sumC) {
	if (index == n) {
		return;
	}
	DFS(index + 1, sumW, sumC);//不选第index件物品
	//只有加入第index件物品后未超过容量V，才能继续
	if (sumW + w[index] <= V) {
		if (sumC + c[index] > ans) {
			ans = sumC + c[index];
		}
		DFS(index + 1, sumW + w[index], sumC + c[index]);
	}
}
//给定N个整数，从中选择K个数，使得这K个数之和恰好等于一个给定的整数X，如果有多种方案，选择元素平方和最大的一个。
int n, k, x, maxSumSqu = -1, A[maxn];
vector<int> temp, ans;
void DFS(int index, int nowK, int sum, int sumSqu) {
	if (nowK == k && sum == x) {
		if (sumSqu > maxSumSqu) {
			maxSumSqu = sumSqu;
			ans = temp;
		}
	}
	if (index == n || nowK > k || sum > x) {
		return;
	}
	temp.push_back(A[index]);
	DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	DFS(index + 1, nowK, sum, sumSqu);
}
//若每个整数可以被选择n次。
void DFS(int index, int nowK, int sum, int sumSqu) {
	if (nowK == k && sum == x) {
		if (sumSqu > maxSumSqu) {
			maxSumSqu = sumSqu;
			ans = temp;
		}
	}
	if (index == n || nowK > k || sum > x) {
		return;
	}
	temp.push_back(A[index]);
	DFS(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	DFS(index + 1, nowK, sum, sumSqu);
}
