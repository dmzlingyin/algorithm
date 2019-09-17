#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 8

typedef struct GNode
{
    int vertex[MAX_VERTEX];//顶点表
    int edge[MAX_VERTEX][MAX_VERTEX];
    int vexnum,arcnum;
}GNode,*Graph;

//图的初始化
void InitGraph(Graph G)
{
    int i,j;
    for(i = 0;i < MAX_VERTEX;i++)
    {
        for(j = 0;j < MAX_VERTEX;j++)
            G->edge[i][j] = 0;
    }

    G->vexnum = 0;
    G->arcnum = 0;

}

void CreateGraph(Graph G)
{
    int i;
    int v1,v2;
    for(i = 0;i < 8;i++)
    {
        G->vertex[i] = i;
        G->vexnum++;
    }

    printf("请输入边,格式例如:0-1,以#-#结束\n");
    getchar();
    scanf("%d-%d\n",&v1,&v2);

    while((v1 != 0) && (v2 != 0))
    {
        printf("%d,%d\n",v1,v2);
        G->edge[v1][v2] = 1;
        G->edge[v2][v1] = 1;
        getchar();
        scanf("%d-%d\n",&v1,&v2);
    }



}

int main()
{
    int i,j;
    Graph G = (Graph)malloc(sizeof(GNode));
    if(!G)
        return 0;

    //初始化
    InitGraph(G);
    CreateGraph(G);
    for(i = 0;i < MAX_VERTEX;i++)
    {
        for(j = 0;j < MAX_VERTEX;j++)
            printf("%d\t",G->edge[i][j]);

        printf("\n");
        printf("\n");
    }

    return 0;
}
