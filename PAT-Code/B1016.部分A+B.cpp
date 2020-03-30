#include<cstdio>
int main()
{
	long long A, DA, B, DB;
	scanf("%lld%lld%lld%lld", &A, &DA, &B, &DB);
	long long PA=0, PB=0;
	while(A)
	{
		if (A % 10 == DA)
			PA = PA * 10 + DA;
		A /= 10;
	}
	while(B)
	{
		if (B % 10 == DB)
			PB = PB * 10 + DB;
		B/= 10;
	}
	printf("%lld\n", PB + PA);
	return 0;
}
//算法笔记
#include <cstdio>
int main() {
    long long a, b, da, db;
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    long long pa = 0, pb = 0;
    while(a != 0) {
        if(a % 10 == da) pa = pa * 10 + da;
        a = a / 10;
    }
    while(b != 0) {
        if(b % 10 == db) pb = pb * 10 + db;
        b = b / 10;
    }
    printf("%lld\n", pa + pb);
    return 0;
}
