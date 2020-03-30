#include<cstdio>//超时
#include<cstring>
#include<algorithm>
using namespace std;
struct stu {
	int id, ge, gi;
	double g;
	int c[5], r;
}s[40010];
struct sch {
	int rc[40000];
}r[100];
bool cmp(struct stu a, struct stu b) {
	if (a.g != b.g)
		return a.g > b.g;
	else return a.ge > b.ge;
}
int main() {
	int N, M, K, sc[100];
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d", &sc[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s[i].ge, &s[i].gi);
		s[i].g = double(s[i].ge + s[i].gi) / 2;
		s[i].id = i;
		for (int j = 0; j < K; j++) {
			scanf("%d", &s[i].c[j]);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			r[i].rc[j] = -1;
	}
	sort(s, s + N, cmp);
	s[0].r = 1;
	for (int i = 1; i < N; i++) {
		if (s[i].g == s[i - 1].g&&s[i].ge == s[i - 1].ge)
			s[i].r = s[i - 1].r;
		else s[i].r = i + 1;
	}
	int sc1[100] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (sc[s[i].c[j]] == 0)
				continue;
			if (sc1[s[i].c[j]] < sc[s[i].c[j]]) {
				sc1[s[i].c[j]]++;
				r[s[i].c[j]].rc[s[i].id] = 1;
				break;
			}
			else if (sc1[s[i].c[j]] >= sc[s[i].c[j]]) {
				int k=-1, cnt = 0;
				for (int l = 0; l < N; l++) {
					if (r[s[i].c[j]].rc[l] == 1) {
						cnt++;
					}
					if (cnt == sc1[s[i].c[j]]) {
						k = l;
						break;
					}
				}
				if (k == -1) break;
				else {
					int temp;
					for (int m = 0; m < N; m++) {
						if (s[m].id == k)
							temp = s[m].r;
					}
					if (temp== s[i].r) {
						r[s[i].c[j]].rc[s[i].id] = 1;
						sc1[s[i].c[j]]++;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		if (sc1[i] == 0)
			printf("\n");
		else {
			for (int j = 0; j < N; j++) {
				if (r[i].rc[j] == 1) {
					printf("%d", j);
					cnt++;
					if (cnt < sc1[i])
						printf(" ");
					else if (cnt == sc1[i]) {
						printf("\n");
						break;
					}
				}
			}
		}
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <algorithm>
using namespace std;
struct Student {
    int GE, GI, sum;
    int r, stuID;
    int cho[6];
}stu[40010];
struct School {
    int quota;
    int stuNum;
    int id[40010];
    int lastAdmit;
}sch[110];
bool cmpStu(Student a,Student b) {
    if(a.sum != b.sum) return a.sum > b.sum;
    else return a.GE > b.GE;
}
bool cmpID(int a, int b) {
    return stu[a].stuID < stu[b].stuID;
}
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d", &sch[i].quota);
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
    }
    for(int i = 0; i < n; i++) {
        stu[i].stuID = i;
        scanf("%d%d", &stu[i].GE, &stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        for(int j = 0; j < k; j++) {
            scanf("%d", &stu[i].cho[j]);
        }
    }
    sort(stu, stu + n, cmpStu);
    for(int i = 0; i < n; i++) {
        if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE) {
            stu[i].r = stu[i - 1].r;
        } else {
            stu[i].r = i;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int choice = stu[i].cho[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if(num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r)) {
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(sch[i].stuNum > 0) {
            sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
            for(int j = 0; j < sch[i].stuNum; j++) {
                printf("%d", stu[sch[i].id[j]].stuID);
                if(j < sch[i].stuNum - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
*/
