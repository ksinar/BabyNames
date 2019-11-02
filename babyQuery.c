#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "babies.h"

int main(int argc, char *argv){
	char num[MAXLENGTH];
	strcpy(num, "123,456,789");
/*	char noComma[MAXLENGTH] = removeCommas(num);
*/	
/*	removeCommas(*num);
*/	removeCommas(num);
	printf("%s\n", num);
}