#include<cstdio>//运行超时，扣6分
#include<algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn], st[maxn], N,cnt;
bool isSorted() {
	for (int i = 0; i < N; i++) {
		if (num[i] != i) {
			return false;
		}
	}
	return true;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		st[num[i]] = i;
	}
	while (st[0] != 0) {
		swap(num[st[0]], num[st[st[0]]]);
		swap(st[0], st[st[0]]);
		cnt++;
	}
	while (!isSorted()) {
		for (int i = 0; i < N; i++) {
			if (num[i] != i) {
				swap(st[0], st[num[i]]);
				swap(num[0], num[i]);
				cnt++;
				break;
			}
		}
		while (st[0] != 0) {
			swap(num[st[0]], num[st[st[0]]]);
			swap(st[0], st[st[0]]);
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];
int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int left = n - 1, num;
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        pos[num] = i;
        if(num == i && num != 0) {
            left--;
        }
    }
    int k = 1;
    while(left > 0) {
        if(pos[0] == 0) {
            while(k < n) {
                if(pos[k] != k) {
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/
