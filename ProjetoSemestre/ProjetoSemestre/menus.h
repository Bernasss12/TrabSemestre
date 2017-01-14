#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <ctype.h>
#include <windows.h>
#include "langhelper.h"
#include "calendario.h"


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

void callInfo();
int numAlunos();

//Default de Cabeçalho
int NUM_ALUNOS = NULL;
int NUM_ALUNO = 10000;
int ANO = 0;





inline void init()
{
	int ESP;
	int ESP_ESQ;
	int ESP_DIR;

	setlocale(LC_ALL, "Portuguese_Portugal.860");
	printf("");
	top(50);
	printf("%c        GERA%c%cO ALEAT%cRIA DE UM CALEND%cRIO        %c\n", BARRA_VERTICAL, C_MAI_CED, A_MAI_TIL, O_MAI_ACE, A_MAI_AGU, BARRA_VERTICAL);
	printf("%c    Calend%crio do tipo %cCalend%crio do ADVENTO%c    %c\n", BARRA_VERTICAL, A_MIN_AGU, C_ASPAS, A_MIN_AGU, O_ASPAS, BARRA_VERTICAL);
	if (ANO != 0) {
		printf("%c                      ANO %4d                    %c\n", BARRA_VERTICAL, ANO, BARRA_VERTICAL);
	}

	if (NUM_ALUNOS != NULL){
		for (int i = 0; i < NUM_ALUNOS; i++)
		{
			
			ESP = floor(((26 - strlen(alunos[i].nome)) - strlen(alunos[i].apelido))/2);
			if (ESP % 2 == 0) {
				ESP_DIR = (int)floor(ESP) + 1;
				ESP_ESQ = (int)floor(ESP);
			} else
			{
				ESP_DIR = (int)floor(ESP);
				ESP_ESQ = (int)floor(ESP);
			}

			ico(BARRA_VERTICAL);
			space(ESP_ESQ);
			printf("Aluno N%c %5d - ", 167, alunos[i].num);
			printf("Nome: ");
			printf("%s ", alunos[i].nome);
			printf("%s", alunos[i].apelido);
			space(ESP_DIR);
			ico(BARRA_VERTICAL);
			//printf("ESP:%d ESPE:%d ESPD:%d NOME:%d APELIDO:%d", ESP, ESP_ESQ, ESP_DIR, strlen(alunos[i].nome), strlen(alunos[i].apelido)); //Debug
			printf("\n");
		}
	}
	
	linhacon(50);
}
inline char menu()
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
	
	do {
		scanf(" %c", &resposta);
		resposta = toupper(resposta);
		if(resposta == 'T' || resposta == 'S' || resposta == 'F'){
			return resposta;
		}
		printf("\033[A \r>(Resposta inv%clida!)", A_MIN_AGU);
		Sleep(500);
		printf("\33[2K\r>");
	} while (!(resposta == 'T' || resposta == 'S' || resposta == 'F'));

	return 0;
}

int TEMP1;
int TEMP2;

inline void inscaluno()
{
	system("cls");
	init();
	printf("%c             Informa%c%ces de Cabe%calho             %c\n", BARRA_VERTICAL, C_MIN_CED, O_MIN_TIL, C_MIN_CED, BARRA_VERTICAL);
	linhacon(50);
	if (NUM_ALUNOS == NULL) {
		numAlunos();
	}

	if (alunos == NULL) {//Alocação dinâmica da memoria para os alunos.
		alunos = (aluno*)malloc(NUM_ALUNOS * sizeof(aluno));
	}

	for (int i = 0; i < NUM_ALUNOS; i++)
	{
		alunos[i].nome[i] = '\0';
		alunos[i].apelido[i] = '\0';

		printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
		printf("%c Qual %c o n%cmero do aluno?          [10000-45000] %c\n", BARRA_VERTICAL, E_MIN_ACE, U_MIN_ACE, BARRA_VERTICAL);
		bot(50);
		printf("\nAluno %d >", i + 1);
		alunos[i].num = 0;
		while (!(alunos[i].num >= 10000 && alunos[i].num <= 45000)) {
			scanf(" %d", &alunos[i].num);
			if ((alunos[i].num >= 10000 && alunos[i].num <= 45000)) {
				break;
			}
			printf("\033[A \r(Numero %d inv%clido!)", alunos[i].num, A_MIN_AGU);
			Sleep(500);
			printf("\33[2K\rAluno %d>", i+1);
		}
		
		printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
		printf("%c Qual %c o nome do aluno?                          %c\n", BARRA_VERTICAL, E_MIN_ACE, BARRA_VERTICAL);
		bot(50);
		printf("\nAluno %d>", i + 1);
		scanf("%s", &alunos[i].nome);

		printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
		printf("%c Qual %c o apelido do aluno?                       %c\n", BARRA_VERTICAL, E_MIN_ACE, BARRA_VERTICAL);
		bot(50);
		printf("\nAluno %d>", i + 1);
		scanf("%s", &alunos[i].apelido);

	}
	callInfo();
}
inline void callInfo(){
	system("cls");
	init();
	printf("%c Qual o ano do calend%crio que pretende gerar?     %c\n", BARRA_VERTICAL, A_MIN_AGU, BARRA_VERTICAL);
	bot(50);
	printf("\n>");
	scanf("%d", &ANO);
	fflush(stdin);
}
inline int numAlunos(){
	system("cls");
	init();
	printf("%c Quantos alunos est%co no grupo?          [1 ou 2] %c\n", BARRA_VERTICAL, A_MIN_TIL, BARRA_VERTICAL);
	bot(50);
	printf("\n>");
	while (NUM_ALUNOS != 1 && NUM_ALUNOS != 2) {
		scanf_s(" %d", &NUM_ALUNOS);
		if (NUM_ALUNOS == 1 || NUM_ALUNOS == 2) {
			break;
		}
		printf("\033[A \r(Numero inv%clido!)", A_MIN_AGU);
		Sleep(500);
		printf("\33[2K\r>");
	}
	return NUM_ALUNOS;
}
inline void sair(){
	int COUNTDOWN = 3;

	if (alunos != NULL) {
		free(alunos);
	}
	
	freeCal();

	system("cls");
	init();
	printf("                                        \033[A\33[2k\r");
	bot(50);
	while (COUNTDOWN != 0) {
		printf("\33[k\rA sair do programa em %d segundos...", COUNTDOWN);
		Sleep(1000);
		COUNTDOWN--;
	}
	exit(1);
}//FALTA FECHAR FICHEIROS E DESALOCAR MEMORIA

