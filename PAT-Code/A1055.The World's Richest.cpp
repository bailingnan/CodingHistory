#include<cstdio>//运行超时
#include<cstring>
#include<algorithm>
using namespace std;
struct Person {
	char Nm[10];
	int age, wt;
}P[10010];
struct qu {
	int num, bg, ed;
}Q[1010];
bool cmp(struct Person a, struct Person b) {
	if (a.wt != b.wt)
		return a.wt > b.wt;
	else if (a.age != b.age)
		return a.age < b.age;
	else return strcmp(a.Nm, b.Nm) < 0;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", P[i].Nm, &P[i].age, &P[i].wt);
	}
	sort(P, P + N, cmp);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &Q[i].num, &Q[i].bg, &Q[i].ed);
	}
	for (int i = 0; i < K; i++) {
		int cnt = 0;
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < N; j++) {
			if (P[j].age >= Q[i].bg&&P[j].age <= Q[i].ed) {
				cnt++;
				printf("%s %d %d\n", P[j].Nm, P[j].age, P[j].wt);
				if (cnt == Q[i].num)
						break;
			}
		}
		if (cnt == 0)
			printf("None\n");
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int Age[maxn] = {0};
struct Person {
    int age, worths;
    char name[10];
} ps[maxn], valid[maxn];
bool cmp(Person a, Person b) {
    if(a.worths != b.worths) return a.worths > b.worths;
    else if(a.age != b.age) return a.age < b.age;
    return strcmp(a.name, b.name) < 0;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worths);
    }
    sort(ps, ps + n, cmp);
    int validNum = 0;
    for(int i = 0; i < n; i++) {
        if(Age[ps[i].age] < 100) {
            Age[ps[i].age]++;
            valid[validNum++] = ps[i];
        }
    }
    int m, ageL, ageR;
    for(int i = 1; i <= k; i++) {
        scanf("%d%d%d", &m, &ageL, &ageR);
        printf("Case #%d:\n", i);
        int printNum = 0;
        for(int j = 0; j < validNum && printNum < m; j++) {
            if(valid[j].age >= ageL && valid[j].age <= ageR) {
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
                printNum++;
            }
        }
        if(printNum == 0) {
            printf("None\n");
        }
    }
    return 0;
}
*/
