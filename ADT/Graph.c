/*
Date:2019-08-14
Description:huihui Graph
*/

/*
对于没有权值的边，邻接矩阵中存储的是1和0
1 表示两个顶点之间存在边
0 表示两个顶点之间不存在边
*/

//邻接矩阵的存储结构定义
#define MaxVertexNum 100
typedef char VertexType;    //顶点的数据类型
typedef int EdgeType;       //边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum]; //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //边表
    int vexnum,arcnum; //当前的顶点数和弧数
}MGraph;


//Breadth first search
bool visited[Max_vex];//定义访问标记数组

void BFSTraverse(Graph G)
{
    for(i = 0;i < G.vexnum;i++)
        visited[i] = false;

    InitQueue(Q);
    for(v = 0;v < G.vexnum;v++)
    {
        if(!visited[v])
            BFS(G,v);
    }
}

void BFS(Graph G,int v)
{
    visit[v];
    visited[v] = true;
    EnQueue(Q,v);

    while(!isEmpty(Q))
    {
         DeQueue(Q,v);
         for(w = FirstNeighbor(G,v),w >= 0;w = NextNeighbor(G,v,w))
         {
            if(!visited[w])
            {
                visit[w];
                visited[w] = true;
                EnQueue(Q,w);
            }
         }
    }
}


//Depth First Search
bool visited[Max_vex];

void DFSTraverse(Graph G)
{
    for(i = 0;i < G.vexnum;i++)
        visited[i] = false;

    for(v = 0;v < G.vexnum; v++)
    {
        if(!visited[v])
            DFS(G,v);
    }
}

void DFS(Graph G,int v)
{
    visit(v);
    visited[v] = true;
    for(w = FirstNeighbor(G,v);w >= 0;w = NextNeighbor(G,v,w))
    {
        if(!visited[w])
            DFS(G,w);

    }
}


//有向图采用邻接表存储结构
//若G无回路，则输出G的顶点的一个拓扑序列，并返回OK,否则，返回ERROOR
//拓扑排序  ADT
Status TopologicalSort(Graph G)
{
    FindInDgree(G,indgree);//对个顶点求入度，存入indgree数组
    InitStack(s);

    for(i = 0;i < G.vexnum; i++)
        if(!indgree[i])
            push(s,i);

    count = 0;//对输出顶点计数

    whille(!StackEmpty(s))
    {
        pop(s,i);
        printf(i,G.vertices[i].data);
        count++；

        for(p = G.vertices[i].firstarc;p;p = p->nextarc)
        {
            k = p->adjvex;
            if(!(--indgree[k]))
                push(s,k);
        }
    }

    if(count < G.vexnum)
        return ERROR;

    else
        return OK;
}
