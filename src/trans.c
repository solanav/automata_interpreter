#include <stdio.h>
#include <string.h>

#include "../include/types.h"
#include "../include/trans.h"

int create_trans_list(trans *ts, size_t size)
{
    memset(ts, -1, sizeof(trans) * size);

    return OK;
}

int add_trans_to_list(trans *ts, char trigger, int *next, size_t size_next)
{
    // Find empty space inside transition list
    for (int i = 0; i < MAX_TRANS; i++)
    {
        if (ts[i].c == -1)
        {
            // When you find empty space, copy data to that position
            ts[i].c = trigger;
            memcpy(ts[i].next, next, sizeof(int) * size_next);

            return OK;
        }
    }

    printf(DEBUG_BUILD"Could not find empty space inside transition list\n");

    return ERROR;
}

void print_trans_list(trans *ts, size_t size)
{
    for (int i = 0; i < size; i++)
        print_trans(&(ts[i]));
}

void print_trans(trans *t)
{
    printf("[%c] > [", t->c);
    
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (t->next[i] == -1)
            break;

        printf("%d, ", t->next[i]);
    }

    printf("]\n");
}