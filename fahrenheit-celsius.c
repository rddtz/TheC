#include <stdio.h>

/* Print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., n
    u can change the stop two, so:
    for fahr = 0, 0 + step, ..., n*/
int main(){

    int fahr, celsius; 
    int upper, step;

    fahr = 0;
    
    printf("\nStep: ");
    scanf("%d", &step);

    printf("Max: ");
    scanf("%d", &upper);

    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("\n%d\t%d", fahr, celsius);
        fahr += step;
    }

    return 0;
}
