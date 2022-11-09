#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROW1 4
#define COL1 6



void main()
{
	setlocale(0, "Russian");
	int row, col;
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= row; col++)
			printf("%5d", col * row);
		printf("\n");
	}

	puts("\v\v");

	int row1, col1;
	for (row1 = 1; row1 <= ROW1; ++row1)
	{
		for (col1 = 1; col1 <= COL1; col1++)
			printf(" 5");
		printf("\n");
	}

	int count = 0, num;
	while (1) {
		char a;
		puts("Введите ваше число:\n");
		scanf_s("%d", &num);
		while (num != 0)
		{
			if (num % 10 == 3) {
				num = num / 10;
				count++;
			}
			else {
				num = num / 10;
			}
		}
		printf("Количество троек в вашем числе: %d\n", count);
		count = 0;
		printf("Продолжить ? (Да - y, нет - n)\n");
		scanf("%c", &a);
		if ((a = getchar()) == 'n') break;
	}

	//homework

	char s;
	int a;
	float u;
	puts("Введите символ");
	scanf("%c", &s);
	puts("Введите значение стороны квадрата");
	scanf("%d", &a);
	puts("Введите значение угла поворота (будет округлено в сторону 45 градусов)");
	scanf("%f", &u);
	puts("\n");

	u = fabs(u);   // берём модуль, потому что знак при таком подходе роли не играет
	while (u > 90)
	{
		u -= 90;  // получаем угол со значением в отрезке [0, 90]
	}

	// оставляем при [0; 22.5) (67.5; 90]
	// поворачиваем (= округляем угол до 45) при [22.5; 67.5] 


	if (22.5 <= u && u <= 67.5)
	{
		// вывели первую строку ромба
		for (int i = 1; i <= a - 1; i++) printf("%3c", ' ');
		printf("%3c\n", s);

		// первая половина ромба
		int count_c_column = 1;
		int count_l_column = a - 2;
		for (int row = 2; row <= a; row++)
		{

			for (int empty_col = count_l_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			for (int empty_col = count_c_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			count_c_column += 2;
			count_l_column--;
			printf("\n");
		}

		// вторая половина ромба
		count_l_column = 1;
		count_c_column -= 4;
		for (int row = 2; row < a; row++)
		{

			for (int empty_col = count_l_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			for (int empty_col = count_c_column; empty_col > 0; empty_col--) printf("%3c", ' ');
			printf("%3c", s);
			count_c_column -= 2;
			count_l_column++;
			printf("\n");
		}

		// вывели последнюю строку ромба
		for (int i = 1; i <= a - 1; i++) printf("%3c", ' ');
		printf("%3c\n", s);
	}
	else
	{
		// первая строка квадрата
		for (int i = 1; i <= a; i++) printf("%3c", s);
		printf("\n");

		// середина квадрата
		for (int row = 2; row <= a - 1; row++)
		{
			printf("%3c", s);
			for (int j = 1; j <= a - 2; j++) printf("%3c", ' ');
			printf("%3c\n", s);
		}

		// последняя строка квадрата
		for (int i = 1; i <= a; i++) printf("%3c", s);
	}
}