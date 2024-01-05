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

    // �ӵ�һ���ڵ㿪ʼ�����������
    dfs(0, visited, graph);

    // ����Ƿ���δ���ʵ��Ľڵ�
    for (int i = 0; i < graph->numNodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    // ��תͼ�ı߷���
    Graph* reversedGraph = createGraph(graph->numNodes);
    for (int i = 0; i < graph->numNodes; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            addEdge(reversedGraph, current->value, i);
            current = current->next;
        }
    }

    // ���³�ʼ�� visited ����
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = 0;
    }

    // �ӵ�һ���ڵ㿪ʼ�������������ת���ͼ
    dfs(0, visited, reversedGraph);

    // ����Ƿ���δ���ʵ��Ľڵ�
    for (int i = 0; i < graph->numNodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numNodes;
    printf("������ڵ�����");
    scanf("%d", &numNodes);

    Graph* graph = createGraph(numNodes);

    printf("������ߵ���Ϣ����ʽΪ src -> dest���� -1 ��������\n");
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
