#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stck
{
	char data[MAX];
}STACK;


int encode(STACK *s, char *css)
{
	int i = 0, j = 0, tmpnum, k;
	while (s->data[i] != 0)
	{
		if (s->data[i] >= 48 && s->data[i] <= 57)
		{
			tmpnum = s->data[i] - 48;
			if (tmpnum > j)
			{
				return 0;
			}
			else
			{
				for (k = 0; k < tmpnum; k++)
				{
					css[j - k - 1] = 0;
				}

				j = j - tmpnum;
			}
		}
		else
		{
			css[j] = s->data[i];
			j++;
		}

		i++;
	}
	return 1;
}

int main()
{
	STACK stack1, stack2;
	char input[MAX], temp[MAX], casus1[MAX], casus2[MAX];
	int i = 0, j = 0, tmpnum, k;
	printf("type the first message:\n");
	scanf("%s", input);
	strcpy(stack1.data, input);
	printf("type the second message:\n");
	scanf("%s", input);
	strcpy(stack2.data, input);


	if ((encode(&stack1, spy1) == 0) || (encode(&stack2, spy2) == 0))
	{
		printf("error!");
	}
	else
	{
		printf("spy1: %s\n", spy1);
		printf("spy2: %s\n", spy2);
		if(strcmp(spy1, spy2)==0){
			printf("spys can communicate.");
		}
		else{
			printf("spys can not communicate.");
		}
	}
	return 0;
}
