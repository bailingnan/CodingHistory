#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu {
	char Nm[20],ID[20];
	int gd;
}S[10010];
bool cmp(struct Stu a, struct Stu b) {
	return a.gd > b.gd;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", S[i].Nm, S[i].ID, &S[i].gd);
	}
	int gd1, gd2;
	scanf("%d %d", &gd1, &gd2);
	sort(S, S + N, cmp);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (S[i].gd >= gd1 && S[i].gd <= gd2) {
			printf("%s %s\n", S[i].Nm, S[i].ID);
			cnt++;
		}
	}
	if (cnt == 0)
		printf("NONE\n");
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct Student {
    char name[11];
    char id[11];
    int grade;
}stu[maxn];
bool cmp(Student a, Student b) {
    return a.grade > b.grade;
}
int main() {
    int n, left, right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d%d", &left, &right);
    sort(stu, stu + n, cmp);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(stu[i].grade >= left && stu[i].grade <= right) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if(flag == false) {
        printf("NONE\n");
    }
    return 0;
}
