#include<cstdio>
int main()
{
	int N, win = 0, tie = 0, lose = 0,AW[3]={0},AL[3]={0};
	char c[3] = { 'B','C','J' };
	scanf("%d", &N);
	getchar();
	for(int i=0;i<N;i++)
	{
		char A, B;
		scanf("%c", &A);
		getchar();
		scanf("%c", &B);
		getchar();
		if(A=='B')
		{
			if (B =='B')
				tie++;
			else if (B =='C')
			{
				win++;
				AW[0]++;
			}
			else
			{
				lose++;
				AL[2]++;
			}
		}
		else if(A=='C')
		{
			if (B == 'B')
			{
				lose++;
				AL[0]++;
			}
			else if (B == 'C')
				tie++;
			else
			{
				win++;
				AW[1]++;
			}
		}
		else
		{
			if (B == 'B')
			{
				win++;
				AW[2]++;
			}
			else if (B == 'C')
			{
				lose++;
				AL[1]++;
			}
			else
				tie++;
		}
	}
	int max1 = 0, max2 = 0,num1=0,num2=0;
	for(int i=0;i<3;i++)
	{
		if (AW[i] > max1)
		{
			num1 = i;
			max1 = AW[i];
		}
		if(AL[i]>max2)
		{
			num2 = i;
			max2 = AL[i];
		}
	}
	printf("%d %d %d\n", win, tie, lose);
	printf("%d %d %d\n", lose, tie, win);
	printf("%c ", c[num1]);
	printf("%c", c[num2]);
	return 0;
}
//算法笔记
#include <cstdio>
int change(char c) {
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
}
int main() {
    char mp[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);
    int times_A[3] = {0}, times_B[3] = {0};
    int hand_A[3] = {0}, hand_B[3] = {0};
    char c1, c2;
    int k1, k2;
    for(int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);
        if((k1 + 1) % 3 == k2) {
            times_A[0]++;
            times_B[2]++;
            hand_A[k1]++;
        } else if(k1 == k2) {
            times_A[1]++;
            times_B[1]++;
        } else {
            times_A[2]++;
            times_B[0]++;
            hand_B[k2]++;
        }
    }
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
    int id1 = 0, id2 = 0;
    for(int i = 0; i < 3; i++) {
        if(hand_A[i] > hand_A[id1]) id1 = i;
        if(hand_B[i] > hand_B[id2]) id2 = i;
    }
    printf("%c %c\n", mp[id1], mp[id2]);
    return 0;
}
