/*
* @author Guillermo Ríos y Marcos Valle
* @version 1.0
* @date 13-01-2018
* @copyright GNU Public License */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"


#define MAX_SPACES 100
#define  FIRST_OBJECT 1

/*@param un campo de identificacion id
@param nombre del objeto name*/
typedef struct _Object Object;

/* @brief Crea object_create que reserva memoria
@param1 Este inicializa con el puntero id los campos del objeto que devuelve*/
Object* object_create(Id id);

/* Esta función tiene como finalidad destruir el objeto
-Tiene un puntero al objeto que se quiere destruir */
STATUS object_destroy(Object* object);

/*Tiene como objetivo modificar el nombre del objeto
-name es un puntero a una array de caracteres.Name tiene un tamaño máximo de WORD_SIZE definida anteriormente
*/
STATUS object_set_name(Object* object, char* name);


/*Si el objeto es distintio te devuelve un NULL porque se ha creado mal.
Devuelve el nombre del objeto */
const char * object_get_name(Object* object);

/* @brief Nos da la id del objecto
@param puntero object de tipo Object
@return nos devuelve NO_ID si el objeto es nulo*/
Id object_get_id(Object* object);

/* @brief Imprime un objeto
@param puntero object de tipo Object
@return Si se imprime correctamente nos devuelve OK */
STATUS object_print(Object* object);

#endif
