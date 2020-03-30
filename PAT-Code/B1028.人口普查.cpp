#include<cstdio>
struct Person
{
	char Name[10];
	int year;
	int month;
	int day;
}P[100000],tempy,tempo;
int main()
{
	int n;
	scanf("%d", &n);
	int  old, young;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", P[i].Name, &P[i].year, &P[i].month, &P[i].day);
		int flag = 0;
		if(P[i].year>1814&&P[i].year<2014)
		{
			flag = 1;
		}
		else if(P[i].year==1814)
		{
			if(P[i].month>9)
			{
				flag = 1;
			}
			else if(P[i].month==9)
			{
				if (P[i].day >= 6)
				{
					flag = 1;
				}
			}
		}
		else if(P[i].year==2014)
		{
			if(P[i].month<9)
			{
				flag = 1;
			}
			else if(P[i].month==9)
			{
				if(P[i].day<=6)
				{
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			i--;
			n--;
		}
	}
	tempy.year = 0, tempy.month = 1, tempy.day = 1;
	tempo.year = 9999, tempo.month = 12, tempo.day = 31;
	for(int i=0;i<n;i++)
	{
		if(P[i].year<tempo.year)
		{
			tempo=P[i];
			old= i;
		}
		else if(P[i].year==tempo.year)
		{
			if(P[i].month<tempo.month)
			{
				tempo = P[i];
				old = i;
			}
			else if(P[i].month==tempo.month)
			{
				if(P[i].day<tempo.day)
				{
					tempo = P[i];
					old = i;
				}
			}
		}
		if (P[i].year>tempy.year)
		{
			tempy = P[i];
			young = i;
		}
		else if (P[i].year == tempy.year)
		{
			if (P[i].month>tempy.month)
			{
				tempy = P[i];
				young = i;
			}
			else if (P[i].month == tempy.month)
			{
				if (P[i].day>tempy.day)
				{
					tempy = P[i];
					young = i;
				}
			}
		}
	}
	if (n)
		printf("%d %s %s\n", n, P[old].Name, P[young].Name);
	else
		printf("%d\n", 0);
	return 0;
}
//算法笔记
#include <cstdio>
struct person {
    char name[10];
    int yy, mm, dd;
}oldest, youngest, left, right, temp;
bool LessEqu(person a, person b) {
    if(a.yy != b.yy) return a.yy <= b.yy;
    else if(a.mm != b.mm) return a.mm <= b.mm;
    else return a.dd <= b.dd;
}
bool MoreEqu(person a, person b) {
    if(a.yy != b.yy) return a.yy >= b.yy;
    else if(a.mm != b.mm) return a.mm >= b.mm;
    else return a.dd >= b.dd;
}
void init() {
    youngest.yy = left.yy = 1814;
    oldest.yy = right.yy = 2014;
    youngest.mm = oldest.mm = left.mm = right.mm = 9;
    youngest.dd = oldest.dd = left.dd = right.dd = 6;
}
int main() {
    init();
    int n, num = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
        if(MoreEqu(temp, left) && LessEqu(temp, right)) {
            num++;
            if(LessEqu(temp, oldest)) oldest = temp;
            if(MoreEqu(temp, youngest)) youngest = temp;
        }
    }
    if(num == 0) printf("0\n");
    else printf("%d %s %s\n", num, oldest.name, youngest.name);
    return 0;
}
