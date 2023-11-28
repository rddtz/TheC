#include <stdio.h>
#include <stdlib.h>

#define N 9

int main(){
    
    int campo[N][N] = {0};
    int pedras[N*N][2] = {0};
    int Npedras = 0;
    
    //Matriz resposta
    int solucao[N][N] = {0};
    
    int l, c, i, rodada = 1;
    int fim = 0;
    int lj = 0, cj = 0;

    srand(5);

    for(l = 0; l < N; l++){
        for(c = 0; c < N; c++){
		solucao[l][c] = 5000;
	}
    }

    for(l = 0; l < N; l++){
        for(c = 0; c < N; c++){
            if(rand() < RAND_MAX/(N+N)){
                campo[l][c] = 50;
                pedras[Npedras][0] = l;//Linha
                pedras[Npedras][1] = c;//Coluna
                Npedras++;
            }
        }
    }

    //for(l = 0; l < Npedras; l++){
      //  printf("%d: (%d, %d) | ", l, pedras[l][0], pedras[l][1]);
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

	//gabarito
    /*for(l = 0; l < N; l++){
        printf("\n |");
        for(c = 0; c < N; c++){
            if(campo[l][c] >= 50) printf(" P |");
            else printf(" %d |", campo[l][c]);
        }
    }*/
    
    printf("\nBem vindo! Seu objetivo é encontrar todas as %d pedras preciosas escondidas nesse terreno!\n\n", Npedras);
	
	//primeria vez tudo escondido
    
    printf("------------------- Rodada %d -------------------\n\n", rodada);
    for(c = -1; c < N; c++){
	if(c < 0) printf("   |");
	else printf("C%d |", c+1);
    }
        
    for(l = 0; l < N; l++){
    	printf("\nL%d |", l+1);
        for(c = 0; c < N; c++){
            printf(" X |");
        }
    }

    while(fim < Npedras){
    	rodada++;
        printf("\n\nDigite uma cordenada de (1, 1) ate (%d, %d): ", N, N);
        scanf("%d %d", &lj, &cj);
        printf("\n");

	lj--;
	cj--;
	
	solucao[lj][cj] = campo[lj][cj];
	//printf("campo:%d solucao: %d lj: %d cj:% d", campo[lj][cj], solucao[lj][cj], lj, cj);
	
	
	
	for(l = 0; l < N; l++){
		
		for(c = 0; c < N; c++){
			if(l-1 == lj && c == cj){
		    		 //Cima
		  	 	 solucao[l][c] = campo[l][c];
        		}
			if(l+1 == lj && c == cj) {
				//Baixo
			    	solucao[l][c] = campo[l][c];
			}
			if(l == lj && c+1 == cj){
			    	//Tras
			    	solucao[l][c] = campo[l][c];
			}
			if(l == lj && c-1 == cj){
			    //Frente
			    solucao[l][c] = campo[l][c];
			}
		}
	}
	
        
        for(c = -1; c < N; c++){
		if(c < 0) printf("   |");
		else printf("C%d |", c+1);
	}
        
        for(l = 0; l < N; l++){
     	   printf("\nL%d |", l+1);
     	   for(c = 0; c < N; c++){
     	   	if(solucao[l][c] == 5000){	
     	        	printf(" X |");
     	        } else if (solucao[l][c] >= 50){
     	        	printf(" P |");
     	        } else {
     	        	printf(" %d |", solucao[l][c]);
     	        }
     	   }
    	}

        if(campo[lj][cj] >= 50){
            fim += 1;
            printf("\n\nVoce achou a %dº pedra preciosa!", fim);
        }
        if(!(fim < Npedras)){
        	printf("\nVoce achou todas as pedras! Parabens!!!");
        } else{
    		printf("\n\n------------------- Rodada %d -------------------", rodada);
        }
    }

    printf("\n");

    return 0;
}
