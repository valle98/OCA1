
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#include "set.h"

struct _Set{
  Id ident[MAX];
  int num_id;

};

/*
@brief Crea un conjunto
@param1 puntero id tipo Id
@param2 reserva memoria e inicializa el numero a '0' el numero de identificadores
*/
Set* set_create(){

    Set *set2 = NULL;

    if (set2 == NULL)
      return NULL;

    set2 = (Set *) malloc(sizeof (Set));

    if (set2 == NULL) {
      return NULL;
    }


    for (int i=0; i<MAX; i++){
      set2->ident[i] = NO_ID;
    }
    set2->num_id = 0;

    return set2;
}

/*
@brief Destruye el conjunto
@param1 puntero set de tipo Set que libera la memoria reservada anteriormente
@return1 devuelve ERROR si no se elimina el conjunto
@return2 si se realiza correctamente devuelve OK

 */
STATUS set_destroy(Set* set){

  if (!set) {
    return ERROR;
  }

  free(set);
  set = NULL;
  return OK;

}

/* @brief Añade un valor
@param*/
STATUS set_add(Set* set, Id* id){

  int i = 0;

  if (set == NULL) {
    return ERROR;
  }

  while ( (i < MAX) && (set->ident[i] != NULL)){
    i++;
  }

  if (i >= MAX) {
    return ERROR;
  }

  set->ident[i] = id;

  return OK;


}
/* @brief Elimina un valor */
STATUS set_del(Set *set, Id id){
  int i;

  if (set == NULL || set->num_id==0 || id == NO_ID){
    return ERROR;
  }

  for (i = 0; i < set->num_id; i++){
    if (set->ident[i]=id){

      set->ident[i]=NO_ID;
      set->num_id--;
      return OK;
    }
  }
return ERROR;
}

void set_print(Set *set){
  if (set == NULL){
    return;
  }
  int i;

  for (i=0;i<set->num_id; i++){
    print("Set: %ld", set->ident[i]);
  }
}
