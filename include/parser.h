#ifndef PARSER_H
#define PARSER_H

#include "../include/types.h"
#include "../include/machine.h"

int parse_state(machine *m, char letter, int curr_state);
int parse_letter(machine *m, char letter);
int parse(machine *m, char *str);

#endif