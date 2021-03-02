#include<stdio.h>
#include<stdlib.h>
int main() {
	int x, y, z;
	scanf_s("%d,%d,%d", &x, &y, &z);
	if (x <= 0 || y <= 0 || z <= 0) {
		printf("error\n");
		return -1;
	}
	else {
		if (x + y > z && x + z > y && y + z > x) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	system("pause");
	return 0;
}