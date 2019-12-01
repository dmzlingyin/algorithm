#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct list
{
    int data[MaxSize];
    int length;
}SqList;

SqList *L = (SqList *)malloc(sizeof(SqList));
L->data[] = {1,2,3,4,5,6,7,8};
L->length = 8;
void ReverseList(SqList *L)
{
  int tmp;
  int i = 0;
  int j = L->length-1;
  while(i<=j)
    {
      tmp = L->data[i];
      L->data[i] = L->data[j];
      L->data[j] = tmp;
      j--;
      i++;
    }
}


int main()
{

    int i;
    ReverseList(L);

    for(i=0;i<L->length;i++)
        printf("%d /t",L->data[i]);
    return 0;
}
