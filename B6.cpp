#include <stdio.h>
#include <stdlib.h>

// 定义最大节点数和边数
#define MAX_NODES 100
#define MAX_EDGES 100

// 定义边结构体
typedef struct {
    int from;
    int to;
    int duration;
} Edge;

// 定义图结构体
typedef struct {
    int numNodes;
    int numEdges;
    Edge edges[MAX_EDGES];
    int inDegree[MAX_NODES];
    int ve[MAX_NODES];
    int vl[MAX_NODES];
} Graph;

// 初始化图
void initGraph(Graph *graph) {
    graph->numNodes = 0;
    graph->numEdges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->inDegree[i] = 0;
        graph->ve[i] = 0;
        graph->vl[i] = 0;
    }
}

// 添加边
void addEdge(Graph *graph, int from, int to, int duration) {
    Edge edge = {from, to, duration};
    graph->edges[graph->numEdges] = edge;
    graph->numEdges++;
    graph->inDegree[to]++;
}

// 拓扑排序
void topologicalSort(Graph *graph) {
    int count = 0;
    int stack[MAX_NODES];
    int top = -1;
    
    // 初始化入度为0的节点入栈
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->inDegree[i] == 0) {
            stack[++top] = i;
        }
    }
    
    while (top != -1) {
        int node = stack[top--];
        count++;
        
        // 更新节点的最早开始时间ve
        for (int i = 0; i < graph->numEdges; i++) {
            if (graph->edges[i].from == node) {
                int to = graph->edges[i].to;
                int duration = graph->edges[i].duration;
                if (graph->ve[node] + duration > graph->ve[to]) {
                    graph->ve[to] = graph->ve[node] + duration;
                }
                if (--graph->inDegree[to] == 0) {
                    stack[++top] = to;
                }
            }
        }
    }
    
    if (count != graph->numNodes) {
        printf("存在环路，无法进行拓扑排序\n");
        exit(1);
    }
}

// 计算每个节点的最晚开始时间vl
void calculateVl(Graph *graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        graph->vl[i] = graph->ve[graph->numNodes - 1];
    }
    
    for (int i = graph->numNodes - 2; i >= 0; i--) {
        for (int j = 0; j < graph->numEdges; j++) {
            if (graph->edges[j].from == i) {
                int to = graph->edges[j].to;
                int duration = graph->edges[j].duration;
                if (graph->vl[to] - duration < graph->vl[i]) {
                    graph->vl[i] = graph->vl[to] - duration;
                }
            }
        }
    }
}

// 找到所有关键路径
void findCriticalPaths(Graph *graph, int node, int *path, int pathLen) {
    path[pathLen] = node;
    pathLen++;
    
    if (node == graph->numNodes - 1) {
        // 输出关键路径
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < graph->numEdges; i++) {
            if (graph->edges[i].from == node) {
                int to = graph->edges[i].to;
                int duration = graph->edges[i].duration;
                if (graph->ve[node] == graph->vl[to] - duration) {
                    findCriticalPaths(graph, to, path, pathLen);
                }
            }
        }
    }
}

int main() {
    Graph graph;
    initGraph(&graph);
    
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);
    
    graph.numNodes = numNodes;
    
    int from, to, duration;
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &from, &to, &duration);
        addEdge(&graph, from, to, duration);
    }
    
    topologicalSort(&graph);
    calculateVl(&graph);
    
    int path[MAX_NODES];
    findCriticalPaths(&graph, 0, path, 0);
    
    return 0;
}
