//给定一个递增的正整数序列，和一个正整数M，求序列中的两个不同位置的数a和b，和恰好为M
//O(n)
while (i < j) {
	if (a[i] + a[j] == m) {
		printf("%d %d\n", i, j);
		i++;
		j--;
	}
	else if (a[i] + a[j] < m) {
		i++;
	}
	else {
		j--;
	}
}
//归并排序,O(nlogn)
const int maxn = 1;
//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间,L2=R1+1
void merge(int A[], int L1, int R1, int L2, int R2) {
	int i = L1, j = L2;
	int temp[maxn], index = 0;
	while (i <= R1 && j <= R2) {
		if (A[i] <= A[j]) {
			temp[index++] = A[i++];
		}
		else {
			temp[index++] = A[j++];
		}
	}
	while (i <= R1) temp[index++] = A[i++];
	while (j <= R2) temp[index++] = A[j++];
	for (int i = 0; i < index; i++) {
		A[L1 + i] = temp[i];
	}
}
//将array数组当前区间[left,right]进行归并排序
void mergeSort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, mid + 1, right);
	}
}
//非递归实现
void mergeSort(int A[]) {
	//step为组内元素个数，step/2为左子区间元素个数，注意等号可不取
	for (int step = 2; step / 2 <= n; step *= 2) {
		//每step个元素一组，组内前step/2和后step/2个元素进行合并
		for(int i=1;i<=n;i+=step){
			int mid = i + step / 2 - 1;
			if (mid + 1 <= n) {
				merge(A, i, mid, mid + 1, min(i + step - 1, n));
			}
		}
	}
}
//只要求给出归并排序每一趟结束时的序列，可以使用sort函数
void mergeSort(int A[]) {
	for (int step = 2; step / 2 >= n; step * 2) {
		for (int i = 1; i <= n; i += step) {
			sort(A + i, A + min(i + step, n + 1));
		}
		//此处可输出归并排序的某一趟结束的序列
	}
}
//快速排序,O(nlogn)
//对区间[left,right]进行划分
int Partition(int A[], int left, int right) {
	int temp = A[left];
	while (left < right) {
		while (left<right&&A[right]>temp) right--;
		A[left] = A[right];
		while (left < right&&A[left] <= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
void quickSort(int A[], int left, int right) {
	if (left < right) {
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}
//随机选择主元，对区间[left,right]进行划分
#include<cstdlib>
#include<ctime>
int main(){
    srand((unsigned)time(NULL));
}
int randPartition(int A[], int left, int right) {
	//生成[left,right]内的随机数P
	int p = (round(1.0*rand()/ RAND_MAX)*(right - left) + left);
	swap(A[P],A[left]);
	int temp = A[left];
	while (left < right) {
		while (left<right&&A[right]>temp) right--;
		A[left] = A[right];
		while (left < right&&A[left] <= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
