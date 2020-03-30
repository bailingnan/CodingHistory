#include<cstdio>
#include<vector>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int num;
		scanf("%d", &num);
		int temp = num,dig=0;
		while (temp) {
			temp /= 10;
			dig++;
		}
		int num1, num2 = 0, cnt = 0;
		vector<int> m;
		temp = num;
		while (cnt <dig / 2) {
			int t = temp%10;
			m.push_back(t);
			temp/= 10;
			cnt++;
		}
		num1 =temp;
		for (int i = m.size() - 1; i >= 0; i--) {
			num2 = num2 * 10 + m[i];
		}
		if (num1*num2 == 0) {
			printf("No\n");
		}
		else if (num % (num1 * num2) == 0) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}
