#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_M 100

typedef struct {
    int x, y;
} Point;

int maze[MAX_N][MAX_M];  // �Թ���ͼ
int vis[MAX_N][MAX_M];   // ��¼ÿ�����Ƿ����
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // ���������ĸ�����
int n, m;               // �Թ���ͼ������������
Point start, end;       // �����յ�

// �ж�һ�����Ƿ����Թ���
int inMaze(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// �ݹ��㷨�����·��
int dfs(int x, int y, int step) {
    if (x == end.x && y == end.y) {  // ��������յ㣬���ز���
        return step;
    }
    vis[x][y] = 1;  // ��ǵ�ǰ���ѷ���
    int minStep = -1;
    for (int i = 0; i < 4; i++) {  // ö���ĸ�����
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (inMaze(nx, ny) && maze[nx][ny] == 0 && !vis[nx][ny]) {  // �����һ����Ϸ��ҿɴ���δ���ʹ�
            int result = dfs(nx, ny, step + 1);  // �ݹ����
            if (result != -1) {  // ����ݹ�����Ч
                if (minStep == -1 || result < minStep) {
                    minStep = result;  // ������С����
                }
            }
        }
    }
    vis[x][y] = 0;  // ���ݣ��ָ���ǰ��Ϊδ����״̬
    return minStep;
}

// BFS�㷨�����·��
int bfs() {
    int step = 0;  // ��¼����
    Point queue[MAX_N * MAX_M];  // ����
    int front = 0, rear = 0;     // ��ͷ�Ͷ�β
    queue[rear++] = start;       // �����������
    vis[start.x][start.y] = 1;   // �������ѷ���
    while (front < rear) {
        int size = rear - front;  // ��ǰ��Ľڵ���
        while (size--) {
            Point cur = queue[front++];  // ȡ����ͷ�ڵ�
            if (cur.x == end.x && cur.y == end.y) {  // ��������յ㣬���ز���
                return step;
            }
            for (int i = 0; i < 4; i++) {               // ö���ĸ�����
                int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
                if (inMaze(nx, ny) && maze[nx][ny] == 0 && !vis[nx][ny]) {  // �����һ����Ϸ��ҿɴ���δ���ʹ�
                    queue[rear++] = (Point){nx, ny};                         // ����һ����������
                    vis[nx][ny] = 1;                                        // �����һ�����ѷ���
                }
            }
        }
        step++;  // ������һ
    }
    return -1;  // ����޷������յ㣬����-1
}

int main() {
    // �����Թ���ͼ
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    // ���������յ�
    scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
    start.x--;
    start.y--;
    end.x--;
    end.y--;
    // ��ʼ����������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    // ���õݹ��㷨������·��
    int resultDFS = dfs(start.x, start.y, 0);
    // ����BFS�㷨������·��
    int resultBFS = bfs();
    if (resultDFS == -1) {
        printf("�ݹ��㷨���޷������յ㣡\n");
    } else {
        printf("�ݹ��㷨�����·������Ϊ��%d\n", resultDFS);
    }
    if (resultBFS == -1) {
        printf("BFS�㷨���޷������յ㣡\n");
    } else {
        printf("BFS�㷨�����·������Ϊ��%d\n", resultBFS);
    }
    return 0;
}
