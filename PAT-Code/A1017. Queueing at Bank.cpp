#include<cstdio>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
const int MAXN = 10010;
struct Person {
	int HH, MM, SS, P,time;
}p[MAXN];
bool cmp(Person a, Person b) {
	return a.time < b.time;
}
int N, K,tot=0;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d:%d:%d %d", &p[i].HH, &p[i].MM, &p[i].SS, &p[i].P);
		p[i].time = p[i].HH * 3600 + p[i].MM * 60 + p[i].SS;
		if (p[i].P > 60)
			p[i].P = 60;
		p[i].P = p[i].P * 60;
		if (p[i].HH >= 17 && (p[i].MM > 0 || p[i].SS > 0)) {
			i--;
			N--;
		}
	}
	sort(p+1, p + N+1, cmp);
	queue<Person> q;
	for (int i = 1; i <=N; i++) {
		q.push(p[i]);
	}
	priority_queue<int, vector<int>, greater<int> > tm;
	for (int i = 1; i <= K; i++) {
		tm.push(8 * 3600);
	}
	while (!q.empty()) {
		for (int i = 1; i <= K; i++) {
			if(!q.empty()) {
				if (q.front().time < tm.top()) {
					tot += tm.top() - q.front().time;
					tm.push(tm.top() + q.front().P);
				}
				else {
					tm.push(q.front().time + q.front().P);
				}
				q.pop();
				tm.pop();
			}
		}
	}
	double avg = 1.0*tot /(60*N);
	printf("%.1f", avg);
	return 0;
}
//算法笔记
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int K = 111;
const int INF = 1000000000;
struct Customer {
    int comeTime, serveTime;
} newCustomer;
vector<Customer> custom;
int convertTime(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
bool cmp(Customer a, Customer b) {
    return a.comeTime < b.comeTime;
}
int endTime[K];
int main() {
    int c, w, totTime = 0;
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(17, 0, 0);
    scanf("%d%d", &c, &w);
    for(int i = 0; i < w; i++) endTime[i] = stTime;
    for(int i = 0; i < c; i++) {
        int h, m, s, serveTime;
        scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
        int comeTime = convertTime(h, m, s);
        if(comeTime > edTime) continue;
        newCustomer.comeTime = comeTime;
        newCustomer.serveTime = serveTime <= 60 ? serveTime * 60 : 3600;
        custom.push_back(newCustomer);
    }
    sort(custom.begin(), custom.end(), cmp);
    for(int i = 0; i < custom.size(); i++) {
        int idx = -1, minEndTime = INF;
        for(int j = 0; j < w; j++) {
            if(endTime[j] < minEndTime) {
                minEndTime = endTime[j];
                idx = j;
            }
        }
        if(endTime[idx] <= custom[i].comeTime) {
            endTime[idx] = custom[i].comeTime + custom[i].serveTime;
        } else {
            totTime += (endTime[idx] - custom[i].comeTime);
            endTime[idx] += custom[i].serveTime;
        }
    }
    if(custom.size() == 0) printf("0.0");
    else printf("%.1f", totTime / 60.0 / custom.size());
    return 0;
}
