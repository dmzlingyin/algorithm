
/****************************************************************************************/
//DFS,20189-08-18

//标记数组
bool visited[MAX_VEX]

void DFSTraverse(Graph G)
{
    for(i = 0;i < G.vexnum;i++)
        visited[i] = false;
    for(v = 0;v < G.vexnum;G++)
        if(!visited[v])
            DFS(G,v);
}

void DFS(Graph G,int v)
{
    visit[v];
    visited[v] = true;
    for(w = FirstNeighbor(G,v),w >= 0;w = NextNeighbor(G,v,w))
        if(!visited[w])
            DFS(G,w);
}


/****************************************************************************************/



/****************************************************************************************/
//BFS 2019-08-18

//标记数组
bool visited[MAX_VEX];

void BFSTraverse(Graph G)
{

    InitQueue(Q);//栈的初始化
    for(i=0;i<G.vexnum;i++)
        visited[i] = false;//标记数组的初始化
    for(v=0;v<G.vexnum;v++)
        if(!visited[v])
            BFS(G,v);
}

void BFS(Graph G,int v)
{
    visit(v);
    visited[v] = true;
    EnQueue(Q,v);
    while(!QueueEmpty(Q))
    {
        DeQueue(Q.v)
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor)
        {
            if(!visited[w])
            {
                visit(w);
                visited[w] = true;
                EnQueue(Q,w);
            }
        }
    }

}
/****************************************************************************************/

/****************************************************************************************/
//Topological sorting 2019-08-18

bool topologicalSort(Graph G)
{
    int count = 0;//计数访问的 顶点
    ArcNode *e;//边表指针

    InitStack(s);//栈的初始化

    for(i=0;i<G.vexnum;i++)
        if(G->adjlist[i].in == 0)
            push(s,i);//如果入度 为0，入栈
    while(!StackEmpty(s))
    {
        pop(s,v);
        printf("%d\n",G->adjlist[v].data);
        count++;

        for(e = G->adjlist[v].firstedge;e;e=e->next)
        {
            k = e->adjvex;
            if((--G->adjlist[k].in) == 0)
                push(s,k);
        }
    }//end while

    if(count<G->vexnum)
        return false;s
    else
        return true;
}


/****************************************************************************************/

