#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    int node;
    int earliest_time;
} NodeInfo;

int max(int a, int b) {
    return (a > b) ? a : b;
}

void topologicalSort(int graph[MAX_NODES][MAX_NODES], int nodes, int indegree[MAX_NODES], int earliest_time[MAX_NODES]) {
    int stack[MAX_NODES];
    int top = -1;
    int visited[MAX_NODES] = {0};

    // �ҵ����Ϊ0�Ľڵ㲢��ջ
    for (int i = 0; i < nodes; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
            visited[i] = 1;
        }
    }

    // ��������
    while (top != -1) {
        int node = stack[top--];

        // ���½ڵ�����翪ʼʱ��
        for (int i = 0; i < nodes; i++) {
            if (graph[node][i] > 0) {
                earliest_time[i] = max(earliest_time[i], earliest_time[node] + graph[node][i]);
                if (--indegree[i] == 0 && !visited[i]) {
                    stack[++top] = i;
                    visited[i] = 1;
                }
            }
        }
    }
}

int countCriticalPaths(int graph[MAX_NODES][MAX_NODES], int nodes, int earliest_time[MAX_NODES]) {
    int indegree[MAX_NODES] = {0};
    int latest_time[MAX_NODES];
    int count = 0;

    // ����ÿ���ڵ�����
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph[j][i] > 0) {
                indegree[i]++;
            }
        }
    }

    // �������򣬼���ÿ���ڵ�����翪ʼʱ��
    topologicalSort(graph, nodes, indegree, earliest_time);

    // ��ʼ����ٿ�ʼʱ��
    for (int i = 0; i < nodes; i++) {
        latest_time[i] = earliest_time[nodes - 1];
    }

    // ����ÿ���ڵ����ٿ�ʼʱ��
    for (int i = nodes - 2; i >= 0; i--) {
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] > 0) {
                latest_time[i] = max(latest_time[i], latest_time[j] - graph[i][j]);
            }
        }
    }

    // ͳ�ƹؼ�·������
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] > 0 && earliest_time[i] == latest_time[j] - graph[i][j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int nodes, edges;

    printf("������ڵ�����");
    scanf("%d", &nodes);
    printf("�����������");
    scanf("%d", &edges);

    int graph[MAX_NODES][MAX_NODES] = {0};
    int earliest_time[MAX_NODES] = {0};

    printf("������ÿ���ߵ���㡢�յ��Ȩ�أ��ÿո�ָ�����\n");
    for (int i = 0; i < edges; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        graph[start][end] = weight;
    }

    int count = countCriticalPaths(graph, nodes, earliest_time);
    printf("�ؼ�·��������%d\n", count);

    return 0;
}

