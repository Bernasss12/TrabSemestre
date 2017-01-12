#pragma once
#include "langhelper.h"
#include <clocale>
#include "menus.h"

FILE* cabecalho;

inline void openFiles()
{
}

inline void filePrintCabecalho()
{
		int ESP;
		int ESP_ESQ;
		int ESP_DIR;

		setlocale(LC_ALL, "Portuguese_Portugal.860");
		fprintf(cabecalho, "");
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
}

