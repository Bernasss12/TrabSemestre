#include <stdio.h>
#include <stdlib.h>

void generateCalendar(int);
void printCalendar();

char *DIAS_ANO;
int DIAS_NO_ANO;
int DIAS_NO_MES[12] = {31,0,31,30,31,30,31,31,30,31,30,31};

void generateCalendar(int ANO)
{
	if ((ANO % 4 == 0 && ANO % 100 != 0) || ANO % 400 == 0)

	DIAS_ANO = (char*)malloc(DIAS_NO_ANO * sizeof(char));
	
}
