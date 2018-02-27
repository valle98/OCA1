/**
 * @author Guillermo Ríos y Marcos Valle 
 * @version 1.0
 * @date 13-01-2018
 * @copyright GNU Public License
 */

 #ifndef GAME_H
 #define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"



typedef struct _Game{
  Object* object;
  Player* player;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;
/* Esta primera crea una nueva interfaz para el juego , un puntero de tipo Game llamado game y devuelve OK si se realiza bien la interfaz*/
STATUS game_create(Game* game);

/* Se encarga de iniciar al jugador en la posicion cero partiendo de un archivo "filname" , posee un puntero tipo game.
Esta funcion nos devolverá OK si se realiza correctamente y en caso contrario nos devuelve ERROR*/
STATUS game_create_from_file(Game* game, char* filename);

/*Actualiza la oca, tiene un puntero tipo Game y cmd el cual se utiliza para realizar acciones
y nos devolverá ERROR en caso de que no se complete correctamente y OK si se ha conseguido actualizar */
STATUS game_update(Game* game, T_Command cmd);

/*Esta funcion llama a la funcion de destruir espacios(space_destroy) y destruye el juego , tiene un puntero game de tipo GAME
 Nos devuelve ERROR si se devuelve correctamente y OK si se destruye .*/
STATUS game_destroy(Game* game);

/* Añade un espacio ,un puntero game de tipo Game y otro space de tipo Space,
nos devuelve OK si se realiza correctamente y ERROR si no llega a recibir ese espacio*/
STATUS game_add_space(Game* game, Space* space);

/*Nos informa si el juego ha terminado,con un puntero tipo Game llamado game y nos
devuelve FALSE */
BOOL   game_is_over(Game* game);

/* TERMINAR*/
void   game_print_screen(Game* game);
void   game_print_data(Game* game);
Space* game_get_space(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game);
T_Command game_get_last_command(Game* game);

#endif
