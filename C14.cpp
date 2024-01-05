#include <stdio.h>

void findChange(int amount) {
    int coins[4] = {25, 10, 5, 1}; // Ӳ�����
    int coinCount[4] = {0}; // Ӳ������

    for (int i = 0; i < 4; i++) {
        if (amount >= coins[i]) {
            coinCount[i] = amount / coins[i];
            amount %= coins[i];
        }
    }

    printf("����%d�֣���Ҫ��Ӳ��������\n", amount);
    for (int i = 0; i < 4; i++) {
        if (coinCount[i] > 0) {
            printf("%d �� %d ��Ӳ��\n", coinCount[i], coins[i]);
        }
    }
}

int main() {
    int amount;

    printf("�������������λ���֣���");
    scanf("%d", &amount);

    findChange(amount);

    return 0;
}
