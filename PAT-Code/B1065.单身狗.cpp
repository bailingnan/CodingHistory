#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
bool ht[maxn];
int N, M,cp[maxn];
vector<int> v,p;
int main() {
	fill(ht, ht + maxn, false);
	fill(cp, cp + maxn, -1);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		cp[c1] = c2;
		cp[c2] = c1;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		ht[temp] = true;
		v.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		if (cp[v[i]] == -1 || (cp[v[i]] != -1 && ht[cp[v[i]]] == false)) {
			p.push_back(v[i]);
		}
	}
	sort(p.begin(), p.end());
	printf("%d\n", p.size());
	for (int i = 0; i < p.size(); i++) {
		printf("%05d", p[i]);
		if (i < p.size() - 1) {
			printf(" ");
		}
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
const int maxm = 10010;
int couple[maxn], IDinParty[maxm];
bool isInParty[maxn] = { false };
int numSingleDog = 0, singleDog[maxm];
int main() {
	int n, m;
	scanf("%d", &n);
	memset(couple, -1, sizeof(couple));
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		couple[a] = b;
		couple[b] = a;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &IDinParty[i]);
		if (!isInParty[IDinParty[i]]) {
			isInParty[IDinParty[i]] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		int ID = IDinParty[i];
		if (couple[ID] == -1 || !isInParty[couple[ID]]) {
			singleDog[numSingleDog++] = ID;
		}
	}
	sort(singleDog, singleDog + numSingleDog);
	printf("%d\n", numSingleDog);
	for (int i = 0; i < numSingleDog; i++) {
		printf("%05d", singleDog[i]);
		if (i < numSingleDog - 1) {
			printf(" ");
		}
	}
	return 0;
}
*/
