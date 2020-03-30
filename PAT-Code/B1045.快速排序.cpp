#include<cstdio>
#include<algorithm>
using namespace std;
struct Number {
	int t, m;
}temp[100010];
bool cmp(Number a, Number b) {
	return a.t < b.t;
}
int main() {
	int N, cnt = 0, Num[100010];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &Num[i]);
	}
	for (int i = 0; i < N; i++) {
		int flag = 1;
		if (cnt > 0) {
			if (temp[cnt - 1].t < Num[i]) {
				for (int j = i - 1; j > temp[cnt - 1].m; j--) {
					if (Num[j] > Num[i]) {
						flag = 0;
						break;
					}
				}
				if (flag == 0)
					continue;
				for (int k = i + 1; k < N; k++) {
					if (Num[k] < Num[i]) {
						flag = 0;
						break;
					}
				}
				if (flag == 0)
					continue;
				else {
					temp[cnt++].t = Num[i];
					temp[cnt - 1].m = i;
				}
			}
			else {
				continue;
			}
		}
		else {
			for (int j = 0; j<i; j++) {
				if (Num[j] > Num[i]) {
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				continue;
			for (int k = i + 1; k < N; k++) {
				if (Num[k] < Num[i]) {
					flag = 0;
					break;
				}
			}
			if (flag == 0)
				continue;
			else {
				temp[cnt++].t = Num[i];
				temp[cnt - 1].m = i;
			}
		}
	}
	printf("%d", cnt);
	if (cnt > 0) 
		printf("\n");
	sort(temp, temp + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		printf("%d", temp[i].t);
		if (i < cnt - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
/*
//算法笔记
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3fffffff;    // 一个很大的数
// a为序列，leftMax和rightMin分别为每一位左边最大的数和右边最小的数
int a[MAXN], leftMax[MAXN], rightMin[MAXN];
// ans记录所有主元，num为主元个数
int ans[MAXN], num = 0;
int main(){
    int n;
    scanf("%d", &n);    // 序列元素个数
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);    // 输入序列元素
    }
    leftMax[0] = 0;    // A[0]左边没有比它大的数
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], a[i - 1]);    // 由i-1推得i
    }
    rightMin[n - 1] = INF;    // A[n-1]右边没有比它小的数
    for(int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], a[i + 1]);    // 由i+1推得i
    }
    for(int i = 0; i < n; i++) {
        // 左边所有数比它小，右边所有数比它大
        if(leftMax[i] < a[i] && rightMin[i] > a[i]) {
            ans[num++] = a[i];    // 记录主元
        }
    }
    printf("%d\n", num);    // 输出主元个数
    for(int i = 0; i < num; i++) {
        printf("%d", ans[i]);    // 依次输出所有主元
        if(i < num - 1) printf(" ");
    }
    printf("\n");    // 必须要有换行
    return 0;
}
*/
