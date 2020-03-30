#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
const int St = 8 * 60;
const int Ed = 17 * 60;
struct Person{
	int time,st,ed,num;
}p[MAXN];
int N, M, K, Q;
int qur[MAXN];
queue<Person> q[21],qt;
bool cmp(Person a, Person b) {
	return a.num < b.num;
}
bool isF() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += q[i].size();
	}
	if (sum == 0) return false;
	else return true;
}
int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; i++) {
		int temp;
		scanf("%d", &temp);
		Person t;
		t.time = temp;
		t.num = i;
		if (i <= N) {
			t.st = St;
		}
		qt.push(t);
	}
	for (int i = 1; i <= Q; i++) {
		scanf("%d", &qur[i]);
	}
	
	int t = 1;
	while (!qt.empty()||isF()) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += q[i].size();
		}
		if (sum < N*M && !qt.empty()) {
			int cnt = N * M - sum,count=0;
			while (count < cnt&&!qt.empty()) {
				Person temp = qt.front();
				qt.pop();
				int min = 1000000000,t;
				for (int i = 1; i <= N; i++) {
					if (q[i].size() < min) {
						min = q[i].size();
						t = i;
					}
				}
				q[t].push(temp);
				count++;
			}
		}
		else {
			int min = 1000000000,num;
			for (int i = 1; i <= N; i++) {
				if (!q[i].empty()&&q[i].front().st + q[i].front().time < min) {
					min=q[i].front().st + q[i].front().time;
					num = i;
				}
			}
			if (!q[num].empty()) {
				q[num].front().ed = min;
				p[t++] = q[num].front();
				q[num].pop();
			}
			if (!q[num].empty()) {
				q[num].front().st = min;
			}
		}
	}
	for (int i = 1; i <= Q; i++) {
		if (p[qur[i]].st < Ed) {
			printf("%02d:%02d\n", p[qur[i]].ed / 60, p[qur[i]].ed % 60);
		}
		else {
			printf("Sorry\n");
		}
	}
	return 0;
}
/*
//算法笔记
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxNode = 1111;
int n, m, k, query, q;
int convertToMinute(int h, int m) {
    return h * 60 + m;
}
struct Window {
    int endTime, popTime;
    queue<int> q;
} window[20];
int ans[maxNode], needTime[maxNode];
int main() {
    int inIndex = 0;
    scanf("%d%d%d%d", &n, &m, &k, &query);
    for(int i = 0; i < k; i++) {
        scanf("%d", &needTime[i]);
    }
    for(int i = 0; i < n; i++) {
        window[i].popTime = window[i].endTime = convertToMinute(8, 0);
    }
    for(int i = 0; i < min(n * m, k); i++) {
        window[inIndex % n].q.push(inIndex);
        window[inIndex % n].endTime += needTime[inIndex];
        if(inIndex < n) window[inIndex].popTime = needTime[inIndex];
        ans[inIndex] = window[inIndex % n].endTime;
        inIndex++;
    }
    for(; inIndex < k; inIndex++) {
        int idx = -1, minPopTime = 1 << 30;
        for(int i = 0; i < n; i++) {
            if(window[i].popTime < minPopTime) {
                idx = i;
                minPopTime = window[i].popTime;
            }
        }
        Window& W = window[idx];
        W.q.pop();
        W.q.push(inIndex);
        W.endTime += needTime[inIndex];
        W.popTime += needTime[W.q.front()];
        ans[inIndex] = W.endTime;
    }
    for(int i = 0; i < query; i++) {
        scanf("%d", &q);
        if(ans[q - 1] - needTime[q - 1] >= convertToMinute(17, 0)) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", ans[q - 1] / 60, ans[q - 1] % 60);
        }
    }
    return 0;
}
*/
