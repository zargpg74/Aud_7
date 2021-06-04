#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<malloc.h>

#include"String.h"

void ErrorOpen(errno_t err) {
	if (err != 0) {
		char error_str[100];
		strerror_s(error_str, sizeof(error_str), err);
		printf("%s\n", error_str);
		exit(err);
	}
}


void ErrorFile(FILE* input) {
	char pr;
	pr = getc(input);
	if (pr == EOF) {
		system("cls");
		printf("Файл пуст");
		exit(4);
	}
}



char* longest_substring_search(char* string, int len_string, char* max_substring)
{
	int max_len_substring = 0;

	for (int i = 0; i < (len_string - 1); i++)
	{
		int index_element = i + 1;
		int len_substring = 0;
		char* current_substring = NULL;

		current_substring = (char*)realloc(current_substring, (len_substring + 1) * sizeof(char));
		current_substring[len_substring] = string[i];
		len_substring++;

		while (string[i] != string[index_element])
		{
			int number_of_coincidences = 0;
			for (int j = i; j <= index_element; j++)
				if (string[index_element] != string[j])
					number_of_coincidences++;

			if (number_of_coincidences == (index_element - i))
			{
				current_substring = (char*)realloc(current_substring, (len_substring + 1) * sizeof(char));
				current_substring[len_substring] = string[index_element];
				len_substring++;
			}

			index_element++;
			if (index_element >= len_string)
			{
				index_element--;
				break;
			}
		}


		if (len_substring > max_len_substring)
		{
			max_len_substring = len_substring;
			max_substring = NULL;
			max_substring = (char*)malloc(max_len_substring * sizeof(char));
			for (int i = 0; i < max_len_substring; i++)
			{
				max_substring[i] = current_substring[i];
			}
		}
	}

	max_substring = (char*)realloc(max_substring, (max_len_substring + 1) * sizeof(char));
	for (int i = max_len_substring; i >= 0; i--)
	{
		max_substring[i] = max_substring[i - 1];
	}
	max_substring[0] = max_len_substring;

	return(max_substring);
}



void substring_without_repetitions()
{
	system("cls");
	setlocale(0, "ru");

	FILE* input, * output;
	errno_t err = fopen_s(&input, "input.txt", "r");
	ErrorOpen(err);
	ErrorFile(input);
	rewind(input);

	err = fopen_s(&output, "output.txt", "w");
	ErrorOpen(err);

	char symbol = fgetc(input);
	char* str_in_file = NULL;
	int len_str_in_file = 0;
	while (symbol != EOF)
	{
		str_in_file = (char*)realloc(str_in_file, (len_str_in_file + 1) * sizeof(char));
		str_in_file[len_str_in_file] = symbol;
		len_str_in_file++;

		symbol = fgetc(input);
	}

	printf("Ваша строка из файла input.txt: ");

	for (int i = 0; i < len_str_in_file; i++)
	{
		printf("%c", str_in_file[i]);
	}

	printf("\n");

	char* substring = NULL;
	substring = longest_substring_search(str_in_file, len_str_in_file, substring);

	int len_substring = substring[0];
	for (int i = 1; i <= len_substring; i++)
	{
		printf("%c", substring[i]);
	}

	for (int i = 1; i <= len_substring; i++)
	{
		fprintf(output, "%c", substring[i]);
	}

	rewind(output);
}