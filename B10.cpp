#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// 深度优先搜索函数
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int start, int end, int path[], int pathLength) {
    visited[start] = true;
    path[pathLength++] = start;

    if (start == end) {
        // 打印路径和长度
        printf("从顶点 %d 到顶点 %d 的路径：", start, end);
        for (int i = 0; i < pathLength; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        printf("路径长度：%d\n", pathLength - 1);
    } else {
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[start][i] == 1 && !visited[i]) {
                dfs(graph, visited, i, end, path, pathLength);
            }
        }
    }

    visited[start] = false;
}

// 查找图中所有顶点对之间的路径和长度
void findAllPaths(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int visited[MAX_VERTICES] = {false};
    int path[MAX_VERTICES];
    int pathLength = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (i != j) {
                printf("从顶点 %d 到顶点 %d：\n", i, j);
                dfs(graph, visited, i, j, path, pathLength);
                printf("\n");
            }
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];

    // 输入邻接矩阵
    printf("请输入邻接矩阵：\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    findAllPaths(graph);

    return 0;
}
