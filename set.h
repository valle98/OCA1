
#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set;

Set* set_create();
STATUS set_destroy(Set* set);
STATUS set_add(Set* set, Id* id);
STATUS set_del(Set *set, Id id);
void set_print(Set *set);

#endif
