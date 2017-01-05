#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <ctype.h>
#include <windows.h>

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
void printalunos();

//Default de Cabeçalho
auto NUM_ALUNOS = 1;
int NUM_ALUNO = 10000;


//Códigos ASCII
//Letras
int A_MIN_TIL = 132; //ã
int A_MAI_TIL = 142; //Ã
int O_MIN_ACE = 162; //ó
int O_MAI_ACE = 159; //Ó
int C_MIN_CED = 135; //ç
int C_MAI_CED = 128; //Ç
int A_MIN_AGU = 160; //à
int A_MAI_AGU = 134; //À
int A_MIN_GRA = 133; //á
int A_MAI_GRA = 145; //Á
int O_MIN_TIL = 148; //õ

//Simbolos de tabela
int BARRA_VERTICAL = 186; 
int BARRA_HORIZONTAL_LD = 185;
int BARRA_HORIZONTAL_LE = 204;
int BARRA_HORIZONTAL = 205;
int BARRA_HORIZONTAL_U = 202;
int BARRA_HORIZONTAL_D = 203;
int CNT_SD = 187;        
int CNT_SE = 201;
int CNT_ID = 188;
int CNT_IE = 200;
int O_ASPAS = 34;
int C_ASPAS = 34;


void init()
{
	setlocale(LC_ALL, "Portuguese_Portugal.860");
	printf("");
	top(50);
	printf("%c        GERA%c%cO ALEAT%cRIA DE UM CALEND%cRIO        %c\n",BARRA_VERTICAL, C_MAI_CED, A_MAI_TIL, O_MAI_ACE, A_MAI_AGU, BARRA_VERTICAL);
	printf("%c    Calend%crio do tipo %cCalend%crio do ADVENTO%c    %c\n",BARRA_VERTICAL, A_MIN_AGU, C_ASPAS, A_MIN_AGU, O_ASPAS, BARRA_VERTICAL);
	printf("%c                      ANO %4d                    %c\n", BARRA_VERTICAL, 0000, BARRA_VERTICAL);
	if (alunos != NULL)printalunos();
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

void printalunos()
{
	for(int i = 0; i < NUM_ALUNOS; i++)
	{
		printf("Aluno %d - N%c %5d Nome: %s %s", i, 167, alunos [i].num, alunos [i].nome, alunos [i].apelido);
	}
}

void inscaluno()
{
	system("cls");
	init();
	printf("%c             Informa%c%ces de Cabe%calho             %c\n", BARRA_VERTICAL, C_MIN_CED, O_MIN_TIL, C_MIN_CED, BARRA_VERTICAL);
	linhacon(50);
	printf("%c Quantos alunos est%co no grupo? [1 ou 2]          %c\n", BARRA_VERTICAL, A_MIN_TIL, BARRA_VERTICAL);
	bot(50);
	printf("\n>");
	scanf_s(" %d", &NUM_ALUNOS);
	if (NUM_ALUNOS != 1)
	{
		if (NUM_ALUNOS != 2){
			printf(" Numero inválido!");
			NUM_ALUNOS = 0;
			Sleep(250);
			inscaluno();
		}
	}
	alunos = (aluno *)malloc(NUM_ALUNOS * sizeof(aluno));
	if (alunos==NULL)
	{
		printf("Correu algo de errado com a aloca%c%co de mem%cria.\n", C_MIN_CED, A_MIN_TIL, O_MIN_ACE);
		Sleep(1500);
		sair();
	}

	for ( int i = 0; i < NUM_ALUNOS; i++)
	{
		alunos[i].nome  [i] = '\0';
		alunos[i].apelido [i] = '\0';
		printf("Qual é o número de aluno do Aluno %d?\n\n>", i);
		scanf_s(" %d", &alunos[i].num);
		printf("Qual é o nome do Aluno %d?\n\n>", i);
		scanf_s(" %s", &alunos[i].nome);
		printf("Qual é o apelido do Aluno %d?\n\n>", i);
		scanf_s(" %s", &alunos[i].apelido);
	}
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