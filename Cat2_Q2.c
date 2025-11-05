/*
Name :Eunice Mwende
reg:CT100/G/26231/25
*/

#include <stdio.h>

int main() {
    float hours, rate, gross, tax, net;

    printf("Enter hours worked: ");
    scanf("%f", &hours);

    printf("Enter hourly rate: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours > 40)
        gross = (40 * rate) + (hours - 40) * rate * 1.5;
    else
        gross = hours * rate;

    // Calculate tax
    if (gross <= 600)
        tax = gross * 0.15;
    else
        tax = (600 * 0.15) + (gross - 600) * 0.20;

    // Net pay
    net = gross - tax;

    // Display results
    printf("\nGross Pay: %.2f", gross);
    printf("\nTax: %.2f", tax);
    printf("\nNet Pay: %.2f\n", net);

    return 0;
}