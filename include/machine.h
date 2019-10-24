#ifndef MACHINE_H
#define MACHINE_H

#include "../include/types.h"
#include "../include/state.h"

typedef struct _machine {
    int current[MAX_CURR]; // Current state of the machine
    char language[MAX_LANGUAGE]; // Language for the machine
    state states[MAX_STATES]; // States of the machine
} machine;

void init_machine(machine *m, char *language, int *starting_state, size_t num_s);
int add_curr_state(machine *m, state *s);
int add_state(machine *m, trans *t, int type);
void print_curr(machine *m);

#endif