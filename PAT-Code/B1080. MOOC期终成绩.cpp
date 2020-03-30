#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int cnt = 1,P,M,N;
struct stu {
	string name;
	double sc,gm, gf,g;
	stu() {
		gm = -1;
	}
}p[maxn];
map<string, int> mp;
bool cmp(stu a, stu b) {
	if (a.g != b.g) {
		return a.g > b.g;
	}
	else {
		return a.name < b.name;
	}
}
int main() {
	scanf("%d%d%d", &P, &M, &N);
	for (int i = 0; i < P; i++) {
		string str;
		double sc;
		cin >> str >> sc;
		if (sc < 200) {
			continue;
		}
		else {
			mp[str] = cnt;
			p[cnt].name=str;
			p[cnt].sc = sc;
			cnt++;
		}
	}
	for (int i = 0; i < M; i++) {
		string str;
		double gm;
		cin >> str >>gm;
		if (mp[str] == 0) {
			continue;
		}
		else {
			int temp = mp[str];
			p[temp].gm = gm;
		}
	}
	for (int i = 0; i < N; i++) {
		string str;
		double gf;
		cin >> str >> gf;
		if (mp[str] == 0) {
			continue;
		}
		else {
			int temp = mp[str];
			p[temp].gf = gf;
		}
	}
	int count = cnt;
	for (int i = 1; i <cnt; i++) {
		if (p[i].gm > p[i].gf) {
			p[i].g = (int)round(0.4*p[i].gm + 0.6*p[i].gf);
		}
		else {
			p[i].g = p[i].gf;
		}
		if (p[i].g < 60) {
			count--;
		}
	}
	sort(p + 1, p + cnt, cmp);
	cnt = count;
	for (int i = 1; i < cnt; i++) {
		cout << p[i].name;
		printf(" %d %d %d %d\n",(int)p[i].sc,(int)p[i].gm, (int)p[i].gf,(int)p[i].g);
	}
	return 0;
}
