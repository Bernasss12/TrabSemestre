#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateCalendar(int);
void printCalendar();
void printMonth(int);
void printDay(int, int);
void findOnCalendar(char);
void meS(int);
void freeCal();

int **DIAS_ANO;
int DIAS_NO_MES[12] = {31,0,31,30,31,30,31,31,30,31,30,31};

void generateCalendar(int ANO)
{
	if ((ANO % 4 == 0 && ANO % 100 != 0) || ANO % 400 == 0) {
		DIAS_NO_MES[1] = { 29 };
	}
	else {
		DIAS_NO_MES[1] = { 28 };
	}

	DIAS_ANO = (int**)malloc(12 * sizeof(int*));
	for (int i = 0; i < 12; i++) {
		(DIAS_ANO)[i] = (int*)malloc(DIAS_NO_MES[i] * sizeof(int));
	}

	if (DIAS_ANO == NULL) {
		sair(); 
	}

	srand(time(NULL));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			DIAS_ANO[i][j] = ((rand() % ('Z' - 'A' + 1)) + 'A');
		}
	}
}

void printCalendar() {
	int LINE = 7;
	for (int i = 0; i < 12; i++) {
		meS(i);
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			if (LINE == 0) {
				printf("\n");
				LINE = 7;
			}
			printf("%2c", DIAS_ANO[i][j]);
			LINE--;
		}
		printf("\n");
		LINE = 7;
	}
}

void printMonth(int mes) {
	meS(mes);
	int LINE = 7;
	for (int j = 0; j < DIAS_NO_MES[mes]; j++) {
		if (LINE == 0){
			printf("\n"); 
			LINE = 7;
		}
		printf("%2c", DIAS_ANO[mes][j]);
		LINE--;
	}
	printf("\n");
}

void printDay(int mes, int dia) {

}

void findOnCalendar(char c) {
	c = toupper(c);
	printf("A letra %c pode ser encontrada em:", c);
	for (int i = 0; i < 12; i++) {
		meS(i);
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			if (DIAS_ANO[i][j] == c) {
				printf("\nDia %d de ", j);
				meS(i);
			}
		}
	}
}

void meS(int mes) {
	switch(mes + 1){
	case 1:
		printf("Janeiro");
		break;
	case 2:
		printf("Fevereiro");
		break;
	case 3:
		printf("Mar%co", C_MIN_CED);
		break;
	case 4:
		printf("Abril");
		break;
	case 5:
		printf("Maio");
		break;
	case 6:
		printf("Junho");
		break;
	case 7:
		printf("Julho");
		break;
	case 8:
		printf("Agosto");
		break;
	case 9:
		printf("Setembro");
		break;
	case 10:
		printf("Outubro");
		break;
	case 11:
		printf("Novembro");
		break;
	case 12:
		printf("Dezembro");
		break;
	}
	printf("\n");
}

void freeCal(){
	if (DIAS_ANO != NULL) {
		free(DIAS_ANO);
	}
}