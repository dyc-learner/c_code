#include <stdio.h>

int main() {
	int h, a, b, round = 1, n, min, pri_a = 0, sum_a = 0;
	scanf("%d%d%d", &h, &a, &b);
	int hp = h;
	while (1) {
		pri_a += a;
		sum_a = pri_a;
		h -= sum_a;
		if (h <= 0) {
			n = round;
			min = round;
			printf("n=%d\n", min);
			round = 0;
			pri_a = 0;
			sum_a = 0;
			h = hp;
			break;
		}
		round++;
		pri_a--;
	}
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			pri_a += a;
			sum_a = pri_a;
			h -= sum_a;
			round++;
			pri_a--;
		}
		while (1) {
			sum_a = b + pri_a;
			h -= sum_a;
			if (h <= 0) {
				if (round <= min) {
					min = round;
				}
				round = 0;
				pri_a = 0;
				sum_a = 0;
				h = hp;
				break;
			}
		}
		printf("%d", min);
	}
}