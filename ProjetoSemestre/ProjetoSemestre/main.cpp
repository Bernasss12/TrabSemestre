#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "calendario.h"
#include "filehandler.h"

void menuPrincipal();

void main()
{

	filePrintCabecalho();
	//Menu 1, decis�o
	menuPrincipal();

	/*
	//Menu 2, op��es
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
			filePrintCabecalho();
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
