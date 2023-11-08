#include <stdio.h>

int main(){

    int c, pastcblank = 0, printar = 1;
    float nc, nl, bt;

    for(nc = 0, nl = 0, bt = 0; (c = getchar()) != EOF; nc++){
        
        //Quase, ainda cortando 1 digito e deixando 1 espaço a mais
        if(printar){
            putchar(c); 
        }

        if(c == '\n'){
            nl++;
        } else if(c == ' ' || c == '\t'){
            if(pastcblank){
                printar = 0;}
            bt++;
            pastcblank = 1;
        } else {
            printar = 1;
            pastcblank = 0;
        }
    }

    printf("Numero de caracteres digitados: %.0f\n", nc - nl);
    printf("Numero de linhas digitadas: %.0f\n", nl);
    printf("Numero de espacos e TABs digitados: %.0f\n", bt);

    return 0;
    
}