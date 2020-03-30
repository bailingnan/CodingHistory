//int取值范围：-2147483648~2147483647 即-2^31~2^31-1
//long long -2^63~2^63-1
const int INF=(1<<30)-1;
const int INF=0x3fffffff;
//long long:scanf:%lld printf:%lld
//double scanf:%lf printf:%f
//除%c外，scanf对其他格式符的输入是以空白符（空格，换行等）为结束判断标志的。
//%s读入的时候以空格和换行符为结束的标志。%c格式是可以读入空格跟换行的。
//getchar()可以读入换行符。
fabs(double x)//取绝对值
floor(double x) ceil(double x) //向上取整和向下取整
pow(double r,double p)//r^p
round(double x)//对double型变量x四舍五入，返回类型为double，需(int)进行类型转换
//冒泡排序
#include<cstdio>
int main() {
	int a[10] = { 9,23,34,2,1 };
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 5 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
//冒泡排序
#include<cstdio>
#define MAXSIZE 10
int BubbleSort(int Num[]);
int Swap(int *a, int *b);
int main()
{
	int Num[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++)
		scanf("%d", &Num[i]);
	BubbleSort(Num);
	for (int i = 0; i < MAXSIZE; i++)
		printf("%d\n", Num[i]);
	return 0;
}
int BubbleSort(int Num[])
{
	for(int i=1;i<MAXSIZE;i++)
	{
		for (int j = 0; j < MAXSIZE- i; j++)
			if (Num[j] > Num[j + 1])
				Swap(&Num[j], &Num[j + 1]);
	}
	return 0;
}
int Swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
//gets_s用来输入一行字符串，gets_s识别换行符\n作为输入结束，scanf完一个整数后，如果要使用gets_s，需要先使用getchar接收整数后的换行符。
//puts会自动在末尾换行。
//\0占用一个字符位。使用getchar（）输入字符串，需要在字符串后加\0;
sscanf(str,"%d",&n);//把字符数组str中的内容以"%d"的格式写到n中
sprintf(str,"%d",n);//把n以“%d”的格式写到str字符数组中
int n;
double db;
char str[100]="2048:3.14,hello",str2[100];
sscanf(str,"%d:%lf,%s:,&n,&db,str2);
int n=12;
double db=3.14;
char str[100],str2[100]="good";
sprintf(str,"%d:%.2f,%s",n,db,str2)
//
void swap(int *a, int *b) {
	int x;
	int *temp = &x;//temp被初始化才可以实现交换
	*temp = *a;
	*a = *b;
	*b = *temp;
}
//
#include<cstdio>
void swap(int* &p1, int* &p2) {
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}
int main() {
	int a = 1, b = 2;
	int *p1 = &a, *p2 = &b;//引用是产生变量的别名，因此常量不可使用引用，不可写成swap(&a,&b);
	swap(p1, p2);
	return 0;
}
struct studentInfo {
	int id;
	char gender;
	studentInfo(int _id, char _gender) {
		id = _id;
		gender = _gender;
	}
};
struct studentInfo {
	int id;
	char gender;
	studentInfo(int _id, char _gender) :id(_id), gender(_gender) {}
};
//如果自己重新定义了构造函数，则不能不经初始化就定义结构体变量。
struct studentInfo {
	int id;
	char gender;
	//用以不初始化就定义结构体变量
	studentInfo() {}
	//自定义构造函数
	studentInfo(int _id, char _gender) {
		id = _id;
		gender = _gender;
	}
};
//
char str[100]
cin.getline(str,100)
string str;
getline(cin,str);
//a和b都为0时退出循环
while (scanf("%d%d", &a, &b), a || b) {
    //
}
