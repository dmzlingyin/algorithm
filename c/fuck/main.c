#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct List
{
    int data[50];
    int length;
}SqList;

/*SqList L;

void reverse(SqList L)
{
    int tmp;
    int i=0;
    int j=7;
    while(i<=j)
    {
        tmp = L.data[i];
        L.data[i]=L.data[j];
        L.data[j]=tmp;
        i++;
        j--;
    }
    for(i=0;i<8;i++)
        printf("%d",L.data[i]);

}
int main()
{

    int i;
    for(i=0;i<8;i++)
        L.data[i]=i;

    L.length=8;
    reverse(L);
    printf("\n");
    for(i=0;i<8;i++)
        printf("%d",L.data[i]);
    return 0;
}
*/

int i=9;
int j=0;


int main()
{
    int i;
    SqList *p = (SqList *)malloc(sizeof(SqList));
    for(i=0;i<8;i++)
        p->data[i] = i+1;
    p->length = 8;
    return 0;
}
