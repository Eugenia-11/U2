
#include <stdio.h>
#include <limits.h>



int two[32];
int pal[32];
int num;
int num2;

void two1(int num);
void two2(int num);
void pal1(int num);
void pal2(int num);
void sxt(int num);



int main() {
	printf("정수 입력:");
	scanf("%d", &num, INT_MIN, INT_MAX);

	if (num >= 0) {
		two1(num);
		printf("\n");
		pal1(num);
		printf("\n");
	    sxt(num);
		printf("\n");
		num2 = num;

	}
	else {
		two2(num);
		printf("\n");
		pal2(num);
		printf("\n");
	    sxt(num);
		printf("\n");
		num2 = num;
	
	}
	printf("\n");
	return 0;
}

void two1(int num) {
	int i = 0;
	int n = 0;
	while (num > 0) {
		two[i] = num % 2;
		num /= 2;
		i++;
	}
	printf("2진수: ");
	for (n = i; n >= 0; n--) {
		printf("%d", two[n]);
	}
}

void two2(int num) {
	int i = 0;
	num++;
	num *= -1;
	while (num > 0) {
		two[i] = num % 2;
		num /= 2;
		i++;
	}

	printf("2진수: ");
	for (i = 31; i >= 0; i--) {
		printf("%d", !(two[i]));
		
	}
	printf("");
}

void pal1(int num) {
	int ct = 0;
	int i;
	for (i = 0; i < 32; i += 3) {
		if ((num >> i) > 0) {
			ct = i / 3;
		}
	}
	
	printf("8진수: ");
	for (i = ct * 3; i >= 0; i -= 3) {
		printf("%d", (num >> i) & 7);
	}
}

void pal2(int num) {
	int ct = 0;
	int i;
	for (i = 0; i < 32; i += 3) {
		if ((num >> i) > 0) {
			ct = i / 3;
		}
	}

	printf("8진수: ");
	for (i = ct * 3; i >= 0; i -= 3) {
		printf("%d", (num >> i) & 7);
	}
}

void sxt(int num)
{
	int ct = 0;
	int i;
	int sxt;

	for (i = 0; i < 32; i += 4) {
		if ((num >> i) > 0) {
			ct = i / 4;
		}
	}

	printf("16진수: ");
	for (i = ct * 4; i >= 0; i -= 4) {
		sxt = ((num >> i) & 15);
		if (sxt < 10) {
			printf("%d", sxt);
		}

		else {
			printf("%c", sxt + 55);
		}
	}
}
