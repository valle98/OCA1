/*Con este modulo conseguimos implementar los jugadores*/
/*
* @author Guillermo Ríos y Marcos Valle
* @version 1.0
* @date 13-01-2018
* @copyright GNU Public License */

#ifndef PLAYER_H
#define PLAYER_H


#include "space.h"
/*En este caso cada jugador tendrá una id
-Con unnombre de máximo de caracteres [WORD_SIZE+1] .
-Con un id de espacio
-Y por último un id donde posee el objeto
*/

typedef struct _Player Player;
/*
@brief crea el jugador a partir de la id
@param Id
@return NULL si algo ha fallado
@return newplayer
*/
Player* player_create(Id id);
/*
@brief destruye el jugador indicado liberando la memoria que lo contiene
@param Player* es el jugador a eliminar
@return ERROR si algo ha fallado
@return OK
*/

STATUS player_destroy(Player* player);
/*
@brief modifica el nombre de un jugador
@param Player * jugador al cual establecer el nombre
@param char * nombre que se desea establecer
@return ERROR si algo ha fallado
@return OK
*/
STATUS player_set_name(Player* player, char* name);
/*
@brief modifica el objeto indicaDO
@param Player * jugador al que se le desea modificar el objeto
@param Id es el id del objeto
@return ERROR si algo ha fallado
@return OK
*/

STATUS player_set_object(Player* player, Id id);
/*
@brief obtiene el nombre a partir del jugador indicado
@param Player* jugador del que se desea obtener el nombre
@return ERROR si algo ha fallado
@return OK
*/
const char * player_get_name(Player* player);
/*
@brief crea el jugador a partir de la id
@param Id
@return NULL si algo ha fallado
@return newplayer
*/
Id player_get_id(Player* player);
/*
@brief obtiene el objeto que se encuentra donde el jugador indicado
@param Player * jugador del que se desea sobtener el objeto
@return ERROR si algo ha fallado
@return OK
*/
Id player_get_object(Player* player);
/*
@brief modifica el espacio
@param Player* jugador del cual se desea modificar su espacio
@param Id id que se desea modificar
@return ERROR si algo ha fallado
@return OK
*/
STATUS player_set_space(Player* player, Id id);
/*
@brief obtiene el espacio en el que esta situado el jugador
@param Player * jugador del que se desea obtener el espacio
@return ERROR si algo ha fallado
@return OK
*/
Id player_get_space(Player* player);
/*
@brief Imprime el jugador indicado
@param Player * jugador que se desea imprimir
@return ERROR si algo ha fallado
@return OK
*/

STATUS player_print(Player* player);

#endif
