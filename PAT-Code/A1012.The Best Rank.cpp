#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu {
	char  ID[10];
	int C, M, E, A;
	int CR, MR, ER, AR;
}S[2000],M1[2000];
bool cmp1(Stu a, Stu b) {
		return a.C > b.C;
}
bool cmp2(Stu a, Stu b) {
	return a.M > b.M;
}
bool cmp3(Stu a, Stu b) {
	return a.E > b.E;
}
bool cmp4(Stu a, Stu b) {
	return a.A > b.A;
}
int mi(Stu a) {
	int temp = 9999;
	if (a.AR < temp)
		temp = a.AR;
	if (a.CR < temp)
		temp = a.CR;
	if (a.MR < temp)
		temp = a.MR;
	if (a.ER < temp)
		temp = a.ER;
	return temp;
}
void pt(Stu a) {
	if(mi(a)==a.AR)
		printf("%d %c\n", a.AR, 'A');
	else if(mi(a)==a.CR)
		printf("%d %c\n", a.CR, 'C');
	else if(mi(a)==a.MR)
		printf("%d %c\n", a.MR, 'M');
	else if(mi(a)==a.ER)
		printf("%d %c\n", a.ER, 'E');
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", S[i].ID,&S[i].C, &S[i].M, &S[i].E);
		S[i].A = (S[i].C + S[i].M + S[i].E) / 3;
	}
	sort(S, S + N, cmp1);
	S[0].CR = 1;
	for (int i = 1; i < N; i++) {
		if (S[i].C < S[i - 1].C)
			S[i].CR = i + 1;
		else S[i].CR = S[i - 1].CR;
	}
	sort(S, S + N, cmp2);
	S[0].MR = 1;
	for (int i = 1; i < N; i++) {
		if (S[i].M < S[i - 1].M)
			S[i].MR = i + 1;
		else S[i].MR = S[i - 1].MR;
	}
	sort(S, S + N, cmp3);
	S[0].ER = 1;
	for (int i = 1; i < N; i++) {
		if (S[i].E < S[i - 1].E)
			S[i].ER = i + 1;
		else S[i].ER = S[i - 1].ER;
	}
	sort(S, S + N, cmp4);
	S[0].AR = 1;
	for (int i = 1; i < N; i++) {
		if (S[i].A < S[i - 1].A)
			S[i].AR = i + 1;
		else S[i].AR = S[i - 1].AR;
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", M1[i].ID);
	}
	for (int i = 0; i < M; i++) {
		int j;
		for (j = 0; j < N; j++) {
			if (strcmp(S[j].ID,M1[i].ID)==0) {
				pt(S[j]);
				break;
			}
		}
		if (j == N)
			printf("N/A\n");
	}
	return 0;
}
//算法笔记
include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Student{
    int id;
    int grade[4];
}stu[2010];
char course[4] = {'A', 'C', 'M', 'E'};
int Rank[10000000][4] = {0};
int now;
bool cmp(Student a, Student b){
    return a.grade[now] > b.grade[now];
}
int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
    }
    for(now = 0; now < 4; now++){
        sort(stu, stu + n, cmp);
        Rank[stu[0].id][now] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i - 1].grade[now]){
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];
            }else{
                Rank[stu[i].id][now] = i + 1;
            }
        }
    }
    int query;
    for(int i = 0; i < m; i++){
        scanf("%d", &query);
        if(Rank[query][0] == 0){
            printf("N/A\n");
        }else{
            int k = 0;
            for(int j = 0; j < 4; j++){
                if(Rank[query][j] < Rank[query][k]){
                    k = j;
                }
            }
            printf("%d %c\n", Rank[query][k], course[k]);
        }
    }
    return 0;
}
