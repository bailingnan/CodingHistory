#include<cstdio>
#include<algorithm>
using namespace std;
struct Person {
	int ID, V, T;
	int S,J;
}P[100000];
int jg(Person a,int H) {
	if (a.V >=H&&a.T >=H)
		return 1;
	else if (a.V >=H&&a.T < H)
		return 2;
	else if (a.V < H&&a.T < H&&a.V >= a.T)
		return 3;
	else return 4;
}
bool cmp(Person a, Person b) {
	if (a.J != b.J)
		return a.J < b.J;
	else {
		if (a.S != b.S)
			return a.S > b.S;
		else if (a.V != b.V)
			return a.V > b.V;
		else return a.ID < b.ID;
	}
}
int main() {
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &P[i].ID, &P[i].V, &P[i].T);
		if (P[i].V < L || P[i].T < L) {
			i--;
			N--;
		}
		else {
			P[i].S = P[i].V + P[i].T;
			P[i].J = jg(P[i],H);
		}
	}
	sort(P, P + N, cmp);
	printf("%d\n", N);
	for (int i = 0; i < N; i++) {
		printf("%d %d %d\n", P[i].ID, P[i].V, P[i].T);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
    char id[10];
    int de, cai, sum;
    int flag;
}stu[100010];
bool cmp(Student a, Student b) {
    if(a.flag != b.flag) return a.flag < b.flag;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.de != b.de) return a.de > b.de;
    else return strcmp(a.id, b.id) < 0;
}
int main() {
    int n, L, H;
    scanf("%d%d%d", &n, &L, &H);
    int m = n;
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].de < L || stu[i].cai < L) {
            stu[i].flag = 5;
            m--;
        }
        else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
        else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
        else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;
        else stu[i].flag = 4;
    }
    sort(stu, stu + n, cmp);
    printf("%d\n", m);
    for(int i = 0; i < m; i++) {
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }
    return 0;
