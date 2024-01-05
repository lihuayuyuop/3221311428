#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 100

typedef struct {
    int x, y;
} Point;

int maze[MAX_N][MAX_M];  // 迷宫地图
int vis[MAX_N][MAX_M];   // 记录每个点是否访问
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // 上下左右四个方向
int n, m;               // 迷宫地图的行数和列数
Point start, end;       // 起点和终点

// 判断一个点是否在迷宫内
int inMaze(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 递归算法求最短路径
int dfs(int x, int y, int step) {
    if (x == end.x && y == end.y) {  // 如果到达终点，返回步数
        return step;
    }
    vis[x][y] = 1;  // 标记当前点已访问
    int minStep = -1;
    for (int i = 0; i < 4; i++) {  // 枚举四个方向
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (inMaze(nx, ny) && maze[nx][ny] == 0 && !vis[nx][ny]) {  // 如果下一个点合法且可达且未访问过
            int result = dfs(nx, ny, step + 1);  // 递归调用
            if (result != -1) {  // 如果递归结果有效
                if (minStep == -1 || result < minStep) {
                    minStep = result;  // 更新最小步数
                }
            }
        }
    }
    vis[x][y] = 0;  // 回溯，恢复当前点为未访问状态
    return minStep;
}

// BFS算法求最短路径
int bfs() {
    int step = 0;  // 记录步数
    Point queue[MAX_N * MAX_M];  // 队列
    int front = 0, rear = 0;     // 队头和队尾
    queue[rear++] = start;       // 将起点加入队列
    vis[start.x][start.y] = 1;   // 标记起点已访问
    while (front < rear) {
        int size = rear - front;  // 当前层的节点数
        while (size--) {
            Point cur = queue[front++];  // 取出队头节点
            if (cur.x == end.x && cur.y == end.y) {  // 如果到达终点，返回步数
                return step;
            }
            for (int i = 0; i < 4; i++) {               // 枚举四个方向
                int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
                if (inMaze(nx, ny) && maze[nx][ny] == 0 && !vis[nx][ny]) {  // 如果下一个点合法且可达且未访问过
                    queue[rear++] = (Point){nx, ny};                         // 将下一个点加入队列
                    vis[nx][ny] = 1;                                        // 标记下一个点已访问
                }
            }
        }
        step++;  // 层数加一
    }
    return -1;  // 如果无法到达终点，返回-1
}

int main() {
    // 读入迷宫地图
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    // 读入起点和终点
    scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
    start.x--;
    start.y--;
    end.x--;
    end.y--;
    // 初始化访问数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    // 调用递归算法求解最短路径
    int resultDFS = dfs(start.x, start.y, 0);
    // 调用BFS算法求解最短路径
    int resultBFS = bfs();
    if (resultDFS == -1) {
        printf("递归算法：无法到达终点！\n");
    } else {
        printf("递归算法：最短路径步数为：%d\n", resultDFS);
    }
    if (resultBFS == -1) {
        printf("BFS算法：无法到达终点！\n");
    } else {
        printf("BFS算法：最短路径步数为：%d\n", resultBFS);
    }
    return 0;
}
