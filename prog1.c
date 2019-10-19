#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1

#define DEBUG_BUILD "[BUILD] "
#define DEBUG_RUN "[RUN  ] "

#define MAX_LANGUAGE 15
#define MAX_STATES 15
#define MAX_TRANS 15
#define MAX_CURR 5

#define NORMAL_STATE 0
#define END_STATE 1
#define START_STATE 2

typedef struct _state state;
typedef struct _machine machine;

typedef struct _trans {
    char c; // trigger
    int next[MAX_STATES]; // next array
} trans;

typedef struct _state {
    trans t[MAX_TRANS];
    int type; // Type of state
} state;

typedef struct _machine {
    int current[MAX_CURR]; // Current state of the machine
    char language[MAX_LANGUAGE]; // Language for the machine
    state states[MAX_STATES]; // States of the machine
} machine;

void init_machine(machine *m, char *language, int starting_state)
{
    memset(m, -1, sizeof(machine));

    strcpy(m->language, language);
    m->current[0] = starting_state;
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
            print_state(&(m->states[i]));

            return i;
        }
    }

    return ERROR;
}

int parse_letter(machine *m, char letter, int curr)
{
    printf(DEBUG_RUN"Current state > %d with char %c\n", m->current[curr], letter);

    for (int i = 0; i < MAX_STATES; i++)
    {
        for (int j = 0; j < MAX_TRANS; j++)
        {
            if (m->states[m->current[curr]].t[j].c == letter)
            {
                m->current[curr] = m->states[m->current[curr]].t[j].next;
                printf(DEBUG_RUN"\tChanged to state > %d\n", m->current);
                
                return OK;
            }
        }
    }

    return OK;
}

int parse(machine *m, char *str)
{
    printf(DEBUG_RUN"Parsing \"%s\"\n", str);

    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < MAX_CURR; j++)
        {
            if (parse_letter(m, str[i], j) == ERROR)
            {
                printf(DEBUG_RUN"Failed to run parse_letter in %d\n", i);
                return ERROR;
            }
        }
    }

    if (m->states[m->current].type == END_STATE)
        printf(DEBUG_RUN"Final state reached\n");
    else
        printf(DEBUG_RUN"Final state not reached\n");
    

    return OK;
}

int main()
{
    machine m;

    trans ts[MAX_TRANS];
    memset(&ts, -1, sizeof(trans) * MAX_TRANS);
    
    trans t;
    memset(&t, -1, sizeof(trans));
    t.c = 'b';
    t.next[0] = 1;
    t.next[1] = 2;
    t.next[2] = 3;

    ts[0] = t;
    ts[1] = t;
    ts[2] = t;

    // Init the machine
    init_machine(&m, "abc", 0);

    // State 0 ( 0 -> 1 through "b" )
    add_state(&m, ts, NORMAL_STATE);
    add_state(&m, ts, NORMAL_STATE);

    return ERROR;
}