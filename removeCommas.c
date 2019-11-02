#include <string.h>
#include "babies.h"

int removeCommas(char *num){
	int len = strlen(num);
	char sub[MAXLENGTH];
	int i;
	int replace = 0;
	int commasRemoved = 0;
	for(i = 0; i < len; i++){
		*(sub + i) = *(num + i);
	}

	for(i = 0; i < len; i++){
		if(*(sub + i) != ','){
			*(num + replace) = *(sub + i);
			replace++;
		}else{
			commasRemoved++;
		}
	}

	*(num + replace) = '\0';

return (commasRemoved);
}
