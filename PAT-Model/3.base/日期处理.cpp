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
