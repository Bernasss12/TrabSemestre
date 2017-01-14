#pragma once
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
int O_ASPAS = 147;
int C_ASPAS = 148;

//Aparencia
inline void ico(int i) {
	printf("%c", i);
}
inline void top(int i)
{
	printf("%c", CNT_SE);
	linha(i);
	printf("%c\n", CNT_SD);
}
inline void bot(int i)
{
	printf("%c", CNT_IE);
	linha(i);
	printf("%c\n", CNT_ID);
}
inline void linhacon(int i)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	for (int j = 0; j < i; j++) {
		printf("%c", BARRA_HORIZONTAL);
	}
	printf("%c\n", BARRA_HORIZONTAL_LD);
}
inline void linha(int i)
{
	for (int j = 0; j < i; j++) {
		printf("%c", BARRA_HORIZONTAL);
	}
}
inline void linhacon_IU(int i, int j)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_U);
	linha(i - j - 1);
	printf("%c\n", BARRA_HORIZONTAL_LD);
}
inline void linhacon_ID(int i, int j)
{
	printf("%c", BARRA_HORIZONTAL_LE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_D);
	linha(i - j - 1);
	printf("%c\n", BARRA_HORIZONTAL_LD);
}
inline void bot_U(int i, int j)
{
	printf("%c", CNT_IE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_U);
	linha(i - j - 1);
	printf("%c\n", CNT_ID);
}
inline void top_D(int i, int j)
{
	printf("%c", CNT_SE);
	linha(j);
	printf("%c", BARRA_HORIZONTAL_D);
	linha(i - j - 1);
	printf("%c\n", CNT_SD);
}
inline void space(int i) {
	for (int j = 0; j < i; j++) {
		printf(" ");
	}
}
