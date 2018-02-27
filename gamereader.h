/*
* @author Guillermo Ríos y Marcos Valle
* @version 1.0
* @date 13-01-2018
* @copyright GNU Public License */
#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "game.h"


/*
@brief se encarga de cargas los espacios en el juego, posee un puntero game de tipo GAME
y a filname que que es el archivo que se encarga de cargar los espacios
@param Game * puntero a Game
@param char* carga los espacios
@return ERROR si algo ha fallado
@return OK
*/
STATUS game_load_spaces(Game* game, char* filename);

#endif
