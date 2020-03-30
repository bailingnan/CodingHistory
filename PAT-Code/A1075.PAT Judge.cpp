//完美通过牛客网
#include<cstdio>
#include<algorithm>
using namespace std;
struct Stu {
	int ID,sc[10], cnt=0,tl=0,flag=0,r;
}S[10010];
bool cmp(struct Stu a, struct Stu b) {
	if (a.flag != b.flag)
		return a.flag > b.flag;
	else if (a.tl != b.tl)
		return a.tl > b.tl;
	else if (a.cnt != b.cnt)
		return a.cnt > b.cnt;
	else return a.ID < b.ID;
}
int main() {
	int N, K, M;
	int fl[10];
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++)
			S[i].sc[j] = -2;
	}
	for (int i = 1; i <= K; i++)
		scanf("%d", &fl[i]);
	for (int i = 0; i < M; i++) {
		int temp1, temp2, temp3;
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		S[temp1].ID = temp1;
		if (temp3 > S[temp1].sc[temp2]) {
			S[temp1].sc[temp2] = temp3;
			if (temp3 >= 0)
				S[temp1].flag = 1;
			if (temp3 == fl[temp2])
				S[temp1].cnt++;
		}
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= K; j++) {
			int temp = S[i].sc[j];
			if (temp < 0)
				temp = 0;
			sum += temp;
		}
		S[i].tl = sum;
	}
	sort(S + 1, S + N + 1, cmp);
	S[1].r=1;
	for (int i = 1; i <= N&& S[i].flag == 1; i++) {
		if (i > 1) {
			if (S[i].tl == S[i - 1].tl)
				S[i].r = S[i - 1].r;
			else
				S[i].r = i;
		}
		printf("%d %05d %d ", S[i].r, S[i].ID, S[i].tl);
		for (int j = 1; j <= K; j++) {
			if (S[i].sc[j] == -1)
				printf("0");
			else if (S[i].sc[j] == -2)
				printf("-");
			else if (S[i].sc[j] >=0)
				printf("%d", S[i].sc[j]);
			if (j < K) printf(" ");
		}
		printf("\n");
		
	}
}
//算法笔记(不能全通过牛客网)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Student {
    int id;
    int score[6];
    bool flag;
    int score_all;
    int solve;
}stu[maxn];
int n, k, m;
int full[6];
bool cmp(Student a, Student b) {
    if(a.score_all != b.score_all) return a.score_all > b.score_all;
    else if(a.solve != b.solve) return a.solve > b.solve;
    else return a.id < b.id;
}
void init() {
    for(int i = 1; i <= n; i++) {
        stu[i].id = i;
        stu[i].score_all = 0;
        stu[i].solve = 0;
        stu[i].flag = false;
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &m);
    init();
    for(int i = 1; i <= k; i++) {
        scanf("%d", &full[i]);
    }
    int u_id, p_id, score_obtained;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u_id, &p_id, &score_obtained);
        if(score_obtained != -1) {
            stu[u_id].flag = true;
        }
        if(score_obtained == -1 && stu[u_id].score[p_id] == -1) {
                stu[u_id].score[p_id] = 0;
        }
        if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]) {
            stu[u_id].solve++;
        }
        if(score_obtained > stu[u_id].score[p_id]) {
            stu[u_id].score[p_id] = score_obtained;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(stu[i].score[j] != -1) {
                stu[i].score_all += stu[i].score[j];
            }
        }
    }
    sort(stu + 1, stu + n + 1, cmp);
    int r = 1;
    for(int i = 1; i <= n && stu[i].flag == true; i++) {
        if(i > 1 && stu[i].score_all != stu[i - 1].score_all) {
            r = i;
        }
        printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
        for(int j = 1; j <= k; j++) {
            if(stu[i].score[j] == -1) {
                printf(" -");
            } else {
                printf(" %d", stu[i].score[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
