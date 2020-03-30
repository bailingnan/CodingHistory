//初始化
for (int i = 1; i <= N; i++) {
	father[i] = i;
}
//查找
int findFather(int x) {
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}
int findFather(int x) {
	if (x == fatehr[x]) return x;
	else return findFather(father[x]);
}
//合并
void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
//路径压缩
int findFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
int findFather(int v) {
	if (v == father[v]) return v;
	else {
		int F = findFather(father[v]);
		father[v] = F;
		return F;
	}
}
