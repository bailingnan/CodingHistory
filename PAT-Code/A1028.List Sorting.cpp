#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu {
	int ID,Gr;
	char Nm[10];
}s[100010];
bool cmp1(struct Stu a, struct Stu b) {
	return a.ID < b.ID;
}
bool cmp2(struct Stu a, struct Stu b) {
	if (strcmp(a.Nm, b.Nm) != 0)
		return strcmp(a.Nm, b.Nm) < 0;
	else return a.ID < b.ID;
}
bool cmp3(struct Stu a, struct Stu b) {
	if (a.Gr != b.Gr)
		return a.Gr < b.Gr;
	else return a.ID < b.ID;
}
int main() {
	int N, C;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &s[i].ID, s[i].Nm, &s[i].Gr);
	}
	if (C == 1) {
		sort(s, s + N, cmp1);
		for (int i = 0; i < N; i++) {
			printf("%06d %s %d", s[i].ID, s[i].Nm, s[i].Gr);
			if (i != N - 1)
				printf("\n");
		}
	}
	else if (C == 2) {
		sort(s, s + N, cmp2);
		for (int i = 0; i < N; i++) {
			printf("%06d %s %d", s[i].ID, s[i].Nm, s[i].Gr);
			if (i != N - 1)
				printf("\n");
		}
	}
	else if (C == 3) {
		sort(s, s + N, cmp3);
		for (int i = 0; i < N; i++) {
			printf("%06d %s %d", s[i].ID, s[i].Nm, s[i].Gr);
			if (i != N - 1)
				printf("\n");
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Student {
    int id;
    char name[10];
    int score;
}stu[maxn];
bool cmp1(Student a, Student b) {
    return a.id < b.id;
}
bool cmp2(Student a, Student b) {
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0;
    else return a.id < b.id;
}
bool cmp3(Student a, Student b) {
    if(a.score != b.score) return a.score < b.score;
    else return a.id < b.id;
}
int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++) {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    if(c == 1) sort(stu, stu + n, cmp1);
    else if(c == 2) sort(stu, stu + n, cmp2);
    else sort(stu, stu + n, cmp3);
    for(int i = 0; i < n; i++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}
