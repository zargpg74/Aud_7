#include<stdio.h>
#include<locale.h>
#include<Windows.h>

#include"String.h"

void main()
{
	system("cls");
	setlocale(0, "ru");

	printf("������� ����� �������: ");
	int task_number;
	scanf_s("%d", &task_number);

	switch (task_number)
	{
	case 1:
		substring_without_repetitions();
		break;
	default:
		system("cls");
		printf("������ ������� �� ����������");
		exit(task_number);
	}
}