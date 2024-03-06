#include <stdio.h>
#include <strings.h>
#define NUM_MONTHS 12

char months[][NUM_MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\n", months[i]);
    }
}