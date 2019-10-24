#include <stdio.h>

#include "../include/types.h"
#include "../include/machine.h"

int parse_state(machine *m, char letter, int curr_state)
{
    printf(DEBUG_RUN"Current state > %d with char %c\n", m->current[curr_state], letter);
    return OK;
}

int parse_letter(machine *m, char letter)
{
    printf("Parsing letter %c\n", letter);

    for (int i = 0; i < MAX_CURR; i++)
        parse_state(m, letter, i);

    return OK;
}

int parse(machine *m, char *str)
{
    printf(DEBUG_RUN"Parsing \"%s\"\n", str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (parse_letter(m, str[i]) == ERROR)
        {
            printf(DEBUG_RUN"Failed to run parse_letter in %d\n", i);
            return ERROR;
        }
    }
/*
    if (m->states[m->current].type == END_STATE)
        printf(DEBUG_RUN"Final state reached\n");
    else
        printf(DEBUG_RUN"Final state not reached\n");
*/  

    return OK;
}
