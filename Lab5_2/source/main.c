#include <stdio.h>
#include <stdlib.h>
#define students 3
#define exams 4
void minimun(int grade[][exams], int pupils, int tests);
void maximun(int grade[][exams], int pupils, int tests);
void average(int grade[][exams], int pupils, int tests);
void printarray(int grade[][exams], int pupils, int tests);
void printmenu(void);
int main(void)
{
	void(*processgrades[4])(int[][exams], int, int) = { printarray,minimun,maximun,average };
	int choice = 0;
	int studentgrades[students][exams] = { {77,68,86,73},
										   {96,87,89,78},
										   {70,90,86,81} };
	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);
		if (choice != 4)
		{
			(*processgrades[choice])(studentgrades, students, exams);
		}
		else
		{
			printf("Program ended.\n");
		}
	}
	system("pause");
	return 0;
}
void minimun(int grade[][exams], int pupils, int tests)
{
	int i; int j;
	int lowgrade = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grade[i][j] < lowgrade)
			{
				lowgrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowgrade);
}
void maximun(int grade[][exams], int pupils, int tests)
{
	int i; int j;
	int highgrade = 0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grade[i][j] > highgrade)
			{
				highgrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highgrade);
}
void average(int grade[][exams], int pupils, int tests)
{
	int i;
	int j;
	int total;
	printf("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += grade[i][j];
		}
		printf("\tThe average for student %d is %.1f\n", i + 1, (double)total / tests);
	}

}
void printarray(int grade[][exams], int pupils, int tests)
{
	int i;
	int j;
	printf("\n\t                [0]	[1]	[2]	[3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentgrades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf(" %-7d", grade[i][j]);
		}
	}
	printf("\n");
}
void printmenu(void)
{
	printf("\n\tEnter the choice: \n\t 0 print the array of grades\n\t 1 find the minimun grade"
		"\n\t 2 find the maximun grade\n\t 3 print the average on all tests for each studnet\n\t"
		" 4 end program\n\t Which one?");
}