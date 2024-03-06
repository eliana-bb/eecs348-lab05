#include <stdio.h>
#define NUM_MONTHS 12

unsigned int getcents() {
    unsigned int current_dollars;
    unsigned int current_cents;
    scanf("%d.%2d", &current_dollars, &current_cents);
    return (100*current_dollars + current_cents);
}

int main()
{
    char months[NUM_MONTHS][9] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    unsigned int monthly_earnings_cents[12];
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        monthly_earnings_cents[i] = getcents();
    }
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        printf("%9s", months[i]);
        printf("%8d.%02d\n", monthly_earnings_cents[i] / 100, monthly_earnings_cents[i] % 100);
    }
    return 0;
}

