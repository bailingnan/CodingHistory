#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num;
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	int i = 0, j = N - 1;
	bool flag = false;
	while (i < j) {
		if (num[i] + num[j] == M) {
			flag = true;
			break;
		}
		else if (num[i] + num[j] > M) {
			j--;
		}
		else { 
			i++; 
		}
	}
	if (flag ==true) {
		printf("%d %d", num[i], num[j]);
	}
	else {
		printf("No Solution");
	}
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N, M,num[100010];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	int l , r = N - 1,flag=0;
	for (int i = 0; i < N; i++) {
		l = i;
		while (l < r) {
			if (num[l] + num[r] == M) {
				flag = 1;
				printf("%d %d", num[l], num[r]);
				break;
			}
			else {
				if (num[l] + num[r] < M)
					break;
				else r--;
			}
		}
		if (flag == 1)
			break;
	}
	if (flag==0)
		printf("No Solution");
	return 0;
}
*/
/*
#include<cstdio>
#include<algorithm>
using namespace std;
int bs(int num[], int l, int r, int t) {
	while (l <=r) {
		int mid = (l + r) / 2;
		if (num[mid] == t) return mid;
		else if (num[mid] > t)
			r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
int main() {
	int N, M, num[100010];
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	int flag = 0;
	for (int i = 0; i < N; i++) {
		int m = bs(num,i+1, N - 1, M-num[i]);
		if (m != -1) {
			flag = 1;
			printf("%d %d", num[i],num[m]);
			break;
		}
	}
	if (flag == 0)
		printf("No Solution");
	return 0;
}
*/
/*
//算法笔记，方法一：哈希法
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int HashTable[N];
int main() {
    int n, m, a;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        ++HashTable[a];
    }
    for(int i = 0; i < N; i++) {
        if(HashTable[i] && HashTable[m - i]) {
            if(i == m - i && HashTable[i] <= 1) {
                continue;
            }
            printf("%d %d\n", i, m - i);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
//方法二：二分查找法
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int Bin(int left,int right,int key){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]>key) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main(){
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        int pos=Bin(0,n-1,m-a[i]);
        if(pos!=-1 && i!=pos){
            printf("%d %d\n",a[i],a[pos]);
            break;
        }
    }
    if(i==n) printf("No Solution\n");
    return 0;
}
//方法三：two pointers
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int a[maxn];
void twoPointers(int n, int m) {
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == m) break;
        else if(a[i] + a[j] < m) {
            i++;
        } else {
            j--;
        }
    }
    if(i < j) {
        printf("%d %d\n", a[i], a[j]);
    } else {
        printf("No Solution\n");
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    twoPointers(n, m);
    return 0;
}
*/
