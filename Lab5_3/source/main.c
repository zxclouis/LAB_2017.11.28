#include <stdio.h>
#include<stdlib.h>
#define issues 5
#define ratings 10
void recordresponse(int i, int response);
void highestrating();
void lowestrating();
float averagerating(int issue);
void displayresults();
int response[issues][ratings];
const char *topic[issues] = { "Global warning","The economy","War","Health care","education" };
int main(void)
{
	int response;
	int i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10\n1 = least important, 10 = most inportant\n");
		for (i = 0; i < issues;i++)
		{
			do
			{
				printf("%s", topic[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}
		printf("Enter 1 to stop.\nEnter 0 to rate the issues again.    ");
		scanf_s("%d", &response);
	} while (response != 1);
	displayresults();
	system("pause");
	return 0;
}
void recordresponse(int issue, int rating)
{
	response[issue][rating - 1]++;
}
void highestrating(void)
{
	int highrating = 0;
	int hightopic = 0;
	int i;
	int j;
	for (i = 0; i < issues; i++)
	{
		int topicrating = 0;
		for (j = 0; j < ratings; j++)
		{
			topicrating += response[i][j] * (j + 1);
		}
		if (highrating < topicrating)
		{
			highrating = topicrating;
			hightopic = i;
		}
	}
	printf("\nThe highest rated topic was ");
	printf("%s", topic[hightopic]);
	printf(" with a total rating of %d\n", highrating);
}
void lowestrating(void)
{
	int lowrating;
	int lowtopic = 0;
	int i;
	int j;
	for (i = 0; i < issues; i++)
	{
		int topicrating = 0;
		for (j = 0; j < ratings; j++)
		{
			topicrating += response[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowrating = topicrating;
		}
		if (lowrating > topicrating)
		{
			lowrating = topicrating;
			lowtopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topic[lowtopic]);
	printf(" with a total rating of %d\n", lowrating);
}
float averagerating(int issue)
{
	float total = 0;
	int counter = 0;
	int j;
	for (j = 0; j < ratings; j++)
	{
		if(response[issue][j]!=0)
		{
			total += response[issue][j]*(j + 1);
			counter += response[issue][j];
		}
	}
	return total / counter;
}
void displayresults()
{
	int i;
	int j;
	printf("%20s", "Topic");
	for (i = 1; i <= ratings; i++)
	{
		printf("%4d", i);
	}
	printf("%20s", "Average rating");
	for (i = 0; i < issues; i++)
	{
		printf("%20s", topic[i]);
		for (j = 0; j < ratings; j++)
		{
			printf("%4d", response[i][j]);
		}
		printf("%20.2f", averagerating(i));
	}
	highestrating();
	lowestrating();
}