#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <clocale>


typedef struct aluno
{
	
};

char menu();

void main()
{	
	setlocale(LC_ALL, "pt-PT");
	auto opt1 = menu();
	int opt1_1 = 0;
	while (opt1_1 == 0)
		if (opt1 == 'T' || opt1 == 't')
		{
			printf("T.\n\n");
			opt1_1 = 1;
		}
		else if (opt1 == 'F' || opt1 == 'f')
		{
			printf("Nao T, F.\n\n");
			opt1_1 = 1;
		}
		else if (opt1 == 'S' || opt1 == 's')
		{
			printf("A sair.\n\n");
			opt1_1 = 1;
			exit(1);
		}
		else
		{
			opt1_1 = 0;
		}

	system("pause");
}

char menu()
{	
	system("cls");
	char resposta;
	printf("==============\n");
	printf("Menu Principal %c\n", 132);
	printf("==================================================\n");
	printf("Como deseja fornecer os dados?\n");
	printf("==================================================\n");
	printf("Por Teclado                   |");
	printf("Insira 'T'\n");
	printf("Por Ficheiro                  |");
	printf("Insira 'F'\n");
	printf("Desejo sair do programa.      |");
	printf("Insira 'S'\n");
	scanf(" %c", &resposta);
	return resposta;
}