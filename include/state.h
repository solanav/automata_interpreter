#ifndef STATE_H
#define STATE_H

#include "../include/trans.h"

typedef struct _state {
    trans t[MAX_TRANS];
    int type; // Type of state
} state;

int state_empty(state *s);
void print_state(state *s);
int find_trans_empty(state *s);

#endif