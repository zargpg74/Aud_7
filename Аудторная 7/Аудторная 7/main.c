#include<stdio.h>
#include<locale.h>
#include<Windows.h>

#include"String.h"

void coice(int task_number)
{
	system("cls");
	printf("Aud 7\n");
	printf("Error\nТакого задания не существует, попробуйте еще раз: ");
	scanf_s("%d", &task_number);
	
	switch (task_number)
	{
	case 1:
		substring_without_repetitions();
		break;
	default:
		coice(task_number);
	}
}

void main()
{
	system("cls");
	setlocale(0, "ru");
	printf("Aud 7\n");

	printf("Введите номер задания: ");
	int task_number;
	scanf_s("%d", &task_number);

	switch (task_number)
	{
	case 1:
		substring_without_repetitions();
		break;
	default:
		coice(task_number);
	}
}