#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;
vector<int> g[maxn];
double cnt[maxn], area[maxn];
bool vis[maxn];
int N,num[maxn];
struct fam {
	int ID, n;
	double m, a;
};
vector<fam> f;
void DFS(int ID, int &minid, int &count, double &sume, double &suma) {
	vis[ID] = true;
	if (ID < minid) {
		minid = ID;
	}
	count++;
	sume += cnt[ID];
	suma += area[ID];
	if (g[ID].size() == 0) {
		return;
	}
	for (int i = 0; i < g[ID].size(); i++) {
		if (vis[g[ID][i]] == false) {
			DFS(g[ID][i], minid, count, sume, suma);
		}
	}
}
bool cmp(fam a, fam b) {
	if (a.a != b.a) {
		return a.a > b.a;
	}
	else {
		return a.ID < b.ID;
	}
}
int main() {
	fill(vis, vis + maxn, false);
	fill(cnt, cnt + maxn, 0);
	fill(area, area + maxn, 0);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int ID, f, m, k;
		scanf("%d%d%d", &ID, &f, &m);
		num[i] = ID;
		if (f != -1) {
			g[ID].push_back(f);
			g[f].push_back(ID);
		}
		if (m!= -1) {
			g[ID].push_back(m);
			g[m].push_back(ID);
		}
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int temp;
			scanf("%d", &temp);
			g[ID].push_back(temp);
			g[temp].push_back(ID);
		}
		scanf("%lf%lf", &cnt[ID], &area[ID]);
	}
	for (int i = 0; i < N; i++) {
		if (vis[num[i]] == false) {
			int minid = maxn,count=0;
			double sume= 0, suma = 0;
			DFS(num[i], minid,count,sume, suma);
			fam temp;
			temp.ID = minid;
			temp.n = count;
			temp.m = sume / temp.n;
			temp.a = suma / temp.n;
			f.push_back(temp);
		}
	}
	printf("%d\n", f.size());
	sort(f.begin(), f.end(), cmp);
	for (int i = 0; i < f.size(); i++) {
		printf("%04d %d %.3lf %.3lf", f[i].ID, f[i].n, f[i].m, f[i].a);
		if (i < f.size() - 1) {
			printf("\n");
		}
	}
	return 0;
}
/*#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n, numEstate[maxn] = { 0 }, area[maxn] = { 0 };
int father[maxn];  //存放父亲结点
struct Family {
	int ID, numMember, sumEstate, sumArea;
	double avgEstate, avgArea;
	Family() {
		ID = -1;
		numMember = sumEstate = sumArea = avgEstate = avgArea = 0;
	}
} family[maxn];
int findFather(int x) {  //查找x所在集合的根结点
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	//路径压缩（可不写）
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b) {  //合并a和b所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[max(faA, faB)] = min(faA, faB);
	}
}
void init(int ID) {
	if (father[ID] == -1) {
		father[ID] = ID;
	}
}
bool cmp(Family a, Family b) {
	if (a.avgArea != b.avgArea) return a.avgArea > b.avgArea;
	else return a.ID < b.ID;
}
int main() {
	scanf("%d", &n);
	memset(father, -1, sizeof(father));
	for (int i = 0; i < n; i++) {
		int ID, Father, Mother, k, Child;
		scanf("%d%d%d%d", &ID, &Father, &Mother, &k);
		if (father[ID] == -1) father[ID] = ID;
		if (Father != -1) {
			init(Father);
			Union(ID, Father);
		}
		if (Mother != -1) {
			init(Mother);
			Union(ID, Mother);
		}
		for (int j = 0; j < k; j++) {
			scanf("%d", &Child);
			init(Child);
			Union(ID, Child);
		}
		scanf("%d%d", &numEstate[ID], &area[ID]);
	}
	for (int i = 0; i < maxn; i++) {
		if (father[i] != -1) {
			int Father = findFather(i);
			family[Father].ID = Father;
			family[Father].numMember++;
			family[Father].sumEstate += numEstate[i];
			family[Father].sumArea += area[i];
		}
	}
	for (int i = 0; i < maxn; i++) {
		if (family[i].ID != -1) {
			family[i].avgEstate = 1.0 * family[i].sumEstate / family[i].numMember;
			family[i].avgArea = 1.0 * family[i].sumArea / family[i].numMember;
		}
	}
	sort(family, family + maxn, cmp);   // 排序后顺序将与原先不一致
	int numFamily = 0;  //记录集合数目
	for (int i = 0; i < maxn; i++) {
		if (family[i].ID != -1) {    //不能用father[i] != i
			numFamily++;
		}
	}
	printf("%d\n", numFamily);
	for (int i = 0; i < maxn; i++) {
		if (family[i].ID != -1) {
			printf("%04d %d %.3f %.3f\n", family[i].ID, family[i].numMember, family[i].avgEstate, family[i].avgArea);
		}
	}
	return 0;
}*/
