#include<stdio.h>


int fun(int val)
{
	if(val <= 1)
		return val;
	return val * fun(val - 1);
}
void main()
{
	int result = fun(5);
	printf("½×³ËÎª:%d\n",result);
}