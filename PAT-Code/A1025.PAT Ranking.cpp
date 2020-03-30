#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct stu {
	string ID;
	int  tr, l, lr, sc;
};
bool cmp(stu a, stu b) {
	if (a.sc != b.sc)
		return a.sc > b.sc;
	else return a.ID < b.ID;
}
vector<stu> v[110], t;
int N, K, tK = 0;
int main() {
	scanf("%d", &N);
	for (int l = 1; l <=N; l++) {
		scanf("%d", &K);
		tK += K;
		for (int i = 0; i < K; i++) {
			stu temp;
			temp.l = l;
			cin >> temp.ID;
			scanf("%d",&temp.sc);
			v[l].push_back(temp);
		}
		sort(v[l].begin(), v[l].end(), cmp);
		v[l][0].lr = 1;
		for (int i = 1; i < K; i++) {
			if (v[l][i].sc == v[l][i - 1].sc) {
				v[l][i].lr = v[l][i - 1].lr;
			}
			else {
				v[l][i].lr = i+1;
			}
		}
		for (int i = 0; i < K; i++) {
			t.push_back(v[l][i]);
		}
	}
	sort(t.begin(), t.end(), cmp);
	t[0].tr = 1;
	for (int i = 1; i < t.size(); i++) {
		if (t[i].sc == t[i - 1].sc) {
			t[i].tr = t[i - 1].tr;
		}
		else {
			t[i].tr = i+1;
		}
	}
	printf("%d\n", tK);
	for (int i = 0; i < t.size(); i++) {
		cout << t[i].ID;
		printf(" %d %d %d\n",t[i].tr, t[i].l, t[i].lr);
	}
	return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student {
	char ID[20];
	int S;
	int l;
	int r;
	int zr;
}s[100][300], t[30000];
int Add(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}
bool cmp(Student a, Student b) {
	if (a.S != b.S) return a.S > b.S;
	else return strcmp(a.ID,b.ID)<0;
}
int main() {
	int N, K[100], m = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &K[i]);
		for (int j = 0; j < K[i]; j++) {
			scanf("%s %d", t[m].ID, &t[m].S);
			t[m++].l = i + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		sort(t+Add(K,i), t+Add(K,i+1), cmp);
	}
	for (int i = 0; i < N; i++) {
		t[Add(K,i)].r = 1;
		for (int j = Add(K,i)+1; j < Add(K,i+1); j++) {
			if (t[j].S < t[j-1].S) {
				t[j].r = j-Add(K,i)+1;
			}
			else {
				t[j].r = t[j - 1].r;
			}
		}
	}
	sort(t, t + m, cmp);
	t[0].zr = 1;
	for (int i = 1; i < m; i++) {
		if (t[i].S < t[i - 1].S) {
			t[i].zr = i + 1 ;
		}
		else {
			t[i].zr = t[i - 1].zr;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += K[i];
	}
	printf("%d\n", sum);
	for (int i = 0; i < m; i++) {
		printf("%s %d %d %d\n", t[i].ID, t[i].zr, t[i].l, t[i].r);
	}
	return 0;
}
*/
//算法笔记
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
    char id[15];
    int score;
    int location_number;
    int local_rank;
}stu[30010];
bool cmp(Student a, Student b) {
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}
int main() {
    int n, k, num = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        sort(stu + num - k, stu + num, cmp);
        stu[num - k].local_rank = 1;
        for(int j = num - k + 1; j < num; j++) {
            if(stu[j].score == stu[j - 1].score) {
                stu[j].local_rank = stu[j - 1].local_rank;
            } else {
                stu[j].local_rank = j + 1 - (num - k);
            }
        }
    }
    printf("%d\n", num);
    sort(stu, stu + num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++) {
        if(i > 0 && stu[i].score != stu[i - 1].score) {
            r = i + 1;
        }
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
    }
    return 0;
}
