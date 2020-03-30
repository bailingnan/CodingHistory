#include<cstdio>
#include<algorithm>
using namespace std;
struct Num {
	int n,w, cnt = 100010;
}s[10010];
bool cmp(Num a, Num b) {
	if (a.cnt != b.cnt)
		return a.cnt < b.cnt;
	else return a.w< b.w;
}
int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		s[temp].n = temp;
		s[temp].w = i;
		if (s[temp].cnt == 100010)
			s[temp].cnt = 1;
		else s[temp].cnt++;
	}
	sort(s, s + 10010, cmp);
	if (s[0].cnt == 1)
		printf("%d", s[0].n);
	else printf("None");
	return 0;
}
//算法笔记
#include <cstdio>
int a[100001], HashTable[10001] = {0};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        HashTable[a[i]]++;
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(HashTable[a[i]] == 1) {
            ans = a[i];
            break;
        }
    }
    if(ans == -1) printf("None");
    else printf("%d\n", ans);
    return 0;
}
