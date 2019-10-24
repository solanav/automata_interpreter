#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/trans.h"
#include "../include/state.h"
#include "../include/machine.h"

int main()
{
    machine m;

    // Create list of transitions (16)
    trans ts[MAX_TRANS];
    create_trans_list(ts, MAX_TRANS);

    // Create a transition
    int next[] = {2, 3};
    add_trans_to_list(ts, 'a', next, 2);

    int next2[] = {1};
    add_trans_to_list(ts, 'b', next2, 1);

    // Init the machine
    int starting[] = {0, 1, 2, 3, 4, 5};
    init_machine(&m, "abc", starting, 5);

    print_curr(&m);

    // State 0 ( 0 -> 1 through "b" )
    add_state(&m, ts, NORMAL_STATE);
    add_state(&m, ts, NORMAL_STATE);

    return ERROR;
}