//算法笔记，无法通过牛客网的某个用例
//错误用例：
//10 
//3 1 2 8 7 5 9 4 6 0 
//1 2 3 5 7 8 9 4 6 0
//Insertion Sort 
//1 2 3 4 5 7 8 9 6 0 
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N], changed[N];
int n;
bool isSame(int A[], int B[]) {
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}
bool showArray(int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if(i < n - 1) printf(" ");
    }
    printf("\n");
}
bool insertSort() {
    bool flag = false;
    for(int i = 1; i < n; i++) {
        if(i != 1 && isSame(tempOri, changed)) {
            flag = true;
        }
        int temp = tempOri[i], j = i;
        while(j > 0 && tempOri[j - 1] > temp) {
            tempOri[j] = tempOri[j - 1];
            j--;
        }
        tempOri[j] = temp;
        if(flag == true) {
            return true;
        }
    }
    return false;
}
void mergeSort() {
    bool flag = false;
    for(int step = 2; step / 2 <= n; step *= 2) {
        if(step != 2 && isSame(tempOri, changed)) {
            flag = true;
        }
        for(int i = 0; i < n; i += step) {
            sort(tempOri + i, tempOri + min(i + step, n));
        }
        if(flag == true) {
            showArray(tempOri);
            return;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &changed[i]);
    }
    if (insertSort()) {
        printf("Insertion Sort\n");
        showArray(tempOri);
    } else {
        printf("Merge Sort\n");
        for(int i = 0; i < n; i++) {
            tempOri[i] = origin[i];
        }
        mergeSort();
    }
    return 0;
}
//PAT，牛客网均可通过
#include <cstdio>
#include <algorithm>
using namespace std;
int buf1[110];
int buf2[110];
int temp[110];
bool IsSame(int a[], int b[], int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		if (a[i] != b[i]) return false;
	}

	return true;
}

int InsertSort(int a[], int n)
{
	int i, j, tmp;
	int flag = 0;
	for (i = 1; i<n; i++)
	{
		if (a[i] < a[i - 1])
		{
			if (IsSame(a, buf2, n))
			{
				flag = 1;
			}

			tmp = a[i];
			for (j = i - 1; a[j]>tmp && j >= 0; j--)
			{
				a[j + 1] = a[j];
			}

			a[j + 1] = tmp;
		}

		if (flag == 1)
		{
			return 1;
		}
	}

	return 0;
}

void output(int a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void MergeSort(int a[], int n)
{
	int step, i, j;
	int flag = 0;
	for (step = 2; step / 2 <= n; step *= 2)
	{
		if (IsSame(a, buf2, n))
		{
			flag = 1;
		}
		for (i = 0; i<n; i += step)
		{
			sort(a + i, a + min(i + step, n));
		}


		if (flag == 1) return;
	}
}

int main()
{
		int n, i;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &buf1[i]);
		temp[i] = buf1[i];
	}

	for (i = 0; i<n; i++)
	{
		scanf("%d", &buf2[i]);
	}

	if (InsertSort(buf1, n) == 1)
	{
		printf("Insertion Sort\n");
		output(buf1, n);
	}
	else
	{
		MergeSort(temp, n);
		printf("Merge Sort\n");
		output(temp, n);
	}

	return 0;
}
