#include <stdio.h>
#define SCORE_TD_2PC 8
#define SCORE_TD_EP 7
#define SCORE_TD 6
#define SCORE_FG 3
#define SCORE_SAFETY 2

void print_score_arrangement(int td_2pc, int td_ep, int td, int fg, int safety) {
    printf("%d TD+2PC, %d TD+EP, %d TD, %d FG, %d Safety\n", td_2pc, td_ep, td, fg, safety);
}

int main()
{
    int target_score = 0;
    while (1)
    {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &target_score);
        if (target_score < 2)
        {
            return 0;
        }
        const int MAX_TD_2PC = target_score / SCORE_TD_2PC;
        const int MAX_TD_EP = target_score / SCORE_TD_2PC;
        const int MAX_TD = target_score / SCORE_TD;
        const int MAX_FG = target_score / SCORE_FG;
        const int MAX_SAFETY = target_score / SCORE_SAFETY;
        int current_td_2pc, current_td_ep, current_td, current_fg, current_safety = 0;
        while (1) {
            
            break;
        }
    }
}