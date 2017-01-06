#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <clocale>
#include "menus.h"
#include "langhelper.h"

void main()
{	
	int MENU_INPUT = 0;

	setlocale(LC_ALL, "pt-PT");
	linha(50);

	//Menu 1, decisão
	while (MENU_INPUT != 1){
		switch (menu()) {
		case 'T':
			printf("Input Teclado\n");
			inscaluno();
			MENU_INPUT = 1;	
			break;
		case 'F':
			printf("Input Ficheiro\n");
			MENU_INPUT = 1;
			break;
		case 'S':
			MENU_INPUT = 1;
			sair();
			break;
		default:
			break;
		}
	}

	system("pause");
}

