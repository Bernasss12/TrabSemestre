#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#include <ctype.h>
#include <windows.h>
#include <direct.h> 

//Aluno struct
typedef struct
{
	int num;
	char nome[10];
	char apelido[10];
}aluno;

//Array de alunos
aluno *alunos;

//Ficheiros
FILE* cabecalho;
FILE* input;
FILE* output;
FILE* calendario;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
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
int E_MIN_ACE = 130; //é
int E_MAI_ACE = 144; //É
int U_MIN_ACE = 163; //ú

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

//Menu
int TEMP1;
int TEMP2;
int NUM_ALUNOS = NULL;
int NUM_ALUNO = 10000;
int ANO = 0;
int MENU_INPUT = 1;

//Calendario
int **DIAS_ANO;
int DIAS_NO_MES[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
int CALENDARIO_GERADO = 0;

int ATUAL = 0;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Paths pastas e ficheiros
char PATHOUTPUT[19] = "0://tmp//output.tx";
char PATHCALENDARIO[23] = "0://tmp//calendario.tx";
char PATHCABECALHO[22] = "0://tmp//cabecalho.tx";
char PATHINPUT[18] = "0://tmp//input.tx";
char DIRECTORY[7] = "0://tm";
char DRIVE;

///////////////////////////////////////////////////////////////////////////////////
//Inicialização das funções.///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void menuPrincipal();
void callInfo();
int numAlunos();
void inscaluno();
void init();
char menu();
void sair();
int menu2();
void menuOpcao1();

//Calendario
void generateCalendar(int);
void printCalendar();
void printMonth(int);
void printDay(int, int);
void findOnCalendar(char);
void meS(int);
int mesSize(int);
void freeCal();
void howManyChar(char);

//Ficheiros
void directory();
void fileInput();
void fileCalendar();
void filePrintCabecalho();
void pathGerais();



void flushstdin();

//Aparencia
void ico(int);
void linha(int);
void linhacon(int);
void linhacon_ID(int, int);
void linhacon_IU(int, int);
void top_D(int, int);
void bot_U(int, int);
void top(int);
void bot(int);
void space(int);

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
//MAIN/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
void main()
{
	setlocale(LC_ALL, "Portuguese_Portugal.860");
	while (true) {
		switch (ATUAL)
		{
		case 0:
			ATUAL = 1;
			menuPrincipal();	
			break;
		case 1:
			ATUAL = 1;
			menuOpcao1();
			break;
		}
		system("pause");
	}	
}
///////////////////////////////////////////////////////////////////////////////////
//MAIN/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//Menu Switches////////////////////////////////////////////////////////////////////
void menuPrincipal(){
	switch (menu()) {
	case 'T': //Input de teclado
		pathGerais();
		directory();
		inscaluno();
		break;
	case 'F': //Input de ficheiro
		pathGerais();
		directory();
		break;
	case 'S': //Sair do programa
		sair();
		break;
	}
}
void menuOpcao1()
{
	if (CALENDARIO_GERADO == 0)
	{
		generateCalendar(ANO);
	}

	while (ATUAL == 1)
	{
		switch(menu2())
		{
		case 1: //29 fevereiro
			system("cls");
			init();
			printf("                                                           \033[A\33[2k\r");
			bot(50);
			printDay(2, 29);
			break;
		case 2: //Quais os dias do ano letra A?
			system("cls");
			init();
			printf("                                                           \033[A\33[2k\r");
			bot(50);
			findOnCalendar('A');
			break;
		case 3: //Para quantos dias foi escolhido a letra k
			system("cls");
			init();
			printf("                                                           \033[A\33[2k\r");
			bot(50);
			howManyChar('K');
			break;
		case 4: //Imprima o calendario referente ao mes fevereiro
			system("cls");
			init();
			printf("                                                           \033[A\33[2k\r");
			bot(50);
			printMonth(2);
			break;
		case 5: //Mais Opçoes... TODO
		case 6: //Voltar ao menu de input.
			ATUAL = 0;
			main();
			break;
		default:
			menuOpcao1();
			break;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////

//Menus////////////////////////////////////////////////////////////////////////////
void init()
{
	int ESP;
	int ESP_ESQ;
	int ESP_DIR;

	setlocale(LC_ALL, "Portuguese_Portugal.860");
	printf("");
	top(50);
	printf("%c      \x1b[36m  GERA%c%cO ALEAT%cRIA DE UM CALEND%cRIO   \x1b[0m     %c\n", BARRA_VERTICAL, C_MAI_CED, A_MAI_TIL, O_MAI_ACE, A_MAI_AGU, BARRA_VERTICAL);
	printf("%c   \x1b[36m Calend%crio do tipo %cCalend%crio do ADVENTO%c  \x1b[0m  %c\n", BARRA_VERTICAL, A_MIN_AGU, C_ASPAS, A_MIN_AGU, O_ASPAS, BARRA_VERTICAL);
	if (ANO != 0) {
		printf("%c            \x1b[36m          ANO %4d          \x1b[0m          %c\n", BARRA_VERTICAL, ANO, BARRA_VERTICAL);
	}

	if (NUM_ALUNOS != NULL) {
		for (int i = 0; i < NUM_ALUNOS; i++)
		{

			ESP = floor((26 - strlen(alunos[i].nome) - strlen(alunos[i].apelido)) / 2);
			if (ESP % 2 == 0) {
				ESP_DIR = (int)floor(ESP);
				ESP_ESQ = (int)floor(ESP);
			}
			else
			{
				ESP_DIR = (int)floor(ESP) + 1;
				ESP_ESQ = (int)floor(ESP);
			}

			ico(BARRA_VERTICAL);
			space(ESP_ESQ);
			printf("\x1b[36mAluno N%c %5d - ", 167, alunos[i].num);
			printf("Nome: ");
			printf("%s ", alunos[i].nome);
			printf("%s\x1b[0m", alunos[i].apelido);
			space(ESP_DIR);
			ico(BARRA_VERTICAL);
			//printf("ESP:%d ESPE:%d ESPD:%d NOME:%d APELIDO:%d", ESP, ESP_ESQ, ESP_DIR, strlen(alunos[i].nome), strlen(alunos[i].apelido)); //Debug
			printf("\n");
		}
	}

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
	printf("%c Por Teclado                   %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" Insira 'T'       %c\n", BARRA_VERTICAL);
	printf("%c Por Ficheiro                  %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" Insira 'F'       %c\n", BARRA_VERTICAL);
	printf("%c Desejo sair do programa.      %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" Insira 'S'       %c\n", BARRA_VERTICAL);
	bot_U(50, 31);
	printf("\n>");

	do {
		scanf(" %c", &resposta);
		resposta = toupper(resposta);
		if (resposta == 'T' || resposta == 'S' || resposta == 'F') {
			return resposta;
		}
		printf("\033[A \r>(Resposta inv%clida!)", A_MIN_AGU);
		flushstdin();
		Sleep(500);
		printf("\33[2K\r>");
	} while (!(resposta == 'T' || resposta == 'S' || resposta == 'F'));

	return 0;
}
void sair() {
	int COUNTDOWN = 3;

	system("cls");
	init();
	printf("                                        \033[A\33[2k\r");
	bot(50);
	while (COUNTDOWN != 0) {
		printf("\33[k\r\x1b[31m\n       A sair do programa em %d segundos...       \x1b[30m\033[A", COUNTDOWN);
		Sleep(1000);
		COUNTDOWN--;
	}
	exit(1);
}//FALTA FECHAR FICHEIROS E DESALOCAR MEMORIA
int menu2()
{
	system("cls");
	init();
	int RESPOSTA2;
	printf("%c                 Menu de Controlo                 %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	linhacon(50);
	printf("%c Qual a fun%c%co a ser realizada pelo programa?     %c\n", BARRA_VERTICAL, C_MIN_CED, A_MIN_TIL, BARRA_VERTICAL);
	printf("%c [1,2,3,4,5,6]                                    %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	printf("%c", BARRA_HORIZONTAL_LE);linha(44); printf("%c", 203); linha(5);printf("%c\n", BARRA_HORIZONTAL_LD);
	printf("%c Qual a letra gerada para 29 FEV?           %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [1] %c\n", BARRA_VERTICAL);
	printf("%c Para que dias foi gerada a letra A?        %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [2] %c\n", BARRA_VERTICAL);
	printf("%c Para quantos dias foi gerado K?            %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [3] %c\n", BARRA_VERTICAL);
	printf("%c Imprimir Fevereiro.                        %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [4] %c\n", BARRA_VERTICAL);
	printf("%c Mais opcoes...                             %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [5] %c\n", BARRA_VERTICAL);
	printf("%c                                            %c", BARRA_VERTICAL, BARRA_VERTICAL);printf("     %c\n", BARRA_VERTICAL);
	printf("%c Voltar ao menu anterior.                   %c", BARRA_VERTICAL, BARRA_VERTICAL);printf(" [6] %c\n", BARRA_VERTICAL);
	bot_U(50, 44);
	printf("\n>");

	do {
		scanf(" %1d", &RESPOSTA2);
		RESPOSTA2 = toupper(RESPOSTA2);
		if (RESPOSTA2 == 1 || RESPOSTA2 == 2 || RESPOSTA2 == 3 || RESPOSTA2 == 4 || RESPOSTA2 == 5 || RESPOSTA2 == 6) {
			MENU_INPUT = 2;
			return RESPOSTA2;
		}
		printf("\033[A \r>(Resposta inv%clida!)", A_MIN_AGU);
		flushstdin();
		Sleep(500);
		printf("\33[2K\r> ");
	} while (!(RESPOSTA2 == 1 || RESPOSTA2 == 2 || RESPOSTA2 == 3 || RESPOSTA2 == 4 || RESPOSTA2 == 5 || RESPOSTA2 == 6));
}
///////////////////////////////////////////////////////////////////////////////////

//Inputs///////////////////////////////////////////////////////////////////////////
void inscaluno()
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
			flushstdin();
			Sleep(500);
			printf("\33[2K\rAluno %d>", i + 1);
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
	MENU_INPUT = 1;
	main();
}
void callInfo() {
	printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
	printf("%c Qual o ano do calend%crio que pretende gerar?     %c\n", BARRA_VERTICAL, A_MIN_AGU, BARRA_VERTICAL);
	bot(50);
	printf("\n>");
	scanf("%d", &ANO);
	flushstdin();
}
int numAlunos() {
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
		flushstdin();
		printf("\33[2K\r>");
	}
	return NUM_ALUNOS;
}
///////////////////////////////////////////////////////////////////////////////////

//File Handler/////////////////////////////////////////////////////////////////////
void directory() {
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
void fileInput()
{
	PATHINPUT[17] = 't';
	PATHOUTPUT[18] = 't';



	input = fopen(PATHINPUT, "w+");

	fprintf(input, "N%c    Nome      Apelido\n", 163);
	fprintf(input, "XXXXX XXXXXXXXXX XXXXXXX\n");

	fclose(input);
}
void fileCalendar()
{

	PATHCALENDARIO[22] = 't';
}
void filePrintCabecalho()
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
void pathGerais() {

	setlocale(LC_ALL, "Portuguese_Portugal.860");

	printf("                                                                     \033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\033[A\33[2K\r");
	linhacon(50);
	printf("%c Qual a drive em que pretende criar o ficheiro?   %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	printf("%c [C,D,E]                                          %c\n", BARRA_VERTICAL, BARRA_VERTICAL);
	bot(50);
	printf("\n> ");
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
void inscalunoFile()
{
	input = fopen(PATHINPUT, "r+");
	printf("%c             Informa%c%ces de Cabe%calho             %c\n", BARRA_VERTICAL, C_MIN_CED, O_MIN_TIL, C_MIN_CED, BARRA_VERTICAL);
	linhacon(50);
	if (NUM_ALUNOS == NULL) {
		//		numAlunos();
	}
	if (alunos == NULL) {//Alocação dinâmica da memoria para os alunos.
		alunos = (aluno*)malloc(NUM_ALUNOS * sizeof(aluno));
	}

	for (int i = 0; i < NUM_ALUNOS; i++)
	{
		alunos[i].nome[i] = '\0';
		alunos[i].apelido[i] = '\0';

		alunos[i].num = 0;
		fscanf(input, " %5d", &alunos[1].num);
		fscanf(input, "%9s", &alunos[1].nome, 10);
		fscanf(input, "%9s", &alunos[1].apelido, 10);

	}
	//callInfo();
}
///////////////////////////////////////////////////////////////////////////////////

//Calendario///////////////////////////////////////////////////////////////////////
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
		int COUNTDOWN = 3;
		freeCal();
		system("cls");
		printf("                                        \033[A\33[2k\r");
		bot(50);
		while (COUNTDOWN != 0) {
			printf("\33[k\rA sair do programa em %d segundos...", COUNTDOWN);
			Sleep(1000);
			COUNTDOWN--;
		}
		exit(1);
	}

	srand((unsigned)time(NULL));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			DIAS_ANO[i][j] = ((rand() % ('Z' - 'A' + 1)) + 'A');
		}
	}
	CALENDARIO_GERADO = 1;
} //gera o calendario
void printCalendar() {
	int LINE = 7;
	for (int i = 0; i < 12; i++) {
		meS(i);
		printf("\n");
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
	int ESPM = (int)floor((15 - mesSize(mes-1))/2);
	int ESPMD, ESPME;
	if(ESPM % 2 != 0)
	{
		ESPME = ESPM - 2;
		ESPMD = ESPM - 2;
	}else
	{
		ESPME = ESPM - 2;
		ESPMD = ESPM - 2 + 1;
	}
	linha(ESPME);
	printf("%c ", BARRA_HORIZONTAL_LD);
	meS(mes-1);
	printf(" %c", BARRA_HORIZONTAL_LE);
	linha(ESPMD);
	printf("\n");
	int LINE = 7;
	for (int j = 0; j < DIAS_NO_MES[mes-1]; j++) {
		if (LINE == 0) {
			printf("\n");
			LINE = 7;
		}
		printf("%2c", DIAS_ANO[mes-1][j]);
		LINE--;
	}
	printf("\n");
	linha(15);
	printf("\n\n");
	system("pause");
}
void printDay(int mes, int dia) {
	if (DIAS_NO_MES[1] == 28 && mes-1 == 1 && dia == 29)
	{
		printf("\nO dia %d de ", dia);
		meS(mes-1);
		printf(" n%co exite pois o ano n%co %c bissexto.\n\n", A_MIN_TIL, A_MIN_TIL, E_MIN_ACE);
		system("pause");
		main();
	}
	else {
		printf("\nA letra gerada para o dia %d de ", dia);
		meS(mes-1);
		printf(" %c %c.\n\n", E_MIN_ACE, DIAS_ANO[mes - 1][dia - 1]);
	}
	system("pause");
}
void findOnCalendar(char c) {
	c = toupper(c);
	printf("\nA letra %c pode ser encontrada em:\n", c);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			if (DIAS_ANO[i][j] == c) {
				printf("\nDia %d de ", j+1);
				meS(i);
				printf(".");
			}
		}
	}
	printf("\n\n");
	system("pause");
}
void howManyChar(char c)
{
	int vezes = 0;
	c = toupper(c);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < DIAS_NO_MES[i]; j++) {
			if (DIAS_ANO[i][j] == c) {
				vezes++;
			}
		}
	}
	printf("\nA letra %c foi designada %d vezes.", c, vezes);
	printf("\n\n");
	system("pause");
}
void meS(int mes) {
	switch (mes + 1) {
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
}
int mesSize(int mes) {
switch (mes + 1) {
	case 1:
		return 7;
	case 2:
		return 9;
	case 3:
		return 5;
	case 4:
		return 5;
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 5;
	case 8:
		return 6;
	case 9:
		return 8;
	case 10:
		return 7;
	case 11:
		return 8;
	case 12:
		return 8;
	}
	return 0;
}
void freeCal() {
	if (DIAS_ANO != NULL) {
		free(DIAS_ANO);
	}
}
///////////////////////////////////////////////////////////////////////////////////

//Aparencia////////////////////////////////////////////////////////////////////////
void ico(int i) {
	printf("%c", i);
}
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
void space(int i) {
	for (int j = 0; j < i; j++) {
		printf(" ");
	}
}
///////////////////////////////////////////////////////////////////////////////////

//Quando scanf retira a informacao que estava à espera, apaga o resto do chamado 'buffer'. Quando lhe é dado informacao a mais ou diferente do suposto este nunca vai limpar o resto do buffer, criando um loop infinito. Esta função quando corrida depois do scanf apaga forçosamente toda a informação que este não utilizou para evitar o bloqueio do programa.
void flushstdin() {
	int c; while ((c = getchar()) != '\n' && c != EOF);
}