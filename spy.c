#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stck
{
	char veriler[MAX];
}STACK;


int sifrecoz(STACK *s, char *css)
{
	int i = 0, j = 0, tmpsayi, k;
	while (s->veriler[i] != 0)
	{
		if (s->veriler[i] >= 48 && s->veriler[i] <= 57)
		{
			tmpsayi = s->veriler[i] - 48;
			if (tmpsayi > j)
			{
				return 0;
			}
			else
			{
				for (k = 0; k < tmpsayi; k++)
				{
					css[j - k - 1] = 0;
				}

				j = j - tmpsayi;
			}
		}
		else
		{
			css[j] = s->veriler[i];
			j++;
		}

		i++;
	}
	return 1;
}

int main()
{
	STACK stack1, stack2;
	char metin[MAX], temp[MAX], casus1[MAX], casus2[MAX];
	int i = 0, j = 0, tmpsayi, k;
	printf("ilk sifreli mesaji giriniz:\n");
	scanf("%s", metin);
	strcpy(stack1.veriler, metin);
	printf("ikinci sifreli mesaji giriniz:\n");
	scanf("%s", metin);
	strcpy(stack2.veriler, metin);


	if ((sifrecoz(&stack1, casus1) == 0) || (sifrecoz(&stack2, casus2) == 0))
	{
		printf("hata oldu!");
	}
	else
	{
		printf("casus1: %s\n", casus1);
		printf("casus2: %s\n", casus2);
		if(strcmp(casus1, casus2)==0){
			printf("casuslar konusabilir.");
		}
		else{
			printf("casuslar konusamaz.");
		}
	}
	return 0;
}