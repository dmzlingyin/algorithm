#include<stdio.h>
#include<string.h>

char T[] = "lingyin";
char P[] = "yin";

int pattern()
{
	int i = 0,j = 0;
	int k = i;
	int len_t = strlen(T);
	int len_p = strlen(P);
	while(i < len_t && j < len_p)
	{
		if(T[i] == P[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = ++k;
		}
	}

	if(j>=len_p)
	{
		printf("∆•≈‰≥…π¶!\n");
		printf("Œª÷√£∫%d\n",k);
		return k;
	}
	
	else
		return 0;

}

void main()
{
	pattern();

}