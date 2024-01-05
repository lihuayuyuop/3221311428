#include <stdio.h>

void findChange(int amount) {
    int coins[4] = {25, 10, 5, 1}; // 硬币面额
    int coinCount[4] = {0}; // 硬币数量

    for (int i = 0; i < 4; i++) {
        if (amount >= coins[i]) {
            coinCount[i] = amount / coins[i];
            amount %= coins[i];
        }
    }

    printf("找零%d分，需要的硬币数量：\n", amount);
    for (int i = 0; i < 4; i++) {
        if (coinCount[i] > 0) {
            printf("%d 个 %d 分硬币\n", coinCount[i], coins[i]);
        }
    }
}

int main() {
    int amount;

    printf("请输入找零金额（单位：分）：");
    scanf("%d", &amount);

    findChange(amount);

    return 0;
}
