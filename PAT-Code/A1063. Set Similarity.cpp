#include<cstdio>//超时，扣4分
#include<cmath>
#include<set>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	set<int>num[51];
	for (int i = 1; i <= N; i++) {
		int M;
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			int temp;
			scanf("%d", &temp);
			num[i].insert(temp);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		set<int> t;
		set<int>::iterator it;
		for (it = num[b].begin(); it != num[b].end(); it++) {
			t.insert(*it);
		}
		for (it = num[a].begin(); it != num[a].end(); it++) {
			t.insert(*it);
		}
		int len = t.size();
		int temp = abs(int(num[a].size()+num[b].size()-len));
		double r = double(temp) / len;
		printf("%.1f%%\n", r * 100);
	}
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];
void compare(int x, int y) {
    int totalNum = st[y].size(), sameNum = 0;
    for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
        if(st[y].find(*it) != st[y].end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%\n", sameNum * 100.0 / totalNum);
}
int main() {
    int n, k, q, v, st1, st2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &st1, &st2);
        compare(st1, st2);
    }
    return 0;
}
*/
