#include<cstdio>
int main()
{
	int T,win1=0,win2=0;
	scanf("%d", &T);
	while(T--)
	{
		int in1, out1, in2, out2;
		scanf("%d%d%d%d", &in1, &out1, &in2, &out2);
		if (out1 == (in1 + in2) && out2 != (in1 + in2))
			win2++;
		if (out2 == (in1 + in2) && out1 != (in1 + in2))
			win1++;
	}
	printf("%d %d\n", win1, win2);
	return 0;
}
