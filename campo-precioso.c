#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
    
    int campo[N][N] = {0};
    int pedras[N][2] = {0};
    int chutes[100][2] = {0};
    int Nchutes = 0;
    int Npedras = 0;
    int l, c, i, aux = 0;
    int fim = 0;
    int lj = 0, cj = 0;

    srand(5);

    for(l = 0; l < N; l++){
        for(c = 0; c < N; c++){
            if(rand() < RAND_MAX/N){
                campo[l][c] = 10;
                pedras[Npedras][0] = l;//Linha
                pedras[Npedras][1] = c;//Coluna
                Npedras++;
            }
        }
    }

    //for(l = 0; l < N; l++){
     //   printf("%d: (%d, %d) | ", l, pedras[l][0], pedras[l][1]);
    //}

    for(l = 0; l < Npedras; l++){

        if(pedras[l][0] != 0){
            //Cima
            campo[pedras[l][0] - 1][pedras[l][1]] += 1;
        }
        if(pedras[l][0] != N - 1) {
            //Baixo
            campo[pedras[l][0] + 1][pedras[l][1]] += 1;
        }
        if(pedras[l][1] != 0){
            //Tras
            campo[pedras[l][0]][pedras[l][1] - 1] += 1;
        }
        if(pedras[l][1] != N - 1){
            //Frente
            campo[pedras[l][0]][pedras[l][1] + 1] += 1;
        }
        if(pedras[l][1] != 0 && pedras[l][0] != N - 1){
            //Diagonal inferior esquerdo
            campo[pedras[l][0] + 1][pedras[l][1] - 1] += 1;
        }
        if(pedras[l][1] != N - 1 && pedras[l][0] != N - 1){
            //Diagonal inferior direito
            campo[pedras[l][0] + 1][pedras[l][1] + 1] += 1;
        }
        if(pedras[l][1] != N - 1 && pedras[l][0] != 0){
            //Diagonal superior direito
            campo[pedras[l][0] - 1][pedras[l][1] + 1] += 1;
        }
        if(pedras[l][1] != 0 && pedras[l][0] != 0){
            //Diagonal superior esquerdo
            campo[pedras[l][0] - 1][pedras[l][1] - 1] += 1;
        }
    }

    for(l = 0; l < N; l++){
        printf("\n |");
        for(c = 0; c < N; c++){
            if(campo[l][c] >= 10) printf(" P |");
            else printf(" %d |", campo[l][c]);
        }
    }
    
    printf("\n\n");

    for(l = 0; l < N; l++){
        printf("\n |");
        for(c = 0; c < N; c++){
            printf(" X |");
        }
    }

    while(!fim){
        printf("\n\nDigite uma cordenada de (0, 0) ate (%d, %d): ", N-1, N-1);
        scanf("%d %d", &chutes[Nchutes][0], &chutes[Nchutes][1]);

        
        for(l = 0; l < N; l++){
            printf("\n |");
            for(c = 0; c < N; c++){
                lj = chutes[Nchutes + aux][0];
                cj = chutes[Nchutes + aux][1];
                if(cj == c && lj == l){
                    if(campo[l][c] >= 10) printf(" P |");
                    else printf(" %d |", campo[l][c]);
                } else {
                    printf(" X |");
                }
            }
        }

        if(campo[lj][cj] >= 10){
            printf("\n\nVoce achou uma pedra preciosa!");
            fim = 1;
        }

        Nchutes++;

    }

    printf("\n");

    return 0;
}
