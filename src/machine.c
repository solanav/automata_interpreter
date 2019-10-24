#include <stdio.h>
#include <string.h>

#include "../include/types.h"
#include "../include/machine.h"

void init_machine(machine *m, char *language, int *starting_state, size_t num_s)
{
    if (num_s > MAX_STATES)
    {
        printf(DEBUG_BUILD"Cannot add that many starting states to the machine\n");
        return;
    }

    memset(m, -1, sizeof(machine));

    memcpy(m->current, starting_state, sizeof(int) * num_s);
}

int add_curr_state(machine *m, state *s)
{
    for (int i = 0; i < MAX_CURR; i++)
    {
        // TODO
    }

    return ERROR; 
}

int add_state(machine *m, trans *t, int type)
{    
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (m->states[i].type == -1)
        {
            // Free space
            memcpy(m->states[i].t, t, MAX_TRANS * sizeof(trans));
            m->states[i].type = type;
            
            printf(DEBUG_BUILD"Added state number [%d] type [%d] to machine\n", i, type);
            
            if (m->states[i].type)
            print_state(&(m->states[i]));

            return i;
        }
    }

    return ERROR;
}

void print_curr(machine *m)
{
    printf("CURR > [");
    
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (m->current[i] == -1)
            break;

        printf("%d, ", m->current[i]);
    }

    printf("]\n");
}

void print_curr_ext(machine *m)
{
    printf("CURR >\n");

}