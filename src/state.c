#include <stdio.h>
#include <string.h>

#include "../include/types.h"
#include "../include/state.h"
#include "../include/machine.h"

int state_empty(state *s)
{
    if (s->type == EMPTY)
        return true;

    return false;
}

void print_state(state *s)
{
    printf("Type: %d\n", s->type);
    for (int i = 0; i < MAX_TRANS; i++)
    {
        printf("%c > (", s->t[i].c);
        for (int j = 0; j < MAX_STATES; j++)
        {
            printf("%d, ", s->t[i].next[j]);
        }
        printf(")\n");
    }
}

int find_trans_empty(state *s)
{
    for (int i = 0; i < MAX_TRANS; i++)
    {
        printf(">>> [%d]\n", s->t[i].c);
        if (s->t[i].c == -1)
            return i;
    }

    return ERROR;
}