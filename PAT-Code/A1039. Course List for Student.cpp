#include<cstdio>//运行超时，扣2分
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct C {
	int num,cnt;
	char nm[200][5];
	C() {
		cnt = 0;
	}
}crs[2500];
struct S {
	int cnt;
	vector<int> cs;
	char nm[5];
	S() {
		cnt = 0;
	}
}stu[40000];
int main() {
	int Ns, Nc;
	scanf("%d%d", &Ns, &Nc);
	for (int i = 0; i < Nc; i++) {
		scanf("%d %d", &crs[i].num, &crs[i].cnt);
		for (int j = 0; j < crs[i].cnt; j++) {
			scanf("%s",crs[i].nm[j]);
		}
	}
	for (int i = 0; i < Ns; i++) {
		scanf("%s", stu[i].nm);
	}
	for (int i = 0; i < Nc; i++) {
		for (int j = 0; j < crs[i].cnt; j++) {
			for (int k = 0; k < Ns; k++) {
				if (strcmp(stu[k].nm, crs[i].nm[j]) == 0) {
					stu[k].cnt++;
					stu[k].cs.push_back(crs[i].num);
				}
			}
		}
	}
	for (int i = 0; i < Ns; i++) {
		sort(stu[i].cs.begin(), stu[i].cs.end());
		printf("%s %d", stu[i].nm, stu[i].cnt);
		vector<int>::iterator it;
		for (it=stu[i].cs.begin();it!=stu[i].cs.end(); it++) {
			printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
}
//运行超时，扣2分
/*
#include<cstdio>
#include<string>
#include<iostream>
#include<set>
#include<map>
using namespace std;
int N, K;
map<string,set<int>> stu;
int main() {
	scanf("%d%d", &N, &K);
	for (int o = 0; o < K; o++) {
		int temp,cnt;
		scanf("%d%d", &temp,&cnt);
		for (int i = 0; i < cnt; i++) {
			string str;
			cin >> str;
			stu[str].insert(temp);
		}
	}
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		cout << str;
		if (stu[str].size() == 0) {
			printf(" 0");
		}
		else {
			printf(" %d", (int)stu[str].size());
			set<int>::iterator it;
			for (it = stu[str].begin(); it != stu[str].end(); it++) {
				printf(" %d", *it);
			}
		}
		printf("\n");
	}
	return 0;
}
*/
//算法笔记
/*
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010;
const int M = 26*26*26*10 + 1;
vector<int> selectCourse[M];
int getID(char name[]) {
    int id = 0;
    for(int i = 0; i < 3; i++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}
int main() {
    char name[5];
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++) {
        int course, x;
        scanf("%d%d", &course, &x);
        for(int j = 0; j < x; j++) {
            scanf("%s", name);
            int id = getID(name);
            selectCourse[id].push_back(course);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %d", name, selectCourse[id].size());
        for(int j = 0; j < selectCourse[id].size(); j++) {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }
    return 0;
}
*/
