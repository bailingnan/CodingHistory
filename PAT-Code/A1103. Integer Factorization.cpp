#include<cstdio>//运行超时一个测试点，扣3分；
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> vt,temp;
void intil(int K) {
	for (int i = 0; i < K; i++) {
		vt.push_back(0);
	}
}
int add1(vector<int> v,int P) {
	int sum=0;
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		sum += pow(*it, P);
	}
	return sum;
}
int add2(vector<int> v) {
	int sum = 0;
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		sum +=*it;
	}
	return sum;
}
bool ck(vector<int> temp,int N, int K, int P) {
	if (temp.size() != K)
		return false;
	int sum = add1(temp, P);
	if (sum != N)
		return false;
	return true;
}
bool cmp(int a,int b) {
	return a > b;
}
void DFS(int m,int N,int K,int P,int max) {
	if (ck(temp,N,K,P)== true) {
		if (add2(temp) > max) {
			max = add2(temp);
			vt = temp;
			return ;
		}
		else if (add2(temp) == max) {
			sort(temp.begin(), temp.end(), cmp);
			sort(vt.begin(),temp.end(), cmp);
			vector<int>::iterator itt = temp.begin();
			vector<int>::iterator itv = vt.begin();
			for (; itt != temp.end() && itv != vt.end(); itt++, itv++) {
				if (*itt > *itv) {
					vt = temp;
					return;
				}
			}
		}
	}
	if (m>(int)sqrt(1.0*N)||add1(temp,P) > N || temp.size() > K)
		return;
	temp.push_back(m);
	DFS(m, N, K, P, max);
	temp.pop_back();
	DFS(m + 1, N, K, P, max);
}
int main() {
	int N, K, P;
	scanf("%d%d%d", &N, &K, &P);
	intil(K);
	DFS(1, N, K, P,0);
	if (ck(vt, N, K, P) == true) {
		sort(vt.begin(), vt.end(), cmp);
		printf("%d = ", N);
		vector<int>::iterator it = vt.begin();
		for (int i = 0; i < K; i++,*it++) {
			if (i < K - 1) {
				printf("%d^%d", *it, P);
				printf(" + ");
			}
			else {
				printf("%d^%d", *it, P);
			}
		}
	}
	else printf("Impossible\n");
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// n、k、p如题所述，maxFacSum记录最大底数之和
int n, k, p, maxFacSum = -1;
// fac记录0^p,1^p...i^p，使得i^p为不超过n的最大数
// ans存放最优底数序列，temp存放递归中的临时底数序列
vector<int> fac, ans, temp;
// power函数计算x^p
int power(int x) {
    int ans = 1;
    for(int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}
// init函数预处理fac数组，注意把0也存进去
void init() {
    int i = 0, temp = 0;
    while(temp <= n) {    // 当i^p没有超过n时，不断把i^p加入fac
        fac.push_back(temp);
        temp = power(++i);
    }
}
// DFS函数，当前访问fac[index]，nowK为当前选中个数
// sum为当前选中的数之和， facSum为当前选中的底数之和
void DFS(int index, int nowK, int sum, int facSum) {
    if(sum == n && nowK == k) {    // 找到一个满足的序列
        if(facSum > maxFacSum) {    // 底数之和更优
            ans = temp;    // 更新最优底数序列
            maxFacSum = facSum;    // 更新最大底数之和
        }
        return;
    }
    if(sum > n || nowK > k) return;    // 接下来不会有答案，直接返回
    if(index - 1 >= 0) {    // fac[0]不需要选择
        temp.push_back(index);    // 把底数index加入临时序列temp
        DFS(index, nowK + 1, sum + fac[index], facSum + index);    // “选”的分支
        temp.pop_back();    // “选”的分支结束后把刚加进去的数pop掉
        DFS(index - 1, nowK, sum, facSum);    // “不选”的分支
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();    // 初始化fac数组
    DFS(fac.size() - 1, 0, 0, 0);    // 从fac的最后一位开始往前搜索
    if(maxFacSum == -1) printf("Impossible\n");    // 没有找到满足的序列
    else {
        printf("%d = %d^%d", n, ans[0], p);    // 输出ans的结果
        for(int i = 1; i < ans.size(); i++) {
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}
*/
