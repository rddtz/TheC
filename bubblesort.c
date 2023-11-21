#include <stdio.h>

int main(){

    int arranjo[] = {23, 14, 57, 7, 89, 26, 10, 14, 64, 59};
    int fim = 1, mudou = 0, aux = 0, i = 0;
    int tamanho = sizeof(arranjo) / sizeof(arranjo[0]) - 1;


    while(fim){

        if(i == tamanho){
            i = 0;
            if(!mudou){
                fim = 0;
            }
            mudou = 0;
        }

        if(arranjo[i+1] < arranjo[i]){
                aux = arranjo[i+1];
                arranjo[i+1] = arranjo[i];
                arranjo[i] = aux;
                mudou += 1;
        }

        i++;
    }

    for(i = 0; i <= tamanho; i++)
        printf("%d - ", arranjo[i]);

    return 0;
}
