#include <stdio.h>

int main(){

    int fahr;
    int upper, step;

    printf("\n-  Step: ");
    scanf("%d", &step);

    printf("-  Max: ");
    scanf("%d", &fahr);

    printf("\n\t  F   |    C");
    printf("\n        ---------------");

    for(upper = 0; fahr >= upper; fahr -= step){

        printf("\n\t%4d  |  %5.1f", fahr, (5.0/9.0)*(fahr - 32));
    }

    printf("\n");

    return 0;
}