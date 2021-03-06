#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "babies.h"

/*Code by: Kaan Sinar*/

int main(int argc, char **argv){
	char decade[MAXLENGTH];
	char path[MAXLENGTH];
	char rank[MAXLENGTH];
	char gender[MAXLENGTH];

  	struct pNames popNames;
  	char maleSNumber[20];
  	char femaleSNumber[20];
  	char string[100];

	int i;
	int rankNb;
	int genderNb;
	FILE *f1;
	char fileName[20];

	int askDecadeLoop = 1;
	int secondQ = 1;

	while(askDecadeLoop == 1){

	printf("What decade do you want to look at? [1880 to 2010] ");
	fgets(decade,MAXLENGTH,stdin);
	sscanf(decade, "%*s");

	int decadeCheck = atoi(decade);

	if(((decadeCheck < 1879) || (decadeCheck > 2011)) || (decadeCheck % 10 != 0)){
		printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
		continue;
	}
	for(i = 0; i < strlen(decade); i++){
		fileName[i] = decade[i];
	}

	for(i = 0; i < strlen(decade); i++){
		if(decade[i] == '\n'){
			decade[i] = '\0';
		}
	}

	for(i = 0; i < strlen(fileName); i++){
		if(fileName[i] == '\n'){
			fileName[i] = '\0';
		}
	}




	strcat(fileName, "Names.txt");

	i = 0;

	/* code below is from displayBabies.c */

	if ( (f1 = fopen(fileName, "r")) != NULL ) {
      while ( fgets(string, 100, f1) != NULL ) {
         sscanf (string, "%d %s %s %s %s", &popNames.rank[i], popNames.maleName[i], maleSNumber, popNames.femaleName[i], femaleSNumber);

         removeCommas ( maleSNumber );
         removeCommas ( femaleSNumber );
         popNames.maleNumber[i] = atoi ( maleSNumber );
         popNames.femaleNumber[i] = atoi ( femaleSNumber );
         i++;
      }
   } else {
      printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
		continue;
   }

	int contPath = 1;

	while(contPath == 1){

	printf("Would you like to see a rank, search for a name, or see the top 10? [rank, search, top]: ");
	fgets(path,MAXLENGTH,stdin);
	sscanf(path, "%*s");
	

	

	if((strcmp(path, "rank\n") != 0) && (strcmp(path, "search\n") != 0) && (strcmp(path, "top\n") != 0)){
		printf("Please type in rank, search, or top exactly as requested.\n");
		continue;
		
	}else{
		contPath = 0;
	}
	

	if(strcmp(path, "rank\n") == 0){
	
		int askRank = 1;

		while(askRank == 1){

		printf("What rank do you wish to see? [1-200]: ");
		fgets(rank,MAXLENGTH,stdin);
		sscanf(rank, "%*s");

		rankNb = atoi(rank);

		if((rankNb < 1) || (rankNb > 200)){
			printf("Only numbers between 1 and 200 are acceptable.\n");
			askRank = 1;
		}else{
			askRank = 0;
		}
		}
		int askGender = 1;

		while(askGender == 1){

		printf("Would you like to see the male (0), female (1) or both (2) name(s)? [0-2]: ");
		fgets(gender,MAXLENGTH,stdin);
		sscanf(gender, "%*s");
		fflush(stdin);
		genderNb = atoi(gender);

		if((genderNb != 0) && (genderNb != 1) && (genderNb != 2)){
			printf("Only the numbers 0, 1, or 2 are acceptable.\n");
			continue;
		}

		if(genderNb == 0){
			printf("Rank %d: Male: %s (%d)\n", rankNb, popNames.maleName[rankNb - 1], popNames.maleNumber[rankNb - 1]);
			askGender = 0;
			contPath = 0;

		}

		if(genderNb == 1){
			printf("Rank %d: Female: %s (%d)\n", rankNb, popNames.femaleName[rankNb - 1], popNames.femaleNumber[rankNb - 1]);
			askGender = 0;
			contPath = 0;
		}

		if(genderNb == 2){
			printf("Rank %d: Male: %s (%d) and Female: %s (%d)\n", rankNb, popNames.maleName[rankNb - 1], popNames.maleNumber[rankNb - 1],
																	popNames.femaleName[rankNb - 1], popNames.femaleNumber[rankNb - 1]);
			askGender = 0;
			contPath = 0;
		}
	}
	}
	if(strcmp(path, "top\n") == 0){
		int j = 0;
		for ( j=0; j<10; j++ ) {
			if((strlen(popNames.maleName[j]) < 8) && (strlen(popNames.femaleName[j]) < 8)){
    			printf ( "%d\t%s\t\t%d\t\t%s\t\t%d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], 
                                                     popNames.femaleName[j], popNames.femaleNumber[j] );
    		}
    		else if((strlen(popNames.maleName[j]) < 8)){
    			printf ( "%d\t%s\t\t%d\t\t%s\t%d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], 
                                                     popNames.femaleName[j], popNames.femaleNumber[j] );
    		}
    		else if((strlen(popNames.femaleName[j]) < 8)){
    			printf ( "%d\t%s\t%d\t\t%s\t\t%d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], 
                                                     popNames.femaleName[j], popNames.femaleNumber[j] );
    		}else{
    			printf ( "%d\t%s\t%d\t\t%s\t%d\n", popNames.rank[j], popNames.maleName[j], popNames.maleNumber[j], 
                                                     popNames.femaleName[j], popNames.femaleNumber[j] );
    		}

   		}


	}

	if(strcmp(path, "search\n") == 0){
		char nameCmp[MAXLENGTH];

		printf("What name do you want to search for? [case sensitive]: ");
		fgets(nameCmp,MAXLENGTH,stdin);
		sscanf(nameCmp, "%*s");

		for(i = 0; i < strlen(nameCmp); i++){
			if(nameCmp[i] == '\n'){
				nameCmp[i] = '\0';
			}
		}

	
	int searchNb = 1;

		while(searchNb == 1){
		printf("Do you wish to search male (0), female (1) or both (2) name? [0-2]: ");

		fgets(gender,MAXLENGTH,stdin);
		sscanf(gender, "%*s");

		genderNb = atoi (gender);

		searchNb = 0;

		if((genderNb != 0) && (genderNb != 1) && (genderNb != 2)){
			printf("Only the numbers 0, 1, or 2 are acceptable.\n");
			searchNb = 1;
		}
		}
	
		int exitLoop = 5000;
		int noName;
		int rankCountMale = 0;
		int rankCountFemale = 0;
		if (genderNb == 0){
			for(i = 0; i < ROWS; i++){
				if(strcmp(nameCmp, popNames.maleName[i]) == 0){
					printf("In %d, the male name %s is ranked %d with a count of %d.\n", decadeCheck, nameCmp, 
																					  popNames.rank[i], popNames.maleNumber[i]);
					i = exitLoop;
					noName = exitLoop;
				} 
			}

			if(noName != exitLoop){
					printf("In %d, the male name %s is not ranked.\n", decadeCheck, nameCmp);

			}
		}

		else if (genderNb == 1){
			for(i = 0; i < ROWS; i++){
				if(strcmp(nameCmp, popNames.femaleName[i]) == 0){
					printf("In %d, the female name %s is ranked %d with a count of %d.\n", decadeCheck, nameCmp, 
																					  popNames.rank[i], popNames.femaleNumber[i]);
					i = exitLoop;
					noName = exitLoop;
				} 
			}
			if(noName != exitLoop){
					printf("In %d, the female name %s is not ranked.\n", decadeCheck, nameCmp);
			}
		}

		else if (genderNb == 2){
			int maleExists = 0;
			int femaleExists = 0;
			for(i = 0; i < ROWS; i++){
				if(strcmp(nameCmp, popNames.femaleName[i]) == 0){
					femaleExists = 1;
					rankCountFemale = i;
				}

				if(strcmp(nameCmp, popNames.maleName[i]) == 0){
					maleExists = 1;
					rankCountMale = i;
				}

			}

			if((femaleExists == 1) && (maleExists == 1)){
				printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d.\n"
					, decadeCheck, nameCmp, rankCountFemale + 1, popNames.femaleNumber[rankCountFemale], nameCmp, rankCountMale + 1, popNames.maleNumber[rankCountMale]);
			}
			else if(femaleExists == 1){
				printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked.\n"
					, decadeCheck, nameCmp, rankCountFemale + 1, popNames.femaleNumber[rankCountFemale], nameCmp);
			}
			else if(maleExists == 1){
				printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d.\n"
					, decadeCheck, nameCmp, nameCmp, rankCountMale + 1, popNames.maleNumber[rankCountMale]);
			}
			else{
				printf("In %d, the female name %s is not ranked and the male name %s is not ranked.\n",
					decadeCheck, nameCmp, nameCmp);
			}
		}
		gender[0] = '\0';
		memset(nameCmp, 0, MAXLENGTH);
	}
	
	char response1[2];

	int firstQ = 1;
	

	while(firstQ == 1){

		printf("Do you want to ask another question about %d? [Y or N] ", decadeCheck);
		fgets(response1,MAXLENGTH,stdin);
		sscanf(response1, "%*s");
		fflush(stdin);


		if((strcmp(response1, "Y\n") == 0) || (strcmp(response1, "y\n") == 0)){
			contPath = 1;
			firstQ = 0;
			secondQ = 0;
		}else if((strcmp(response1, "N\n") == 0) || (strcmp(response1, "n\n") == 0)){
			firstQ = 0;
			contPath = 0;
			secondQ = 1;
		}else {
			printf("Only the single characters Y or N are acceptable.\n");
			firstQ = 1;
		}
	}
	}
	

	char response2[2];

	while(secondQ == 1){

		printf("Would you like to select another year? [Y or N] ");
		fgets(response2,MAXLENGTH,stdin);
		sscanf(response2, "%*s");
		fflush(stdin);

		if((strcmp(response2, "Y\n") == 0) || (strcmp(response2, "y\n") == 0)){
			askDecadeLoop = 1;
			secondQ = 0;
		}else if((strcmp(response2, "N\n") == 0) || (strcmp(response2, "n\n") == 0)){
			printf("Thank you for using babyQuery.\n");
			askDecadeLoop = 0;
			secondQ = 0;
		}else {
			printf("Only the single characters Y or N are acceptable.\n");
			secondQ = 1;;
		}
	}
}
return(0);
}