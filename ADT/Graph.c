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


