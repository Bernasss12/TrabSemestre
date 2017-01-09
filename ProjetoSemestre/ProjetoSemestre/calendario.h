#pragma once
#include "menus.h"

void generateCalendar();
char getValueDay(int);
char getValueMonth(int, int);
void printCalendar();

int DIAS_MES[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char **DIAS;

char *JAN, *FEV, *MAR, *ABR, *MAI, *JUN, *JUL, *AGO, *SET, *OTU, *NOV, *DEZ;

//char *MÊS[] = { JAN, FEV, ABR, MAI, JUN, JUL, AGO, SET, OTU, NOV, DEZ };

char LETRAS[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


void generateCalendar() {
	int DIAS_TOTAIS, BISSEXTO;
	int CALENDARIO_GERADO = 0;

	time_t t;

	srand((unsigned)time(&t));

	DIAS = (char **)malloc(12 * sizeof(char *));
	for (int i = 0; i<10 ;i++) DIAS[i] = (char *)malloc(20 * sizeof(char));

	if ((ANO % 4 == 0 && ANO % 100 != 0) || ANO % 400 == 0) {
		DIAS_MES[1] = '29';
		BISSEXTO = 1;
	}

	for (int MES = 0; MES < 12; MES++) {
		for (int DIA = 0; DIA < DIAS_MES[MES]; DIA++) {
			DIAS[MES][DIA] = LETRAS[(rand() % 26)];
		}
	}

}

char getValueDay(int dia) {

}

char getValueMonth(int dia, int mes) {

}

void printCalendar() {
	int n = 0;
	for (int MES = 0; MES < 12; MES++) {
		for (int DIA = 0; DIA < DIAS_MES[MES]; DIA++) {
			printf(" %3c", DIAS[MES][DIA]);
			n++;
			if (n == 5){
				printf("\n");
				n = 0;
			}
		}
	}
}