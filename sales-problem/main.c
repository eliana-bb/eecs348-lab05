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

void print_monthly_report(char months[NUM_MONTHS][MONTH_LENGTH], unsigned int earnings[NUM_MONTHS])
{
    printf("\nMonthly sales report for 2023:");
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        printf("\n%-9s ", months[i]);
        print_dollars(earnings[i]);
    }
    printf("\n\n");
}

unsigned int get_average_sales(int start_month, int end_month, unsigned int earnings[NUM_MONTHS])
{
    unsigned int total_sum = 0;
    for (int m = start_month; m < end_month; m++)
    {
        total_sum += earnings[m];
    }
    return ((total_sum << 2) / (end_month - start_month)) >> 2;
}

int find_min_index(unsigned int earnings[NUM_MONTHS])
{
    int current_min_index = 0;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if (earnings[i] < earnings[current_min_index])
            current_min_index = i;
    }
    return current_min_index;
}

int find_max_index(unsigned int earnings[NUM_MONTHS])
{
    int current_max_index = 0;
    for (int i = 0; i < NUM_MONTHS; i++)
    {
        if (earnings[i] > earnings[current_max_index])
            current_max_index = i;
    }
    return current_max_index;
}

void print_sales_report(char months[NUM_MONTHS][MONTH_LENGTH], unsigned int earnings[NUM_MONTHS])
{
    printf("Sales summary:\n");
    printf("Minimum sales:  ");
    int super_month = find_min_index(earnings);
    print_dollars(earnings[super_month]);
    printf("  (%s)\n", months[super_month]);
    printf("Maximum sales:  ");
    super_month = find_max_index(earnings);
    print_dollars(earnings[super_month]);
    printf("  (%s)\n", months[super_month]);
    printf("Average sales:  ");
    print_dollars(get_average_sales(0, 12, earnings));
    printf("\n\n");
}

void print_rolling_averages(char months[NUM_MONTHS][MONTH_LENGTH], unsigned int earnings[NUM_MONTHS]) {
    printf("Six-Month Moving Average Report:");
    
    for (int start_month = 0; start_month + 5 < NUM_MONTHS; start_month++){
        printf("\n%-9s - %-9s  ", months[start_month], months[start_month+5]);
        print_dollars(get_average_sales(start_month, start_month+6, earnings));
    }
    printf("\n");
}

int main()
{
    char months[NUM_MONTHS][MONTH_LENGTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    unsigned int monthly_earnings_cents[12];
    get_monthly_data(monthly_earnings_cents);
    print_monthly_report(months, monthly_earnings_cents);
    print_sales_report(months, monthly_earnings_cents);
    print_rolling_averages(months, monthly_earnings_cents);
    return 0;
}
