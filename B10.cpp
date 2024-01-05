#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// ���������������
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int start, int end, int path[], int pathLength) {
    visited[start] = true;
    path[pathLength++] = start;

    if (start == end) {
        // ��ӡ·���ͳ���
        printf("�Ӷ��� %d ������ %d ��·����", start, end);
        for (int i = 0; i < pathLength; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        printf("·�����ȣ�%d\n", pathLength - 1);
    } else {
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[start][i] == 1 && !visited[i]) {
                dfs(graph, visited, i, end, path, pathLength);
            }
        }
    }

    visited[start] = false;
}

// ����ͼ�����ж����֮���·���ͳ���
void findAllPaths(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int visited[MAX_VERTICES] = {false};
    int path[MAX_VERTICES];
    int pathLength = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (i != j) {
                printf("�Ӷ��� %d ������ %d��\n", i, j);
                dfs(graph, visited, i, j, path, pathLength);
                printf("\n");
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];

    // �����ڽӾ���
    printf("�������ڽӾ���\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    findAllPaths(graph);

    return 0;
}
