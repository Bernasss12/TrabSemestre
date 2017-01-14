#pragma once
#include "langhelper.h"
#include <locale>
#include "menus.h"
#include <direct.h> 
#include <ctype.h>

FILE* cabecalho;
FILE* input;
FILE* output;
FILE* calendario;

void directory();
void fileInput();
void fileCalendar();
void filePrintCabecalho();
void pathGerais();

//Falta o t porque o compilador acrescenta o \0 automaticamente, mas como é indesejado tem que ser retirado, assim substituo por t e fico com o vetor do tamanho exatamente necessário.
char PATHOUTPUT[19] = "0://tmp//output.tx";
char PATHCALENDARIO[23] = "0://tmp//calendario.tx";
char PATHCABECALHO[22] = "0://tmp//cabecalho.tx";
char PATHINPUT[18] = "0://tmp//input.tx";
char DIRECTORY[7] = "0://tm";
char DRIVE;

inline void directory(){
	DIRECTORY[6] = 'p';

	if (_mkdir(DIRECTORY) != 0)
	{
		printf("Erro ao criar a pasta!\n");
	}
	else
	{
		printf("Pasta criada com sucesso!\n");
	}
}
inline void fileInput()
{
	PATHINPUT[17] = 't';
	PATHOUTPUT[18] = 't';
}
inline void fileCalendar()
{

	PATHCALENDARIO[22] = 't';
}
inline void filePrintCabecalho()
{
	PATHCABECALHO[21] = 't';

	cabecalho = fopen(PATHCABECALHO, "w+");
		int ESP;
		int ESP_ESQ;
		int ESP_DIR;

		setlocale(LC_ALL, "Portuguese_Portugal.860");
		fprintf(cabecalho, "%c", CNT_SE);
		for (int j = 0; j < 50; j++) {
			fprintf(cabecalho, "%c", BARRA_HORIZONTAL);
		}
		fprintf(cabecalho, "%c\n", CNT_SD);
		fprintf(cabecalho, "%c        GERA%c%cO ALEAT%cRIA DE UM CALEND%cRIO        %c\n", BARRA_VERTICAL, C_MAI_CED, A_MAI_TIL, O_MAI_ACE, A_MAI_AGU, BARRA_VERTICAL);
		fprintf(cabecalho, "%c    Calend%crio do tipo %cCalend%crio do ADVENTO%c    %c\n", BARRA_VERTICAL, A_MIN_AGU, C_ASPAS, A_MIN_AGU, O_ASPAS, BARRA_VERTICAL);
		if (ANO != 0) {
			fprintf(cabecalho, "%c                      ANO %4d                    %c\n", BARRA_VERTICAL, ANO, BARRA_VERTICAL);
		}

		if (NUM_ALUNOS != NULL) {
			for (int i = 0; i < NUM_ALUNOS; i++)
			{

				ESP = floor(((26 - strlen(alunos[i].nome)) - strlen(alunos[i].apelido)) / 2);
				if (ESP % 2 == 0) {
					ESP_DIR = (int)floor(ESP) + 1;
					ESP_ESQ = (int)floor(ESP);
				}
				else
				{
					ESP_DIR = (int)floor(ESP);
					ESP_ESQ = (int)floor(ESP);
				}

				fprintf(cabecalho, "%c", BARRA_VERTICAL);
				for (int j = 0; j < ESP_ESQ; j++) {
					fprintf(cabecalho, " ");
				}
				fprintf(cabecalho, "Aluno N%c %5d - ", 167, alunos[i].num);
				fprintf(cabecalho, "Nome: ");
				fprintf(cabecalho, "%s ", alunos[i].nome);
				fprintf(cabecalho, "%s", alunos[i].apelido);
				for (int j = 0; j < ESP_DIR; j++) {
					fprintf(cabecalho, " ");
				}
				fprintf(cabecalho, "%c", BARRA_VERTICAL);
				//printf("ESP:%d ESPE:%d ESPD:%d NOME:%d APELIDO:%d", ESP, ESP_ESQ, ESP_DIR, strlen(alunos[i].nome), strlen(alunos[i].apelido)); //Debug
				fprintf(cabecalho, "\n");
			}
		}

		fprintf(cabecalho, "%c", CNT_IE);
		for (int j = 0; j < 50; j++) {
			fprintf(cabecalho, "%c", BARRA_HORIZONTAL);
		}
		fprintf(cabecalho, "%c\n", CNT_ID);

		fclose(cabecalho);
}
inline void pathGerais() {

	setlocale(LC_ALL, "Portuguese_Portugal.860");

	printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
	printf("%c Qual a drive em que pretende criar o ficheiro?   %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	printf("%c Lembre-se que n%co deve utilizar caracteres       %c\n", BARRA_VERTICAL, A_MIN_TIL, BARRA_VERTICAL);
	printf("%c especiais. (i.e. %c%c%c ou %c%c%c)                     %c\n", BARRA_VERTICAL, O_ASPAS, A_MIN_TIL, C_ASPAS, O_ASPAS, C_MIN_CED, C_ASPAS, BARRA_VERTICAL);
	bot(50);
	do {
		scanf(" %c", &DRIVE);
		DRIVE = toupper(DRIVE);
		if (DRIVE == 'D' || DRIVE == 'E' || DRIVE == 'C') {
			break;
		}
		printf("\033[A \r>(Resposta inv%clida!)", A_MIN_AGU);
		Sleep(500);
		printf("\33[2K\r>");
	} while (!(DRIVE == 'D' || DRIVE == 'E' || DRIVE == 'C'));

	PATHOUTPUT[0] = DRIVE;
	PATHCABECALHO[0] = DRIVE;
	PATHINPUT[0] = DRIVE;
	PATHCALENDARIO[0] = DRIVE;
	DIRECTORY[0] = DRIVE;
	
}
inline void inscalunoFile()
{
	input = fopen(PATHINPUT, "r+");
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

		alunos[i].num = 0;
		fscanf(" %d", &alunos[1].num);
		fscanf("%s", &alunos[1].nome);
		fscanf("%s", &alunos[1].apelido);

	}
	callInfo();
}


