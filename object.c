/*
* @author Guillermo Ríos y Marcos Valle
* @version 1.0
* @date 13-01-2018
* @copyright GNU Public License */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
/* @brief En este caso cada objeto tendrá un id y un nombre de máximo de caracteres [WORD_SIZE+1]*/
struct _Object {
  Id id;
  char name[WORD_SIZE + 1];

};

/* @brief Sirve para gestionar los objetos, muy similar al módulo Space  */
Object* object_create(Id id) {

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0';


  return newObject;
}


STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * object_get_name(Object* object) {
    if (!object) {
      return NULL;
    }
    return object->name;
  }


STATUS object_print(Object* object) {


    if (!object)
      return ERROR;


    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
  }
