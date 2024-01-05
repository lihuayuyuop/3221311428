#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void dfs(int node, int visited[], Graph* graph) {
    visited[node] = 1;
    Node* current = graph->adjList[node];
    while (current != NULL) {
        if (visited[current->value] == 0) {
            dfs(current->value, visited, graph);
        }
        current = current->next;
    }
}

int isStronglyConnected(Graph* graph) {
    int visited[MAX_NODES] = {0};

    // 从第一个节点开始深度优先搜索
    dfs(0, visited, graph);

    // 检查是否有未访问到的节点
    for (int i = 0; i < graph->numNodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    // 反转图的边方向
    Graph* reversedGraph = createGraph(graph->numNodes);
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            addEdge(reversedGraph, current->value, i);
            current = current->next;
        }
    }

    // 重新初始化 visited 数组
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    // 从第一个节点开始深度优先搜索反转后的图
    dfs(0, visited, reversedGraph);

    // 检查是否有未访问到的节点
    for (int i = 0; i < graph->numNodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numNodes;
    printf("请输入节点数：");
    scanf("%d", &numNodes);

    Graph* graph = createGraph(numNodes);

    printf("请输入边的信息（格式为 src -> dest，以 -1 结束）：\n");
    int src, dest;
    while (1) {
        scanf("%d", &src);
        if (src == -1) {
            break;
        }
        scanf(" -> %d", &dest);
        addEdge(graph, src, dest);
    }

    int result = isStronglyConnected(graph);
    if (result) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
