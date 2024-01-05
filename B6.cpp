#include <stdio.h>
#include <stdlib.h>

// �������ڵ����ͱ���
#define MAX_NODES 100
#define MAX_EDGES 100

// ����߽ṹ��
typedef struct {
    int from;
    int to;
    int duration;
} Edge;

// ����ͼ�ṹ��
typedef struct {
    int numNodes;
    int numEdges;
    Edge edges[MAX_EDGES];
    int inDegree[MAX_NODES];
    int ve[MAX_NODES];
    int vl[MAX_NODES];
} Graph;

// ��ʼ��ͼ
void initGraph(Graph *graph) {
    graph->numNodes = 0;
    graph->numEdges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->inDegree[i] = 0;
        graph->ve[i] = 0;
        graph->vl[i] = 0;
    }
}

// ��ӱ�
void addEdge(Graph *graph, int from, int to, int duration) {
    Edge edge = {from, to, duration};
    graph->edges[graph->numEdges] = edge;
    graph->numEdges++;
    graph->inDegree[to]++;
}

// ��������
void topologicalSort(Graph *graph) {
    int count = 0;
    int stack[MAX_NODES];
    int top = -1;
    
    // ��ʼ�����Ϊ0�Ľڵ���ջ
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->inDegree[i] == 0) {
            stack[++top] = i;
        }
    }
    
    while (top != -1) {
        int node = stack[top--];
        count++;
        
        // ���½ڵ�����翪ʼʱ��ve
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
        printf("���ڻ�·���޷�������������\n");
        exit(1);
    }
}

// ����ÿ���ڵ������ʼʱ��vl
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

// �ҵ����йؼ�·��
void findCriticalPaths(Graph *graph, int node, int *path, int pathLen) {
    path[pathLen] = node;
    pathLen++;
    
    if (node == graph->numNodes - 1) {
        // ����ؼ�·��
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
