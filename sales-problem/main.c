#include <stdio.h>
#define NUM_MONTHS 12
#define MONTH_LENGTH 10

void print_dollars(unsigned int cents) { printf("$%05d.%02d", cents / 100, cents % 100); }

unsigned int getcents()
{
    unsigned int current_dollars;
    unsigned int current_cents;
    scanf("%d.%2d", &current_dollars, &current_cents);
    return (100 * current_dollars + current_cents);
}

void get_monthly_data(unsigned int earnings[NUM_MONTHS])
{
    printf("Enter monthly sales figures:\n");
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        earnings[i] = getcents();
    }
}

void print_monthly_report(char months[NUM_MONTHS][MONTH_LENGTH], unsigned int earnings[])
{
    printf("Monthly sales report for 2023:\n");
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        printf("\n%9s  ", months[i]);
        print_dollars(earnings[i]);
    }
}

int main()
{
    char months[NUM_MONTHS][MONTH_LENGTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    unsigned int monthly_earnings_cents[12];
    get_monthly_data(monthly_earnings_cents);
    print_monthly_report(months, monthly_earnings_cents);
    return 0;
}
