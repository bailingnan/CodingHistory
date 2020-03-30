//叶子结点的路径长度是指从根结点出发到达该结点所经过的边数。
//叶子结点的权值乘以其路径长度的结果称为这个叶子结点的带权路径长度。
//树的带权路径长度等于它所有叶子结点的带权路径长度之和。
//已知n个数，寻找一棵树，使得树的所有叶子结点的权值恰好为这n个数。
#include<cstdio>
#include<queue>
#include<functional>
using namespace std;
//代表小顶堆的优先队列
priority_queue<long long, vector<long long>, greater<long long>>q;
int main() {
	int n;
	long long temp,x, y, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		q.push(temp);
	}
	while (q.size() > 1) {//只要优先队列中至少有两个元素
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		ans += x + y;
	}
	printf("%lld", ans);
	return 0;
}
