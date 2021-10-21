#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ArraySize 100
#define WordSize 20

int main () {
    printf("\033[0;33mstarting... \n");
    clock_t start = clock();

    FILE *Ifp;
    FILE *Ofp;

    char TempRead[WordSize];
    char temp[WordSize];
    char StraingsArray[ArraySize][WordSize];
    register int i = 0;
    register int j = 0;
    
    Ifp = fopen("Strings.txt", "r");
    Ofp = fopen("Alphabetized_Strings.txt", "w");

    //* Read Strings file and put all staings into an array.
    while (fscanf(Ifp, "%s", &TempRead) != EOF) {

        strcpy(StraingsArray[i], TempRead);
        i++;
        
    }

    //* sort array.
    for(i = 0; i < ArraySize; i++) {

        for(j = 0; j < ArraySize - 1 - i; j++) {

            if(strcmp(StraingsArray[j], StraingsArray[j + 1]) > 0) {

                strcpy(temp, StraingsArray[j]);
                strcpy(StraingsArray[j], StraingsArray[j + 1]);
                strcpy(StraingsArray[j + 1], temp);

            }
        }
    }

    //* print all strings to the output file.
    for (i = 0; i <= ArraySize - 1; i++) {

        fprintf(Ofp, "%s\n", StraingsArray[i]);

    }

    fclose(Ifp);
    fclose(Ofp);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\033[0;94mIt took \033[0;31m%.3f\033[0;94m seconds.\033[0m", time_spent);

    return 0;
}