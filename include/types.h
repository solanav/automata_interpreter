#include <stdbool.h>

#define OK 0
#define ERROR -1

#define DEBUG_BUILD "[BUILD] "
#define DEBUG_RUN "[RUN  ] "

#define MAX_LANGUAGE 15
#define MAX_STATES 15
#define MAX_TRANS 15
#define MAX_CURR 5

#define EMPTY -1
#define NORMAL_STATE 0
#define END_STATE 1
#define START_STATE 2