#ifndef TRANS_H
#define TRANS_H

#include "../include/types.h"

typedef struct _trans {
    char c; // trigger
    int next[MAX_STATES]; // next array
} trans;

int create_trans_list(trans *ts, size_t size);

int add_trans_to_list(trans *ts, char trigger, int *next, size_t size_next);

void print_trans_list(trans *ts, size_t size);
void print_trans(trans *t);

#endif