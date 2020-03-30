#include<cstdio>//超时扣4分；
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Cs {
	vector<string> nm;
}cs[2501];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cnt;
		scanf("%d",&cnt);
		for (int j = 0; j < cnt; j++) {
			int m;
			scanf("%d", &m);
			cs[m].nm.push_back(str);
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d %d\n", i, cs[i].nm.size());
		sort(cs[i].nm.begin(), cs[i].nm.end());
		vector<string>::iterator it;
		for (it=cs[i].nm.begin(); it!=cs[i].nm.end(); it++) {
			cout << *it<<endl;
		}
	}
	return 0;
}
/*超时扣4分
#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> cou[2510];
int N, K;
int main() {
	scanf("%d%d",&N, &K);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int temp;
			scanf("%d", &temp);
			cou[temp].insert(str);
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d %d\n", i, (int)cou[i].size());
		if ((int)cou[i].size() != 0) {
			set<string>::iterator it;
			for (it = cou[i].begin(); it != cou[i].end(); it++) {
				cout << *it << endl;
			}
		}
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
const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];
vector<int> course[maxc];
bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k, c, courseID;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &c);
        for(int j = 0; j < c; j++) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for(int j = 0; j < course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}
*/
