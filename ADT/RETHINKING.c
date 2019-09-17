
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
