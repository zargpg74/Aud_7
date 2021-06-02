#include<stdio.h>
#include<locale.h>
#include<Windows.h>

#include"String.h"
#include"getUser.h"

void coice(int task_number, int argc, wchar_t* argv[])
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
	case 2:
		wmain(argc, argv);
		break;
	default:
		coice(task_number, argc, argv);
	}
}

void main(int argc, wchar_t* argv[])
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
	case 2:
		wmain(argc, argv);
		break;
	default:
		coice(task_number, argc, argv);
	}
}