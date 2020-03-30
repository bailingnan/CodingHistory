#include<cstdio>
struct Student
{
	char Name[20];
	char ID[20];
	int Score;
}Stu[1000];
int main()
{
	int n, max=0,maxi=0, min=100,mini=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d", Stu[i].Name, Stu[i].ID, &Stu[i].Score);
		if (Stu[i].Score > max)
		{
			maxi = i;
			max = Stu[i].Score;
		}
		if (Stu[i].Score < min)
		{
			mini = i;
			min = Stu[i].Score;
		}
	}
	printf("%s %s\n", Stu[maxi].Name, Stu[maxi].ID);
	printf("%s %s", Stu[mini].Name, Stu[mini].ID);
	return 0;
}
//算法笔记
#include <cstdio>
struct Student {
    char name[15];
    char id[15];
    int score;
}temp, ans_max, ans_min;
int main() {
    int n;
    scanf("%d", &n);
    ans_max.score = -1;
    ans_min.score = 101;
    for(int i = 0; i < n; i++) {
        scanf("%s%s%d", temp.name, temp.id, &temp.score);
        if(temp.score > ans_max.score) ans_max = temp;
        if(temp.score < ans_min.score) ans_min = temp;
    }
    printf("%s %s\n", ans_max.name, ans_max.id);
    printf("%s %s\n", ans_min.name, ans_min.id);
    return 0;
}
