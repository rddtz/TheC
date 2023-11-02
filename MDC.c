#include <stdio.h>

int main(){

    long int A, B; // Numeros para descobrir o MDC
    int aux; // Variavel para trocar caso necessario
    int R; // Resto da Divisão
    int contador = 1; //Contar quantas vezes rodou
    long int MDC = 0;

    printf("\nA: ");
    scanf("%d", &A);

    printf("B: ");
    scanf("%d", &B);

    int holdA = A;
    int holdB = B;

    //Casos especificos
    if (A == 1 || B == 1){ // MDC(A,1)
        MDC = 1;
    } else if (A == B) { //MDC (A,A)
                if (A > 0) {
                    MDC = A;
                } else {
                    MDC = -A;
                }
    } else if (A%B == 0) { //MDC(B|A)
                if (B > 0) {
                    MDC = B;
                } else {
                    MDC = -B;
                }
    } else if (B%A == 0) { //MDC(B|A)
                if (A > 0) {
                    MDC = A;
                } else {
                    MDC = -A;
                }
    } else if (A == 0) { //MDC(A, 0)
                if (A > 0) {
                    MDC = A;
                } else {
                    MDC = -A;
                }
    } else if (B == 0) { //MDC(B, 0)
                if (B > 0) {
                    MDC = B;
                } else {
                    MDC = -B;
                }
    }

    if (MDC == 0) {
        if (B > A){
            aux = A;
            A = B;
            B = aux;
        }

        do {
            R = A % B;
            if (R != 0){
                A = B;
                B = R;
                contador++;
            }
        } while (R != 0);

        MDC = B;
    }

     //B tem que ser menor que A

    printf("\nMDC(%ld,%ld) = %ld", holdA, holdB, MDC);
    printf("\nCalculou %d vezes\n", contador);

    return 0;
}
