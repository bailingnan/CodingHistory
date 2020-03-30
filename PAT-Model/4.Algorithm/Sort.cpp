void selectSort() {//选择排序，O(n^2)
	for (int i=1; i <= n; i++) {
		int k = i;
		for (int j = i; j <= n; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp;
	}
}
//插入排序
int A[maxn], n;
void insertSort() {
	for (int i = 2; i <= n; i++) {//n-1趟排序
		int temp = A[i], j = i;
		while (j > 1 && temp < A[j - 1]) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}
//排名的实现
stu[0].r = 1;
for (int i = 1; i < n; i++) {
	if (stu[i].score == stu[i].score) {
		stu[i].r = stu[i - 1].r;
	}
	else {
		stu[i].r = i + 1;
	}
}
//直接输出
int r = 1;
for (int i = 0; i < n; i++) {
	if (i > 0 && stu[i].score != stu[i - 1].score) {
		r = i + 1;
	}
	//输出当前个体信息，或者令stu[i].r=r;
}
