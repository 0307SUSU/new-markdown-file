#include <stdio.h>
int main() {
	int price = 0;

	printf("�������� ��Ԫ��:");
	scanf_s("%d", &price); /*%d���һ������*/

	int change = 100 - price;

	printf("����%dԪ\n",change);

	return 0;
	
}