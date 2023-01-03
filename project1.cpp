#include <stdio.h>

void print_two(int input)
{
	int i = 0;

	for (i = 31; i >= 0; i--) {
		printf("%d", (input >> i) & 1);
	}
}

void print_eht(int input)
{
	int count = 0;
	int i;

	for (i = 0; i < 32; i += 3) {
		if ((input >> i) > 0) {
			count = i / 3;
		}
	}

	for (i = count * 3; i >= 0; i -= 3) {
		printf("%d", (input>> i) & 7);
	}
}

void print_sxt(int input)
{
	int ct = 0;
	int i;
	int sxt;

	for (i = 0; i < 32; i += 4) {
		if ((input >> i) > 0) {
			ct = i / 4;
		}
	}

	for (i = ct * 4; i >= 0; i -= 4) {
		sxt = ((input >> i) & 15);
		if (sxt < 10) {
			printf("%d", sxt);
		}
		else {
			printf("%c", sxt + 55);
		}
	}
}

int main(int argc, char **argv)
{
	int i;

	while (1) {
		printf("정수 >> ");
		scanf("%d", &i);
		if (i < 0) {
			continue;
		}
		else if (i > 2147483648 && i < -2147483648) {
			break;
		}
		printf("2 진수: ");
		print_two(i);
		printf("\n");
		printf("8 진수: ");
		print_eht(i);
		printf("\n");
		printf("16진수: ");
		print_sxt(i);
		printf("\n");
	}
	return 0;
}