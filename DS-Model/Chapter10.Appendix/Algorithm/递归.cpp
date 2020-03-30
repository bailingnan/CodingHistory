#include<cstdio>//全排列
const int maxn = 11;
//P为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = { false };
//当前处理排列的第index号位
void generateP(int index) {
	if (index == n + 1) {//递归边界，已经处理完排列的1~n位
		for (int i = 1; i <= n; i++) {
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	for (int x = 1; x <= n; x++) {//枚举1~n,试图将x填入P[index]
		if (hashTable[x] == false) {//如果x不在P[0]~P[index-1]中
			P[index] = x;//令P的第index位为x，即把x加入当前排列
			hashTable[x] = true;//记x已在P中
			generateP(index + 1);//处理排列的第index+1号位
			hashTable[x] = false;//已处理完P[index]为x的子问题，还原状态
		}
	}
}
int main() {
	n = 3;
	generateP(1);
	return 0;
}
//n皇后问题
int count = 0;
void generateP(int index) {
	if (index == n + 1) {//递归边界，生成一个序列
		bool flag = true;//flag为true表示当前排列为一个合法方案
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(i - j) == abs(P[i] - P[j])) {//如果在一条对角线上
					flag = false;
				}
			}
		}
		if (flag) count++;
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (hashTable[x] == false) {
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}
//回溯法
void generateP(int index) {//递归边界，生成一个合法方案
	if (index == n + 1) {//能到达这里一定是合法的
		count++;
		return;
	}
	for (int x = 1; x <= n; x++) {//第x行
		if (hashTable[x] == false) {//第x行还没有皇后
			bool flag = true;//flag为true表示当前皇后不会和之前的皇后冲突
			for (int pre = 1; pre < index; pre++) {//遍历之前的皇后
				//第index列皇后的行号为x，第pre列皇后的行号为P[pre]
				if (abs(index - pre) == abs(x - P[pre])) {//在一条对角线，冲突
					flag = false;
					break;
				}
			}
			if (flag) {
				P[index] = x;
				hashTable[x] = true;
				generateP(index + 1);
				hashTable[x] = false;
			}
		}
	}
}
