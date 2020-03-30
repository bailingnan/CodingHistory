//随机选择算法，从A[left,right]中返回第K大的数
int randSelect(int A[], int left, int right, int K) {
	if (left == right) return A[left];//边界
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if (K == M) return A[p];
	if (K < M) {
		return randSelect(A, left, p - 1, K);
	}
	else {
		return randSelect(A, p + 1, right, K - M);
	}
}
