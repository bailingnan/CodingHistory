#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N, temp, a[110], ht[10000] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		temp = a[i];
		ht[temp]++;
		while (temp != 1) {
			if (temp % 2 == 0) {
				temp /= 2;
				ht[temp]++;
			}
			else {
				temp = (3 * temp + 1)/2;
				ht[temp]++;
			}
		}
	}
	sort(a, a + N);
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (ht[a[i]] == 1)
			cnt++;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (ht[a[i]] == 1) {
			printf("%d", a[i]);
			cnt--;
			if (cnt > 0)
				printf(" ");
		}
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, m, a[110];
    scanf("%d", &n);
    bool HashTable[10000] = {0};     //1000不行就开10000，必过
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m = a[i];
        while(m != 1) {
            if(m % 2 == 1) m = (3 * m + 1) / 2;
            else m = m / 2;
            HashTable[m] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(HashTable[a[i]] == false) {
            count++;
        }
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) {
        if(HashTable[a[i]] == false) {
            printf("%d", a[i]);
            count--;
            if(count > 0) printf(" ");
        }
    }
    return 0;
}
