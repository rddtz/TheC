#include <stdio.h>

/* Print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., n
    u can change the step two, so:
    for fahr = 0, 0 + step, ..., n*/
int main(){

    int fahr = 0;
    float celsius; 
    int upper, step;
    
    printf("\n-  Step: ");
    scanf("%d", &step);

    printf("-  Max: ");
    scanf("%d", &upper);

    printf("\n\t F   |    C");
    printf("\n       ---------------");
    while (fahr <= upper) {
        celsius = (float) 5 * (fahr - 32) / 9;
        printf("\n\t%3d  |  %5.1f", fahr, celsius);
        fahr += step;
    }

    printf("\n");
    return 0;
}
