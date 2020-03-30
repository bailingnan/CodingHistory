#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct Node {
	int cnt, flag;
	double pr;
	vector<int> v;
	Node(){
		flag = 0;
	}
}n[100010];
int N,mincnt=0;
double p, r, rt,minn=10000000001;
queue<int> q;
void BFS(int root) {
	q.push(root);
	n[root].cnt = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (n[temp].flag == 1) {
			double pr = p * pow(rt, n[temp].cnt*1.0);
			n[temp].pr = pr;
			if (pr < minn)
				minn = pr;
		}
		for (int i = 0; i < n[temp].v.size(); i++) {
			n[n[temp].v[i]].cnt = n[temp].cnt + 1;
			q.push(n[temp].v[i]);
		}
	}
}
int main() {
	scanf("%d %lf %lf", &N, &p, &r);
	rt = 1 + 0.01*r;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 0) {
			n[i].flag = 1;
		}
		for (int j = 0; j < temp;j++) {
			int t;
			scanf("%d", &t);
			n[i].v.push_back(t);
		}
	}
	BFS(0);
	for (int i = 0; i < N; i++) {
		if (n[i].flag == 1) {
			if (n[i].pr == minn)
				mincnt++;
		}
	}
	printf("%.4f %d", minn, mincnt);
	return 0;
}
//算法笔记
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;    // 很大的数，10^12
vector<int> Node[maxn];    // Node[i]存放i的所有孩子的编号
int n, num = 0;    // n为结点个数，num为价格最低的叶子结点个数
double p, r, ans = INF;    // ans为最低叶子结点价格
void DFS(int index, int depth) {
    if(Node[index].size() == 0) {    // 到达叶结点
        double price = p * pow(1 + r, depth);    // 当前价格
        if(price < ans) {    // 如果低于全局最低价格
            ans = price;    // 更新全局最低价格
            num = 1;    // 价格最低的叶子结点个数为1
        } else if(price == ans) {    // 如果等于全局最低价格
            num++;    // 价格最低的叶子结点个数加1
        }
        return;
    }
    for(int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], depth + 1);    // 递归访问子结点
    }
}
int main() {
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k != 0) {    // 叶结点标志
            for(int j = 0; j < k; j++) {
                scanf("%d", &child);
                Node[i].push_back(child);    // child为结点i的子结点
            }
        }
    }
    DFS(0, 0);    // DFS入口
    printf("%.4f %d\n", ans, num);    // 输出结果
    return 0;
}
