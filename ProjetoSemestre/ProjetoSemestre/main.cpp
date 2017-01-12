#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <clocale>
#include "menus.h"
#include "calendario.h"

void menuPrincipal();

void main()
{
	int OPERACAO_INPUT = 0;
	char TMP = '0';

	//ANO = 2015;

	generateCalendar(2000);
	printMonth(11);
	system("pause");
	system("cls");
	printf("> ");
	scanf(" %c", &TMP);
	findOnCalendar(TMP);
	system("pause");

	sair();
	//Menu 1, decisão
	menuPrincipal();

	/*
	//Menu 2, opções
	while (OPERACAO_INPUT != 1) {
		switch (menu()) {
		case 1:			
			OPERACAO_INPUT = 1;
			break;
		case 2://TODO
			printf("Input Ficheiro\n");
			OPERACAO_INPUT = 1;
			break;
		case 3:
			OPERACAO_INPUT = 1;
			sair();
			break;
		default:
			printf("\033[A \r>(Op%c%co inv%clida!)", C_MIN_CED, A_MIN_TIL, A_MIN_AGU);
			Sleep(500);
			break;
		}
	}
	*/


	system("cls");
	init();
	
	system("pause");
}

void menuPrincipal(){
int MENU_INPUT = 0;
	while (MENU_INPUT != 1) {
		switch (menu()) {
		case 'T':
			//printf("Input Teclado\n"); //Debug
			inscaluno();
			MENU_INPUT = 1;
			break;
		case 'F'://TODO
				 //printf("Input Ficheiro\n"); //Debug
			MENU_INPUT = 1;
			break;
		case 'S':
			MENU_INPUT = 1;
			sair();
			break;
		default:
			printf("\033[A \r>(Resposta inv%clida!)", A_MIN_AGU);
			Sleep(500);
			break;
		}
	}
}
