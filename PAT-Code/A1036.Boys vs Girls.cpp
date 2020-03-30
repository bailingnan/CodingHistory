#include<cstdio>
struct Student {
	char name[20];
	char sex;
	char ID[20];
	int grade;
}temp,male,female;
int main()
{
	female.grade = -1;
	male.grade = 101;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %c %s %d", temp.name, &temp.sex, temp.ID, &temp.grade);
		if (temp.sex == 'M')
		{
			if (temp.grade < male.grade)
				male = temp;
		}
		else {
			if (temp.grade > female.grade)
				female = temp;
		}
	}
	if (male.grade != 101 && female.grade != -1)
	{
		printf("%s %s\n", female.name, female.ID);
		printf("%s %s\n", male.name, male.ID);
		printf("%d\n", female.grade - male.grade);
	}
	else 
	{
		if (female.grade == -1)
			printf("Absent\n");
		else
			printf("%s %s\n", female.name, female.ID);
		if(male.grade==101)
			printf("Absent\n");
		else
			printf("%s %s\n", male.name, male.ID);
		printf("NA\n");
	}
	return 0;
}
//算法笔记
#include <cstdio>
struct person {
    char name[15];
    char id[15];
    int score;
}M, F, temp;
void init() {
    M.score = 101;
    F.score = -1;
}
int main() {
    init();
    int n;
    char gender;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %c %s %d", temp.name, &gender, temp.id, &temp.score);
        if(gender == 'M' && temp.score < M.score) {
            M = temp;
        } else if(gender == 'F' && temp.score > F.score) {
            F = temp;
        }
    }
    if(F.score == -1) printf("Absent\n");
    else printf("%s %s\n", F.name, F.id);
    if(M.score == 101) printf("Absent\n");
    else printf("%s %s\n", M.name, M.id);
    if(F.score == -1 || M.score == 101) printf("NA\n");
    else printf("%d\n", F.score - M.score);
    return 0;
}
