#include <stdio.h>

int main(){

    int c, i, n, nwhite, nother;
    int ndigit[10] = {0};

    nwhite = nother = 0; //Inicialização

    while((c = getchar()) != EOF){

        if(c >= '0' && c <= '9'){
            ndigit[c-'0']++;
        } 
        else if(c == ' ' || c == '\n' || c == '\t'){
            nwhite++;
        }
        else {
            nother++;
        }
    }
        
    printf("Digits =");
    for(i = 0; i < 10; i++){
        printf(" %d", ndigit[i]);
    }
    printf(", white spaces = %d, other = %d\n", nwhite, nother);

    //Histogram:
    printf("\n_________________________________________________________\nHISTOGRAM:\n\n");
    for(i = 0; i < 10; i++){
        printf("%d: ", i);
        for(n = 0; n < ndigit[i]; n++){
            printf("-");
        }
        printf("\n");
    }

    printf("W: ");
    for(n = 0; n < nwhite; n++){
            printf("-");
    }

    printf("\n");
    printf("O: ");
    for(n = 0; n < nother; n++){
            printf("-");
    }
    printf("\n");

    return 0;
}