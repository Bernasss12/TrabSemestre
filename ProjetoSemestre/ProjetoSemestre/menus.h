#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <ctype.h>
#include <windows.h>
#include "langhelper.h"

typedef struct
{
	int num;
	char nome[10];
	char apelido[10];
}aluno;

aluno *alunos;

void init();
char menu();
void sair();

void linha(int);
void linhacon(int);
void linhacon_ID(int, int);
void linhacon_IU(int, int);
void top_D(int, int);
void bot_U(int, int);
void top(int);
void bot(int);
void printalunos(int);

//Default de Cabeçalho
auto NUM_ALUNOS = 1;
int NUM_ALUNO = 10000;
int ANO = 0000;





void init()
{
	setlocale(LC_ALL, "Portuguese_Portugal.860");
	printf("");
	top(50);
	printf("%c        GERA%c%cO ALEAT%cRIA DE UM CALEND%cRIO        %c\n",BARRA_VERTICAL, C_MAI_CED, A_MAI_TIL, O_MAI_ACE, A_MAI_AGU, BARRA_VERTICAL);
	printf("%c    Calend%crio do tipo %cCalend%crio do ADVENTO%c    %c\n",BARRA_VERTICAL, A_MIN_AGU, C_ASPAS, A_MIN_AGU, O_ASPAS, BARRA_VERTICAL);
	printf("%c                      ANO %4d                    %c\n", BARRA_VERTICAL, ANO, BARRA_VERTICAL);
	if (alunos != NULL) {
		for (int i = 1; i <= NUM_ALUNOS; i++)
		{
			printalunos(i);
		}
	}
	printf("%c                                                  %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	printf("%c                                                  %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	linhacon(50);
}

char menu()
{
	system("cls");
	init();
	char resposta;
	printf("%c                 Menu de Controlo                 %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	linhacon(50);
	printf("%c Como deseja fornecer os dados?                   %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	printf("%c", BARRA_HORIZONTAL_LE);linha(31); printf("%c", 203); linha(18);printf("%c\n", BARRA_HORIZONTAL_LD);
	printf("%c Por Teclado                   %c", BARRA_VERTICAL, BARRA_VERTICAL);printf( " Insira 'T'       %c\n", BARRA_VERTICAL);
	printf("%c Por Ficheiro                  %c", BARRA_VERTICAL, BARRA_VERTICAL);printf( " Insira 'F'       %c\n", BARRA_VERTICAL);
	printf("%c Desejo sair do programa.      %c", BARRA_VERTICAL, BARRA_VERTICAL);printf( " Insira 'S'       %c\n", BARRA_VERTICAL);
	bot_U(50, 31);
	printf("\n>");
	scanf(" %c", &resposta);
	resposta = toupper(resposta);
	return resposta;
}

void printalunos(int i)
{
		printf("Aluno %d - N%c %5d Nome: %s %s", i, 167, alunos [i-1].num, alunos [i-1].nome, alunos [i-1].apelido);
}

int STAGE = 1; //Fase de inscrição
int ALUNO = 1; //Aluno nº
int STAGE_ALUNO1 = 1; //Fase aluno1
int STAGE_ALUNO2 = 1; //Fase aluno2

int TEMP1;
int TEMP2;

void inscaluno()
{
	system("cls");
	init();
	printf("%c             Informa%c%ces de Cabe%calho             %c\n", BARRA_VERTICAL, C_MIN_CED, O_MIN_TIL, C_MIN_CED, BARRA_VERTICAL);
	linhacon(50);
	switch (STAGE) { //varias fases
	case 1: //Numero de alunos
		printf("%c Quantos alunos est%co no grupo?          [1 ou 2] %c\n", BARRA_VERTICAL, A_MIN_TIL, BARRA_VERTICAL);
		bot(50);
		printf("\n>");
		scanf_s(" %d", &NUM_ALUNOS);
		if (NUM_ALUNOS == 1 || NUM_ALUNOS == 2)
		{
			STAGE = 2;
			inscaluno();
		}
		else {
			printf(" Numero inválido!");
			STAGE = 1;
			NUM_ALUNOS = 0;
			Sleep(500);
			inscaluno();
		}
		break;
	case 2://Numero, Nome, Apelido
		alunos = (aluno *)malloc(NUM_ALUNOS * sizeof(aluno));
		if (alunos == NULL)
		{
			printf("Correu algo de errado com a aloca%c%co de mem%cria.\n", C_MIN_CED, A_MIN_TIL, O_MIN_ACE);
			Sleep(1500);
			sair();
		}
		switch (ALUNO) {
		case 1:
			alunos[1].num = 0;
			alunos[1].nome[1] = '\0';
			alunos[1].apelido[1] = '\0';
			switch (STAGE_ALUNO1) {
			case 1:
				printf("%c Qual %c o n%cmero do Aluno-1?        [10000-45000] %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, U_MIN_ACE, BARRA_VERTICAL);
				scanf_s(" %d", alunos[1].num, 5);
				if (alunos[1].num >= 10000) {
					if (alunos[1].num <= 45000){
						STAGE_ALUNO1 = 2;
						inscaluno();
					}
					else {
						printf(" Numero inválido!");
						STAGE_ALUNO1 = 1;
						Sleep(500);
						inscaluno();
					}
				}
				else {
					printf(" Numero inválido!");
					STAGE_ALUNO1 = 1;
					Sleep(500);
					inscaluno();
				}
				break;
			case 2:
				printf("%c Qual %c o nome do Aluno-1?                        %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, BARRA_VERTICAL);
				scanf_s("%s", alunos[1].nome, 10);
				STAGE_ALUNO1 = 3;
				inscaluno();
				break;
			case 3:
				printf("%c Qual %c o apelido do Aluno-1?                     %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, BARRA_VERTICAL);
				scanf_s("%s", alunos[1].apelido, 10);
				STAGE_ALUNO1 = 0;
				if (NUM_ALUNOS == 1) {
					STAGE = 3;
				}
				else if (NUM_ALUNOS == 2){
					ALUNO = 2;
				}
				inscaluno();
				break;
			}
			break;
		case 2:
			switch (STAGE_ALUNO2) {
			case 1:
				alunos[2].nome[2] = '\0';
				alunos[2].apelido[2] = '\0';
				printf("%c Qual %c o n%cmero do Aluno-2?        [10000-45000] %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, U_MIN_ACE, BARRA_VERTICAL);
				scanf_s(" %d", TEMP2, 5);
				if ((TEMP2 >= 10000) && (TEMP2 <= 45000)) {
					alunos[2].num = TEMP2;
					STAGE_ALUNO2 = 2;
					inscaluno();
				}
				else {
					printf(" Numero inválido!");
					STAGE_ALUNO2 = 1;
					Sleep(500);
					inscaluno();
				}
				break;
			case 2:
				printf("%c Qual %c o nome do Aluno-2?                        %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, U_MIN_ACE, BARRA_VERTICAL);
				scanf_s("%s", alunos[2].nome, 10);
				STAGE_ALUNO2 = 3;
				inscaluno();
				break;
			case 3:
				printf("%c Qual %c o apelido do Aluno-2?                     %c\n\n>", BARRA_VERTICAL, E_MIN_ACE, U_MIN_ACE, BARRA_VERTICAL);
				scanf_s("%s", alunos[2].apelido, 10);
				STAGE_ALUNO2 = 0;
				STAGE = 3;
				inscaluno();
				break;
			default:
				inscaluno();
				break;
			}
			break;
		}
		break;
	}
	/*
	
	else {
		alunos = (aluno *)malloc(NUM_ALUNOS * sizeof(aluno));
		if (alunos == NULL)
		{
			printf("Correu algo de errado com a aloca%c%co de mem%cria.\n", C_MIN_CED, A_MIN_TIL, O_MIN_ACE);
			Sleep(1500);
			sair();
		}

		if ( alunos[i].num)
			for (int i = 0; i < NUM_ALUNOS; i++)
			{
				alunos[i].nome[i] = '\0';
				alunos[i].apelido[i] = '\0';
				printf("Qual %c o n%cmero de aluno do Aluno-%d?\n\n>", E_MIN_ACE, U_MIN_ACE, i + 1);
				scanf_s(" %d", &alunos[i].num, 5);
				printf("Qual é o nome do Aluno-%d?\n\n>", i + 1);
				scanf_s("%s", alunos[i].nome, 10);
				printf("Qual é o apelido do Aluno-%d?\n\n>", i + 1);
				scanf_s("%s", alunos[i].apelido, 10);
			}
	}
	*/
}

void sair(){
	system("cls");
	init();
	bot(50);
	printf("A sair do programa");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	exit(1);
}

//Aparencia
void top(int i)
{
	printf("%c", CNT_SE);
	linha(i);
	printf("%c\n", CNT_SD);
}

void bot(int i)
{
	printf("%c", CNT_IE);
	linha(i);
	printf("%c\n", CNT_ID);
}

void linhacon(int i)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	for (int j = 0; j < i; j++) {
		printf("%c", BARRA_HORIZONTAL);
	}
	printf("%c\n", BARRA_HORIZONTAL_LD);
}

void linha(int i)
{
	for (int j = 0; j < i; j++) {
		printf("%c", BARRA_HORIZONTAL);
	}
}

void linhacon_IU(int i, int j)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_U);
	linha(i - j - 1);
	printf("%c\n", BARRA_HORIZONTAL_LD);
}

void linhacon_ID(int i, int j)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_D);
	linha(i - j - 1);
	printf("%c\n", BARRA_HORIZONTAL_LD);
}

void bot_U(int i, int j)
{
	printf("%c", CNT_IE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_U);
	linha(i - j - 1);
	printf("%c\n", CNT_ID);
}

void top_D(int i, int j)
{
	printf("%c", CNT_SE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_D);
	linha(i - j - 1);
	printf("%c\n", CNT_SD);
}